#include <iostream>
#include <queue>

using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};


Node* connect(Node* root) {
    if (root == nullptr) return nullptr;

    queue<Node*> myqueue;
    myqueue.push(root);
    int size;

    while (!myqueue.empty())
    {
        size = myqueue.size();
        for (int i = 0; i < size; i++)
        {
            Node* node = myqueue.front();
            myqueue.pop();

            if (i != size - 1) node->next = myqueue.front();

            if (node->left) myqueue.push(node->left);
            if (node->right) myqueue.push(node->right);
        } 
    }
    return root;
} 

int main() {
    

    return 0;
}