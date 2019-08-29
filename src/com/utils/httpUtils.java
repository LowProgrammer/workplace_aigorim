package com.utils;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.apache.http.HttpResponse;
import org.apache.http.NameValuePair;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;

import java.io.IOException;
import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.List;
import java.util.Map;

/**
 * @author feifei
 * @Classname httpUtils
 * @Description TODO
 * @Date 2019/8/29 10:21
 * @Created by 陈群飞
 */
public class httpUtils {
    /**
     * @author feifei
     * @param
     * @param params,url,headers,config
     * @Description TODO 发送get请求，设置header和参数
     * @Date 2019/8/29 10:28
     * @Created by 陈群飞
     * @return
     */
    public JSONObject qccHttpGet(Map<String,String> params, String url, JSONObject headers, RequestConfig config){

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

        httpGet.setHeader("Token",headers.getString("Token"));
        httpGet.setHeader("Timespan",headers.getString("Timespan"));

        httpGet.setConfig(config);

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
