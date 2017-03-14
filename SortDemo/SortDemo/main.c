//
//  main.c
//  SortDemo
//
//  Created by 123 on 17/3/14.
//  Copyright © 2017年 MakeKeyReuseable. All rights reserved.
//

#include <stdio.h>

void printList(int a[]){
    for (int i = 0; i<10; i++) {
        printf(" %d",a[i]);
    }
    printf("\n");
}
void bubbleSort(int a[]){
    for (int i = 0 ; i<10; i++) {
        for (int j = 9; j>i; j--) {
            if (a[j]<a[j-1]) {
                int timp = a[j-1];
                a[j-1] =a[j];
                a[j] = timp;
            }
        }
    }
}
void exchangeSort(int a[]){
    for (int i = 0; i<10; i++) {
        for (int j = 9 ; j>i; j--) {
            if (a[i]>a[j]) {
                int timp = a[i];
                a[i] =a[j];
                a[j] = timp;
            }
        }
    }
}
void selectSort(int a[]){
    for (int i = 0; i<10; i++) {
        int minIndex = i;
        for (int j = 9 ; j>i; j--) {
            if (a[j]<a[minIndex]) {
                minIndex = j;
            }
        }
        int timp = a[minIndex];
        a[minIndex] =a[i];
        a[i] = timp;
    }
}
void insertSort(int a[]){
    for (int i = 1; i<10; i++) {
        if (a[i]<a[i-1]) {
            int j = i;
            int temp = a[i];
            while (a[j-1]>temp&&j>0) {
                a[j] = a[j-1];
                j--;
            }
            a[j] = temp;
        }
    }
}
void quickSort(int a[] , int left ,int right){
    if (left>right) {
        return;
    }
    int i = left;
    int j = right;
    int p = a[i];
    while(i < j)
    {
        while(i< j && p <a[j])
        {
            j --;
        }
        a[i] = a[j];
        while(i < j && p >a[i])
        {
            i ++;
        }
        a[j] = a[i];
    }
    a[i] = p;
    quickSort(a,left,i -1);
    quickSort(a,i +1, right);
}
int main(int argc, const char * argv[]) {
    int a[] = {9,8,7,6,5,4,3,2,1,0};
    printf("初始化数组\n");
    printList(a);
//    bubbleSort(a);
//    exchangeSort(a);
//    selectSort(a);
//    insertSort(a);
    quickSort(a,0,9);
    printf("排序后数组\n");
    printList(a);
    return 0;
}
