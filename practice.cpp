//input for the BST

#include<iostream>
using namespace std;


class node{
    public : 
    int data;
    node* left;
    node*right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};


node* insertBT(node* root){
    int data;
    cin>>data;
    if(data == -1) return NULL;

    root = new node(data);

    cout<<"Enter the data for left of"<<root->data<<endl;
    root->left = insertBT(root->left);
     cout<<"Enter the data for right of"<<root->data<<endl;
     root->right = insertBT(root->right);

     return root;

}


node* insertInBST(node*&root, int data){
    if(data == -1){
        return NULL;
    };

    if(root == NULL){
        root = new node(data);
        return root;
    };

    if(data < root->data){
        root->left = insertInBST(root->left, data);
    }
    if(data> root->data){
        root->right = insertInBST(root->right, data);
    }   

    return root;

}
void takeInput(node* &root){
    int data;
    cout<<"Enter the data"<<endl;
    cin>>data;
      
    while(data!= -1){
        insertInBST(root,data);
        cin>>data;
    }
    
}

void print(node* root){
    if(root == NULL) return;
    print(root->left);
    cout<<root->data<<" ";
    print(root->right);


}

int main(){

    node* root = NULL;
    // takeInput(root);

    // //printint the bst

    // cout<<"Printing the BST"<<endl;
    cout<<"Enter the data"<<endl;
    root = insertBT(root);
    print(root);




    return 0;
}