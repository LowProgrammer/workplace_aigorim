package com.utils;

import java.util.ArrayList;
import java.util.List;

/**
 * @author feifei
 * @Classname Aigorim
 * @Description TODO
 * @Date 2019/9/23 18:32
 * @Created by 陈群飞
 */
public class Aigorim {


    /**
     * @author feifei
     * @param arr
     * @param low
     * @param heigh
     * @Description TODO 数组快排
     * @Date 2019/9/23 18:53
     * @Created by 陈群飞
     * @return
     */
   public static void quick_sort(int arr[], int low, int heigh){
        if (low < heigh)
        {
            int pos = partition(arr, low, heigh);
            quick_sort(arr, low, pos - 1);
            quick_sort(arr, pos + 1, heigh);
        }
   }
   private static int partition(int arr[], int low, int heigh){
       int tmp = arr[low];
       while (low < heigh){
            while (arr[heigh] >= tmp && low < heigh){
                heigh--;
            }
            arr[low] = arr[heigh];
            while (arr[low] <= tmp && low < heigh) {
                low++;
            }
            arr[heigh] = arr[low];
       }
       arr[low] = tmp;
       return low;
   }


   public List<Integer> getDigit(int num){
       List<Integer> result=new ArrayList<Integer>();
       int n=num,i=0;
       while (n>0){
           result.add(n%10);
           n=n/10;
       }
       return result;
   }
}
