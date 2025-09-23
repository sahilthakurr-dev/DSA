#include<iostream>
#include<queue>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    };

};

node* createBinaryTree(node *& root){
    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }

    root = new node(data);
    cout<<"Enter the data in left of :"<< data<<endl;
    root->left = createBinaryTree(root->left);

    cout<<"Enter the data in right of: "<< data<<endl;
    root->right = createBinaryTree(root->right);

    return root;

}

void levelOrderInput(node* &root){
    queue<node*> q;
    cout<<"Enter the data"<<endl;
    int data;
    cin>>data;
    root = new node(data);
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        //for left
        cout<<"Enter the data for left of "<<temp->data<<endl;
        int  leftData;
        cin>>leftData;

        if(leftData != -1){
            temp->left = new node(leftData);
            q.push(temp->left);
        }

        // for right
         cout<<"Enter the data for right of "<<temp->data<<endl;
        int  rightData; 
        cin>>rightData;

        if(rightData != -1){
            temp->right = new node(rightData);
            q.push(temp->right);
        }

        
    }




}

void levelOrderTraversal(node* root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout<<endl;

            if(!q.empty()){
                q.push(NULL);
            }

        } else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }

        }
    }

}


void inOrder(node* root){
    if(root == NULL) return;
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

void preOrder(node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(node* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

int main(){
    node* root = NULL;



    root = createBinaryTree(root);

      levelOrderInput(root);

    cout << "\nLevel Order Traversal:\n";
    levelOrderTraversal(root);
    

    cout << "\nInorder Traversal:\n";
    inOrder(root);

    cout << "\nPreorder Traversal:\n";
    preOrder(root);

    cout << "\nPostorder Traversal:\n";
    postOrder(root);

    return 0;


    
}
