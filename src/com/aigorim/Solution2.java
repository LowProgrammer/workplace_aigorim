package com.aigorim;

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
        s.countBits(16);
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

    public void getNum(int[] arr,int n,int x){
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
}
