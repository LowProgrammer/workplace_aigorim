package com.utils;


import org.apache.commons.compress.archivers.ArchiveEntry;
import org.apache.commons.compress.archivers.ArchiveException;
import org.apache.commons.compress.archivers.ArchiveInputStream;
import org.apache.commons.compress.archivers.zip.ZipArchiveInputStream;
import org.apache.commons.compress.utils.IOUtils;

import java.io.*;
import java.nio.file.Files;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.zip.ZipEntry;
import java.util.zip.ZipException;
import java.util.zip.ZipFile;
import java.util.zip.ZipInputStream;

public class FileUtils {
    private static final Integer ONE = 1;
    /**
     * @author feifei
     * @param path
     * @Description TODO 逐行读取文件内容
     * @Date 2019/11/13 9:28
     */
    public static Map<String,Integer> readFile(String path){
        Map<String, Integer> map = new HashMap<String, Integer>();

        /* 读取数据 */
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(path)),
                    "UTF-8"));
            String lineTxt = null;
            while ((lineTxt = br.readLine()) != null) {
                String[] names = lineTxt.split(",");
                for (String name : names) {
                    if (map.keySet().contains(name)) {
                        map.put(name, (map.get(name) + ONE));
                    } else {
                        map.put(name, ONE);
                    }
                }
            }
            br.close();
        } catch (Exception e) {
            System.err.println("read errors :" + e);
        }
        return map;
    }
    //private static final Logger log = LoggerFactory.getLogger(FileUtils.class);

    public int getFileCount(String strPath) {

        File dir = new File(strPath);
        File[] files = dir.listFiles(); // 该文件目录下文件全部放入数组
        return (files.length-2)/2;
    }

    public List<String> getAllJpg(String strPath) {

        File dir = new File(strPath);
        File[] files = dir.listFiles(); // 该文件目录下文件全部放入数组
        List<String> list = new ArrayList<>();
        if (files != null) {
            for (int i = 0; i < files.length; i++) {
                String fileName = files[i].getName();
                if (fileName.endsWith("obverseImg.jpg")) {
                    list.add(fileName.split("_")[0]);
                } else {
                    continue;
                }
            }
        }
        return list;
    }
    public  boolean delAllFile(String path) {
        boolean flag = false;
        File file = new File(path);
        if (!file.exists()) {
            return flag;
        }
        if (!file.isDirectory()) {
            return flag;
        }
        String[] tempList = file.list();
        File temp = null;
        if(tempList.length==0){
            flag=true;
        }
        for (int i = 0; i < tempList.length; i++) {
            if (path.endsWith(File.separator)) {
                temp = new File(path + tempList[i]);
            } else {
                temp = new File(path + File.separator + tempList[i]);
            }
            if (temp.isFile()) {
                temp.delete();
                flag = true;
            }
            if (temp.isDirectory()) {
                delAllFile(path + "/" + tempList[i]);//先删除文件夹里面的文件
                flag = true;
            }
        }
        return flag;
    }

    /**
     * @author feifei
     * @param destDir
     * @param zipFile
     * @Description TODO 解压zip文件
     * @Date 2019/9/3 15:11
     * @Created by 陈群飞
     * @return
     */
    public void unzip(File zipFile, File destDir) throws IOException, ArchiveException {
        String destDirectory = destDir.getAbsolutePath();

        try (ArchiveInputStream i = new ZipArchiveInputStream(new
                FileInputStream(zipFile), "UTF-8", false, true)) {
            ArchiveEntry entry = null;
            while ((entry = i.getNextEntry()) != null) {
                if (!i.canReadEntryData(entry)) {
                    System.out.println("Can't read entry: " + entry);
                    continue;

                }
                String name = destDirectory + File.separator + entry.getName();
                File f = new File(name);
                if (entry.isDirectory()) {
                    if (!f.isDirectory() && !f.mkdirs()) {
                        throw new IOException("failed to create directory " + f);
                    }
                } else {
                    File parent = f.getParentFile();
                    if (!parent.isDirectory() && !parent.mkdirs()) {
                        throw new IOException("failed to create directory " + parent);
                    }
                    try (OutputStream o = Files.newOutputStream(f.toPath())) {
                        IOUtils.copy(i, o);
                    }

                }
            }
        }
    }
    /**
     * 解压压缩包到指定目录
     *
     * @param inputFile
     * @param outputFile
     */
    public boolean unZip(File inputFile, File outputFile) {

        if (!outputFile.exists()) {
            outputFile.mkdirs();
        }

        ZipFile zipFile = null;
        ZipInputStream zipInput = null;
        ZipEntry entry = null;
        OutputStream output = null;
        InputStream input = null;
        File file = null;
        try {
            zipFile = new ZipFile(inputFile);
            zipInput = new ZipInputStream(new FileInputStream(inputFile));
            String path = outputFile.getAbsolutePath() + File.separator;
            //log.info("path:"+path);
            while ((entry = zipInput.getNextEntry()) != null) {
                // 从压缩文件里获取指定已压缩文件的输入流
                input = zipFile.getInputStream(entry);

                // 拼装压缩后真实文件路径
                String fileName = path + entry.getName();
                System.out.println("文件路径："+fileName);
                //log.info("fileName:"+fileName);
                // 创建文件缺失的目录（不然会报异常：找不到指定文件）
                file = new File(fileName.substring(0, fileName.lastIndexOf(File.separator)));
               // log.info("file:"+file);
                file.mkdirs();

                // 创建文件输出流
                output = new FileOutputStream(fileName);

                // 写出解压后文件数据
                write(input, output);
                output.close();
            }
            return true;
        } catch (ZipException e) {
            e.printStackTrace();
            //log.error("解压失败，错误信息"+e.getMessage());
        } catch (IOException e) {
            e.printStackTrace();
            //log.error("解压失败（IO），错误信息"+e.getMessage());
        } finally {
            try {
                if (output != null) {
                    output.close();
                }

                if (zipInput != null) {
                    zipInput.close();
                }
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return false;
    }
    /**
     * 从输入流写入到输出流的方便方法 【注意】这个函数只会关闭输入流，且读写完成后会调用输出流的flush()函数，但不会关闭输出流！
     *
     * @param input
     * @param output
     */
    private static void write(InputStream input, OutputStream output) {
        int len = -1;
        byte[] buff = new byte[1024];
        try {
            while ((len = input.read(buff)) != -1) {
                output.write(buff, 0, len);
            }
            output.flush();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                input.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
    }


    /**
     * 获取所有文件列表
     * @param strPath
     * @return
     */
    public List<String> getAllFileList(String strPath) {

        File dir = new File(strPath);
        File[] files = dir.listFiles(); // 该文件目录下文件全部放入数组
        List<String> list = new ArrayList<>();
        if (files != null) {
            for (int i = 0; i < files.length; i++) {
                String fileName = files[i].getName();
                if (fileName.endsWith("jpg")) { // 判断文件名是否以.avi结尾System.out.println("---" + strFileName);
                    list.add(fileName);
                } else {
                    continue;
                }
            }

        }
        return list;
    }

    /**
     * 按行读取文件，返回数组集合
     * @param filename
     * @return
     */
    public List<String> fileReader(String filename){
        InputStreamReader isr;
        List<String> list = new ArrayList<String>();

        try {
            isr = new InputStreamReader(new FileInputStream(filename), "GBK");
            BufferedReader read = new BufferedReader(isr);
            String s=null;
            while((s=read.readLine())!=null)
            {
                if(s.trim().length()>1){
                    list.add(s.trim());
                }
            }
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return list;
    }
}
