package com.aigorim;

import com.aigorim.tree.Node;
import com.aigorim.tree.TreeNode;
import com.utils.Aigorim;

import java.util.*;
import java.util.concurrent.Semaphore;
import java.util.function.IntConsumer;

/**
 * @author feifei
 * @Classname Solution
 * @Description TODO
 * @Date 2019/8/22 15:39
 * @Created by 陈群飞
 */
public class Solution {

    public static void main(String[] args) {
//        int arr[]=getArr(2);
//        for (int i = 0; i < arr.length; i++) {
//            System.out.println(arr[i]);
//        }
//        System.out.println(getMostMaxNum(2));
//        List<Integer> li;
//        for (int i = 1; i < 100; i++) {
//
//            li=new Solution().pathInZigZagTree(i);
//            for (Integer l:li ) {
//                System.out.println(l);
//            }
//        }

//        List<Integer> list=new Solution().pathInZigZagTree(26);
//        for (Integer l:list ) {
//            System.out.println(l);
//        }


//        String []arr=new String[]{"cat","bt","hat","tree"};
//        String chars="atach";
//
        Solution solution=new Solution();
        //System.out.println(solution.countCharacters(arr,chars));

        //1162
//        TreeNode root=new TreeNode(1);
//        root.left=new TreeNode(2);
//        root.right=new TreeNode(0);
//        root.left.left=new TreeNode(3);
//        root.left.right=new TreeNode(0);
//        root.left.right.left=new TreeNode(0);
        //TreeNode root=new TreeNode(1);

//        int a=solution.maxLevelSum(root);
//        System.out.println(a);

        //solution.heightChecker(new int[]{1,1,4,2,1,3});

        //solution.distributeCoins(root);

//        for (int i = 0; i < 20; i++) {
//
//            System.out.println(solution.fib(i));
//        }
//        char[][] battle=new char[4][4];
//        for (int i = 0; i < 4; i++) {
//            for (int j = 0; j < 4; j++) {
//                battle[i][j]=' ';
//                if (i==0&&j==0){
//                    battle[i][j]='X';
//                }
//                if (j==3){
//                    battle[i][j]='X';
//                }
//            }
//        }
//        solution.countBattleships(battle);


//        String[] arr=new String[]{"900 google.mail.com","50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
//        solution.subdomainVisits(arr);

//        String seq="()(())()";
//        int[] re=solution.maxDepthAfterSplit(seq);
//        for (int a:re) {
//            System.out.println(a);
//        }

        int[] test=new int[]{4,2,1,3};
        solution.minimumAbsDifference(test);
    }
    /**
     * @author feifei
     * @param
     * @param num
     * @Description TODO 生成规律数组
     * @Date 2019/8/22 16:26
     * @Created by 陈群飞
     * @return
     */
    public static int[] getArr(int num){
        num=getMostMaxNum(num);
        int arr[]=new int[num];
        int count=0,
            level=1,            //本层层数
            levelLastCount=0,//上一层数目
            levelNowCount=1;//本层节点数目
        int index=1;

        while(count<num){
            if(level%2!=0) {
                if (index <= levelNowCount) {
                    arr[count] = getTotalNum(level) + index;
                    index++;
                    count++;
                } else {
                    level++;
                    index=1;
                    levelNowCount*=2;
                }
            }else{
                if (index <= levelNowCount){
                    arr[count]=getTotalNum(level)+levelNowCount+1-index;
                    index++;
                    count++;
                }else {
                    level++;
                    index=1;
                    levelNowCount*=2;
                }
            }
            //count++;
        }

        return arr;
    }


    /**
     * @author feifei
     * @param
     * @param level
     * @Description TODO 计算本层以上总数
     * @Date 2019/8/22 16:19
     * @Created by 陈群飞
     * @return
     */
    public static int getTotalNum(int level){
        if (level==0||level==1){
            return 0;
        }else {
            int num=0,count=1;
            for (int i = 1; i < level; i++,count*=2) {
                num+=count;
            }
            return num;
        }
    }

