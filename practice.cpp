#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Tree Node
struct Node {
    char data;
    Node* left;
    Node* right;
    Node(char val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to check if a character is operator
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

// 1️⃣ Construct Expression Tree from Prefix Expression
Node* constructTreeFromPrefix(string prefix) {
    stack<Node*> st;

    // Read from right to left
    for (int i = prefix.size() - 1; i >= 0; i--) {
        char c = prefix[i];
        Node* node = new Node(c);

        if (isOperator(c)) {
            // Pop two operands
            Node* leftNode = st.top(); st.pop();
            Node* rightNode = st.top(); st.pop();

            node->left = leftNode;
            node->right = rightNode;
        }

        // Push current node to stack
        st.push(node);
    }

    // Root of expression tree
    return st.top();
}

// 2️⃣ Non-Recursive Postorder Traversal
void postorderNonRecursive(Node* root) {
    if (root == nullptr) return;

    stack<Node*> s1, s2;
    s1.push(root);

    while (!s1.empty()) {
        Node* curr = s1.top();
        s1.pop();
        s2.push(curr);

        if (curr->left)
            s1.push(curr->left);
        if (curr->right)
            s1.push(curr->right);
    }

    cout << "\nPostorder Traversal: ";
    while (!s2.empty()) {
        cout << s2.top()->data << " ";
        s2.pop();
    }
    cout << endl;
}

// 3️⃣ Delete entire tree
void deleteTree(Node* root) {
    if (root == nullptr) return;
    deleteTree(root->left);
    deleteTree(root->right);
    cout << "Deleting node: " << root->data << endl;
    delete root;
}

// 4️⃣ Mirror the tree (swap left and right)
void mirrorTree(Node* root) {
    if (root == nullptr) return;
    swap(root->left, root->right);
    mirrorTree(root->left);
    mirrorTree(root->right);
}

int main() {
    string prefix = "+--a*bc/def";
    cout << "Prefix Expression: " << prefix << endl;

    Node* root = constructTreeFromPrefix(prefix);

    postorderNonRecursive(root);

    cout << "\nMirroring the tree..." << endl;
    mirrorTree(root);

    cout << "\nAfter Mirroring, Postorder Traversal: ";
    postorderNonRecursive(root);

    cout << "\nDeleting tree..." << endl;
    deleteTree(root);

    return 0;
}
