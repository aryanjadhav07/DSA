#include <bits/stdc++.h>
using namespace std;

struct Node {
    int id, salary;
    Node *left, *right;

    Node(int i, int s) {
        id = i;
        salary = s;
        left = right = NULL;
    }
};

// Insert new employee
Node* insert(Node* root, int id, int salary) {
    if (!root) return new Node(id, salary);

    if (id < root->id)
        root->left = insert(root->left, id, salary);
    else
        root->right = insert(root->right, id, salary);

    return root;
}

// Search employee
Node* search(Node* root, int id) {
    if (!root) return NULL;
    if (root->id == id) return root;
    if (id < root->id) return search(root->left, id);
    return search(root->right, id);
}

// Display in sorted order
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << "ID: " << root->id << ", Salary: " << root->salary << endl;
    inorder(root->right);
}

// Find minimum salary employee
Node* findMinNode(Node* root) {
    if (!root) return NULL;
    while (root->left) root = root->left;
    return root;
}

// Find maximum salary employee
Node* findMaxNode(Node* root) {
    if (!root) return NULL;
    while (root->right) root = root->right;
    return root;
}

// Height
int height(Node* root) {
    if (!root) return 0;
    return 1 + max(height(root->left), height(root->right));
}

// Count internal nodes (non-leaf)
int countInternal(Node* root) {
    if (!root || (!root->left && !root->right))
        return 0;
    return 1 + countInternal(root->left) + countInternal(root->right);
}

int main() {
    Node* root = NULL;
    int choice;

    do {
        cout << "\n--- Employee Record System (BST) ---\n";
        cout << "1. Insert new employee\n";
        cout << "2. Search employee by ID\n";
        cout << "3. Find min and max salary\n";
        cout << "4. Display all employees (sorted)\n";
        cout << "5. Display height and internal nodes\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            int id, salary;
            cout << "Enter employee ID: ";
            cin >> id;
            cout << "Enter salary: ";
            cin >> salary;
            root = insert(root, id, salary);
        }
        else if (choice == 2) {
            int id;
            cout << "Enter ID to search: ";
            cin >> id;
            Node* res = search(root, id);
            if (res)
                cout << "Employee Found, Salary: " << res->salary << endl;
            else
                cout << "Employee not found.\n";
        }
        else if (choice == 3) {
            Node* minN = findMinNode(root);
            Node* maxN = findMaxNode(root);
            cout << "Minimum Salary: " << minN->salary << endl;
            cout << "Maximum Salary: " << maxN->salary << endl;
        }
        else if (choice == 4) {
            inorder(root);
        }
        else if (choice == 5) {
            cout << "Height: " << height(root) << endl;
            cout << "Internal nodes: " << countInternal(root) << endl;
        }
        else if (choice == 6) {
            cout << "Exiting...\n";
        }
        else {
            cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