    /**
     * @author feifei
     * @param
     * @param num
     * @Description TODO 找到最接近整除的数
     * @Date 2019/8/22 16:39
     * @Created by 陈群飞
     * @return
     */
    public static int getMostMaxNum(int num){
        int count=1;
        num++;
        while(num!=1){
            count++;
            num/=2;
        }
        return getTotalNum(++count);
    }
    /**
     * @author feifei
     * @param
     * @param label
     * @Description 解决办法 leetcode 1104
     * @Date 2019/8/22 16:28
     * @Created by 陈群飞
     * @return
     */
    public List<Integer> pathInZigZagTree(int label) {

        List<Integer> li=new ArrayList<>();

        if(label==1){
            li.add(label);
            return li;
        }
        int arr[]=getArr(label);
        int i=0;

        int total=getMostMaxNum(label);
        System.out.println("下标最大数"+total);

        while(arr[total-1]!=label){
            total--;
        }
        System.out.println("起始位置："+total);

        while(total!=0){
            li.add(arr[total-1]);
            if(total%2!=0){
                    total /= 2;
            }else{
                total=(total+1)/2;
            }
        }
        li.sort(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1<o2?-1:1;
            }
        });
        return li;
    }

    /**
     * @author feifei
     * @param
     * @param words,chars
     * @Description TODO leetcode 1160 Find Words That Can Be Formed by Characters
     * @Date 2019/8/23 11:22
     * @Created by 陈群飞
     * @return
     */
    public int countCharacters(String[] words, String chars) {
        int count=0,wNum=words.length,chLength=chars.length();
        int msk[]=new int[chars.length()];
        for (int i = 0; i < chLength; i++) {
            msk[i]=0;
        }

        for (String word:words) {
            if(isConclud(word,chars,msk)){
                count+=word.length();
            }
            msk=getMask(chLength);
        }
        return count;
    }

    /**
     * @author feifei
     * @param
     * @param word,chars,mask
     * @Description TODO 判断字符串在模板中是否包含在其中
     * @Date 2019/8/23 11:32
     * @Created by 陈群飞
     * @return
     */
    public boolean isConclud(String word,String chars,int[] mask){
        int strLen=word.length(),arrLen=chars.length();

        char []wArr=word.toCharArray();
        char []cArr=chars.toCharArray();
        int count=0;
        //System.out.println(word);
        for (int i = 0; i < strLen; i++) {
            for (int j = 0; j < arrLen; j++) {
                if(wArr[i]==cArr[j]&&mask[j]==0){
                    //System.out.println(w_arr[i]+"========="+c_arr[j]);
                    mask[j]=1;
                    count++;
                    break;
                }
            }
        }
        //System.out.println(count+"-----------"+str_len);
        if(count==strLen){
            //System.out.println(word);
            return true;
        }
        return false;
    }

    /**
     * @author feifei
     * @param
     * @param len
     * @Description TODO 生成标志字符数组
     * @Date 2019/8/23 11:55
     * @Created by 陈群飞
     * @return
     */
    public int[] getMask(int len){
        int msk[]=new int[len];
        for (int i = 0; i < len; i++) {
            msk[i]=0;
        }
        return msk;
    }



    /**
     * @author feifei
     * @param 
     * @param root
     * @Description TODO leetcode 1161  Maximum Level Sum of a Binary Tree
     * @Date 2019/8/26 11:33
     * @Created by 陈群飞
     * @return 
     */
    public int maxLevelSum(TreeNode root) {
        ArrayDeque<TreeNode> li=new ArrayDeque<>();

        if (root==null){
            return 0;
        }
        int num=0;//每层数值
        int result=0,reslutLe=0;//最终每层总数 最终所在层数
        int count=0,countLeNnum=1,countLe=0;//计数器 每层数目  所在层数
        int mask=1;
        li.add(root);
        while(!li.isEmpty()){
            TreeNode node=li.pop();
            if(count<mask)
            {
                num+=node.val;
                System.out.print(node.val);
                count++;
            }

            if(node.left!=null){
                li.add(node.left);
                //System.out.println("====="+(++count_le_num));
            }
            if (node.right!=null){
                li.add(node.right);
                //System.out.println("====="+(++count_le_num));
            }

            if (count==mask){
                count=0;
                mask=li.size();
                //System.out.print("  "+node.val);
                System.out.println("===");
                countLe++;

                if (num>result){
                    result=num;
                    reslutLe=countLe;
                }
                num=0;
            }
        }
        return reslutLe;
    }


    /**
     * @author feifei
     * @param root
     * @param val
     * @Description TODO 二叉树搜索 700. Search in a Binary Search Tree
     * @Date 2019/8/28 16:36
     * @Created by 陈群飞
     * @return
     */
    public TreeNode searchBST(TreeNode root, int val) {
        if(root.val==val){
            return root;
        }
        if (val>root.val&&root.right==null){
            return null;
        }
        if (val<root.val&&root.left==null){
            return null;
        }
        if (root.val<val){
           return searchBST(root.right,val);
        }else{
            return searchBST(root.left,val);
        }
    }


    /**
     * @author feifei
     * @param
     * @param heights 1,1,4,2,1,3
     * @Description TODO leetcode 1051. Height Checker
     *  比较最后结果序列与开始序列作比较得到一定会修改的数据
     * @Date 2019/8/28 16:43
     * @Created by 陈群飞
     * @return height
     */
    public int heightChecker(int[] heights) {
        int[] he=new int[heights.length];
        for (int i = 0; i < heights.length; i++) {
            he[i]=heights[i];
        }
        for (int i = 0; i < heights.length; i++) {
            for (int j = i; j < heights.length; j++) {
                if(heights[i]>heights[j]){
                    int te=heights[i];
                    heights[i]=heights[j];
                    heights[j]=te;
                }
            }
        }
        int count=0;
        for (int i = 0; i < heights.length; i++) {
            if (he[i]!=heights[i]){
                count++;
            }
            System.out.println(he[i]+"======"+heights[i]);
        }
        System.out.println(count);
        return count;
    }

    /**
     * @author feifei
     * @param
     * @param root
     * @Description TODO 589. N-ary Tree Preorder Traversal
     * 非二叉树的先序遍历
     * @Date 2019/8/29 13:02
     * @Created by 陈群飞
     * @return
     */
    List<Integer> re=new ArrayList<>();
    public List<Integer> preorder(Node root) {
        if (root==null){
            return re;
        }else if (root.children==null){
            re.add(root.val);
        }else {

            for (Node no : root.children) {
                preorder(no);
            }
            re.add(root.val);
        }
        return re;
    }

    /**
     * @author feifei
     * @param
     * @param root
     * @Description TODO 590. N-ary Tree Postorder Traversal
     * N叉树的后序遍历
     * @Date 2019/8/30 13:30
     * @Created by 陈群飞
     * @return
     */
    List<Integer> postRe=new ArrayList<>();
    public List<Integer> postorder(Node root) {
        if (root==null){
            return postRe;
        }else if (root.children==null){
            postRe.add(root.val);
        }else {

            for (Node no : root.children) {
                postorder(no);
            }
            postRe.add(root.val);
        }
        return postRe;
    }

    /**
     * @author feifei
     * @param
     * @param root
     * @Description TODO leetcode 979 Distribute Coins in Binary Tree
     *对每一个root进行考虑，如果以他为根的子树的硬币个数大于节点个数，也就是说他多出来了x枚硬币，那么这x枚硬币一定是要走向他的父亲的，
     * 因为儿子不在需要了。此时就会在这条边产生x的贡献；反之就是需求硬币，是要从他父亲向他产生x的贡献。
     * 最后返回当前节点处理完之后剩余的硬币个数(正数即为多余，负数就是需求)。
     * @Date 2019/9/2 9:37
     * @Created by 陈群飞
     * @return
     */
    public int distributeCoins(TreeNode root) {
        res=0;
        dfs(root);
        System.out.println(res);
        return res;
    }

    int res=0;
    private int dfs(TreeNode root){
        if(root==null){
            return 0;
        }
        int L=dfs(root.left);
        int R=dfs(root.right);
        res+=Math.abs(L)+Math.abs(R);
        return root.val+L+R-1;
    }

    /**
     * @author feifei
     * @param
     * @param root
     * @Description TODO 根据根节点计算一共有多少个节点
     * @Date 2019/9/3 15:38
     * @Created by 陈群飞
     * @return Integer
     */
    public int countNum(TreeNode root){
        if(root!=null){
            return 1+countNum(root.left)+countNum(root.right);
        }else{
            return 0;
        }
    }

    /**
     * @author feifei
     * @param
     * @param A
     * @Description TODO leetcode 922. Sort Array By Parity II
     *
     * @Date 2019/9/4 9:40
     * @Created by 陈群飞
     * @return
     */
    public int[] sortArrayByParityII(int[] A) {
        int oddCount=1,evenCount=0;
        int len=A.length;
        int[] re=new int[len];
        for (int i = 0; i < len; i++) {
            if (A[i]%2==0){
                re[evenCount]=A[i];
                evenCount+=2;
            }else {
                re[oddCount]=A[i];
                oddCount+=2;
            }
        }
        return re;
    }

    /**
     * @author feifei
     * @param 
     * @param root
     * @Description TODO leetcode 965. Univalued Binary Tree
     * 判断一个二叉树是否val值是否一致，
     * @Date 2019/9/4 10:00
     * @Created by 陈群飞
     * @return 
     */
    public boolean isUnivalTree(TreeNode root) {
        if (root==null){
            return true;
        }
        if (root.right==null&&root.left!=null){
            return root.val==root.left.val&&isUnivalTree(root.left)&&isUnivalTree(root.right);
        }
        if (root.left==null&&root.right!=null){
            return  root.val==root.right.val&&isUnivalTree(root.left)&&isUnivalTree(root.right);
        }
        if (root.left!=null&&root.right!=null) {
            return root.val == root.left.val && root.val == root.right.val && isUnivalTree(root.left) && isUnivalTree(root.right);
        }
        return true;
    }





    /**
     * @author feifei
     * @param N
     * @Description TODO 509. Fibonacci Number
     * 斐波那契数列，循环实现，代替递归减小资源的消耗
     * @Date 2019/9/5 10:01
     */
    public int fib(int N) {
        int left=0,right=0,result=0;

           for (int i = 0; i <= N; i++) {
               if (i==0){
                   left=0;
                   continue;
               }
               if (i==1){
                   right=1;
                   result=left+right;
                   continue;
               }
                result=left+right;
                left=right;
                right=result;
           }
        return result;
    }

    /**
     * @author feifei
     * @param board
     * @Description TODO 419. Battleships in a Board
     * Could you do it in one-pass, using only O(1) extra memory and without modifying the value of the board?
     * X 。。X
     * 。。。X
     * 。。。X
     * 。。。X
     * 计算出船的数量，循环遍历数组，判断每个点可能出现的可能，是‘。’ 或者‘X’
     * @Date 2019/9/5 10:03
     */
    public int countBattleships(char[][] board) {
        int countNum=0;
        for (int i = 0; i <board.length; i++) {
            for (int j = 0; j < board[0].length; j++) {
                if (board[i][j]=='X') {
                    if (board[i][j] == 'X' && i == 0 && j == 0) {
                        countNum++;
                    }
                    if (i==0){
                        if (j>0&&board[i][j-1]=='.'){
                            countNum++;
                        }
                    }else {
                        if(j==0) {
                            if (board[i - 1][j] == '.') {
                                countNum++;
                            }
                        }else{
                            if (board[i - 1][j] == '.'&&board[i][j-1]=='.') {
                                countNum++;
                            }
                        }
                    }
                }
            }
        }
        System.out.println(countNum);

        return countNum;
    }

    /**
     * @author feifei
     * @param cpdomains
     * @Description TODO leetcode 811. Subdomain Visit Count
     * 计算网址的访问量
     * @Date 2019/9/9 15:58
     * ["9001 leetcode.com","9001 discuss.leetcode.com","9001 com"]
     */
    public List<String> subdomainVisits(String[] cpdomains) {
        int len=cpdomains.length;
        Set<String> countSet=new HashSet<>();
        Map<String,Integer> count=new HashMap<>();
        List<String> res=new ArrayList<>();
        for (int i = 0; i < len; i++) {
            String[] strings=cpdomains[i].split(" ");
            Integer cou=Integer.parseInt(strings[0]);
            List<String> getList=getDomains(strings[1]);

            for (int j = 0; j < getList.size(); j++) {
                if (countSet.contains(getList.get(j))){
                    Integer a=count.get(getList.get(j));
                    //System.out.println("sdasdfasf"+a);

                    count.put(getList.get(j),Integer.sum(a,cou));
                }else{
                    count.put(getList.get(j),cou);
                    countSet.add(getList.get(j));
                }
            }

        }
        for ( Map.Entry<String, Integer> se:count.entrySet()) {
            String st=se.getValue()+" "+se.getKey();
            //System.out.println(st);
            res.add(st);
        }

        return res;
    }
    /**
     * @author feifei
     * @param website
     * @Description TODO
     * 根据"."分割字符串，生成子路径，根路径
     * @Date 2019/9/9 16:58
     */
    public List<String> getDomains(String website){
        //System.out.println(website);
        String[] arr=website.split("\\.");
        List<String> result=new ArrayList<>();
        for (int i = 0; i < arr.length; i++) {
            String st="";
            for (int j = i; j <arr.length ; j++) {
                st=st+arr[j];
                if (j<arr.length-1){
                    st+=".";
                }
            }
            result.add(st);
        }
        return result;
    }

    /**
     * @author feifei
     * @param seq
     * @Description TODO 1111. Maximum Nesting Depth of Two Valid Parentheses Strings
     * @Date 2019/9/10 14:00
     * 奇数层为1 偶数层为0
     * Leetcode 1111:有效括号的嵌套深度
     */
    public int[] maxDepthAfterSplit(String seq) {
        int deep=0;
        int len=seq.length();
        int[] answer=new int[len];
        for(int i=0;i<len;i++){
            if(seq.charAt(i)=='('){
                deep++;
                answer[i]=deep%2;
            }else{
                answer[i]=deep%2;
                deep--;
            }
        }
        return answer;
    }
    /**
     * @author feifei
     * @param arr
     * @Description TODO 1200. Minimum Absolute Difference
     * 找出最小的间隔
     * @Date 2019/9/23 18:52
     */
    public List<List<Integer>> minimumAbsDifference(int[] arr) {
//        for (int i = 0; i < arr.length; i++) {
//            for (int j = 0; j < arr.length; j++) {
//                if (arr[i]<arr[j]){
//                    int tmp=arr[i];
//                    arr[i]=arr[j];
//                    arr[j]=tmp;
//                }
//            }
//        }
        int len=arr.length-1;
        Aigorim.quick_sort(arr,0,len);


        int min=arr[len]-arr[0];
        int[] re=new int[len];
        for(int i = 0; i < len; i++) {
            re[i]=arr[i+1]-arr[i];
            if (re[i]<min){
                min=re[i];
            }
        }
        List<List<Integer>> list=new ArrayList<>();
        for (int i = 0; i < len; i++) {
            if (re[i]==min){
                List<Integer> lis=new ArrayList<>();
                lis.add(arr[i]);
                lis.add(arr[i+1]);
                list.add(lis);
                System.out.println(arr[i]+"===="+arr[i+1]);
            }
        }
        return list;
    }
}
/**
 * @author feifei
 * @param
 * @Description TODO leetcode 1195 Fizz Buzz Multithreaded
 * @Date 2019/9/25 14:16
 */
