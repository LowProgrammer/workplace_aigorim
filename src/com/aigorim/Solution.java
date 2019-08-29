package com.aigorim;

import java.util.*;

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
//        root.left=new TreeNode(7);
//        root.right=new TreeNode(0);
//        root.left.left=new TreeNode(7);
//        root.left.right=new TreeNode(-8);
//        root.left.right.left=new TreeNode(-9);
        //TreeNode root=new TreeNode(1);

//        int a=solution.maxLevelSum(root);
//        System.out.println(a);

        solution.heightChecker(new int[]{1,1,4,2,1,3});
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

}
