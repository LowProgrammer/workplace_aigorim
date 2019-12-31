package com.aigorim;

import com.aigorim.tree.TreeNode;
import com.utils.MapperUtils;

import java.util.*;

/**
 * @author feifei
 * @Classname Solution2
 * @Description TODO
 * @Date 2019/10/9 16:00
 * @Created by 陈群飞
 */
public class Solution2 {
    private static String[] weekName={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    public static void main(String[] args) throws Exception {
        Solution2 solution2=new Solution2();
        TreeNode root=new TreeNode(0);
        root.right=new TreeNode(1);
        root.left=new TreeNode(2);

        root.right.right=new TreeNode(3);
        root.left.right=new TreeNode(4);
//        root.left.right.right=new TreeNode(5);


        System.out.println(solution2.deepestLeavesSum(root));
    }

    int re=0;
    /**
     * 计算出树最大深度的叶子值之和
     * 法1：利用递归求出最大深度，在找出符合最大深度叶子
     * 法2：层次遍历计算出每层的之和，返回最后一个
     * @param root
     * @Description TODO leetcode 1302. Deepest Leaves Sum
     */
    public int deepestLeavesSum(TreeNode root) {
        //方法1
//        int maxDe=result(root);
//        int deep=0;
//        getMaxLeavesSum(root,deep,maxDe);
//        return re;

        //方法2
        return getMaxLeavesSum2(root);
    }
    public int getMaxLeavesSum2(TreeNode node){
        List<TreeNode> nodes=new ArrayList<>();
        int left=0,right=0;//左右指针
        int leveR=0;//每层节点的数量
        if (node!=null){
            nodes.add(node);
            leveR++;
            right=leveR;
        }
        int count=1;//深度
        int resultNum=0;//计算出每层之和
        leveR=0;
        int N=0;
        while(left<right){
            TreeNode root=nodes.get(left);
//            System.out.println(root.val);
            left++;
            resultNum+=root.val;

            if (root.left!=null){
                nodes.add(root.left);
                leveR++;
            }
            if (root.right!=null){
                nodes.add(root.right);
                leveR++;
            }

            if (left==right){
                count++;
                N=resultNum;
                resultNum=0;
                right+=leveR;
                leveR=0;
            }
        }
//        System.out.println(N);
        return N;
    }


    public void getMaxLeavesSum(TreeNode root,int deep,int max){
        if (root!=null) {
            deep++;
            if (deep==max){
                re+=root.val;
            }
            getMaxLeavesSum(root.left,deep,max);
            getMaxLeavesSum(root.right,deep,max);
        }
    }

    /**
     * 计算树的最大深度
     * @param root
     * @return
     */
    public int result(TreeNode root){
        if (root==null){
            return 0;
        }else{
            if (result(root.right)>result(root.left)) {
                return 1 + result(root.right);
            }else {
                return 1+result(root.left);
            }
        }
    }



    /**
     * 计算链表二进制对应的十进制数值
     * @param head 1290. Convert Binary Number in a Linked List to Integer
     * @return
     */
    public int getDecimalValue(ListNode head) {
        List<Integer> li=new ArrayList<>();
        while (head!=null){
            li.add(head.val);
            head=head.next;
        }
        int n=li.size();
        int result=0;
        for (int i:li) {
            int pos=1;
            for (int j = 0; j <n-1; j++) {
                pos*=2;
            }
            result+=i*pos;
            n--;
        }
        return result;
    }

    /**
     * 计算出整数中的每个数相乘减去相加的数值
     * @param n leetcode 1281. Subtract the Product and Sum of Digits of an Integer
     * @return
     */
    public int subtractProductAndSum(int n) {
        int mulNum=1,addNum=0;
        while(n>0){
            mulNum*=n%10;
            addNum+=n%10;
            n=n/10;
        }
        return mulNum-addNum;
    }

    /**
     *分组且每个分组的数量为分组的数字值n
     * @param groupSizes leetcode 1282. Group the People Given the Group Size They Belong To
     * @return
     */
    public  List<List<Integer>> groupThePeople(int[] groupSizes) {
        Map<Integer,List<Integer>> map=new HashMap<>();
        for (int i = 0; i < groupSizes.length; i++) {
            if (map.containsKey(groupSizes[i])){
                map.get(groupSizes[i]).add(i);
            }else{
                List<Integer> li=new ArrayList<>();
                li.add(i);
                map.put(groupSizes[i],li);
            }
        }
        List<List<Integer>> re=new ArrayList<>();
        for (Integer a: map.keySet()) {
            if(map.get(a).size()!=a){
                for (int i = 0; i <map.get(a).size()/a ; i++) {
                    re.add(map.get(a).subList(i*a,(i+1)*a));
                }
            }else{
                re.add(map.get(a));
            }
        }
        return re;
    }


    /**
     * 计算数组中有多少个偶数个数值INTEGER
     * @param nums leetcode 1295. Find Numbers with Even Number of Digits
     * @return
     */
    public int findNumbers(int[] nums) {
        int n=0;
        for (int i: nums) {
            int count=0;
            while (i>0){
                count++;
                i=i/10;
            }
            if (count%2==0){
                n++;
            }
        }
        return n;
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
        List<String> list=new ArrayList<String>();
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


    /**
     * @author feifei
     * @param s
     * @Description TODO leetcode 557. Reverse Words in a String III
     * @Date 2019/10/12 10:54
     * 反转字符串
     */
    public String reverseWords(String s) {
        String[] strings=s.split(" ");
        int len=strings.length;
        for (int i = 0; i < len; i++) {
            strings[i]=getReverse(strings[i]);
        }
        StringBuilder str=new StringBuilder();
        for (int i = 0; i <len ; i++) {
            str.append(strings[i]);
            if (i<len-1){
                str.append(" ");
            }
        }
        return str.toString();
    }
    private String getReverse(String str){
        char[] chars=str.toCharArray();
        int len=chars.length;
        for (int i = 0; i < len/2; i++) {
            char a=chars[i];
            chars[i]=chars[len-1-i];
            chars[len-1-i]=a;
        }
        return String.valueOf(chars);
    }

    /**
     * @author feifei
     * @param head
     * @Description TODO leetcode 876. Middle of the Linked List
     * @Date 2019/10/14 10:13
     * 找出链表的中间那个结点
     */
    public ListNode middleNode(ListNode head) {
        ListNode first,tail;
        first=head;
        tail=head;
        int count=0;
        while(first!=null){
            first=first.next;
            count++;
            if (count%2==0){
                tail=tail.next;
            }
        }
        return tail;
    }

    /**
     * @author feifei
     * @param N
     * @Description TODO leetcode 1025. Divisor Game
     * @Date 2019/10/14 10:18
     */
    public boolean divisorGame(int N) {
        return N%2==0?true:false;
    }

    /**
     * @author feifei
     * @param day
     * @param month
     * @param year
     * @Description TODO LeetCode 1185 Day of the Week
     * @Date 2019/10/17 11:04
     * 返回某一天是星期几
     */
    public String dayOfTheWeek(int day, int month, int year) {
        //String weeks[] = {"Thursday", "Friday", "Saturday","Sunday","Monday", "Tuesday", "Wednesday"};
        int i, days = 0, monthdays[] = {31,28,31,30,31,30,31,31,30,31,30,31};
        //1971-1-1 周五
        for(i = 1971; i < year; ++i)
        {
            if((i%4 == 0 && i%100 != 0) || i%400 == 0) {
                days += 366;
            }
            else{
                days += 365;
            }
        }
        for(i = 0; i < month-1; ++i)
        {
            days += monthdays[i];
        }
        days += day;
        if(((year%4 == 0 && year%100 != 0) || year%400 == 0) && month > 2) {
            ++days;
        }
        return weekName[days%7];
    }



}
