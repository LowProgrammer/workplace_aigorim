package com.utils;

import com.jcraft.jsch.*;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;
import java.util.Properties;
import java.util.concurrent.TimeUnit;

/**
 * @author feifei
 * @Classname sftpUtils
 * @Description TODO
 * @Date 2019/9/3 12:56
 * @Created by 陈群飞
 */
public class sftpUtils {
    private static int downloadSleep=1000;
    private static int downloadRetry=10;
    /**
     * @author feifei
     * @param localpath
     * @param pathname
     * @Description TODO
     * @Date 2019/9/3 12:57
     * @Created by 陈群飞
     * @return 
     */
    public List<String> downloadFile(String pathname,String localpath,String user,String password,String ip,int port,String privateKey){
        ChannelSftp sftp = SFTPConnectionFactory.getInstance(user,password,ip,port,privateKey).makeConnection();

        List<String> files=new ArrayList<>();
        //String zipName = "";
        Integer i = 0;
        //log.info("baiduPath:"+baiduPathname);
        int index = pathname.lastIndexOf('/');
        String rq = pathname.substring(index+1,pathname.length());
        String fName = "idcard_"+rq+".zip";//完全匹配zip文件名称
//        String fName = "idcard_20190410.zip";//完全匹配zip文件名称
        if (pathname != null && !"".equals(pathname)) {
            try {
                sftp.cd(pathname);//进入指定的目录
            } catch (Exception e) {
                //log.error("sftp文件下载，目录不存在，错误信息"+e.getMessage());
            }
        }
        //获取sftp服务器下的文件
        List sftpFiles = new ArrayList<>();
        try {
            sftpFiles = sftp.ls(pathname);
        } catch (SftpException e) {
            e.printStackTrace();
        }
        //log.info("sftp服务器"+"路径"+baiduPathname+"下的所有文件："+sftpFiles);
//        for(File sftpFile:sftpFiles){
        for(int j=0;j<sftpFiles.size();j++){
            String[] arr =sftpFiles.get(j).toString().split(" ");
            String sftpFile = arr[arr.length-1];
            //  String idcard = sftpFile.split("_")[0];

            //if(sftpFile.equals(fName)){
                File file = new File(pathname+"/"+sftpFile);
                FileOutputStream fileOutputStream = null;
                try {
                    if(!file.getParentFile().exists()){
                        file.getParentFile().mkdirs();
                        try {
                            file.createNewFile();
                        } catch (IOException e) {
                            e.printStackTrace();
                        }
                    }
                    fileOutputStream = new FileOutputStream(file);
                } catch (FileNotFoundException e1) {
                    //log.error("sftp文件下载失败，本地目录不存在"+e1.getMessage());
                    System.out.println("sftp文件下载失败，本地目录不存在"+e1.getMessage());
                }
                try {
                    sftp.get(sftpFile, fileOutputStream);
                    if(i>0){
                        System.out.println("sftp文件重试下载成功,sftp地址:"+pathname+",本地文件地址:"+localpath);
                        //log.info("sftp文件重试下载成功,sftp地址:"+baiduPathname+",本地文件地址:"+baiduLocalpath);
                    }else{
                        System.out.println("sftp文件下载成功,sftp地址:"+pathname+",本地文件地址:"+localpath);
                        //log.info("sftp文件下载成功,sftp地址:"+baiduPathname+",本地文件地址:"+baiduLocalpath);
                    }
                    files.add(sftpFile);
                } catch (SftpException e1) {
                    i++;
                    System.out.println("sftp文件下载失败，重试中。。。第"+i+"次，错误信息"+e1.getMessage());
                    //log.error("sftp文件下载失败，重试中。。。第"+i+"次，错误信息"+e1.getMessage());
                    if(i>downloadRetry){
                        System.out.println("ftp文件下载失败，超过重试次数结束重试，错误信息"+e1.getMessage());
                        //log.error("ftp文件下载失败，超过重试次数结束重试，错误信息"+e1.getMessage());
                    }
                    try {
                        TimeUnit.MILLISECONDS.sleep(downloadSleep);
                    } catch (Exception e2) {
                        e2.printStackTrace();
                    }
                }finally {
                    try {
                        sftp.disconnect();
                        fileOutputStream.close();
                    } catch (IOException e) {
                        e.printStackTrace();
                    }
                }
        }
        return files;

    }
}
class SFTPConnectionFactory {
    //private static final org.slf4j.Logger log = LoggerFactory.getLogger(BaiduSFTPConnectionFactory.class);
    /** SFTP 登录用户名*/

    private static String user;
    /** SFTP 登录密码*/
    private static String password;
    /** 私钥 */
    private static String privateKey;
    /** SFTP 服务器地址bdip地址*/
    private static String ip;
    /** SFTP 端口*/
    private static int port;
    private static  SFTPConnectionFactory factory = new SFTPConnectionFactory(user,password,ip,port,privateKey);

    private ChannelSftp client;
    private Session session;
    private SFTPConnectionFactory(){

    }
    private  SFTPConnectionFactory(String user,String password,String ip,int port,String privateKey){
        SFTPConnectionFactory.user=user;
        SFTPConnectionFactory.password=password;
        SFTPConnectionFactory.ip=ip;
        SFTPConnectionFactory.port=port;
        SFTPConnectionFactory.privateKey=privateKey;
    }
    public static SFTPConnectionFactory getInstance(String user,String password,String ip,int port,String privateKey){
        if (SFTPConnectionFactory.user==null||SFTPConnectionFactory.user==""){
            factory=new SFTPConnectionFactory(user,password,ip,port,privateKey);
        }
        return factory;
    }
    synchronized public ChannelSftp makeConnection(){
        if(client==null||session==null||!client.isConnected()||!session.isConnected()){
            try {
                JSch jsch = new JSch();
                if (privateKey != null) {
                    jsch.addIdentity(privateKey);// 设置私钥
                }
                session = jsch.getSession(user, ip, port);
                if (password != null) {
                    session.setPassword(password);
                }
                Properties config = new Properties();
                config.put("StrictHostKeyChecking", "no");
                session.setConfig(config);
                session.connect();
                Channel channel = session.openChannel("sftp");
                channel.connect();
                client = (ChannelSftp) channel;
                //log.info("sftp服务器连接成功");
            } catch (JSchException e) {
                //log.error("sftp登录失败，检测登录bdip，端口号，用户名密码是否正确，错误信息为"+e.getMessage());
            }
        }
        return client;
    }
    /**
     * 关闭连接 server
     */
    public  void logout(){
        if (client != null) {
            if (client.isConnected()) {
                client.disconnect();
            }
        }
        if (session != null) {
            if (session.isConnected()) {
                session.disconnect();
            }
        }
    }
    public static String getUser() {
        return user;
    }

    public static void setUser(String user) {
      SFTPConnectionFactory.user = user;
    }
    public static String getPassword() {
        return password;
    }
    public static void setPassword(String password) {
       SFTPConnectionFactory.password = password;
    }
    public static String getPrivateKey(){
        return privateKey;
    }
    public static void setPrivateKey(String privateKey) {
        SFTPConnectionFactory.privateKey = privateKey;
    }
    public static String getIp() {
        return ip;
    }
    public static void setIp(String ip) {
        SFTPConnectionFactory.ip = ip;
    }
    public static int getPort() {
        return port;
    }
    public static void setPort(int port) {
        SFTPConnectionFactory.port = port;
    }
}
