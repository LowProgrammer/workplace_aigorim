#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <string>

#include "aigorithm.cpp"
#include "tree.cpp"
using namespace std;

void quick_sort(int arr[], int low, int heigh);
void print_arr(int a[], int size_arr);
void print_arr(int *a, int x,int y);
int partition(int arr[], int low, int heigh);
string removePar(string s, int x);
/**
 * leecode 771
**/
int numJewelsInStones(string J, string S)
{
    int num = 0;
    int jell[60] = {0};
    int len1 = J.length();
    int len2 = S.length();
    if (!len1 || !len2)
        return 0;
    for (int i = 0; i < len1; i++)
    {
        if (jell[(int)J[i] - 65] == 0)
            jell[(int)J[i] - 65] = 1;
    }

    for (int i = 0; i < len2; i++)
    {
        if (jell[((int)S[i]) - 65] == 1)
            num++;
    }
    return num;
}
/**
 * leecode 709
**/
string toLowerCase(string str)
{
    int len = str.length();
    string result = "";
    for (int i = 0; i < len; i++)
    {
        if ((int)str[i] <= 90 && (int)str[i] >= 65)
        {
            //result+=(char)((int)str[i]+32);
            str[i] = (char)((int)str[i] + 32);
        }
        // else
        // {
        //     result+=str[i];
        // }

        /* code */
    }
    return str;
}
/**
 * leecode 804
 * 
 * */
int uniqueMorseRepresentations(vector<string> &words)
{
    string ch[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};
    vector<string> result;
    set<string> result_set;
    int len = words.size();
    cout << len << (int)'a' << "123" << endl;
    int num = 0, index1 = 97;

    for (int i = 0; i < len; i++)
    {
        string str = "";
        string demoS = words[i];
        for (int j = 0; j < demoS.length(); j++)
        {
            str += ch[(int)(demoS[j]) - 97];
        }
        result.push_back(str);
        result_set.insert(str);
        //cout<<num++<<str<<endl;
    }
    sort(result.begin(), result.end());
    result.erase(unique(result.begin(), result.end()), result.end());
    for (int k = 0; k < result.size(); k++)
    {
        cout << result[k] << endl;
    }
    num = result.size();
    return result_set.size();
}

/**
 * leecode 929 
 * 
 * */
int numUniqueEmails(vector<string> &emails)
{
    int len = emails.size();
    set<string> result;
    stack<char> str;
    for (int i = 0; i < len; i++)
    {
        string name = "";
        cout << emails[i] << endl;
        //bool is_name=false;
        int pos = emails[i].find('@');
        //cout<<"pos:"<<pos<<endl;
        int len2 = emails[i].length();

        for (int j = 0; j < pos; j++)
        {

            if (emails[i][j] == '.')
                continue;
            if (emails[i][j] == '+')
            {
                break;
            }
            name += emails[i][j];
            //str.push(emails[i][j]);
        }
        for (int j = pos; j < len2; j++)
        {
            //str.push(emails[i][j]);
            name += emails[i][j];
        }
        // while(!str.empty()){
        //     name=str.top()+name;
        //     str.pop();
        // }
        cout << name << endl;
        result.insert(name);
    }
    return result.size();
}

/**
 * leecode 961
 * 
 * */

int repeatedNTimes(vector<int> &A)
{
    int len = A.size();
    int num = 1, id;
    id = A[0];
    cout << "id-->" << id << endl;
    int ind = 0;
    for (int i = 1; i < len; i++)
    {

        if (A[i] == id)
        {
            num++;
        }
        else
        {
            num--;
            if (num < 0)
            {
                for (int j = 0; j < len; j++)
                {
                    if (A[j] == A[i])
                        ind++;
                }
                if (ind >= len / 2)
                {
                    id = A[i];
                    break;
                }
                else
                {
                    id = A[i + 1];
                    i++;
                    num = 1;
                }
            }
        }
        cout << "id-->" << id << endl;
    }
    cout << "id: " << id << endl;
    return id;
}

/**
 * leecode 977
 * 
 * */
