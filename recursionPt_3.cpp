#include<iostream>
#include<string>
using namespace std;

string reverseString(string& word, int start){
    int size = word.length();

    int end =  size - start - 1;
   
    if(start>=end){
        return word;
    }

    swap(word[start], word[end]);
 
    
    return  reverseString(word, start+1);
    
}

bool isPalindrome(string& word, int start){
    int size = word.length()-1;
     int end = size - start - 1;
    //base condition
    if(size>=end){
        return true ;
    }

    if(word[start] != word[end]){
        return true;
    }

    
// recurisve relation
    return isPalindrome(word, start+1);



}

int power(int  a, int b){

 // base condition

 if(b==0) return 1;
 if(b==1) return a;
 //recursive relation3

 int ans = power(a, b/2);


 if(b&1){
     //odd
     return ans = a * ans * ans;
    } else{
    //even
  return ans = ans * ans;
}
}

void bubbleSort(int arr[], int size){
    //base condition
    if(size == 0 || size == 1) return;
    for (int i = 0; i < size-1; i++)
    {
       if (arr[i]>arr[i+1])
       {
        swap(arr[i], arr[i+1]);
       }
       
    }
    // recursive relation

    bubbleSort(arr, size-1);
}

void selectionSort(int arr[], int start, int size){
    // base condition
    if (start>=size-1) return ;
    int minIndex = start;

    for (int i = start+1; i < size; i++)
    {
       if (arr[i]<arr[minIndex])
       {
       minIndex = i;
       }
       
    };

    swap(arr[start], arr[minIndex]);
   

    return selectionSort(arr, start +1,size);

}

void insertionSort(int arr[], int start, int size) {

    // base condition
   
    if (start >= size) return;

    int key = arr[start];
    int j = start - 1;

   
    while (j >= 0 && arr[j] > key) {
        arr[j + 1] = arr[j];  // shift
        j--;
    }

    arr[j + 1] = key; 

   
    // recursive relation
    insertionSort(arr, start + 1, size);
}

    
    

    
void merge(int arr[], int start, int end){

    int mid = start + (end - start)/2;
// taking the length for both the arrays-->
    int length1 = mid - start+1;
    int length2 = end - mid;

    int *first = new int [length1];
    int *second = new int [length2];

    // copying for first array
     int mainArrayIndex = start;

    for (int i = 0; i < length1; i++)
    {
      first[i] = arr[mainArrayIndex++]; 
    }

    // copying for second array
    mainArrayIndex = mid + 1;
    for ( int i = 0; i < length2; i++)
    {
        second[i] = arr[mainArrayIndex++];
    }
    
    // sorting both the arrays

   int index1 = 0;
   int index2 = 0;
   mainArrayIndex = start;

   while (index1 < length1 && index2 < length2)
   {
    if(first[index1]< second[index2]){
        arr[mainArrayIndex++] = first[index1++];
    } else { 
         arr[mainArrayIndex++] = second[index2++];
    }
   }
// filling the rest values if left
   while (index1 < length1)
   {
        arr[mainArrayIndex++] = first[index1++];
   }
   while (index2 < length2)
   {
        arr[mainArrayIndex++] = second[index2++];
   }
   
    delete[] first;
    delete[] second;
    
    

}
    
void mergeSort(int arr[], int start, int end){

    //base case 

    if(start>=end){
        return;
    }

    int mid = start + (end-start)/2;

    //sorting left part

    mergeSort(arr,start,mid);

    // sorting right part
    
    mergeSort(arr,mid+1,end);

    //merging the arrays

    merge(arr, start,end);
}

    
    
    

int main(){
//  string word = "sahil";
//  reverseString(word, 0);
//     cout<<word<<endl;

//     string word2 = "Noon";

// bool ans = isPalindrome(word2,0);
// if(ans){
//     cout<<"Is Palindrome"<<endl;
// } else{
//     cout<<"Not a Palindrome"<<endl;
// }

// cout<<"Enter the first number"<<endl;
// int a,b;
// cin>>a;
// cout<<"Enter the second number"<<endl;
// cin>>b;

// int ans = power(a,b);
// cout<<ans<<endl;

 

int arr[5] = {2,1,4,5,3};
int size = 5;

// bubbleSort(arr, 5);
// selectionSort(arr,0,5);
// insertionSort(arr,1,5);
mergeSort(arr,0,size-1);

for (int i = 0; i < 5; i++)
{
    cout<<arr[i]<<endl;
}

}





   
    

    

