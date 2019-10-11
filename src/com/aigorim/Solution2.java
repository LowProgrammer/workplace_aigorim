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
        int[] arr=s.countBits(129);
        for (int i = 0; i < arr.length; i++) {
            System.out.print(arr[i]+"  ");
        }
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
     * @Description TODO  leetcode 999. Available Captures for Rook
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
}
