#include<iostream>

using namespace std;

class queue{
    public:
    int * arr;
    int front;
    int rear;
    int size;
// creating constructor
    queue(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push_front(int val){
        if((front == 0 && rear == size-1) || ( rear == (front- 1+ size)%size)){
            cout<<"Queue is full"<<endl;
        } else if(front == -1){
            front = rear = 0;
        } else if(front == 0 && rear != size -1){
            front = size-1;
        } else {
            front--;
        }
        arr[front] = val;
    }

     void push_rear(int val){
        if((front == 0 && rear == size-1) || ( rear == (front- 1+ size)%size)){
            cout<<"Queue is full"<<endl;
        } else if(front == -1 ){
            front = rear = 0;
        } else if(front != 0 && rear == size-1){
            rear = 0;
        } else {
            rear++;
        }
        arr[rear] = val;
    };

    int pop_front(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        } else if(front == size-1){
            front = 0;
        } else if(front == rear){
            front = rear = -1;
        } else {
            front--;
        }
        return arr[front];
    }

     int pop_back(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        } else if(rear == 0){
            rear = size-1;
        } else if(front == rear){
            front = rear = -1;
        } else {
            rear--;
        }
        return arr[rear];
    }

    bool isEmpty(){
        if(front == -1 && rear == -1){
            return true;
        } else{
            return false;
        }
    }

    int get_front(){
        if(isEmpty()){
            return -1;
        } else{
            return arr[front];
        }
    }

    int get_back(){
        if(isEmpty()){
            return -1;
        } else{
            return arr[rear];
        }
    }

    void print(){
         int i = front;
        while(true){
            cout<<arr[i]<<" ";
            if(i == rear) break;
            i = (i+1)% size;

        }
        cout<<endl;
    }
};
int main(){

   queue q(5);
   q.push_front(5);
   q.push_rear(6);
   q.push_rear(10);
   q.push_front(5);

   
   q.print();
   q.pop_back();
   cout<<q.get_front()<<endl;
   cout<<q.get_back()<<endl;
   q.print();
 

}