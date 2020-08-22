#include<stdio.h>
#include<limits.h>
#define min(a,b) (a<b ? a : b)

int minDist(int *arr, int size, int x, int y){
    int numx ,numy , min_dist=size;
    numx = numy = -1;
    for(int i=0; i<size; i++) {
        if(arr[i]==x){
            numx = i;
        }
        if(arr[i]==y) {
            numy = i;
        }
        if(numx != -1 && numy != -1){
            int dist=0;
            if(numx >= numy){
                dist = numx-numy;
                numy =-1;
            }
            if(numy > numx) {
                dist = numy -numx;
                numx=-1;
            }
            if(dist < min_dist)min_dist= dist;
        }
    }
    return min_dist;
}

int minDist2(int *arr, int size, int x, int y){
    int previous_index = -1, min_dist = size+1;

    for(int i=0; i<size; i++){
        if(arr[i]==x || arr[i]==y) {
            if(previous_index != -1 && arr[i] != arr[previous_index])
                min_dist = min(min_dist, i-previous_index);
            previous_index = i;
        }
    }
    return min_dist == size+1 ? -1 : min_dist;
}

int main() 
{ 
    int arr[] ={3, 5, 4, 2, 6,  3, 0, 0, 5, 4, 8, 3}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    int x = 3; 
    int y = 6; 
  
    printf("Minimum distance between %d and %d is %d\n", x, y, 
            minDist2(arr, n, x, 9)); 
    return 0; 
} 