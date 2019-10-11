package com.aigorim;

import java.util.*;

/**
 * @author feifei
 * @Classname Solution2
 * @Description TODO
 * @Date 2019/10/9 16:00
 * @Created by 陈群飞
 */
public class Solution2 {
    public static void main(String[] args) {
        System.out.println(232356);
        Solution2 s=new Solution2();
        String[] a=new String[]{"cool","lock","cook"};
        s.commonChars(a);
    }

    /**
     * @author feifei
     * @param num
     * @Description TODO leetcode 338. Counting Bits
     * @Date 2019/10/10 9:32
     * 计算0~n（n+1）个换成二进制有多少个一
     */
    public int[] countBits(int num) {
        int[] arr=new int[num+1];
        int x=1;
        for (int i = 0; i <=num; i++) {
            if (i<2){
                getNum(arr,i,0);
            }else if (x*2>=i){
                getNum(arr,i,x);
            }else{
                x=x*2;
                getNum(arr,i,x);
            }
            //System.out.println(arr[i]);
        }
        return arr;
    }

    /**
     * 计算数n换成二进制数会有多少个1
     * @param arr
     * @param n
     * @param x
     */
    private void getNum(int[] arr,int n,int x){
        if (n==0){
            arr[0]=0;
        }else if (n==1){
            arr[1]=1;
        }else if (n==x*2){
            arr[n]=1;
        }else{
            arr[n]=1+arr[n-x];
        }
    }

    /**
     * @author feifei
     * @param board
     * @Description TODO  ·
     * @Date 2019/10/11 10:57
     * 计算一个车在四个方向上能有多少个卒子能吃，使用数组来标记四个方向
     *
     */
    public int numRookCaptures(char[][] board) {
        int x = 0,y=0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j]=='R'){
                    x=i;
                    y=j;
                    break;
                }
            }
        }
        int[][] di=new int[][]{{-1,0},{1,0},{0,1},{0,-1}};
        int res=0;
        for (int i = 0; i < 4; i++) {
            int x0=x+di[i][0];
            int y0=y+di[i][1];
            while(x0>=0&&x0<8&&y0<8&&y0>=0){
                if (board[x0][y0]=='p'){
                    res++;
                    break;
                }
                if (board[x0][y0]=='B'){
                    break;
                }
                x0+=di[i][0];
                y0+=di[i][1];
            }
        }
        return res;
    }

    /**
     * @author feifei
     * @param A
     * @Description TODO leetcode 1002. Find Common Characters
     * @Date 2019/10/11 12:32
     * 找出字符串中重复出现的部分
     */
    public List<String> commonChars(String[] A) {
        int len=A.length;
        List<String> list=new ArrayList<>();
        char[] arr=A[0].toCharArray();
        for (int i = 1; i <len; i++) {
            arr=removeLeft(arr,A[i]);
        }
        for (int i = 0; i < arr.length; i++) {
            list.add(arr[i]+"");
            System.out.println(arr[i]);
        }

//        Map<Character, Integer> maps=new HashMap<>();
//        for (int i = 0; i < len; i++) {
//            for (int j = 0; j < A[i].length(); j++) {
//                if (maps.containsKey(A[i].charAt(j))){
//                    int n=maps.get(A[i].charAt(j))+1;
//                    maps.put(A[i].charAt(j),n);
//                }else{
//                    maps.put(A[i].charAt(j),1);
//                }
//            }
//        }
//        for (Map.Entry<Character, Integer> e:maps.entrySet()         ) {
//            if (e.getValue()==len){
//                list.add(e.getKey()+"");
//            }
//        }
        return list;
    }

    /**
     * 找出字符串b中跟arr相同的部分，并且返回重复出现的数组
     * @param arr
     * @param b
     * @return
     */
    private char[] removeLeft(char[] arr,String b){
        int[] m=new int[arr.length];
        int[] m2=new int[b.length()];
        int count=0;
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < b.length(); j++) {
                if (arr[i]==b.charAt(j)&&m[i]==0&&m2[j]==0){
                    m[i]=1;
                    m2[j]=1;
                    count++;
                }
            }
        }
        char[] res=new char[count];
        count=0;
        for (int i = 0; i < m.length; i++) {
            if (m[i]==1){
                res[count++]=arr[i];
            }

        }
        return res;
    }


}
