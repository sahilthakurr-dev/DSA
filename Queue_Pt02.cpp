//QUEUE IMPLEMENTATION USING LINKED LIST
#include<iostream>
using namespace std;

class queue{
    public:


    struct Node
    {
      int data;
      Node* next = NULL;
      //creating constructor for node
      Node(int data){
        this->data = data;
        this->next = NULL;
    }

};
Node* frontIndex;
Node* rear;

// creating constructor for queue
   queue(){
    frontIndex = NULL;
    rear = NULL;
}


   void push(int data){
     Node* newNode = new Node(data);
     if(frontIndex == NULL){
        frontIndex = newNode;
        rear = newNode;
     } else{
        rear->next = newNode;
        rear = newNode;
     } 

    }

    void pop(){
        if(frontIndex == NULL || rear == NULL){
            cout<<"queue is empty"<<endl;
        } else{
            Node* temp = frontIndex;
            int val = temp->data;
            frontIndex = temp->next;
            delete temp;
        }
    };

    bool isEmpty(){
        if(frontIndex == NULL && rear == NULL){
            return 1;
        } else{
            return 0;
        }
    };

    int front(){
        if(frontIndex == NULL){
            return -1;
        } else{
            return frontIndex->data;
        }
    };

    int back(){
        if(rear == NULL){
            return -1;
        } else{
            return rear->data;
        }
    };

  //creating destructor

  
 ~queue() {
        while (frontIndex != NULL) {
            Node* temp = frontIndex;
            frontIndex = frontIndex->next;
            cout<<"deleting node"<< temp->data<<endl;
            delete temp;
        }
        rear = NULL;
    }


    
};
int main(){
    queue q;
    q.push(5);
    q.push(10);
    q.push(15);

    // q.pop();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    

}