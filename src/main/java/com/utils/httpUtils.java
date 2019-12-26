package com.utils;

import com.alibaba.fastjson.JSON;
import com.alibaba.fastjson.JSONObject;
import org.apache.http.*;
import org.apache.http.client.ClientProtocolException;
import org.apache.http.client.HttpClient;
import org.apache.http.client.config.RequestConfig;
import org.apache.http.client.entity.UrlEncodedFormEntity;
import org.apache.http.client.methods.CloseableHttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.utils.URIBuilder;
import org.apache.http.entity.mime.MIME;
import org.apache.http.entity.mime.MultipartEntityBuilder;
import org.apache.http.entity.mime.content.FileBody;
import org.apache.http.impl.client.CloseableHttpClient;
import org.apache.http.impl.client.HttpClientBuilder;
import org.apache.http.impl.client.HttpClients;
import org.apache.http.message.BasicNameValuePair;
import org.apache.http.util.EntityUtils;

import java.io.*;
import java.net.URI;
import java.net.URISyntaxException;
import java.text.SimpleDateFormat;
import java.util.*;

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
        List<NameValuePair> pairs=new ArrayList<NameValuePair>();
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

    /**
     * @author feifei
     * @param
     * @param url,params,headers
     * @Description TODO 发送post请求,可设置header和请求参数
     * @Date 2019/8/29 10:50
     * @Created by 陈群飞
     * @return String
     */
    public String doPost(String url, Map<String,String> params, Header[] headers){
        String result = null;
        //请求地址
        List<NameValuePair> parameForToken = new ArrayList<NameValuePair>();
        for (Map.Entry<String,String> entry:params.entrySet()) {
            parameForToken.add(new BasicNameValuePair(entry.getKey(),entry.getValue()));
        }
        //parameForToken.add("参数名", 参数值);
        // 获取httpclient
        CloseableHttpClient httpclient = HttpClients.createDefault();
        CloseableHttpResponse response = null;
        try {
            //创建post请求
            HttpPost httpPost = new HttpPost(url);
            // 设置请求和传输超时时间
            RequestConfig requestConfig = RequestConfig.custom()
                    .setSocketTimeout(2000).setConnectTimeout(2000).build();
            httpPost.setConfig(requestConfig);

            if(headers.length>0) {
                //设置头部信息
                httpPost.setHeaders(headers);
            }
            // 提交参数发送请求
            UrlEncodedFormEntity urlEncodedFormEntity = new UrlEncodedFormEntity(parameForToken);
            httpPost.setEntity(urlEncodedFormEntity);
            response = httpclient.execute(httpPost);
            // 得到响应信息
            int statusCode = response.getStatusLine().getStatusCode();
            // 判断响应信息是否正确
            if (statusCode != HttpStatus.SC_OK) {
                // 终止并抛出异常
                httpPost.abort();
                throw new RuntimeException("HttpClient,error status code :" + statusCode);
            }
            HttpEntity entity = response.getEntity();
            if (entity != null) {
                //result = EntityUtils.toString(entity);//不进行编码设置
                result = EntityUtils.toString(entity, "UTF-8");
            }
            EntityUtils.consume(entity);

        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        } catch (ClientProtocolException e) {
            e.printStackTrace();
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            //关闭所有资源连接
            if (response != null) {
                try {
                    response.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            if (httpclient != null) {
                try {
                    httpclient.close();
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }
        return result;

    }


    /**
     * @author feifei
     * @param
     * @param url
     * @Description TODO 上传文件工具
     * @Date 2019/9/3 14:12
     * @Created by 陈群飞
     * @return
     */
    public String upload(String url,Header[] headers,String filepath,String imageName) {
        HttpPost post = new HttpPost();
        //post.setHeader("Authorization", "Basic " + authorization);
        post.setHeaders(headers);
        try {
            post.setURI(new URI(url));
        } catch (URISyntaxException e) {

        }

        HttpClient client = HttpClients.createDefault();
        MultipartEntityBuilder builderMaster = MultipartEntityBuilder.create().setCharset(MIME.UTF8_CHARSET);
        //String scan_time = new SimpleDateFormat("yyyy-MM-dd'T'HH:mm:ss.SSS").format(new Date());
        //String flw_code = new SimpleDateFormat("yyyyMMdd HHmmssSSS").format(new Date());
        File file = new File(filepath);
        FileBody fileBody = new FileBody(file);
        builderMaster.addPart("jpg", fileBody);
//        builderMaster.addTextBody("SCAN_TIME", scan_time);
//        builderMaster.addTextBody("FLW_CODE", "ECIF"+flw_code);
//        builderMaster.addTextBody("TYPE_CODE", "1");
//        builderMaster.addTextBody("SYS_CODE", "ECIF");
//        builderMaster.addTextBody("SYSCODE", "ECIF");
//        builderMaster.addTextBody("ORG_CODE", "ECIF");
//        builderMaster.addTextBody("SCAN_MAN", "ECIF");
//        builderMaster.addTextBody("_acl", "{\"read\":{\"users\":[\"ecif\"],\"groups\":[\"WKXT_GROUP\"]},\"write\":{\"users\":[\"ecif\"],\"groups\":[]}}");
//        builderMaster.addTextBody("IMAGE_NAME", imageName);
//        builderMaster.addTextBody("FILE_TYPE", imageName.substring(imageName.lastIndexOf(".") + 1));
//        builderMaster.addTextBody("IS_DELETE", "0");
//        builderMaster.addTextBody("SCAN_INDEX", "0");
//        builderMaster.addTextBody("SOURCE_FLAG", "ECIF");
//        builderMaster.addTextBody("REMARK", "");
//        builderMaster.addTextBody("IMAGE_ID", "");
//        builderMaster.addTextBody("name", "idCard");
//        builderMaster.addTextBody("tag","project-name-test,project-type-test");
        HttpEntity entity = builderMaster.build();
        post.setEntity(entity);
        HttpResponse httpResponse;
        try {
            httpResponse = client.execute(post);
            HttpEntity httpEntity = httpResponse.getEntity();

            if (httpEntity != null) {
                InputStream instreams = httpEntity.getContent();
                String str = convertStreamToString(instreams);
                System.out.println("Response:" + "\n" + str);
                return str;
            }

        } catch (IOException e) {
            System.out.println("error");
            e.printStackTrace();
        }
        return "F";
    }

    public String convertStreamToString(InputStream is) {
        BufferedReader reader = new BufferedReader(new InputStreamReader(is));
        StringBuilder sb = new StringBuilder();
        String line = null;
        try {
            while ((line = reader.readLine()) != null) {
                sb.append(line + "/n");
            }
        } catch (IOException e) {
            e.printStackTrace();
        } finally {
            try {
                is.close();
            } catch (IOException e) {
                e.printStackTrace();
            }
        }
        return sb.toString();

    }
}
