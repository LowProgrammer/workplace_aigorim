#include <stdio.h>
#include <stdlib.h>
#include <iostream>
/**
 * this file include some methods used mostly
 * */
using namespace std;
/**
 * dayinarr 数组打印
 * 
 * */
void print_arr(int a[], int size_arr)
{
    for (int i = 0; i < size_arr; i++)
    {
        cout << a[i] << endl;
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
 * 
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