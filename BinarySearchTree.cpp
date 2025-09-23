#include<iostream>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertIntoBST(Node* root, int data) {
    // base case
   if(root == NULL){
    root = new Node(data);
    return root;
   }

    if (data > root->data) { 
        // insert in right part
        root->right = insertIntoBST(root->right, data);
    } else {
        // insert in left part 
        root->left = insertIntoBST(root->left, data);
    }

    return root; 
}

void takeInput(Node*& root) {
    int data;
    cin >> data;

    while (data != -1) {
        root = insertIntoBST(root, data); 
        cin >> data;
    }
}

void print(Node*& root) {
    // level order traversal
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        Node* front = q.front();
        q.pop();

        if (front == NULL) {
            cout << endl;

            if (!q.empty()) {
                q.push(NULL);
            }
        } else {
            cout << front->data << " ";
            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
    }
};

int minVal(Node* root){
    Node* temp = root;
    while(temp->left!= NULL){
        temp = temp->left;
    };
    return temp->data;
}

int maxVal(Node* root){
    Node* temp = root;
    while(temp->right != NULL){
        temp = temp->right;
    };
    return temp->data;
}




int main() {
    Node* root = NULL;
    cout << "Enter the data for BST (-1 to stop):" << endl;
    takeInput(root);
    cout << "\nLevel Order Traversal of BST:" << endl;
    print(root);
    int mini = minVal(root);
    cout<<mini<<endl;
    int maxi = maxVal(root);
    cout<<maxi<<endl;
    cout<<"Root is :"<<root<<endl; 
}
