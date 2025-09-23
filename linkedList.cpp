#include<iostream>
using namespace std;

class Node{

    // struct ListNode{
    //     int data;
    //     ListNode* next;
    //     public:
    //      ListNode(int data){
    //         this->data = data;
    //         this->next = NULL;

    //      }

    // };

    public:
    int data;
    Node* next;

    //constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    //destructor

    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next  = NULL;
        }

        cout<<"Memory free for node with data "<<value<<endl;
    }

};

// insert at head

void insertAtHead(Node* &head, int data){

    Node* temp = new Node(data);
    temp->next = head;
    head = temp;

}

//insert at tail

void insertAtTail(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//insert at position

void insertAtPosition(Node* &head , Node* &tail, int position, int data){
    int cnt = 1;
    Node* temp = head;
    if(position == 1){
        insertAtHead(head,data);
        return;
    }
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    };

    if(temp->next == NULL){
        insertAtTail(tail,data);
        return;

    }
//creating node to insert
    Node* insertToNode = new Node(data);
    insertToNode->next = temp->next;
    temp->next = insertToNode;
}

//link list deletion


void deleteNode(int position, Node* &head, Node* tail){

    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp; 
    } else {
        Node * current = head;
        Node * previous = NULL;

        int cnt  = 1 ;
        while(cnt < position){
            previous = current;
            current = current->next;
            cnt++;
        }

        //if element is alreay last
        if(current->next == NULL){
            tail = previous;
        }



        previous->next = current->next;
        current->next = NULL; 
        delete current;
    }
}




 // Print linked list

void print(Node* head) {
    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}
    
int main(){
    Node* node1 = new Node(10);
    // cout<<node1->data<<endl;
    
    
    //set up the head
    Node* head = node1;
    Node* tail = node1;

    //inserting at head

    // insertAtHead(head,15);
    // insertAtHead(head,20);

    //inserting at tail

    // insertAtTail(tail,15);
    // insertAtTail(tail,20);

    //insert at position

    insertAtPosition(head, tail,2,15);
    insertAtPosition(head,tail,3,20);
    insertAtPosition(head,tail,4,25);
    insertAtPosition(head,tail,5,30);



    //printing after insertion

    // print(head);
    // cout<<head->data<<endl;
    // cout<<tail->data<<endl;

    //after deletion
    deleteNode(4,head, tail);

    print(head);
    cout<<head->data<<endl;
    cout<<tail->data<<endl;
    // cout<<head->data<<endl;
    // cout<<tail->data<<endl;
     
    
}
    
    
    
    

    
   



