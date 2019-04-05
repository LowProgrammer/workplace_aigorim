#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;


void quick_sort(int arr[],int low,int heigh);
void print_arr(int a[],int size_arr);
int partition(int arr[],int low,int heigh);
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
                    id = A[i+1];i++;
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
vector<int> sortedSquares(vector<int>& A) {
    vector<int> reuslt;
    int len=A.size();
    int num[10000];
    //cout<<len<<endl;
    for(int i = 0; i < len; i++)
    {
        num[i]=A[i]*A[i];
      //  cout<<num[i]<<endl;
    }
    quick_sort(num,0,len-1);
    for(int i = 0; i < len; i++)
    {
        reuslt.push_back(num[i]);
    }
    print_arr(num,len);
    return reuslt;        
}





/**
 * dayinarr 数组打印
 * 
 * */
void print_arr(int a[],int size_arr){
    for(int i = 0; i < size_arr; i++)
    {
        cout<<a[i]<<endl;
        /* code */
    }
    
}
/**
 * kuaipai 快排
 * 
 * */
void quick_sort(int arr[],int low,int heigh){
    if(low<heigh){
        int pos=partition(arr,low,heigh);
        quick_sort(arr,low,pos-1);
        quick_sort(arr,pos+1,heigh);
    }
}
int partition(int arr[],int low,int heigh){
    int tmp=arr[low];
    while(low<heigh){
        while(arr[heigh]>=tmp&&low<heigh)heigh--;
        arr[low]=arr[heigh];
        while(arr[low]<=tmp&&low<heigh)low++;
        arr[heigh]=arr[low];
    }
    arr[low]=tmp;
    return low;
}

/***
 * maopao 冒泡
 * 
 ***/
void sort_maopao(int arr[],int size){
    for(int i = 0; i < size; i++)
    {
        for(int j = i; j < size; i++)
        {
            if(arr[i]>arr[j]){
                int te=arr[j];
                arr[i]=arr[j];
                arr[i]=te;
            }
        }
        
    }
    
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
    return 0;
}
