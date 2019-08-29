package com.utils;

import java.security.MessageDigest;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * @author feifei
 * @Classname BasicUtils
 * @Description TODO
 * @Date 2019/8/29 10:31
 * @Created by 陈群飞
 */
public class BasicUtils {

    /**
     * @author feifei
     * @param s
     * @param
     * @Description TODO 对字符串进行MD5加密32位大写字符值
     * @Date 2019/8/28 9:19
     * @Created by 陈群飞
     * @return
     */
    public final static String MD5(String s) {
        char hexDigits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
                'A', 'B', 'C', 'D', 'E', 'F'};
        try {
            byte[] btInput = s.getBytes();
            // 获得MD5摘要算法的 MessageDigest 对象
            MessageDigest mdInst = MessageDigest.getInstance("MD5");
            // 使用指定的字节更新摘要
            mdInst.update(btInput);
            // 获得密文
            byte[] md = mdInst.digest();
            // 把密文转换成十六进制的字符串形式
            int j = md.length;
            char str[] = new char[j * 2];
            int k = 0;
            for (int i = 0; i < j; i++) {
                byte byte0 = md[i];
                str[k++] = hexDigits[byte0 >>> 4 & 0xf];
                str[k++] = hexDigits[byte0 & 0xf];
            }
            return new String(str);
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }
    }

    /**
     * @author feifei
     * @param
     * @param pattern
     * @Description TODO 获取当前日期传入日期格式参数
     * @Date 2019/8/28 9:23
     * @Created by 陈群飞
     * @return
     */
    public String getDate(String pattern){
        Date date = new Date();
        SimpleDateFormat dateFormat = new SimpleDateFormat(pattern);
        String format = dateFormat.format(date);
        return format;
    }

    /**
     * @author feifei
     * @param date
     * @param pattern
     * @Description TODO 把字符串转成制定格式的日期格式
     * @Date 2019/8/28 9:26
     * @Created by 陈群飞
     * @return
     */
    public Date dateForFormat(String date,String pattern){
        Date dat = null;
        try {
            dat=new SimpleDateFormat(pattern).parse(date);
        } catch (ParseException e) {

            e.printStackTrace();
        }
        return dat;
    }

    /**
     * @author feifei
     * @param
     * @param s
     * @Description TODO 判断JSON数组是否为空,不为空返回真
     * @Date 2019/8/29 10:32
     * @Created by 陈群飞
     * @return boolean
     */
    public boolean arrIsNull(String s){
        return !"".equals(s)&&s!=null&&!"null".equals(s)&&!"[]".equals(s);
    }

    /**
     * @author feifei
     * @param
     * @param str
     * @Description TODO 判断字符串是否为空,不为空返回原值，为空返回空字符串
     * @Date 2019/8/29 10:32
     * @Created by 陈群飞
     * @return boolean
     */
    public String strIsNull(String str){
        if(str==null||"".equals(str.trim())||"null".equals(str.trim())){
            return "";
        }
        return str;
    }

    /**
     * @author feifei
     * @param num2
     * @param num1
     * @Description TODO 交换两个数值
     * @Date 2019/8/29 12:56
     * @Created by 陈群飞
     * @return
     */
    public void swap(int num1,int num2){
        int te=num1;
        num1=num2;
        num2=te;
    }
}
