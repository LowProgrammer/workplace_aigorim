/**
 * this file include some methods used mostly
 * */
#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

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
    
}/**
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