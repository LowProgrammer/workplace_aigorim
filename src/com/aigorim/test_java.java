package com.aigorim;

import com.alibaba.fastjson.JSONObject;

import java.util.Random;

public class test_java {
    private String getRandomStr(int length){
        String str="0123456789";
//		if (string==null||"".equals(string.trim())){
//			str="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
//		}else {
//			str=string;
//		}
        //System.out.println(str.length());
        Random random=new Random();
        StringBuffer sb=new StringBuffer();
        for(int i=0;i<length;i++){
            int number=random.nextInt(str.length());
            sb.append(str.charAt(number));
        }
        //System.out.println(sb);
        return sb.toString();

    }


}