vector<int> sortedSquares(vector<int> &A)
{
    vector<int> reuslt;
    int len = A.size();
    int num[10000];
    //cout<<len<<endl;
    for (int i = 0; i < len; i++)
    {
        num[i] = A[i] * A[i];
        //  cout<<num[i]<<endl;
    }
    quick_sort(num, 0, len - 1);
    for (int i = 0; i < len; i++)
    {
        reuslt.push_back(num[i]);
    }
    print_arr(num, len);
    return reuslt;
}
/**
 * leecode 905
 * 
 * */
vector<int> sortArrayByParity(vector<int> &A)
{
    // int arr[5000];
    // vector<int> result;
    int len = A.size();
    int index_l = 0, index_r = 0;
    // for(int i = 0; i < len; i++)
    // {
    //     if(A[i]%2==0){
    //         result.push_back(A[i]);
    //     }else
    //     {
    //         arr[index++]=A[i];
    //     }

    // }
    // index--;
    // while(index>=0){
    //     result.push_back(arr[index--]);
    // }
    // for(int i = 0; i < result.size(); i++)
    // {
    //     cout<<result[i]<<endl;
    // }
    /**
         * 第二种
         **/
    vector<int> re(len);
    for (int i = 0; i < len; i++)
    {
        if (A[i] % 2 == 0)
        {
            re[index_l++] = A[i];
        }
        else
        {
            re[len - 1 - (index_r++)] = A[i];
        }
    }
    for (int i = 0; i < re.size(); i++)
    {
        cout << re[i] << endl;
    }
    return re;
}
/**
 *leecode  832
 * 
 **/
vector<vector<int> > flipAndInvertImage(vector<vector<int> > &A)
{
    //vector<vector<int>> result;
    int tmp;
    int len = A.size(), len_in = (tmp = A[0].size()) % 2 ? (tmp + 1) / 2 : tmp / 2;
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len_in; j++)
        {
            int te = A[i][j];
            A[i][j] = !A[i][tmp - j - 1];
            A[i][tmp - j - 1] = !te;
        }
    }

    return A;
}

/**
 *  leecode 657 
 * 
 **/
bool judgeCircle(string moves)
{
    int pos_x = 0, pos_y = 0; //U D L R
    int len = moves.length();
    for (int i = 0; i < len; i++)
    {
        if (moves[i] == 'U')
            pos_y++;
        if (moves[i] == 'D')
            pos_y--;
        if (moves[i] == 'L')
            pos_x--;
        if (moves[i] == 'R')
            pos_x++;
    }
    return (pos_x == 0 && pos_y == 0) ? true : false;
}
/**
 * leecode 1021
 * 这个题可以可以改成递归求字符串
 * */
string removeOuterParentheses(string S)
{
    //if(S.compare("()"))return "()";
    //stack<char> str;
    int len = S.length();
    string result;
    int index = 0, str_l = 0, str_r;
    for (int i = 0; i < len; i++)
    {
        if (S[i] == '(')
            index++;
        if (S[i] == ')')
            index--;
        if (index == 0)
        {
            int tmp = str_l;
            str_l = i;
            int len_son = i - tmp;
            //cout << result << " ->" << tmp << " len =" << len_son << endl;
            
            if (tmp == 0)
            {
                //cout<<S.substr(tmp, len_son + 1)<<endl;
                result += removePar(S.substr(tmp, len_son + 1), len_son + 1);
            }    
            else
            {
                //cout<<S.substr(tmp+1, len_son )<<endl;
                result += removePar(S.substr(tmp+1, len_son), len_son);
            }
        }
    }
    //cout<<result<<endl;
    return result;
}
string removePar(string S, int size)
{
    if (S == "()")
        return "";
    else
    {
        return S.substr(1, size - 2);
    }
}
/**
 * leecode 807 
 * 
 * */
