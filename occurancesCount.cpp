

#include<iostream>
#include <unordered_map>
using namespace std;

// void occurancesCountHashMap(int arr[], int size) {
//     unordered_map<int, int> countMap;

//     for (int i = 0; i < size; i++) {
//         countMap[arr[i]]++;
//     }

//     for (auto pair : countMap) {
//         cout << pair.first << " occurs " << pair.second << " times in hash map" << endl;
//     }
// }

void occurancesCount(int arr[], int size){

     bool isChecked[5]={false};
     
    for (int i = 0; i < size; i++)
    {
        if (isChecked[i])
        {
           continue;
        }
        int element = arr[i];
        int count =1;

        for (int  j = 0; j < size; j++)
        {
           if (i==j || isChecked[j] )
           {
          continue;
           }

           if (element == arr[j])
           {
            count++;
            isChecked[j] = true;   
            }
           
           
        }

        isChecked[i] = true;
        cout<<arr[i]<<" occures "<<count<< " times"<<endl;
        

        
    }
    


}

void printingArray(int arr[],int size){
    cout<<"PRINTING ARRAY";
    for (int  i = 0; i <size; i++)
    {
        cout<<" "<<arr[i]<<" ";
    }
    
}

int main(){
    int arr[5]= {1,1,1,2,2}; 
    // output = 1->3, 2->2

    occurancesCount(arr,5);
    // occurancesCountHashMap(arr,5);
    printingArray(arr,5);
}






