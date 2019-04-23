#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <string>
#include <map>

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
 * leetcode 701  Insert into a Binary Search Tree 
 * 
 * */
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root->val < val)
    {
        if (!root->right)
            root->right = new TreeNode(val);
        else
            insertIntoBST(root->right, val);
    }
    else
    {
        if (!root->left)
            root->left = new TreeNode(val);
        else
            insertIntoBST(root->left, val);
    }
    return root;
}
/**
 * leetcode 1028. Recover a Tree From Preorder Traversal
 * 采用递归的思想构建树  1-2--3--4-5--6--7
 * 
 * */
int getPos(int num[],int value,int begin,int end){
    int pos=-1;
    for(int i=begin;i<=end;i++){
        if(num[i]==value){
            pos=i;
            break;
        }
    }
    return pos;
}
TreeNode* createTree(TreeNode* root,int index_num[],int num[],int arr_l,int arr_r){
    while (arr_l <=arr_r)
    {   
        int i = index_num[arr_l];
        int pos = getPos(index_num, i, arr_l+1, arr_r);
        cout<<"  L ::"<<arr_l<<" R:: "<<arr_r<<"   ";cout<< " pos: "<<pos<<endl;
        if (pos > 0)
        {
            root->left=new TreeNode(num[arr_l]);
            root->right=new TreeNode(num[pos]);
            createTree(root->left, index_num, num, arr_l+1, pos - 1);
            createTree(root->right, index_num, num, pos+1, arr_r);
        }
        else
        {
            //root=new TreeNode(num[arr_l]);
            // cout<<1234<<" s" ;
            root->left=new TreeNode(num[arr_l]);
            createTree(root->left,index_num,num,arr_l+1,arr_r);
            // else root->right=new TreeNode(num[arr_l]);
        }
        return root;
    }
    return NULL;
}
TreeNode* recoverFromPreorder(string S) {
        //1-2--3--4-5--6--7
        vector<int> index_nu,num;
        TreeNode* root;
        if(S.find('-')==-1){
            root=new TreeNode(my_str2int(S));
            return root;
        }
        int pos_l=0,pos_r,fir_id=1,is_num=0,stage=0;//数字起始左 右 第一个数 是否是数 层数
        int len=S.length();
        for (int i = 0; i < len; i++)
        {
            if(S[i]=='-'&&fir_id){
                //cout<<" first :";
                pos_l=i;
                //index_nu.push_back(0);
                //cout<<S.substr(0,i)<<endl;
                //num.push_back(my_str2int(S.substr(0,i)));
                root=new TreeNode(my_str2int(S.substr(0,i)));
                fir_id=0;
            }
            if(S[i]!='-'&&!is_num&&!fir_id){
                //cout<<" s_index: ";
                pos_r=i;
                //cout<<pos_r-pos_l<<"  ";
                index_nu.push_back(pos_r-pos_l);
                pos_l=i;
                is_num=1;
            }
            if(S[i]=='-'&&is_num&&!fir_id){
                //cout<<" f_num: ";
                pos_r=i;
                //cout<<S.substr(pos_l,pos_r-pos_l)<<"";
                num.push_back(my_str2int(S.substr(pos_l,pos_r-pos_l)));
                pos_l=i;
                is_num=0;
                //cout<<endl;
            }
        }
        num.push_back(my_str2int(S.substr(pos_l)));
       // cout<<" last: "<<S.substr(pos_l)<<endl;
        
        
        // vector<int>::iterator ite_index=index_nu.begin(),ite_num=num.begin();
        // createTree(root,index_nu,num,ite_index,ite_num);
        int index_num[num.size()],arr_num[num.size()];
        for (int i = 0; i < num.size(); i++)
        {
            cout<<index_nu[i]<<" ---> "<<num[i]<<endl;
            index_num[i]=index_nu[i];
            arr_num[i]=num[i];
        
        }

        createTree(root,index_num,arr_num,0,num.size()-1);
        getMidSort(root);//getPreSort(root);
        //cout<<root->right->left->val<<endl;
        // for (int i = 0; i < num.size(); i++)
        // {
        //     cout<<index_nu[i]<<" :: "<<num[i]<<"  ";
        // }
        
        return root;
}
/**
 *  leetcode   1008. Construct Binary Search Tree from Preorder Traversal 
 *  构建二叉搜索树 迭代器和for循环遍历  提交时for循环时间效率更高些
 * */