class FizzBuzz {
    private int n;
    private int m;
    private Semaphore number;
    private Semaphore fizz;
    private Semaphore buzz;
    private Semaphore fizzBuzz;

    public FizzBuzz(int n) {
        this.n = n;
        m = 1;
        number = new Semaphore(1);
        fizz = new Semaphore(0);
        buzz = new Semaphore(0);
        fizzBuzz = new Semaphore(0);
    }

    public void fizz(Runnable printFizz) throws InterruptedException {
        while (m <= n) {
            fizz.acquire();
            if (m > n) break;
            printFizz.run();
            m++;
            number.release();
        }
    }

    public void buzz(Runnable printBuzz) throws InterruptedException {
        while (m <= n) {
            buzz.acquire();
            if (m > n) break;
            printBuzz.run();
            m++;
            number.release();
        }
    }

    public void fizzbuzz(Runnable printFizzBuzz) throws InterruptedException {
        while (m <= n) {
            fizzBuzz.acquire();
            if (m > n) break;
            printFizzBuzz.run();
            m++;
            number.release();
        }
    }

    public void number(IntConsumer printNumber) throws InterruptedException {
        while (m <= n) {
            number.acquire();
            if (m>n){
                break;
            }

            if (m % 15 == 0) {
                fizzBuzz.release();
            } else if (m % 3 == 0) {
                fizz.release();
            } else if (m % 5 == 0) {
                buzz.release();
            } else {
                printNumber.accept(m);
                m++;
                number.release();
            }
        }
        fizz.release();
        buzz.release();
        fizzBuzz.release();
    }
}