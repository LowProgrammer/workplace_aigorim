#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/**
 * this file include some methods used mostly
 * */
using namespace std;

#define max 100 //int2string 方法定义的树组最大值
//forech 方法打印树组 vector
template<typename T>
void printer(const T& val)
{
    cout << val << endl;
}
/**
 * dayinarr 数组打印
 * 
 * */
void print_arr(int a[], int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        if(a[i]==0)break;
        cout << a[i] << "  ";
        /* code */
    }
}
void print_arr(int *a,int rows,int cols){
    for(int i = 0; i < rows; i++)
    {
        for(int  j = 0; j < cols; j++)
        {
            cout<<*(a+cols*i+j)<<"  ";
            /* code */
        }
        cout<<endl;
        /* code */
    }
    
}
/**
 * kuaipai 快排
 * 
 * */
int partition(int arr[], int low, int heigh)
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
void quick_sort(int arr[], int low, int heigh)
{
    if (low < heigh)
    {
        int pos = partition(arr, low, heigh);
        quick_sort(arr, low, pos - 1);
        quick_sort(arr, pos + 1, heigh);
    }
}

/***
 * maopao 冒泡
 * 
 ***/
void sort_maopao(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i; j < size; i++)
        {
            if (arr[i] > arr[j])
            {
                int te = arr[j];
                arr[i] = arr[j];
                arr[i] = te;
            }
        }
    }
}
/**
 * substr 改写字符串分割 因为C++自带的分割有些麻烦
 * begin开始位置 end结束位置
 **/
string myStrSub(string s, int begin, int end)
{
    if (begin == 0)
    {
        return s.substr(begin,end);
    }
    else
    {
        return s.substr(begin,end-begin);
    }
}
/**
 * 字符串匹配分割
 * */
void mySplitString(const string &str,vector<string> &result,const string &mark){
    string::size_type pos1,pos2;
    pos2=str.find(mark);
    pos1=0;
    while(string::npos!=pos2){
        result.push_back(str.substr(pos1,pos2-pos1));

        pos1=pos2+mark.size();
        pos2=str.find(mark,pos1);
    }
    if(pos1 != str.length())
        result.push_back(str.substr(pos1));
}
/**
 * int2string 方法
 * 
 **/

string int2string(int n){
    int m=n;
    char s[max];
    char ss[max];
    int i=0,j=0;
    if(n<0){
        m=0-m;
        j=1;
        ss[0]='-';
    }
    while(m>0){
        s[i++]=m%10+'0';
        m=m/10;
    }
    s[i]='\0';
    i=i-1;
    while(i>=0){
        ss[j++]=s[i--];
    }
    ss[j]='\0';
    return ss;
}