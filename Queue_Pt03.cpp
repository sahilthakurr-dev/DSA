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
        frontIndex = -1;
        rear = -1;
    }

    //pushing element
     void push(int data){
        if(frontIndex == 0 && rear == size-1 || rear == frontIndex-1 % size-1){
            cout<<"Queue is full"<<endl;
        } else if(frontIndex == -1){
            frontIndex = rear = 0;

        } else if(rear == size-1 && frontIndex != 0){
            rear = 0;

        } else{
            rear++;
        }

         arr[rear] = data;

    }
  // poping element
    void pop(){
       if(frontIndex == -1){
        cout<<"Queue is empty"<<endl;
       } else if(frontIndex == size-1){
        frontIndex = 0;
    
       } else if(frontIndex == rear){
        frontIndex = rear = -1;

       } else{
        frontIndex++;
       }
    };

    bool isEmpty(){
        if(frontIndex == -1 && rear == -1){
            return true;
        } else{
            return false;
        }
    }

    int getFront(){
        if(frontIndex == -1 && rear == -1){
            return -1;
        } else{
            return arr[frontIndex];

        }
    }
    int back(){
        if(frontIndex == -1 && rear == -1){
            return -1;
        } else{
            return arr[rear];

        }
    }

    void print(){
        int i = frontIndex;
        while(true){
            cout<<arr[i]<<endl;
            if(i== rear) break;
            i = (i+1) % size;
        }
    }


};
int main(){
    queue q(5);
   
    q.push(10);
    q.push(5);
    q.push(10);
    q.push(5);
    q.push(10);
   
    
   

    // cout<<q.getFront()<<endl;

    
    q.pop();
    q.print();
    cout<<q.getFront()<<endl;
    cout<<q.back()<<endl;

    

        
}