#include <stdio.h>
#include <limits.h>

#define max(a, b) a>b ? a : b
#define size(p) (sizeof(p)/sizeof(*p))

void getMaxNeg(int* array, int size) {
  int max_so_far = INT_MIN;
  int max_ending_here = array[0];
  for (int i = 1; i < size; i++) {
    max_ending_here = max(max_ending_here + array[i], array[i]);
    max_so_far = max(max_ending_here, max_so_far);
    // printf("Max here %d \n", max_so_far);
  }
  printf("Max neg %d\n", max_so_far);
}

void getMaxSum(int* ptr, int n) {
  int currSum = ptr[0];
  int bestSum = ptr[0];
  for(int i=0; i<n; i++ ){
    currSum += ptr[i];
    currSum = max(ptr[i], currSum);
    // updates only when current maximum is greater than any previous best value
    bestSum = max(bestSum, currSum);
    // printf("MAX -- %d", currSum);
  }
  printf("Max contigous sum = %d \n", bestSum);
}

void getMaxIndex(int* ptr, int n) {
  int max_so_far = INT_MIN;
  int max_ending_here = ptr[0];
  int s = 0;
  int start_index =0;
  int end_index = 0;
  for(int i=0; i<n; i++){
    if(max_ending_here + ptr[i] > ptr[i]){
      max_ending_here += ptr[i];
    }else {
      max_ending_here = ptr[i]; 
      s = i;
    }
    if(max_so_far < max_ending_here) {
      start_index = s;
      max_so_far = max_ending_here;
      end_index = i;
    }

  }
  printf("Max = %d,\t Start: %d \t End: %d", max_so_far, start_index, end_index);
}

int main(void) {
  // printf("Hello World\n");
  int ptr[] = {-4,-26,-30,-101,-500,-2000,-7000};
  // getMaxSum(ptr, size(ptr));
  // getMaxNeg(ptr, size(ptr));
  getMaxIndex(ptr, size(ptr));
  return 0;
}