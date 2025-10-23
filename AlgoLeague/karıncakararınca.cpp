#include <iostream>
#include <vector>

using namespace std;

struct Node{
    int number;
    vector<Node*> nodeArray;
};

int main() {
    int numOfNodes;
    cin >> numOfNodes;

    int arr[numOfNodes - 1];
    
    int location;
    cin >> location;

    Node* node;

    Node* tmp = new Node;
    tmp->number = 0;
    int counter = 1;

    for (int i = 0; i < numOfNodes - 1; i++)
    {
        node = new Node;
        node->number = counter;
        (tmp->nodeArray).push_back(node);
        counter++;
    }
    



    return 0;
}