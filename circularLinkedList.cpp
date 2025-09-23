#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        int value = this->data;
        if (this->next != NULL) {
            delete next;
            next = NULL;
        }
        cout << "Memory of the node with data " << value << " is deleted" << endl;
    }
};

// inserting the element in the last
void insertNode(Node* &tail, int element, int data) {
    if (tail == NULL) {
        Node* newNode = new Node(data);
        tail = newNode;
        newNode->next = newNode;
    } else {
        //assusming that element is present in the list
        //empty list
        
        // for non empty list
        Node* temp = tail;

        while(temp->data != element){
            temp = temp->next;
        }

        //element found
        //now creating new node 
        Node* newNode = new Node(data);
        newNode->next = temp->next;
        temp->next = newNode;
        tail = newNode;
    }
      
}


//deletion of list

void deleteNode(Node* & tail, int value){

    if(tail == NULL){
        cout<<"List is empty "<<endl;
        return;
    } else{
     int count = 0;
    Node* prev = tail;
    Node* curr = prev->next;

   

    while(curr->data !=value){
        prev = curr;
        curr = curr->next;

    }
    // we got the element
    
    prev->next = curr->next;

    //if there is only one node
    if(curr== prev){
        tail = NULL;

    }

    // for node greater and equal to 2
    if(tail == curr){
        tail = prev;
    }
    curr->next = NULL;
    delete curr;
    }

    


    

}

        
        
        


// printing the list
void print(Node* tail) {
    if (tail == NULL) return;

    Node* temp = tail->next;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != tail->next);
    cout << endl;
}

int main() {
    Node* tail = NULL;

    insertNode(tail, 10, 10); // empty list so 10 is added
    print(tail);
    cout << "Tail is " << tail->data << endl;

    insertNode(tail, 10, 20);
    print(tail);
    cout << "Tail is " << tail->data << endl;

    insertNode(tail, 20, 30);
    print(tail);
    cout << "Tail is " << tail->data << endl;

    // insertNode(tail, 20, 25);
    // print(tail);
    // cout << "Tail is " << tail->data << endl;

    return 0;
}
