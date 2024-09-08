//WAP TO SORT THE 5 NAME USING INSERTION SORT
#include<stdio.h>
#include<string.h>
 int main()
 {
    int i,j,n=3,a[3],key;
     printf("\n enter arry \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",a[i]);
    }
    printf("\n unsorted =");
    for ( i=0; i<n;i++)
    {
        printf("\n %d",a[i]);
    }
    for (i=0;i<n;i++);
    {
        key=a[i];
        for (j=i-1;j>=0 && a[i]>key;j--)
        {
            a[j+1]=a[j];
        }
        a[j+1]=key;
    }
    printf("\n sorted =");
    for ( i=0; i<n;i++)
    {
        printf("\n %d",a[i]);
    }
    
 }