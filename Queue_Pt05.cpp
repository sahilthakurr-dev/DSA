#include<iostream>
#include<vector>
using namespace std;

class  queue{
    public:
    int *arr;
    int val;
    int size;
    int k;
    int freeSpot;
    int * next;
    int * front;
    int* rear;

    queue(int size, int k){
        this->k = k;
        this->size  = size;
        arr = new int[size];
        next = new int[size];
        front = new int[k];
        rear = new int[k];
        freeSpot = 0;

        //setting up the all necessary  arrays

        for(int i = 0;i<size;i++){
            next[i] = i+1;
        };

        next[size - 1] = -1;

        for(int i =0;i<k;i++){
            front[i] = -1;
             rear[i] = -1;
        }

        
        
    }

    //pushing element

     void push(int val, int q){
         if(freeSpot == -1){
             cout<<"Queue is full"<<endl;
             return;
            }
            int index = freeSpot;
            freeSpot = next[index];
        //if element appeared first time
        if(front[q-1] == -1){
            front[q-1] = index;
        } else{
            next[rear[q-1]] = index;
        };
        next[index] = -1;
        rear[q-1] = index;
        arr[index] = val;

    };

    int  pop(int q){
        if(front[q-1] == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }

        int index = front[q-1];
        //increase the front
        front[q-1] = next[index];
        next[index] = freeSpot;
        freeSpot = index;
        return arr[index];
    }

    void print(){
        for (int i = 0; i < size; i++)
        {
            cout<<arr[i]<<endl;
        }
        
    }

    int first( int q){
        if(front[q-1] == -1){
            return -1;
        } else{
            return arr[front[q-1]];
        }
    }

        

};
 int main(){
    queue q(5,3);

    q.push(10,1);
    q.push(20,2);
    q.push(30,1);

   cout<< q.pop(1)<<endl;
   cout<< q.pop(2)<<endl;
   cout<<q.first(1)<<endl;
 
    
 }