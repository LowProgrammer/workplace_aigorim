package com.utils;

import org.apache.commons.lang3.RandomStringUtils;

import java.util.Random;

/**
 * @author feifei
 * @Classname StringUtils
 * @Description TODO
 * @Date 2019/8/29 14:39
 * @Created by 陈群飞
 */
public class StringUtils {

    /**
     * @author feifei
     * @param
     * @param str
     * @Description TODO 判断字符串是否为空 空返回真 非空返回假
     * @Date 2019/8/29 14:42
     * @Created by 陈群飞
     * @return
     */
    public static boolean isBlank(String str) {
        int strLen;
        if (str != null && (strLen = str.length()) != 0) {
            for(int i = 0; i < strLen; ++i) {
                if (!Character.isWhitespace(str.charAt(i))) {
                    return false;
                }
            }

            return true;
        } else {
            return true;
        }
    }

    /**
     * @author feifei
     * @param
     * @param str
     * @Description TODO JSON判断字符串是否为空,不为空返回原值，为空返回空字符串
     * @Date 2019/8/29 10:32
     * @Created by 陈群飞
     * @return boolean
     */
    public static String strIsNull(String str){
        if(str==null||"".equals(str.trim())||"null".equals(str.trim())){
            return "";
        }
        return str;
    }

    /**
     * @author feifei
     * @param
     * @param length
     * @Description TODO 生成固定长度的随机字符串
     * @Date 2019/8/29 19:16
     * @Created by 陈群飞
     * @return
     */
    public static String getRandomStr(int length){
        String filename= RandomStringUtils.randomAlphanumeric(length);
        System.out.println(filename);
        return filename;
    }

    /**
     * @author feifei
     * @param length
     * @param string
     * @Description TODO 根据指定字符串生成随机字符串
     * @Date 2019/8/29 19:22
     * @Created by 陈群飞
     * @return 
     */
    public static String getRandomStr(String string,int length){
        String str="";
        if (string==null||"".equals(string.trim())){
            str="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
        }else {
            str=string;
        }
        System.out.println(str.length());
        Random random=new Random();
        StringBuffer sb=new StringBuffer();
        for(int i=0;i<length;i++){
            int number=random.nextInt(str.length());
            sb.append(str.charAt(number));
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        getRandomStr("",20);
    }
}

