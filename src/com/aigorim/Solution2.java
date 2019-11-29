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
    private static String[] weekName={"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    public static void main(String[] args) {
        System.out.println(232356);
        Solution2 s=new Solution2();
        String str="KHH\n" +
                "TYSHXYDM\n" +
                "HYFL\n" +
                "YGRS\n" +
                "SFSSQY\n" +
                "WWMC\n" +
                "ZCLB\n" +
                "ZCZB\n" +
                "CLSJ\n" +
                "ZCRQ\n" +
                "ZCDQRQ\n" +
                "DJBH\n" +
                "SSRQ\n" +
                "SSD\n" +
                "SSSC\n" +
                "SSMC\n" +
                "GPDM\n" +
                "FRMC\n" +
                "SKRMC\n" +
                "\n" +
                "FZJG\n" +
                "FZJGSZD\n" +
                "ZJYXKSRQ\n" +
                "ZJYXJZRQ\n" +
                "\n" +
                "GDMC\n" +
                "GDLX\n" +
                "GDCGBL\n" +
                "\n" +
                "BBNF\n" +
                "ZCZJ\n" +
                "FZHJ\n" +
                "SYZQYHJ\n" +
                "FZQYHJ\n" +
                "ZYYWSR\n" +
                "YYLR\n" +
                "LRZE\n" +
                "JLR\n" +
                "YYSR\n" +
                "JYHDXJLRXJ\n" +
                "JYHDXJLCXJ\n" +
                "JYHDXJLLJE\n" +
                "TZHDXJLRXJ\n" +
                "TZHDXJLCXJ\n" +
                "TZHDXJLLJE\n" +
                "CZHDXJLRXJ\n" +
                "CZHDXJLCXJ\n" +
                "CZHDXJLLJE\n" +
                "XJDJWJZJE\n" +
                "QMXJDJWYE\n" +
                "\n" +
                "GGMC\n" +
                "GGLX\n" +
                "\n" +
                "LXXXLX\n" +
                "SF\n" +
                "CS\n" +
                "QX\n" +
                "XXDZ\n" +
                "DH1\n" +
                "YZBM\n";
        String code="企业客户号\n" +
                "统一社会信用代码\n" +
                "行业分类\n" +
                "员工人数\n" +
                "是否上市企业\n" +
                "客户英文名称\n" +
                "注册类别\n" +
                "注册资本\n" +
                "成立日期\n" +
                "登记日期\n" +
                "登记到期日期\n" +
                "登记编号\n" +
                "上市时间\n" +
                "上市地\n" +
                "上市市场\n" +
                "上市名称\n" +
                "股票代码\n" +
                "法定代表人\n" +
                "实际控制人名称\n" +
                "\n" +
                "发证机关\n" +
                "证件地址\n" +
                "证件有效开始日期\n" +
                "证件有效截止日期\n" +
                "\n" +
                "股东名称\n" +
                "股东类型\n" +
                "股东持股比例\n" +
                "\n" +
                "报表年份\n" +
                "资产总计\n" +
                "负债合计\n" +
                "所有者权益合计\n" +
                "负债和所有者权益合计\n" +
                "主营业务收入\n" +
                "营业利润\n" +
                "利润总额\n" +
                "净利润\n" +
                "营业收入\n" +
                "经营活动现金流入小计\n" +
                "经营活动现金流出小计\n" +
                "经营活动产生的现金流量净额\n" +
                "投资活动现金流入小计\n" +
                "投资活动现金流出小计\n" +
                "投资活动产生的现金流量净额\n" +
                "筹资活动现金流入小计\n" +
                "筹资活动现金流出小计\n" +
                "筹资活动产生的现金流量净额\n" +
                "现金及现金等价物净增加额\n" +
                "期末现金及现金等价物余额\n" +
                "\n" +
                "高管名称\n" +
                "高管类型\n" +
                "\n" +
                "联系信息类型\n" +
                "省份\n" +
                "城市\n" +
                "区县\n" +
                "详细地址\n" +
                "电话1\n" +
                "邮编\n";
        String[] strArr=str.split("\\n");
        String[] codeArr=code.split("\\n");
        for (int i = 0; i <strArr.length ; i++) {
            System.out.println("\""+strArr[i]+"\":\""+codeArr[i]+"\",");
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
