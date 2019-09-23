package com.utils;

/**
 * @author feifei
 * @Classname Aigorim
 * @Description TODO
 * @Date 2019/9/23 18:32
 * @Created by 陈群飞
 */
public class Aigorim {

    private static int partition(int arr[], int low, int heigh)
    {
        int tmp = arr[low];
        while (low < heigh)
        {
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
   public static void quick_sort(int arr[], int low, int heigh)
    {
        if (low < heigh)
        {
            int pos = partition(arr, low, heigh);
            quick_sort(arr, low, pos - 1);
            quick_sort(arr, pos + 1, heigh);
        }
    }
}