#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
typedef struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 }TreeNode,*Tree;
/**
 * 中序遍历
 * */

void getMidSort(Tree root){
     if(root){
         getMidSort(root->left);
         cout<<"  "<<root->val<<" ";
         getMidSort(root->right);
     }
 }
/**
 * 前序遍历
 * 
 * */
 void getPreSort(Tree root){
     if(root){
         getPreSort(root->left);
         cout<<"  "<<root->val<<" ";
         getPreSort(root->right);
     }
 }
/**
 * 后序遍历
 * */
  void getPostSort(Tree root){
     if(root){
         getPostSort(root->left);
         cout<<"  "<<root->val<<" ";
         getPostSort(root->right);
     }
 }