int maxIncreaseKeepingSkyline(vector<vector<int> >& grid) {
        int len=grid.size();
        int topToBottom[len],leftToRight[len];
        int result=0;
        for(int i = 0; i < len; i++)
        {
            int tmp_1=0,tmp_2=0;
            for(int j = 0; j < len; j++)
            {
                if(grid[i][j]>tmp_1)tmp_1=grid[i][j];
                if(grid[j][i]>tmp_2)tmp_2=grid[j][i];
            }
            topToBottom[i]=tmp_2;
            leftToRight[i]=tmp_1;
        }

        //print_arr(topToBottom,4);print_arr(leftToRight,4);
        for(int i = 0; i < len; i++)
        {
            for(int j = 0; j < len; j++)
            {   //
                if(leftToRight[i]<topToBottom[j])
                    result+=(leftToRight[i]<topToBottom[j])?(leftToRight[i]-grid[i][j]):(topToBottom[j]-grid[i][j]);
                else
                    result+=topToBottom[j]-grid[i][j];
                // if(grid[i][j]<leftToRight[i]&&grid[i][j]<topToBottom[i])
                //     result+=(leftToRight[i]<topToBottom[j])?(leftToRight[i]-grid[i][j]):(topToBottom[j]-grid[i][j]);
                //cout<<result<<"  ";
            }            
        }
        return result;

}
/**
 * leecode 938 二叉搜索树的遍历
 * 包括 中序遍历方法
 * */
/**
 *中序遍历树 把结果放在vector中
 * 
 * */
void getMidSort(Tree root,int l,int r,vector<int> &result_tree){
     if(root){
         getMidSort(root->left,l,r,result_tree);
        //  s+=my_to_string(root->val);
        //  cout<<i++<<" --  "<<s<<endl;
        if(root->val>=l&&root->val<=r)
            result_tree.push_back(root->val);
        getMidSort(root->right,l,r,result_tree);
     }
 }
 /**
  * 中序遍历树组返回结果放在树组中
  * */
 int ind_node_num=0;
 void getMidSortArr(Tree root,int* result_tree){
     if(root){
         getMidSortArr(root->left,result_tree);
        //  s+=my_to_string(root->val);
        //  cout<<i++<<" --  "<<s<<endl;
        //result_tree.push_back(root->val);
        result_tree[ind_node_num++]=root->val;
        getMidSortArr(root->right,result_tree);
     }
 }
int rangeSumBST(TreeNode* root, int L, int R) {
        vector<int> result;//int num[10000];
        getMidSort(root,L,R,result);//getMidSortArr(root,num);
        //print_arr(num,ind_node_num);
        int len=result.size();
        int total_num=0;        

        for(int i = 0; i < len; i++)
        {
            total_num+=result[i];
            //cout<<result[i]<<endl;
            /* code */
        }
        //cout<<total_num<<endl;
        return total_num; 

}
/**
 * leecode 535 Encode and Decode TinyURL
 *  方法没有完善好
 * */

// Encodes a URL to a shortened URL.
string encode(string longUrl) {
    vector<string> result;
   
    mySplitString(longUrl, result, "//");
    // for(vector<string>::iterator iter1=result.begin()+1;iter1!=result.end(); iter1++)
    // {
    //     url_web_com+=*(iter1);
    // }
    // cout<<url_web_com<<" 1 ";
    string shortUrl=result[0]+"//",url_web_com;
    url_web_com=result[1];
    vector<string> url_web;
    mySplitString(url_web_com, url_web, "/");
    
    for (vector<string>::iterator iter=url_web.begin();iter!=url_web.end(); iter++)
    {
        if(*(iter)=="leetcode.com"&&*(iter+1)=="problems")url_web.erase(iter);
        if(*iter=="problems")*iter="pro";
        //cout<<*iter<<" "; 
    }
    for(int i = 0; i < url_web.size(); i++)
    {
        shortUrl=shortUrl+url_web[i];
        if(i!=url_web.size()-1)
            shortUrl+="/";
    }
    
    //for_each(url_web.begin(),url_web.end(),printer<string>);
    return shortUrl;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl) {
    vector<string> result_url;
    mySplitString(shortUrl,result_url,"//");
     string reLongUrl=result_url[0]+"//";
    string long_url_web=result_url[1];
    vector<string> url_web;
    mySplitString(long_url_web,url_web,"/");
    //cout<<"sdassdsadas"<<endl;
    //for_each(url_web.begin(),url_web.end(),printer<string>);
    int len=url_web.size();
    for(int i=0;i<len;i++)
    {
        //cout<<" -->>"<<url_web[i]<<endl;
        if(url_web[i]=="pro"){
            url_web[i]="problems";
            url_web.insert(url_web.begin()+i,"leetcode.com");
        }
    }

    for(int i = 0; i < url_web.size(); i++)
    {
        reLongUrl+=url_web[i];
        if(i!=url_web.size()-1)
            reLongUrl+="/";
        /* code */
    }
    
    return reLongUrl;
}
/**
 * leetcode 654 Maximum Binary Tree
 * 选取数组中最大的数作为节点建立树
 * */

