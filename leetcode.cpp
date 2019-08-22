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
#include <list>

#include "aigorithm.cpp"
#include "tree.cpp"
using namespace std;

void quick_sort(int arr[], int low, int heigh);
void print_arr(int a[], int size_arr);
void print_arr(int *a, int x, int y);
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
vector<vector<int>> flipAndInvertImage(vector<vector<int>> &A)
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
                result += removePar(S.substr(tmp + 1, len_son), len_son);
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
int maxIncreaseKeepingSkyline(vector<vector<int>> &grid)
{
    int len = grid.size();
    int topToBottom[len], leftToRight[len];
    int result = 0;
    for (int i = 0; i < len; i++)
    {
        int tmp_1 = 0, tmp_2 = 0;
        for (int j = 0; j < len; j++)
        {
            if (grid[i][j] > tmp_1)
                tmp_1 = grid[i][j];
            if (grid[j][i] > tmp_2)
                tmp_2 = grid[j][i];
        }
        topToBottom[i] = tmp_2;
        leftToRight[i] = tmp_1;
    }

    //print_arr(topToBottom,4);print_arr(leftToRight,4);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        { //
            if (leftToRight[i] < topToBottom[j])
                result += (leftToRight[i] < topToBottom[j]) ? (leftToRight[i] - grid[i][j]) : (topToBottom[j] - grid[i][j]);
            else
                result += topToBottom[j] - grid[i][j];
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
void getMidSort(Tree root, int l, int r, vector<int> &result_tree)
{
    if (root)
    {
        getMidSort(root->left, l, r, result_tree);
        //  s+=my_to_string(root->val);
        //  cout<<i++<<" --  "<<s<<endl;
        if (root->val >= l && root->val <= r)
            result_tree.push_back(root->val);
        getMidSort(root->right, l, r, result_tree);
    }
}
/**
  * 中序遍历树组返回结果放在树组中
  * */
int ind_node_num = 0;
void getMidSortArr(Tree root, int *result_tree)
{
    if (root)
    {
        getMidSortArr(root->left, result_tree);
        //  s+=my_to_string(root->val);
        //  cout<<i++<<" --  "<<s<<endl;
        //result_tree.push_back(root->val);
        result_tree[ind_node_num++] = root->val;
        getMidSortArr(root->right, result_tree);
    }
}
int rangeSumBST(TreeNode *root, int L, int R)
{
    vector<int> result;             //int num[10000];
    getMidSort(root, L, R, result); //getMidSortArr(root,num);
    //print_arr(num,ind_node_num);
    int len = result.size();
    int total_num = 0;

    for (int i = 0; i < len; i++)
    {
        total_num += result[i];
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
string encode(string longUrl)
{
    vector<string> result;

    mySplitString(longUrl, result, "//");
    // for(vector<string>::iterator iter1=result.begin()+1;iter1!=result.end(); iter1++)
    // {
    //     url_web_com+=*(iter1);
    // }
    // cout<<url_web_com<<" 1 ";
    string shortUrl = result[0] + "//", url_web_com;
    url_web_com = result[1];
    vector<string> url_web;
    mySplitString(url_web_com, url_web, "/");

    for (vector<string>::iterator iter = url_web.begin(); iter != url_web.end(); iter++)
    {
        if (*(iter) == "leetcode.com" && *(iter + 1) == "problems")
            url_web.erase(iter);
        if (*iter == "problems")
            *iter = "pro";
        //cout<<*iter<<" ";
    }
    for (int i = 0; i < url_web.size(); i++)
    {
        shortUrl = shortUrl + url_web[i];
        if (i != url_web.size() - 1)
            shortUrl += "/";
    }

    //for_each(url_web.begin(),url_web.end(),printer<string>);
    return shortUrl;
}

// Decodes a shortened URL to its original URL.
string decode(string shortUrl)
{
    vector<string> result_url;
    mySplitString(shortUrl, result_url, "//");
    string reLongUrl = result_url[0] + "//";
    string long_url_web = result_url[1];
    vector<string> url_web;
    mySplitString(long_url_web, url_web, "/");
    //cout<<"sdassdsadas"<<endl;
    //for_each(url_web.begin(),url_web.end(),printer<string>);
    int len = url_web.size();
    for (int i = 0; i < len; i++)
    {
        //cout<<" -->>"<<url_web[i]<<endl;
        if (url_web[i] == "pro")
        {
            url_web[i] = "problems";
            url_web.insert(url_web.begin() + i, "leetcode.com");
        }
    }

    for (int i = 0; i < url_web.size(); i++)
    {
        reLongUrl += url_web[i];
        if (i != url_web.size() - 1)
            reLongUrl += "/";
        /* code */
    }

    return reLongUrl;
}
/**
 * leetcode 654 Maximum Binary Tree
 * 选取数组中最大的数作为节点建立树
 * */

TreeNode *getTree(int *arr, int l, int r)
{
    if (l <= r)
    {
        int pos = getMaxNumOfArr(arr, l, r);
        TreeNode *root = new TreeNode(*(arr + pos));
        //cout<<"l: "<<l<<" mid: "<<pos<<" r: "<<r;
        //cout << " num: " << *(arr + pos) << " "<<endl;
        root->left = getTree(arr, l, pos - 1);
        root->right = getTree(arr, pos + 1, r);
        return root;
    }
    return NULL;
}

TreeNode *constructMaximumBinaryTree(vector<int> &nums)
{
    //vector<int>::iterator iter;
    int len = nums.size();
    int arr[len];
    for (int i = 0; i < len; i++)
    {
        arr[i] = nums[i];
    }
    TreeNode *root = getTree(arr, 0, len - 1);
    getMidSort(root);
    return root;
}
/**
 * leetcode 701  Insert into a Binary Search Tree 
 * 
 * */
TreeNode *insertIntoBST(TreeNode *root, int val)
{
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
int getPos(int num[], int value, int begin, int end)
{
    int pos = -1;
    for (int i = begin; i <= end; i++)
    {
        if (num[i] == value)
        {
            pos = i;
            break;
        }
    }
    return pos;
}
TreeNode *createTree(TreeNode *root, int index_num[], int num[], int arr_l, int arr_r)
{
    while (arr_l <= arr_r)
    {
        int i = index_num[arr_l];
        int pos = getPos(index_num, i, arr_l + 1, arr_r);
        cout << "  L ::" << arr_l << " R:: " << arr_r << "   ";
        cout << " pos: " << pos << endl;
        if (pos > 0)
        {
            root->left = new TreeNode(num[arr_l]);
            root->right = new TreeNode(num[pos]);
            createTree(root->left, index_num, num, arr_l + 1, pos - 1);
            createTree(root->right, index_num, num, pos + 1, arr_r);
        }
        else
        {
            //root=new TreeNode(num[arr_l]);
            // cout<<1234<<" s" ;
            root->left = new TreeNode(num[arr_l]);
            createTree(root->left, index_num, num, arr_l + 1, arr_r);
            // else root->right=new TreeNode(num[arr_l]);
        }
        return root;
    }
    return NULL;
}
TreeNode *recoverFromPreorder(string S)
{
    //1-2--3--4-5--6--7
    vector<int> index_nu, num;
    TreeNode *root;
    if (S.find('-') == -1)
    {
        root = new TreeNode(my_str2int(S));
        return root;
    }
    int pos_l = 0, pos_r, fir_id = 1, is_num = 0, stage = 0; //数字起始左 右 第一个数 是否是数 层数
    int len = S.length();
    for (int i = 0; i < len; i++)
    {
        if (S[i] == '-' && fir_id)
        {
            //cout<<" first :";
            pos_l = i;
            //index_nu.push_back(0);
            //cout<<S.substr(0,i)<<endl;
            //num.push_back(my_str2int(S.substr(0,i)));
            root = new TreeNode(my_str2int(S.substr(0, i)));
            fir_id = 0;
        }
        if (S[i] != '-' && !is_num && !fir_id)
        {
            //cout<<" s_index: ";
            pos_r = i;
            //cout<<pos_r-pos_l<<"  ";
            index_nu.push_back(pos_r - pos_l);
            pos_l = i;
            is_num = 1;
        }
        if (S[i] == '-' && is_num && !fir_id)
        {
            //cout<<" f_num: ";
            pos_r = i;
            //cout<<S.substr(pos_l,pos_r-pos_l)<<"";
            num.push_back(my_str2int(S.substr(pos_l, pos_r - pos_l)));
            pos_l = i;
            is_num = 0;
            //cout<<endl;
        }
    }
    num.push_back(my_str2int(S.substr(pos_l)));
    // cout<<" last: "<<S.substr(pos_l)<<endl;

    // vector<int>::iterator ite_index=index_nu.begin(),ite_num=num.begin();
    // createTree(root,index_nu,num,ite_index,ite_num);
    int index_num[num.size()], arr_num[num.size()];
    for (int i = 0; i < num.size(); i++)
    {
        cout << index_nu[i] << " ---> " << num[i] << endl;
        index_num[i] = index_nu[i];
        arr_num[i] = num[i];
    }

    createTree(root, index_num, arr_num, 0, num.size() - 1);
    getMidSort(root); //getPreSort(root);
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
TreeNode *createTreePre(TreeNode *root, vector<int> &preorder, vector<int>::iterator &it)
{
    //cout<<*it<<" bb ";
    if (*it > root->val && it < preorder.end())
    {
        if (root->right)
            createTreePre(root->right, preorder, it);
        else
        {
            cout << *it << " ss ";
            root->right = new TreeNode(*it);
            //createTreePre(root,preorder,it);
        }
    }
    if (*it < root->val && it < preorder.end())
    {
        if (root->left)
            createTreePre(root->left, preorder, it);
        else
        {
            cout << *it << " ff ";
            root->left = new TreeNode(*it);
            //createTreePre(root,preorder,it);
        }
    }
    return root;
}
TreeNode *createTreePre(TreeNode *root, vector<int> &preorder, int pos, int end)
{
    //cout<<*it<<" bb ";
    if (preorder[pos] > root->val && pos < end)
    {
        if (root->right)
            createTreePre(root->right, preorder, pos, end);
        else
        {
            //cout<<*it<<" ss ";
            root->right = new TreeNode(preorder[pos]);
            //createTreePre(root,preorder,it);
        }
    }
    if (preorder[pos] < root->val && pos < end)
    {
        if (root->left)
            createTreePre(root->left, preorder, pos, end);
        else
        {
            //cout<<*it<<" ff ";
            root->left = new TreeNode(preorder[pos]);
            //createTreePre(root,preorder,it);
        }
    }
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    TreeNode *root;
    if (preorder.empty())
        return NULL;
    vector<int>::iterator ite = preorder.begin();
    root = new TreeNode(*ite++);
    for (; ite < preorder.end(); ite++)
    {
        createTreePre(root, preorder, ite);
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
 *  路径搜索问题 深度优先 未完成
 * */

bool isRoute(int *arr, int x, int y, int col)
{
    if (*(arr + x * col + y) == 1)
        return true;
    return false;
}
void setRoute(int *arr, int x, int y, int col)
{
    if (*(arr + x * col + y) == 0)
    {
        *(arr + x * col + y) = 1;
    }
}
void getUniquePath(vector<vector<int>> &grid, int *arr, int &total_num, int &count, int start_x, int start_y, int end_x, int end_y, int len)
{
    if (total_num == 0)
    {
        count++;
    }
    if (start_x >= 0 && !isRoute(arr, start_x - 1, start_y, len))
    {
        total_num--;
        setRoute(arr, start_x - 1, start_y, len);
        getUniquePath(grid, arr, total_num, count, start_x - 1, start_y, end_x, end_y, len);
    }
    if (start_y < len && !isRoute(arr, start_x, start_y + 1, len))
    {
        total_num--;
        setRoute(arr, start_x, start_y + 1, len);
        getUniquePath(grid, arr, total_num, count, start_x, start_y + 1, end_x, end_y, len);
    }
    if (start_x < len && !isRoute(arr, start_x + 1, start_y, len))
    {
        total_num--;
        setRoute(arr, start_x + 1, start_y, len);
        getUniquePath(grid, arr, total_num, count, start_x + 1, start_y, end_x, end_y, len);
    }
    if (start_y >= 0 && !isRoute(arr, start_x, start_y - 1, len))
    {
        total_num--;
        setRoute(arr, start_x, start_y - 1, len);
        getUniquePath(grid, arr, total_num, count, start_x, start_y - 1, end_x, end_y, len);
    }
}

int uniquePathsIII(vector<vector<int>> &grid)
{
    int len_col = grid.size(), len_cow = grid[0].size(); //行 列
    int total_num;                                       //上》右》下》左 0总数
    int map[len_col][len_cow] = {0};
    int start_x, start_y, end_x, end_y;
    for (int i = 0; i < len_col; i++)
    {
        for (int j = 0; j < len_cow; j++)
        {
            if (grid[i][j] == 0)
                total_num++;
            //map[i][j]=grid[i][j];
            if (grid[i][j] == 1)
            {
                start_x = i;
                start_y = j;
                map[i][j] = 1;
            }
            if (grid[i][j] == 2)
            {
                end_x = i;
                end_y = j;
                map[i][j] = 1;
            }
            if (grid[i][j] == -1)
                map[i][j] = 1;
        }
    }
    int count = 0;
    getUniquePath(grid, *map, total_num, count, start_x, start_y, end_x, end_y, len_col);
    return count;
}

/**
 * leetcode 950. Reveal Cards In Increasing Order
 *  完成
 * */
int getPoseOfC(vector<int> &arr, int begin, int end)
{
    int tmp = arr[begin];
    while (begin < end)
    {
        while (arr[end] > tmp && begin < end)
            end--;
        arr[begin] = arr[end];
        while (arr[begin] < tmp && begin < end)
            begin++;
        arr[end] = arr[begin];
    }
    arr[begin] = tmp;
    return begin;
}
void card_sort(vector<int> &sort_arr, int begin, int end)
{
    if (begin < end)
    {
        int pos = getPoseOfC(sort_arr, begin, end);
        card_sort(sort_arr, begin, pos - 1);
        card_sort(sort_arr, pos + 1, end);
    }
}
void card_reverse(vector<int> &arr, int start, int end)
{

    int tmp = arr[end];
    arr.pop_back();
    arr.insert(arr.begin() + start, tmp);
    // for (int i = end; i>start; i--)
    // {
    //     arr[i]=arr[i-1];
    // }
    // arr[start]=tmp;
}
void prinrt_card_arr(int arr[], int start, int end)
{

    for (int i = start; i <= end; i++)
    {
        cout << arr[i] << "   ";
        /* code */
    }
    cout << endl;
}
//2,13,3,11,5,17,7  size=3
void sortCard(vector<int> &arr, vector<int> &sort_ar, int start, int end, int mid)
{

    while (mid >= start)
    {
        //cout<<" mid:: "<<mid;
        if (end == mid) //1
        {
            arr[end] = sort_ar[end]; //cout<<"fir： "<<arr[end];
        }
        if (end - 1 == mid) //2
        {
            arr[end] = sort_ar[end];
            arr[mid] = sort_ar[mid]; //cout<<" sec: "<<arr[mid];
        }
        if (end - 1 > mid)
        {
            arr[mid] = sort_ar[mid]; //cout<<" ss： "<<arr[mid]<<"  "<<endl;
            card_reverse(arr, mid + 1, end);
            //prinrt_card_arr(arr,mid,end);
            //sortCard(arr, sort_ar, start, end, --mid);
        }
        mid--;
        //cout<<endl;
    }
}
vector<int> deckRevealedIncreasing(vector<int> &deck)
{
    int len = deck.size();
    int result[len] = {0};
    vector<int> result_ver(deck);
    card_sort(deck, 0, len - 1);
    // for (int i = 0; i < len; i++)
    // {
    //     cout<<deck[i]<<"  ";
    //     /* code */
    // }

    sortCard(result_ver, deck, 0, len - 1, len - 1);
    //cout<<"result::"<<endl;
    // for (int i = 0; i < len; i++)
    // {
    //     //result_ver.push_back(result[i]);
    //     cout<<result_ver[i]<<"  ";
    //     /* code */
    // }
    return result_ver;
}
/**
 * leetcode 890. Find and Replace Pattern
 * 
 **/
bool predictIsFit(string word, string pattern)
{
    int len_1 = word.length();
    int len_2 = pattern.length();
    if (len_1 != len_2)
        return false;
    //cout<<word<<"  :::   "<<pattern<<endl;
    set<char> pair_index, pair_num;
    //map<char,char> pairs;
    char index[len_1], value[len_1];
    int cout = 0;
    for (int i = 0; i < len_1; i++)
    {
        if (pair_index.find(pattern[i]) == pair_index.end())
        {
            pair_index.insert(pattern[i]);
            // pairs[pattern[i]]=word[i];
            index[cout] = pattern[i];
            value[cout++] = word[i];
            pair_num.insert(word[i]);
        }
        else
        {
            // if((*(pairs.find(pattern[i]))).second!=word[i]){
            //     return false;
            // }
            int j;
            for (j = 0; j < cout; j++)
            {
                if (index[j] == pattern[i] && value[j] != word[i])
                {
                    return false;
                }
            }
        }
    }
    if (pair_index.size() != pair_num.size())
    {
        return false;
    }
    return true;
}
vector<string> findAndReplacePattern(vector<string> &words, string pattern)
{
    vector<string> result_vec;
    int len = words.size();
    for (int i = 0; i < len; i++)
    {
        if (predictIsFit(words[i], pattern))
        {
            cout << words[i] << "  ";
            result_vec.push_back(words[i]);
        }
    }
    return result_vec;
}
/**
 * leetcode 814. Binary Tree Pruning
 * 全为0为真
 **/
bool getMostSubNodeTree(TreeNode *root)
{
    if (root)
    {
        if (root->val == 1)
        {
            return false;
        }
        else
        {
            return getMostSubNodeTree(root->left) && getMostSubNodeTree(root->right) ? true : false;
        }
    }
    return true;
}
//int nnnnnn=0;
TreeNode *pruneTree(TreeNode *root)
{
    if (getMostSubNodeTree(root))
    {
        //cout << " <---->" << nnnnnn++ << getMostSubNodeTree(root);
        root = NULL;
    }
    else
    {
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
    }
    return root;
}
/**
 * leetcode  461 Hamming Distance
 * 
 * */
int hammingDistance(int x, int y)
{
    int arr_x[32] = {0}, arr_y[32] = {0};
    int len_x, len_y;
    int2byte(x, arr_x, len_x);
    int2byte(y, arr_y, len_y);
    int max_len = len_x > len_y ? len_x : len_y;
    int num = 0;
    for (int i = 0; i < max_len; i++)
    {
        if (arr_x[i] != arr_y[i])
            num++;
    }

    return num;
}
/**
 * leetcode 894. All Possible Full Binary Trees
 * 
 * */
void getTreeBleNode(TreeNode *root, vector<TreeNode *> &blefNode)
{ //获得叶节点
    if (!root->left && !root->right)
    {
        blefNode.push_back(root);
    }
    else
    {
        getTreeBleNode(root->left, blefNode);
        getTreeBleNode(root->right, blefNode);
    }
}
TreeNode *getCloneTree(TreeNode *root, TreeNode *&clo)
{ //复制树
    if (root)
    {
        clo = new TreeNode(root->val);
        getCloneTree(root->left, clo->left);
        getCloneTree(root->right, clo->right);
    }
    return clo;
}
TreeNode *addNode(TreeNode *root, TreeNode *index)
{ //在复制树上指定位置添加节点
    index->left = new TreeNode(0);
    index->right = new TreeNode(0);
    TreeNode *clo;
    getCloneTree(root, clo);
    index->left = NULL;
    index->right = NULL;
    return clo;
}
bool isSameTree(TreeNode *root1, TreeNode *root2)
{ //两棵树结构是否相同
    if (root1 && root2)
    {
        return isSameTree(root1->left, root2->left) && isSameTree(root1->right, root2->right) ? true : false;
    }
    else if (!root1 && !root2)
    {
        return true;
    }
    else
    {
        return false;
    }

    return true;
}
void removeUnNeed(vector<TreeNode *> &list)
{ //删除两个相同的
    int len = list.size();
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            if (isSameTree(list[i], list[j]))
            {
                list.erase(list.begin() + j);
                len--;
            }
        }
    }
}
vector<TreeNode *> allPossibleFBT(int N)
{
    if (N % 2 == 0)
    {
        vector<TreeNode *> result;
        return result;
    }
    if (N == 1)
    {
        TreeNode *root = new TreeNode(0);
        vector<TreeNode *> result;
        result.push_back(root);
        return result;
    }
    else
    {
        vector<TreeNode *> NodeList = allPossibleFBT(N - 2);
        vector<TreeNode *> result;
        int len = NodeList.size();
        for (int i = 0; i < len; i++)
        {
            vector<TreeNode *> sdubTree;
            getTreeBleNode(NodeList[i], sdubTree);
            int nums = sdubTree.size();
            for (int j = 0; j < nums; j++)
            {
                result.push_back(addNode(NodeList[i], sdubTree[j]));
            }
        }
        removeUnNeed(result);
        return result;
    }
}
vector<TreeNode *> allPossibleFBT_2(int N) //参考优化代码
{
    N--;
    vector<TreeNode *> res;
    if (N == 0)
    {
        res.push_back(new TreeNode(0));
        return res;
    }
    for (int i = 1; i < N; i += 2)
    {
        for (auto &left : allPossibleFBT(i))
        {
            for (auto &right : allPossibleFBT(N - i))
            {
                TreeNode *root = new TreeNode(0);
                root->left = left;
                root->right = right;
                res.push_back(root);
            }
        }
    }
    return res;
}
/**
 * leetcode 797. All Paths From Source to Target
 * 
 * */
int getFirstNode(vector<int> &nextNode)
{
    int tmp = nextNode[0];
    nextNode.erase(nextNode.begin());
    return tmp;
}
bool isPath(vector<int> &li, int end)
{
    if (li[li.size() - 1] == end)
    {
        return true;
    }
    return false;
}
vector<vector<int>> allPathsSourceTarget(vector<vector<int>> &graph)
{
    vector<vector<int>> result;
    int end = graph.size() - 1;

    stack<vector<int>> allNode;
    vector<int> possiblePath;
    list<int> path;

    allNode.push(graph[0]);
    possiblePath.push_back(0);
    //possiblePath.push_back(0);
    path.push_back(0);

    while (!allNode.empty())
    {
        vector<int> nextNode = allNode.top();
        allNode.pop();

        // possiblePath.pop_back();

        if (!nextNode.empty())
        {
            int nex = getFirstNode(nextNode);
            //cout<<"  fist:  "<<nex<<" le : ";print_vect(nextNode);
            possiblePath.push_back(nex);
            if (isPath(possiblePath, end))
            {
                //cout<<" rightPath:  ";
                //print_vect(possiblePath);
                result.push_back(possiblePath);
            }

            allNode.push(nextNode);

            allNode.push(graph[nex]);
        }
        else
        {
            possiblePath.pop_back();
        }
    }

    return result;
}
/**
 * leetcode 942. DI String Match
 * 
 * */
vector<int> diStringMatch(string S)
{
    vector<int> re;
    int len = S.length();
    int pos;
    // for (int i = 0; i <= len; i++)
    // {
    //     re.push_back(i);
    // }
    // print_vect(re);
    int I_begin = 0;
    int D_begin = len;
    for (int i = 0; i < len; i++)
    {
        if (S[i] == 'I')
        {
            re.push_back(I_begin++);
        }
        else
        {
            re.push_back(D_begin--);
        }
    }
    re.push_back(I_begin);
    print_vect(re);
    return re;
}
/**
 * leetcode 763. Partition Labels
 * 记录每个字符出现的最右侧位置，选出最大的进行分割
 * */
vector<int> partitionLabels(string S)
{
    map<char, int> d;
    int len = S.length();
    for (int i = 0; i < len; i++)
        d[S[i]] = i;

    int start = 0, end = 0;
    vector<int> res;
    for (int i = 0; i < len; i++)
    {
        end = max(end, d[S[i]]);
        if (i == end)
        {
            res.push_back(end - start + 1);
            start = end + 1;
        }
    }
    return res;
}
/**
 * leetcode 617. Merge Two Binary Trees
 * 在左树的基础上添加第二棵树，左右节点存在则相加，右节点存在左节点不存在则创造节点
 * */
TreeNode *mergeTrees(TreeNode *t1, TreeNode *t2)
{
    if (t2)
    {
        if (t1)
            t1->val = t1->val + t2->val;
        else
            t1 = new TreeNode(t2->val);
        t1->left = mergeTrees(t1->left, t2->left);
        t1->right = mergeTrees(t1->right, t2->right);
    }
    return t1;
}
/**
 * leetcode 921. Minimum Add to Make Parentheses Valid
 * 
 * */
int minAddToMakeValid(string S)
{
    int len = S.length();
    if (len == 0 || len == 1)
        return len;

    std::stack<char> sta;
    //cout<<123<<len<<endl;
    //int count=0;
    for (int i = 0; i < len; i++)
    {
        //cout<<S[i]<<" ";
        if (S[i] == '(')
        {

            sta.push(S[i]);
            //count++;
            //cout<<" top:: "<<sta.top()<<endl;
        }
        if (S[i] == ')')
        {
            if (!sta.empty() && sta.top() == '(')
            {
                //cout<<" delete ";
                sta.pop();
                //count--;
            }
            else
            {
                //cout<<" ++ ";
                sta.push(S[i]);
                //count++;
            }
        }
    }
    return sta.size();
}
/**
 *leetcode 1038. Binary Search Tree to Greater Sum Tree
 * 
 * */
int getSumOfTree(TreeNode *root)
{
    if (root)
        return root->val + getSumOfTree(root->left) + getSumOfTree(root->right);
    else
        return 0;
}
void getMidSortTree(TreeNode *root, vector<int> &result_tree)
{
    if (root)
    {
        getMidSortTree(root->left, result_tree);
        result_tree.push_back(root->val);
        getMidSortTree(root->right, result_tree);
    }
}
void setTree(TreeNode *root, vector<int> &vec, vector<int>::iterator &ite, int &n, int &fir)
{
    if (root)
    {
        setTree(root->left, vec, ite, n, fir);
        if (fir)
        {
            n = (root->val = n - *ite);
            fir = 0;
        }
        else
        {
            n = (root->val = n - *ite++);
        }
        setTree(root->right, vec, ite, n, fir);
    }
}
TreeNode *bstToGst(TreeNode *root)
{
    int tot = getSumOfTree(root);
    vector<int> nodes_value;
    getMidSortTree(root, nodes_value);

    int fir = 1;
    vector<int>::iterator ite = nodes_value.begin();

    setTree(root, nodes_value, ite, tot, fir);
    return root;
}
/**
 * leetcode 728. Self Dividing Numbers
 * 
 * */
vector<int> getNumNode(int num)
{
    vector<int> res;
    while (num)
    {
        //cout<<num%10<<" ";
        res.push_back(num % 10);
        num = num / 10;
    }
    return res;
}
bool predDividNum(int num)
{

    int tmp = num;
    //vector<int> res;
    while (num)
    {
        //cout<<num%10<<" ";
        if (num % 10 == 0)
            return false;
        else if (tmp % (num % 10) != 0)
            return false;
        num = num / 10;
    }

    // int len=res.size();
    // for (int i = 0; i < len; i++)
    // {
    //     if(res[i]==0)return false;
    //     if(num%res[i]!=0)return false;
    // }
    return true;
}
vector<int> selfDividingNumbers(int left, int right)
{
    vector<int> res;
    for (int i = left; i <= right; i++)
    {
        if (predDividNum(i))
            res.push_back(i);
    }

    return res;
}
/**
 * leetcode 852. Peak Index in a Mountain Array
 * 
 * */
int peakIndexInMountainArray(vector<int> &A)
{
    int len = A.size();
    int pos = 0, num = A[0];
    for (int i = 1; i < len; i++)
    {
        if (A[i] > num)
        {
            num = A[i];
            pos = i;
        }
        else
        {
            break;
        }
    }
    return pos;
}
/**
 * leetcode  933. Number of Recent Calls
 * 
 * 
 * */
class RecentCounter {
	
	vector<int> pq;
    int count;
	RecentCounter() {
		
	}
    
    int ping(int t) {
    	while (!pq.empty()&& *(pq.begin()) + 3000 < t) {
            pq.erase(pq.begin());
    	}
    	pq.push_back(t);
        // count=0;
        // for (int i = 0; i < pq.size(); i++)
        // {
        //     if(pq[i]>t-3000){
        //         count++;
        //     }
        // }
        
    	return pq.size();
    }
};
/**
 * leetcode 861. Score After Flipping Matrix
 * 
 * 
 * */
 bool checkNeedTurn(int i,vector<vector<int>> &A){
    bool retBoolean = false;
    int zeroCount = 0;
    for(int j=0; j<A.size(); j++){
        if(zeroCount > A.size()/2){
            retBoolean = true;
            return retBoolean;
        }
        if(A[j][i] == 0){
            zeroCount++;
        }

    }
    if(zeroCount > A.size()/2){
        retBoolean = true;
    }
    return retBoolean;
}

int matrixScore(vector<vector<int>> &A)
{
    int retData = 0;
    int count = A[0].size() - 1;

    // 先横向反转，然后再纵向反转
    for (int k = 0; k < A.size(); k++)
    {
        if (A[k][0] == 0)
        {
            for (int m = 0; m < A[0].size(); m++)
            {
                A[k][m] = (A[k][m] + 1) % 2;
            }
        }
    }
    // 竖向反转
    for (int i = 0; i < A[0].size(); i++)
    {
        if (!checkNeedTurn(i,A))
        {
            continue;
        }
        for (int j = 0; j < A.size(); j++)
        {
            A[j][i] = (A[j][i] + 1) % 2;
        }
    }

    for (int k = 0; k < A.size(); k++)
    {
        for (int m = 0; m < A[0].size(); m++)
        {
            retData += pow(2, count - m) * A[k][m];
        }
    }
    return retData;
}

/**
 * leetcode 162. Find Peak Element
 * 
 * */
int findPeakElement(vector<int> &nums)
{
    int len = nums.size();
    if (len == 1)
        return 0;
    if (len == 2)
    {
        if (nums[0] > nums[1])
            return 0;
        return 1;
    }
    int res = 0;
    for (int i = 1; i < len - 1; i++)
    {
        if (nums[i] > nums[i - 1] && nums[i] > nums[i + 1])
        {
            res = i;
            break;
        }
    }
    if (!res && nums[len - 1] > nums[len - 2])
        return len - 1;
    return res;
}
/**
 * leetcode 944. Delete Columns to Make Sorted
 * 
 * */
int minDeletionSize(vector<string>& A) {
    int len_arr=A.size();
    int len_str=A[0].length();
    int count=0;
    for (int i = 0; i < len_str; i++)
    {
        int va=A[0][i];
        for (int j = 1; j < len_arr; j++)
        {
           if(A[j][i]>=va){
               va=A[j][i];
           }else
           {
               count++;
               break;
           }
            
        }
        
    }
    return count;
}
/**
 * leetcode 561. Array Partition I
 * */
int partition_quick(vector<int> &arr, int low, int heigh)
{
    int tmp = arr[low];
    while (low < heigh)
    {
        while (arr[heigh] >= tmp && low < heigh)
            heigh--;
        arr[low] = arr[heigh];
        while (arr[low] <= tmp && low < heigh)
            low++;
        arr[heigh] = arr[low];
    }
    arr[low] = tmp;
    return low;
}
void quick_sort(vector<int> &arr, int low, int heigh)
{
    if (low < heigh)
    {
        int pos = partition_quick(arr, low, heigh);
        quick_sort(arr, low, pos - 1);
        quick_sort(arr, pos + 1, heigh);
    }
}
int arrayPairSum(vector<int>& nums) {
        quick_sort(nums,0,nums.size()-1);
        for (int i = 0; i < nums.size(); i++)
        {
            cout<<nums[i]<<"  ";
        }
        
        int res=0;
        for (int i = 0; i < nums.size(); i+=2)
        {
            
            res+=nums[i];
        }
        return res;
        
}