
    if(preorder.empty())return NULL;
    vector<int>::iterator ite=preorder.begin();
    root=new TreeNode(*ite++);
    // for (;ite<preorder.end();ite++)
    // {
    //     createTreePre(root,preorder,ite);
    // }
    for (int i = 1; i <len; i++)
    {
        createTreePre(root,preorder,i,len);
    }
    
    return root;        
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