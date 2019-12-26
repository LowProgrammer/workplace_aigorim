package com.utils;


import org.apache.commons.codec.binary.Base64;


import javax.crypto.Cipher;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.OutputStream;
import java.security.*;
import java.security.interfaces.RSAPrivateKey;
import java.security.interfaces.RSAPublicKey;
import java.security.spec.X509EncodedKeySpec;
import java.util.HashMap;
import java.util.Map;

public class RSAFileUtils {
    private static Map<Integer, String> keyMap = new HashMap<Integer, String>();
    public static final String KEY_ALGORITHM = "RSA";


    /**
     * 最大文件解密块
     */
    private static final int MAX_DECRYPT_BLOCK = 128;



    /**
     * 随机生成密钥对
     * @throws NoSuchAlgorithmException
     */
    public static void genKeyPair() throws NoSuchAlgorithmException {
        // KeyPairGenerator类用于生成公钥和私钥对，基于RSA算法生成对象
        KeyPairGenerator keyPairGen = KeyPairGenerator.getInstance("RSA");
        // 初始化密钥对生成器，密钥大小为96-1024位
        keyPairGen.initialize(1024,new SecureRandom());
        // 生成一个密钥对，保存在keyPair中
        KeyPair keyPair = keyPairGen.generateKeyPair();
        RSAPrivateKey privateKey = (RSAPrivateKey) keyPair.getPrivate();   // 得到私钥
        RSAPublicKey publicKey = (RSAPublicKey) keyPair.getPublic();  // 得到公钥
        String publicKeyString = new String(Base64.encodeBase64(publicKey.getEncoded()));
        // 得到私钥字符串
        String privateKeyString = new String(Base64.encodeBase64((privateKey.getEncoded())));
        // 将公钥和私钥保存到Map
        keyMap.put(0,publicKeyString);  //0表示公钥
        keyMap.put(1,privateKeyString);  //1表示私钥
    }


    /**
     * 通过公钥对文件进行解密的方法
     *
     * @param publicKey    公钥
     * @param srcFileName  源文件名称
     * @param destFileName 解密后保存文件名称
     * @return boolean
     */
    public void decryptFile(String publicKey, String srcFileName, String destFileName) throws Exception {
        OutputStream outputWriter = null;
        FileInputStream inputReader = null;
        try {

            byte[] keyBytes = Base64.decodeBase64(publicKey);
            X509EncodedKeySpec x509KeySpec = new X509EncodedKeySpec(keyBytes);
            KeyFactory keyFactory = KeyFactory.getInstance(KEY_ALGORITHM);
            Key publicK = keyFactory.generatePublic(x509KeySpec);
            Cipher cipher = Cipher.getInstance(keyFactory.getAlgorithm());
            cipher.init(Cipher.DECRYPT_MODE, publicK);

            byte[] buf = new byte[MAX_DECRYPT_BLOCK];
            int buf1;
            outputWriter = new FileOutputStream(destFileName);
            inputReader = new FileInputStream(srcFileName);
            while ((buf1 = inputReader.read(buf)) != -1) {
                byte[] encText = null;
                byte[] newArr = null;
                if (buf.length == buf1) {
                    newArr = buf;
                } else {
                    newArr = new byte[buf1];
                    for (int i = 0; i < buf1; i++) {
                        newArr[i] = (byte) buf[i];
                    }
                }
                encText = cipher.doFinal(newArr);
                outputWriter.write(encText);
            }
            outputWriter.flush();
        } catch (Exception e) {
            throw e;
        } finally {
            try {
                if (outputWriter != null) {
                    outputWriter.close();
                }
                if (inputReader != null) {
                    inputReader.close();
                }
            } catch (Exception e) {
                throw e;
            }
        }
    }

    /**
     * @author feifei
     * @param
     * @param str
     * @Description TODO 加密
     * @Date 2019/9/3 15:06
     * @Created by 陈群飞
     * @return
     */
    public static String encrypt( String str, String publicKey ) throws Exception{
        //base64编码的公钥
        byte[] decoded = Base64.decodeBase64(publicKey);
        RSAPublicKey pubKey = (RSAPublicKey) KeyFactory.getInstance("RSA").generatePublic(new X509EncodedKeySpec(decoded));
        //RSA加密
        Cipher cipher = Cipher.getInstance("RSA");
        cipher.init(Cipher.ENCRYPT_MODE, pubKey);
        String outStr = Base64.encodeBase64String(cipher.doFinal(str.getBytes("UTF-8")));
        return outStr;
    }


    public static void main(String[] args) throws Exception {
        String piublic_key="MIGfMA0GCSqGSIb3DQEBAQUAA4GNADCBiQKBgQCQPgVnVcNIeofLEepCl7Fqcr/QcFeo9pZ3O8oyCHUvGJ852Vwsfa1z2T+SswTak/o8DEeZ8h0CssSsHoDBFBuowsNgCt+KL5HfRRpkxQXe3rFQN4Ne52FtRm5LaYQDaSH4QjHAUbfxpcRzeOBB9kUJj9F+bzIpyb8x+OcrvgosOQIDAQAB";
        RSAFileUtils rsaFileUtils=new RSAFileUtils();
        rsaFileUtils.decryptFile(piublic_key,"C:\\Users\\陈群飞\\Desktop\\idCard_20190903.zip","C:\\Users\\陈群飞\\Desktop\\decrypt.zip");

    }
}
