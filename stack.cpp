// #include<iostream>
// // #include<stack>

// using namespace std;

// class Stack{

    
//     public:
//     //properties
    
//     int top;
//     int size;
//     int *arr;
//     Stack(int size){
//         this->size = size;
//         arr = new int[size];
//         top = -1;
//     }
//     //function 
    
//    void push(int data){
//     if(size-top > 1){

//         top++;
//         arr[top] = data;
//     } else{
//         cout<<"Stack is overflow"<<endl;
//     }
    
    
//     }

//     void pop(){
//         if(top >= 0){
//             top--;
            
//         } else{
//             cout<<"No element to pop"<<endl;
//         }
     

//     }

//     int peek(){
//        if(top >=0 ){
//              return arr[top];
//        } else{
//         cout <<"No element"<<endl;
//         return -1;
        
//        }
//     }
    
//     bool isEmpty(){
//         if(top == -1){
//             return true;
//         } else{
//             return false;
//         }
//     }


//     //creating destructor

//     ~ Stack(){
//         cout<<"lol"<<endl;
//         delete arr;

//     }

// };

// int main(){
// //     stack<int> s;
// //     // s.push(2);
// //     // s.push(3);
// //     // s.pop();
// //     s.top();
// // //    int size =  s.size();

//         Stack st(5);
//         st.push(22);
//         st.push(43);
//         st.push(44);
//         st.pop();
//         st.pop();
//         st.pop();
        


//         cout<<st.peek()<<endl;
//         cout<<st.isEmpty()<<endl;


       
  

// }


#include<iostream>
using namespace std;

class stack{
     
    public:
    struct Node {
        int data;
        Node* next;
    };

  Node* head;    
    public:
    
    //creating constructor 
    stack(){
        head = NULL;
    }   
  
    // creating function
    
    void push(int data){
        Node * newNode = new Node();
        newNode->data = data;
        newNode->next = head;
        head = newNode;
    }

    int pop(){
        Node* temp = head;
        int val = head->data;
        head = temp->next;
        delete temp;
        return val;
        
        
    };

    int top(){
        if(head==NULL){

         return -1;
        } else{
            return head->data;
        };
    }
    
    //creating destructor
    ~stack() {
    Node* temp = head;
    while (temp != nullptr) {
        Node* next = temp->next;
        delete temp;
        temp = next;
    }
}


    

};
int main(){
    stack st;

    st.push(10);
    st.push(20);
    cout<<st.pop()<<endl;
    cout<<st.top()<<endl;

   cout<<st.top()<<endl;

}