#include<iostream>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

Node* newNode(int val){
    Node* node = new Node();
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

Node* insert(Node* root, int val){
    if(root == NULL){
        return newNode(val);
    }
    if(val < root->data){
        root->left = insert(root->left, val);
    }
    else if(val > root->data){
        root->right = insert(root->right, val);
    }
    return root;
}

int longestPath(Node* root){
    if(root == NULL){
        return 0;
    }

    int leftHeight = longestPath(root->left);
    int rightHeight = longestPath(root->right);
    return max(leftHeight, rightHeight) + 1;
}

int findMin(Node* root){
    if(root == NULL){
        cout << "Tree is empty." << endl;
        return -1;
    }

    while(root->left != NULL){
        root = root->left;
    }
    return root->data;
}

bool search(Node* root, int key){
    if(root == NULL){
        return false;
    }
    if(root->data == key){
        return true;
    }
    else if(key < root->data){
        return search(root->left, key);
    }
    else{
        return(root->right, key);
    }
}

void inorder(Node* root){
    if(root == NULL){
        return;
    }

    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main(){
    Node* root = NULL;

    int values[] = {50, 30, 70, 20, 40, 60, 80};
    for(int v : values){
        root = insert(root, v);
}

    cout << "Inorder Traversal : ";
    inorder(root);
    cout << endl;

    root = insert(root, 25);
    cout << "After inserting 25 : ";
    inorder(root);
    cout << endl;

    cout << "Number of nodes in longest path : "<< longestPath(root) << endl;

    cout << "Minimum value : " << findMin(root) << endl;

    int key = 60;
    if(search(root, key)){
        cout << "Key found." << endl;
    }
    else{
        cout << "Key not found." << endl;
    }

    return 0;
}