TreeNode* getTree(int* arr,int l,int r){
    if (l<=r)
    {
        int pos = getMaxNumOfArr(arr, l, r);
        TreeNode* root= new TreeNode(*(arr + pos));
        //cout<<"l: "<<l<<" mid: "<<pos<<" r: "<<r;
        //cout << " num: " << *(arr + pos) << " "<<endl;
        root->left = getTree(arr, l, pos-1);
        root->right = getTree(arr,pos+1, r);
        return root;
    }
    return NULL;
}

TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        //vector<int>::iterator iter;
        int len=nums.size();
        int arr[len];
        for(int i = 0; i < len; i++)
        {
            arr[i]=nums[i];
        }
        TreeNode* root=getTree(arr,0,len-1);
        getMidSort(root);
        return root;
}
/**
 * leetcode 701 Insert into a Binary Search Tree
 * 
 * */

int main()
{
    // char test[]="1234";
    // cout<<test[1]<<strlen(test);
    // cout<<"qwe"<<(int)'A'<<"   "<<(int)'z'<<(int)'a'<<(int)'Z'<<endl;
    // cout<<numJewelsInStones("aAZz","aaaasadhkjhffahdjakaaaZZZfslkahZfGSHGDJGBMCKHUIZZZZZZFFzA");
    // cout<<endl;
    // cout<<toLowerCase("HEshdkhHJSHDBCOIWYEHCKAJSDK");

    // string ss[]={"gin", "zen", "gig", "msg"};
    // vector<string> s(ss,ss+4);
    // cout<<uniqueMorseRepresentations(s);

    //string ss[]={"test.email+alex@leetcode.com","test.e.mail+bob.cathy@leetcode.com","testemail+david@lee.tcode.com"};
    // string ss[] = {"test.email+alex@leetcode.com", "test.email@leetcode.com"};
    // vector<string> emails(ss, ss + 2);
    // cout << numUniqueEmails(emails);

    // int nu[] = {1,6,6,9};
    // vector<int> num(nu, nu +  4);
    // cout << repeatedNTimes(num);

    // int nu[] = {-8,-6,-4,-2,0,1,3,5,7};
    // vector<int> num(nu, nu +  9);
    // sortedSquares(num);

    // int nu[] = {3,1,2,4};
    // vector<int> num(nu, nu +  4);

    // vector<int> s=sortArrayByParity(num);
    // int tmp,s=(tmp=4)%2?(tmp+1)/2:tmp/2;
    // cout<<(!0)<<"   "<<s;

    // cout<<judgeCircle("LLLLRRUDDRR");
    
    // cout << removeOuterParentheses("()()") << endl;
    // string s = "asdfg";
    // cout<<myStrSub(s,1,3);
    // cout << s.substr(1, 3);

    // int arr[4][4]={{3, 0, 8, 4}, {2, 4, 5, 7}, {9, 2, 6, 3}, {0, 3, 1, 0}};
    // vector <vector<int> > ss(4,vector<int>(0));
    // for(int i = 0; i < 4; i++)
    // {
    //     for(int j = 0; j < 4; j++)
    //     {
    //         ss[i].push_back(arr[i][j]);
    //     }
    // }
    // print_arr(*arr,4,4);
    // cout<<maxIncreaseKeepingSkyline(ss)<<endl;
    
    // TreeNode *root=new TreeNode(10);
    // root->left=new TreeNode(5);
    // root->right=new TreeNode(15);
    // root->left->left=new TreeNode(3);
    // root->left->right=new TreeNode(7);
    // // root->right->left=new TreeNode(5);
    // root->right->right=new TreeNode(18);

    // //getMidSort(root);
    // cout<<rangeSumBST(root,7,15);

    // string longurl="https://leetcode.com/problems/design-tinyurl";
    // cout<<decode(encode(longurl));
    // cout<<"over"<<endl;

    //int nu[] = {3,2,1,6,0,5};
    //print_arr(nu,6);
    cout<<123445<<endl;
    //vector<int> num(nu, nu +  6);
    //constructMaximumBinaryTree(num);
    //cout<<getMaxNumOfArr(nu,0,5);
    return 0;
}
