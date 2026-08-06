#include<stdio.h>
int main(){

    int arr1[5];
    int arr2[5];
    int arr3[5];

    for(int i=0; i<5; i++){
        printf("Enter values in Array 1 at index %d : ",i);
        scanf("%d",&arr1[i]);
    }

    for(int i=0; i<5; i++){
        printf("Enter values in Array 2 at index %d : ",i);
        scanf("%d",&arr2[i]);
    }

    for(int i = 0; i<5; i++){
        arr3[i]=arr1[i]+arr2[i];
        printf("Values in Array 3 after multiplication at index %d : %d\n",i,arr3[i]);
    }

    return 0;
}