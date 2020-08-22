#include<stdio.h>
#include<stdlib.h>

int findDigits(int num);
int compare(const void *a, const void *b){
    int num1, num2, r1, r2, d1, d2 ,i;
    num1 = *(int *) a;
    num2 = *(int *) b;
    d1 = findDigits(num1);
    d2 = findDigits(num2);
        printf("Num1- %d  num2- %d ------", num1, num2);

    while(d2>0){
        num1*=10;
        num1+=((num2/d2)%10);
        d2 /=10;
    }
    r1 = num1;
    num1 = *(int *) a;
    while(d1>0){
        num2*=10;
        num2+=((num1/d1)%10);
        d1 /=10;
    }
    printf("Num1- %d  num2- %d \n", r1, num2);

    return num2 - r1;
    
}
int findDigits(int num){
    int count=1;
    while(num/10 >0){
        num/=10;
        count*=10;
        
    }
    // printf("count -- %d \n", count);
    return count;
}

int main(){
    // compare(85788 ,22);
    // findDigits(85788);
    int arr[]= {1, 34, 3, 98, 9, 978,76, 45};
    qsort(arr, 8, sizeof(int), compare);
    for(int i=0; i<8; i++) printf("%d -", arr[i]);
}