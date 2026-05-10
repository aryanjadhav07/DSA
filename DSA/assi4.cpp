#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

struct Node {
    string key;
    string value;
    Node* left;
    Node* right;
    int height;
    Node(string k, string v) {
        key = k;
        value = v;
        left = right = nullptr;
        height = 1;
    }
};

// Utility function to get height of tree
int height(Node* root) {
    return root ? root->height : 0;
}

// Utility function to get balance factor
int getBalance(Node* root) {
    if (!root) return 0;
    return height(root->left) - height(root->right);
}

// Right Rotation (LL)
Node* rightRotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left Rotation (RR)
Node* leftRotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

// Insert (key, value) into AVL tree
Node* insert(Node* root, string key, string value) {
    if (root == nullptr)
        return new Node(key, value);

    if (key < root->key)
        root->left = insert(root->left, key, value);
    else if (key > root->key)
        root->right = insert(root->right, key, value);
    else {
        cout << "Duplicate key not allowed!\n";
        return root;
    }

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Get balance factor
    int balance = getBalance(root);

    // Balancing the tree
    if (balance > 1 && key < root->left->key) // LL
        return rightRotate(root);
    if (balance < -1 && key > root->right->key) // RR
        return leftRotate(root);
    if (balance > 1 && key > root->left->key) { // LR
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    if (balance < -1 && key < root->right->key) { // RL
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Find node by key
Node* find(Node* root, string key, int &comparisons) {
    if (root == nullptr)
        return nullptr;
    comparisons++;
    if (key == root->key)
        return root;
    else if (key < root->key)
        return find(root->left, key, comparisons);
    else
        return find(root->right, key, comparisons);
}

// Get minimum node
Node* minValueNode(Node* root) {
    Node* curr = root;
    while (curr->left)
        curr = curr->left;
    return curr;
}

// Delete node by key
Node* deleteNode(Node* root, string key) {
    if (root == nullptr) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        // Node found
        if (!root->left || !root->right) {
            Node* temp = root->left ? root->left : root->right;
            if (!temp)
                temp = root, root = nullptr;
            else
                *root = *temp;
            delete temp;
        } else {
            Node* temp = minValueNode(root->right);
            root->key = temp->key;
            root->value = temp->value;
            root->right = deleteNode(root->right, temp->key);
        }
    }

    if (!root) return root;

    // Update height
    root->height = 1 + max(height(root->left), height(root->right));

    // Balance
    int balance = getBalance(root);

    // LL
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
    // LR
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    // RR
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
    // RL
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }

    return root;
}

// Display dictionary in Ascending order (Inorder)
void displayAscending(Node* root) {
    if (!root) return;
    displayAscending(root->left);
    cout << root->key << " : " << root->value << endl;
    displayAscending(root->right);
}

// Display dictionary in Descending order
void displayDescending(Node* root) {
    if (!root) return;
    displayDescending(root->right);
    cout << root->key << " : " << root->value << endl;
    displayDescending(root->left);
}

// Count maximum comparisons (height)
int maxComparisons(Node* root) {
    return height(root);
}

// 🌳 Main Menu
int main() {
    Node* root = nullptr;
    int choice;

    do {
        cout << "\n=== Dictionary using AVL Tree ===\n";
        cout << "1. Insert (key, value)\n";
        cout << "2. Find a key\n";
        cout << "3. Delete a key\n";
        cout << "4. Display Ascending Order\n";
        cout << "5. Display Descending Order\n";
        cout << "6. Show Maximum Comparisons\n";
        cout << "7. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        string key, value;
        int comps = 0;

        switch (choice) {
            case 1:
                cout << "Enter key: ";
                cin >> key;
                cout << "Enter value: ";
                cin >> value;
                root = insert(root, key, value);
                break;
            case 2:
                cout << "Enter key to find: ";
                cin >> key;
                comps = 0;
                {
                    Node* res = find(root, key, comps);
                    if (res)
                        cout << "Found! Value = " << res->value << " (Comparisons: " << comps << ")\n";
                    else
                        cout << "Key not found! (Comparisons: " << comps << ")\n";
                }
                break;
            case 3:
                cout << "Enter key to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                break;
            case 4:
                cout << "\nDictionary (Ascending Order):\n";
                displayAscending(root);
                break;
            case 5:
                cout << "\nDictionary (Descending Order):\n";
                displayDescending(root);
                break;
            case 6:
                cout << "Maximum Comparisons (Height): " << maxComparisons(root) << endl;
                break;
            case 7:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice!\n";
        }
    } while (choice != 7);

    return 0;
}
