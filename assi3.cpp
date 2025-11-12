#include<iostream>
#include<stack>
#include<string>
using namespace std;

struct Node{
    char data;
    Node* left;
    Node* right;

    Node(char val){
        data = val;
        left = right = NULL;
    }
};


bool isOperator(char c){
    return (c == '+'|| c == '-'|| c == '*'|| c == '/' || c == '^');
}

Node* constructTreePree(string pree){
    stack<Node*> st;
    for(int i = pree.size() - 1; i >= 0; i--){
        char c = pree[i];
        Node* node = new Node(c);

        if (isOperator(c)){

                Node* leftNode = st.top();
                st.pop();
                Node* rightNode = st.top();
                st.pop();

                node->left = leftNode;
                node->right = rightNode;
        }
        st.push(node);
    }
    return st.top(); 
}

void inorderTrav(Node* root){
    if(root == NULL) return;
    inorderTrav(root->left);
    cout << root->data << " ";
    inorderTrav(root->right);
}

void inorderNonRecursive(Node* root){
    stack<Node*> st;
    Node* curr = root;
    cout << "Inorder Traversal : ";
    while(curr != NULL || !st.empty()){
        while(curr != NULL){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        cout << curr->data << " ";
        curr = curr->right;
    }
    cout << endl;
}

void preorderTrav(Node* root){
    if(root == NULL) return;
    cout << root->data << " ";
    preorderTrav(root->left);
    preorderTrav(root->right);
}

void preorderNonRecursive(Node* root){
    if(root == NULL) return;

    stack<Node*> st;

    st.push(root);

    cout << "Preorder Traversal : ";

    while(!st.empty()){
        Node* curr = st.top();
        st.pop();
        cout << curr->data << " ";

        if(curr->right){
            st.push(curr->right);
        }
        if(curr->left){
            st.push(curr->left);
        }

    }
    cout << endl;
}

void postOrderTrav(Node* root){
    if(root == NULL) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while(!s1.empty()){
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if(curr->left){
            s1.push(curr->left);
        }
        if(curr->right){
            s1.push(curr->right);
        }
    }

    cout << "PostOrder Traversal : ";
    while(!s2.empty()){
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;

}

void postOrderNonRecursive(Node* root){
    if(root == NULL) return;

    postOrderNonRecursive(root->left);
    postOrderNonRecursive(root->right);
    cout << root->data << " ";
}

void mirrorTree(Node* root){
    if(root == NULL) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main(){

    string pree = "+--a*bc/def";

    cout << "Prefix Expression : " << pree << endl;

    Node* root = constructTreePree(pree);
    postOrderTrav(root);
    postOrderNonRecursive(root);

    cout << "Inorder Traversal : ";
    inorderTrav(root);

    cout << endl;

    cout << "Inorder Non-Recursive : ";
    inorderNonRecursive(root);

    cout << endl;

    cout << "Preorder Non-Recursive : ";
    preorderNonRecursive(root);

    cout << endl;

    cout << "Preorder Traversal : ";
    preorderTrav(root);

    cout << "\nMirroring the tree..." << endl;
    
    mirrorTree(root);

    cout << "After mirroring ";
    postOrderTrav(root);

    cout << "After mirroring inorder : ";
    inorderTrav(root);

    cout << endl;
    preorderTrav(root);

    return 0;
}