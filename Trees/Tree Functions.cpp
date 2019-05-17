#include <algorithm>
#include <climits>
#include <deque>
#include <iostream>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#define LN cout << __LINE__ << endl

using namespace std;

struct Node {
    int data;
    Node *left, *right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    queue<Node *> q;
    q.push(root);
    q.push(NULL);  // NULL will seperate different levels

    Node *cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (cur == NULL) {
            cout << endl;
            if (!q.empty()) {  // Dont push a NULL after the last level NULL
                q.push(NULL);
            }
            continue;
        }

        cout << cur->data << " ";

        if (cur->left != NULL) {
            q.push(cur->left);
        }
        if (cur->right != NULL) {
            q.push(cur->right);
        }
    }
}
// For Reverse Level Order Traversal, push right child in queue first. And instead of printing, save the node in a
// stack/vector and start printing from the end of the vector ( or top of stack).

// levelOrderInsert method 1
// if you want to skip nodes, you can modify it to only make a new node if arr[i] != -1
Node *levelOrderInsert(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    Node *root = new Node(arr[0]);
    queue<pair<Node *, int> > q;
    q.push({root, 0});

    Node *curNode;
    int curIdx;
    while (!q.empty()) {
        curNode = q.front().first;
        curIdx = q.front().second;
        q.pop();

        if (2 * curIdx + 1 < n) {
            curNode->left = new Node(arr[2 * curIdx + 1]);
            q.push({curNode, 2 * curIdx + 1});
        }

        if (2 * curIdx + 2 < n) {
            curNode->right = new Node(arr[2 * curIdx + 2]);
            q.push({curNode, 2 * curIdx + 2});
        }
    }

    return root;
}

// levelOrderInsert method 2
Node *levelOrderInsertAlternative(int arr[], int n) {
    if (n == 0) {
        return NULL;
    }

    Node *root = new Node(arr[0]);
    queue<Node *> q;
    q.push(root);
    int idx = 1;

    Node *cur;
    while (!q.empty()) {
        cur = q.front();
        q.pop();

        if (idx < n) {
            cur->left = new Node(arr[idx++]);
            q.push(cur->left);
        }

        if (idx < n) {
            cur->right = new Node(arr[idx++]);
            q.push(cur->right);
        }
    }

    return root;
}

// iterative InOrder Traversal
void iterativeInOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    stack<Node *> s;
    Node *cur = root;

    while (cur != NULL || !s.empty()) {
        while (cur != NULL) {
            s.push(cur);
            cur = cur->left;
        }

        if (!s.empty()) {
            cur = s.top();
            s.pop();

            cout << cur->data << " ";
            cur = cur->right;
        }
    }

    cout << endl;
}

// iterative preOrder Traversal
void iterativePreOrderTraversal(Node *root) {
    if (root == NULL) {
        return;
    }

    stack<Node *> s;
    s.push(root);

    Node *cur;
    while (!s.empty()) {
        cur = s.top();
        s.pop();

        cout << cur->data << " ";
        if (cur->left != NULL) {
            s.push(cur->left);
        }
        if (cur->right != NULL) {
            s.push(cur->right);
        }
    }

    cout << endl;
}

int main() {
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    return 0;
}