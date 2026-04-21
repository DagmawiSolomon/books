#include <stdio.h>


void merge(int left[],int lsize, int right[],int rsize, int arr[]){
  int i=0, j=0, k=0;

  while(i<lsize && j<rsize){
     if (left[i] <= right[j]) arr[k++] = left[i++];
        else arr[k++] = right[j++];
    }

    while (i < lsize) arr[k++] = left[i++];
    while (j < rsize) arr[k++] = right[j++];
}
void mergeSort(int* arr, int size){
  if(size <= 1) return;

  int mid = size / 2;
  int left[mid];
  int right[size-mid];

  for (int i = 0; i < mid; i++){
    left[i] = arr[i];
  }

  for (int i=mid; i<size; i++){
    right[i-mid] = arr[i];
  }

  mergeSort(left, mid);
  mergeSort(right, size-mid);

  merge(left, mid, right, size-mid, arr);

}

int main() {
    int arr[] = {5, 2, 8, 1, 3};
    int size = 5;

    mergeSort(arr, size);

    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
}
