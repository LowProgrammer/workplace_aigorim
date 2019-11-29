package com.aigorim;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.apache.http.NameValuePair;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.*;

import static com.utils.FileUtils.readFile;

public class test_java {
    public static void main(String[] args) {
        test_java t=new test_java();
        Map<String,Integer> map=readFile("C:\\Users\\陈群飞\\Desktop\\test.txt");
        for (String name:map.keySet()         ) {
            System.out.println("1"+name+"1");
            Map<String,String> params=new HashMap<>();
            //http://localhost:9898/qcc/qydwd?keyword=%E5%AD%9F%E5%85%83&type=opername&pageIndex=2
            params.put("keyword",name.trim());
            params.put("type","opername");
            System.out.println(t.qccHttpGet(params,"http://localhost:9898/qcc/qydwd"));
        }

    }
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

    public JSONObject qccHttpGet(Map<String,String> params, String url){

        CloseableHttpClient httpClient= HttpClients.createDefault();
        List<NameValuePair> pairs=new ArrayList<>();
        for (Map.Entry<String,String> entry:params.entrySet()) {
            pairs.add(new BasicNameValuePair(entry.getKey(),entry.getValue()));
        }
        HttpGet httpGet = new HttpGet(url);
        CloseableHttpResponse response=null;

        URI uri=null;
        try {
            URIBuilder builder=new URIBuilder(url);
            builder.setParameters(pairs);
            uri=builder.build();
            httpGet=new HttpGet(uri);
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }

//        httpGet.setHeader("Token",headers.getString("Token"));
//        httpGet.setHeader("Timespan",headers.getString("Timespan"));
//
//        httpGet.setConfig(config);

        JSONObject result=new JSONObject();
        try {
            response=httpClient.execute(httpGet);
            result= JSON.parseObject(EntityUtils.toString(response.getEntity()));
            System.out.println("result--->"+result.toJSONString());
            //response.getEntity();
        } catch (IOException e) {
            e.printStackTrace();
        }
        return  result;
    }
}