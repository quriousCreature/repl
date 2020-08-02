#include <stdio.h>
#define max(a, b) a>b ? a : b
#define size(p) (sizeof(p)/sizeof(*p))

void getTripletSum(int * ptr, int n){
  int max_triplet[3] = {ptr[0],ptr[1],ptr[2]};
  for(int i=3; i<n; i++){
    if(int)
  }

  int sum = max_triplet[0]+max_triplet[1]+max_triplet[2];
  printf("Max triplet sum = %d", sum);
}

int main(void){
  int arr[] = {1, 2, 3, 0, -1, 8, 10};

  getTripletSum(arr, size(arr));

}