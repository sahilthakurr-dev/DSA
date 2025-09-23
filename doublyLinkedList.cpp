#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* previous;
    Node* next;

    //creating constructor

    Node(int data){
        this->data = data;
        this->next = NULL;
        this->previous = NULL;
    }

  ///creating destructor
    ~Node() {
    int value = this->data;
    if(next!= NULL){
        delete next;
        next = NULL;
    }
    cout<<"Memory is free for node with data"<< value<<endl;
}
};


//insert at head

void insertAtHead(Node* &head, Node* & tail, int data){
    //if list is empty
    if (head == NULL)
    {
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
    }else{
        Node * temp = new Node(data);
    temp->next = head;
    head->previous = temp;
    head = temp;
    }
    
}

//insert at tail

void insertTail(Node* &tail, Node* &head, int data){
  if (tail == NULL)
  {
   Node * temp = new Node(data);
   tail = temp;
   head = temp;

  } else{
      Node* temp = new Node(data);
    tail->next = temp;
    temp->previous = tail;
    tail = temp;
  }
  

}

//insert at position

void insertAtPosition(Node* &head, Node* &tail, int position, int data){
    Node * temp = head;
    int count = 1;
//if position is at one add the data in first position and update the head
    if(position ==1){
        insertAtHead(head,tail, data);
        return;
    }

    while(count<position-1){
        temp = temp->next;
        count++;

    }
//if we have to add the add the data in last we have to udpate the tail and add the data
    if(temp->next == NULL){
        insertTail(tail, head, data);
        return;
    }

// now create the new node and add the data in given position
Node* nodeToInsert = new Node(data);
nodeToInsert->next = temp->next;
temp->next->previous = nodeToInsert;
temp->next = nodeToInsert;
nodeToInsert->previous = temp;


}

// deletion at position

void deletionAtPosition(Node* &head, Node* &tail, int position) {
    // Case 1: Delete head node
    if (position == 1) {
        Node* temp = head;
        temp->next->previous = NULL;
        head = temp->next;
        temp->next = NULL;
        delete temp;
        return;

    
    }

    // Case 2: Delete from middle or end
    int count = 1;
    Node* curr = head;
    Node* prev = NULL;

    while (count < position) {
        prev = curr;
        curr = curr->next;
        count++;
    }

    // If position is out of bounds
    if (curr == NULL) {
        cout << "Invalid position" << endl;
        return;
    }

    // If deleting the last node
    if (curr->next == NULL) {
        tail = prev;
    } else {
        curr->next->previous = prev;
    }

    prev->next = curr->next;
    curr->next = NULL;
    curr->previous = NULL;
    delete curr;
}


//printing the list

void print(Node* & head){
    Node* temp = head;
    while (temp != NULL)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<"NULL";
    cout<<endl;
}
       

// function to know the length of link list

int length(Node* &head){
    int length = 0;
    Node* temp = head;

    while(temp != NULL){
        length ++;
        temp = temp-> next;
    }
    return length;
}
    





int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    // inserting at head
    insertAtHead(head,tail,5);
    // // // inserting at tail
    insertTail(tail, head,15);
    insertTail(tail,head,25);
    // // // inserting at position
    // insertAtPosition(head,tail,4,20);
    //deletion at position
    deletionAtPosition(head,tail,4);
    //printing the list
    print(head);
    //data of head and tai
    cout<<"Head is: "<<head->data<<endl;
    cout<<"Tail is: "<<tail->data<<endl;
    int size = length(head);
    cout<<"Length of the list is: "<<size<<endl;

    


}