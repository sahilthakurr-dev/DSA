#include<iostream>

using namespace std;

class queue{
 
    
    public:
    int * arr;
    int size;
    int frontIndex;
    int rear;
    queue(int size){
        this->size = size;
        arr = new int[size];
        frontIndex = 0;
        rear = 0;
    }

    //pushing element
     void push(int data){
        if(rear == size){
            cout<<"Queue is full"<<endl;

        } else{
            arr[rear] = data;
            rear++; 
        }

    }
  // poping element
    void pop(){
        if(frontIndex == rear){
            cout<<"No element to pop"<<endl;
        } else{
            arr[frontIndex] = -1;
            frontIndex++;
            if(frontIndex == rear){
                frontIndex = 0;
                rear = 0;
            }
        

        }
    };

    bool isEmpty(){
        if(frontIndex == rear){
            return true;
        } else{
            return false;
        }
    }

    int getFront(){
        if(frontIndex == rear){
            return -1;
        } else{
            return arr[frontIndex];

        }
    }
    int back(){
        if(frontIndex == rear){
            return -1;
        } else{
            return arr[rear-1];

        }
    }


};
int main(){
    queue q(5);
    q.push(5);
    q.push(10);
   

    // cout<<q.getFront()<<endl;
    q.pop();
    // cout<<q.getFront()<<endl;
    // cout<<q.back()<<endl;

    

        
}