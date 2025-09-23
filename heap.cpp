#include<iostream>
using namespace std;

class heap{
    public:
    int arr[100];
    int size;

    heap(){
        arr[0] = -1;
        this->size = 0;
    }
    
    void insert(int val){
        size = size+1;
        int index = size;
        arr[index] = val;

       while(index>1){
        int parent = index/2;
        if(arr[parent]< arr[index]){
            swap(arr[parent], arr[index]);
            index = parent;
        } else{
            return;
        };
       };

    };

    void print(){
        for(int i = 1; i<=size; i++){
            cout<<arr[i]<<" ";
        };

    };

    void del(){
        if(size == 0) return;
        arr[1] = arr[size];
        size--;

        int index = 1;
        while(index<size){
            int left = 2* index;
            int right = 2* index +1;

            if(left< size && arr[index]<arr[left]){
                swap(arr[left], arr[index]);
                index = left;
            }else if(right< size && arr[index]<arr[right]){
                swap(arr[right], arr[index]);
                index = right;
            } else{
                return;
            }            

        }
    };
};

  void maxHeapify(int arr[], int size, int i){
        int largest = i;
        int left = 2*i;
        int right = 2* i + 1;

        if(left<=size && arr[largest]<arr[left]){
            largest = left;
        };

        if(right <=size && arr[largest]<arr[right]){
            largest = right;
        };

        if(largest!=i){
            swap(arr[largest], arr[i]);
            maxHeapify(arr, size , largest);
        };

    };

    void minHeapify(int arr[], int size, int i){
        int  smallest = i;
        int left = 2*i;
        int right =2*i + 1;

        if(left<=size && arr[smallest]> arr[left]){
            smallest = left;
        };

        if(right<=size && arr[smallest]> arr[right]){
            smallest = right;
        };

        if(smallest!=i){
            swap(arr[smallest], arr[i]);
            minHeapify(arr,size, smallest);
        }


    };

    void heapSort(int arr[], int n ){
        int size = n;

        while(size>1){
            swap(arr[size], arr[1]);
            size--;
            maxHeapify(arr, size,1);
        }
    }
int main(){

    // heap h;
    // h.insert(50);
    // h.insert(55);
    // h.insert(53);
    // h.insert(52);
    // h.insert(54);
    // h.del();
    // h.print();
    int size =5;
    int arr[6] = {-1, 54,53,55,52,50};

     for(int i = 5/2 ; i>0; i--){
        maxHeapify(arr,5,i);
     }
    heapSort(arr, 5);

     cout<<"Printing the max Heap"<<endl;

     for(int i = 1; i<=size;i++){
        cout<<arr[i]<<" ";
     };
    
    //  for (int i = 5/2; i>0; i--)
    //  {
    //     minHeapify(arr,5,i);
    //  }
     
    //  cout<<"Printing the min Heap"<<endl;

    //  for( int i = 1; i<=size;i++){
    //     cout<<arr[i]<<" ";
    //  }


    return 0;
}