TreeNode* createTreePre(TreeNode* root,vector<int>& preorder,vector<int>::iterator &it){
    //cout<<*it<<" bb ";
    if(*it>root->val&&it<preorder.end()){
        if(root->right)
            createTreePre(root->right,preorder,it);
        else{
            cout<<*it<<" ss ";
            root->right=new TreeNode(*it);
            //createTreePre(root,preorder,it);
        }
    }
    if(*it<root->val&&it<preorder.end()){
        if(root->left)
            createTreePre(root->left,preorder,it);
        else{
            cout<<*it<<" ff ";
            root->left=new TreeNode(*it);
            //createTreePre(root,preorder,it);
        }
    }
    return root;
}
TreeNode* createTreePre(TreeNode* root,vector<int>& preorder,int pos,int end){
    //cout<<*it<<" bb ";
    if(preorder[pos]>root->val&&pos<end){
        if(root->right)
            createTreePre(root->right,preorder,pos,end);
        else{
            //cout<<*it<<" ss ";
            root->right=new TreeNode(preorder[pos]);
            //createTreePre(root,preorder,it);
        }
    }
    if(preorder[pos]<root->val&&pos<end){
        if(root->left)
            createTreePre(root->left,preorder,pos,end);
        else{
            //cout<<*it<<" ff ";
            root->left=new TreeNode(preorder[pos]);
            //createTreePre(root,preorder,it);
        }
    }
    return root;
}
TreeNode* bstFromPreorder(vector<int>& preorder) {
    TreeNode* root;
    if(preorder.empty())return NULL;
    vector<int>::iterator ite=preorder.begin();
    root=new TreeNode(*ite++);
    for (;ite<preorder.end();ite++)
    {
        createTreePre(root,preorder,ite);
    }
    //  int len=preorder.size();
    // root=new TreeNode(preorder[0]);
    // for (int i = 1; i <len; i++)
    // {
    //     createTreePre(root,preorder,i,len);
    // }
    return root;        
}


/**
 * leetcode 980. Unique Paths III
 *
 *  路径搜索问题 深度优先
 * */

bool isRoute(int *arr,int x,int y,int col){
    if(*(arr+x*col+y)==1)return true;
    return false;
}
void setRoute(int *arr,int x,int y,int col){
    if(*(arr+x*col+y)==0){
        *(arr+x*col+y)=1;
    }
}
void getUniquePath(vector<vector<int>>& grid,int *arr,int &total_num,int &count,int start_x,int start_y,int end_x,int end_y,int len){
    if(total_num==0){
        count++;
    }
    if(start_x>=0&&!isRoute(arr,start_x-1,start_y,len)){
        total_num--;setRoute(arr,start_x-1,start_y,len);
        getUniquePath(grid,arr,total_num,count,start_x-1,start_y,end_x,end_y,len);
    }
    if(start_y<len&&!isRoute(arr,start_x,start_y+1,len)){
        total_num--;setRoute(arr,start_x,start_y+1,len);
        getUniquePath(grid,arr,total_num,count,start_x,start_y+1,end_x,end_y,len);
    }
    if(start_x<len&&!isRoute(arr,start_x+1,start_y,len)){
        total_num--;setRoute(arr,start_x+1,start_y,len);
        getUniquePath(grid,arr,total_num,count,start_x+1,start_y,end_x,end_y,len);
    }
    if(start_y>=0&&!isRoute(arr,start_x,start_y-1,len)){
        total_num--;setRoute(arr,start_x,start_y-1,len);
        getUniquePath(grid,arr,total_num,count,start_x,start_y-1,end_x,end_y,len);
    }
}


int uniquePathsIII(vector<vector<int>>& grid) {
        int len_col=grid.size(),len_cow=grid[0].size();//行 列
        int total_num;//上》右》下》左 0总数
        int map[len_col][len_cow]={0};
        int start_x,start_y,end_x,end_y;
        for (int i = 0; i < len_col; i++)
        {
            for (int j = 0; j < len_cow; j++)
            {
                if(grid[i][j]==0)total_num++;
                //map[i][j]=grid[i][j];
                if(grid[i][j]==1){
                    start_x=i;
                    start_y=j;
                    map[i][j]=1;
                }
                if(grid[i][j]==2){
                    end_x=i;
                    end_y=j;
                    map[i][j]=1;
                }
                if(grid[i][j]==-1)
                    map[i][j]=1;
            }
        }
        int count=0;
        getUniquePath(grid,*map,total_num,count,start_x,start_y,end_x,end_y,len_col);
        return count;
}
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
    //vector<int> num(nu, nu +  6);
    //constructMaximumBinaryTree(num);
    //cout<<getMaxNumOfArr(nu,0,5);


    // TreeNode *root=new TreeNode(4);
    // root->left=new TreeNode(2);
    // root->right=new TreeNode(7);
    // root->left->left=new TreeNode(1);
    // root->left->right=new TreeNode(3);
    // // root->right->left=new TreeNode(5);
    // //root->right->right=new TreeNode(18);
    // getMidSort(root);cout<<endl;
    
    // getMidSort(insertIntoBST(root,5));
    //string st="1258905676";
    //int pos;
    //char ss[3];strcpy(ss,st.c_str());
    //cout<<my_str2int(st);

    //1088
    // int nu[] = {8,5,1,7,10,12};
    // //print_arr(nu,6);
    // cout << endl;
    // vector<int> num(nu, nu + 6);
    // TreeNode *root = bstFromPreorder(num);
    // cout << root->val << " root ";
    // cout << " midsort ";
    // getMidSort(root);
    // cout << " presort ";
    // getPreSort(root);

    //1008
    // string str="1-2--3--4-5--6--7";
    // recoverFromPreorder(str);

     int arr[4][4]={{1,0,0,0},{0,0,0,0},{0,0,0,2}};
    vector <vector<int> > ss(4,vector<int>(0));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            ss[i].push_back(arr[i][j]);
        }
    }
    print_arr(*arr,4,4);
    cout<<uniquePathsIII(ss)<<endl;

    return 0;
}
