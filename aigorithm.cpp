#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <sstream>
/**
 * this file include some methods used mostly
 * */
using namespace std;

#define max_len1 100 //int2string 方法定义的树组最大值
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
void print_vect(vector<int> &li){
    int len=li.size();
    for (int i = 0; i< len; i++) /* code */
    {
        cout<<li[i]<<"  ";
    }
    cout<<endl;
}
/**
 * 二维数组打印 
 * 
 * */
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
 * 从数组中得到最大的值 begin to end
 * 
 * */
int getMaxNumOfArr(int* arr,int begin,int end){
    if(begin<=end){
        int num=0, pos=begin;
        for (int i = begin; i <= end; i++)
        {
            if (*(arr + i) > num)
            {
                pos = i;
                num = *(arr + i);
            }

        }
        //cout<<"  pos: "<<pos<<endl;
        return pos;
    }
    return -1;
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
 * 有序数组二分查找 value代表查找的数值
 * */
int bs(int arr[], int t, int s, int e,int value) {
    	int lf = s;
    	int rt = e - 1;
    	// x + 3000 < t
    	while (lf < rt) {
    		int mid = lf + (rt - lf + 1) / 2;
    		int val =  value;
    		if (val < t) {
    			lf = mid;
    		}
    		else { // >= t
    			rt = mid - 1;
    		}
    	}
    	if (arr[lf]!=value) return -1;
    	return lf;
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
    char s[max_len1];
    char ss[max_len1];
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
/**
 * 十进制数字转为二进制 返回数组 和 二进制数的长度
 * */
void int2byte(int value,int arr[],int &len){
    int te=2;int i=0;
    while(value!=0){
        arr[i]=value%2;
        cout<<arr[i]<<endl;
        value=value/2;
        i++;
    }
    len=i;
    // arr[i]=value%2;
    // cout<<arr[i]<<endl;
}
/**
 * 字符串转数字
 * 
 **/
int str2int(string str){
    stringstream sstr(str);
    int num;
    sstr>>num;
    sstr.clear();
    return num;
}
int str2int(const char* str){
    return atoi(str);
}
int str2int(char str[]){
    int x;
    scanf(str,"%d",&x);
    return x;
}
/**
 * 字符串转int应该 不能超过int的范围
 * 字符串转数字
 * */
int my_str2int(string str){
    if(str.empty())return 0;
    int sign=0,len=str.length();
    if(str[0]=='-'||str[0]=='+'){
        if(str[0]=='-')
            sign=1;
        str=str.substr(1,len-1);
    }
    int po1=0,po2=0;
    int len_num=str.length();
    for(int i=0;i<len_num;i++){
        po2=str[i]-'0';
        po1=po1*10+po2;
      //  cout<<po1<<"  ";
    }
    //cout<<po1;
    return sign==1?-po1:po1;
}
/**
 * 计算以x为底n为指数的次方
 * */
int pow(int x,int n){
    if(n==0)return 1;
    int res=0;
    for(int i=1;i<=n;i++){
        res*=x;
    }
    return res;
}