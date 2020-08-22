#include <stdio.h>
#include <limits.h>

#define max(a, b) a>b ? a : b
#define size(p) (sizeof(p)/sizeof(*p))

void getTripletSum(int * ptr, int n){
  int max_triplet[3] = {INT_MIN};
  for(int i=0; i<n; i++){

    if( ptr[i] > max_triplet[0]) {
      max_triplet[2] = max_triplet[1];
      max_triplet[1] = max_triplet[0];
      max_triplet[0] = ptr[i];
    }else if(ptr[i] > max_triplet[1]) {
      max_triplet[2] = max_triplet[1];
      max_triplet[1] = ptr[i];
    }else if(ptr[i] > max_triplet[2])
      max_triplet[2] = ptr[i];
  }

  int sum = max_triplet[0]+max_triplet[1]+max_triplet[2];
  printf("Max triplet sum = %d", sum);
  printf("[%d, %d, %d]", *max_triplet, *(max_triplet+1), *(max_triplet+2));
}

int main(void){
  int arr[] = {1, 2, 3, 0, -1, 8, 10};

  getTripletSum(arr, size(arr));

}