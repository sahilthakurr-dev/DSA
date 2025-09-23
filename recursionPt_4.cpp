#include<iostream>
using namespace std;

int partition(int arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;

    // Count how many elements are less than or equal to pivot
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Rearranging elements
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) i++;
        while (arr[j] > pivot) j--;

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end){
    //base condition
    if(start>=end) return;

    int p = partition(arr,start,end);
    // sort left side;
    quickSort(arr,start,p-1);
    //sort right side;
    quickSort(arr,p+1,end);
}

int main(){
    int arr[6] = {3,5,1,8,2,4};

    int size = 6;
    quickSort(arr,0,size-1);

    //printing 

    for (int i = 0; i < 6; i++)
{
    cout<<arr[i]<<endl;
}
}