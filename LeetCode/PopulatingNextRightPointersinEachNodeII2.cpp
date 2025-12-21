#include <iostream>

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

Node* connect(Node* root) 
{
    Node* head = root;
    
    while (head != nullptr)
    {
        Node* dummy = new Node(0);
        Node* tail = dummy;
        Node* current = head;

        while (current != nullptr)
        {
            if (current->left)
            {
                tail->next = current->left;
                tail = tail->next;
            }
            
            if (current->right)
            {
                tail->next = current->right;
                tail = tail->next;
            }

            current = current->next;
        }
        head = dummy->next;
        delete dummy;
    }
    return root;
}

int main() {
    

    return 0;
}