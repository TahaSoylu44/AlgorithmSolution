#include <bits/stdc++.h>

using namespace std;

class Node
{
    public:
        pair<int, int> mypair;
        Node* prev;
        Node* next;

        Node(int key, int value)
        {
            mypair.first = key;
            mypair.second = value;
            prev = nullptr;
            next = nullptr;
        }
};

class DoublyLinkedList
{
    public:
        Node* head = nullptr;
        Node* tail = nullptr;

        void moveToHead(Node* node)
        {
            if (node == head) return;

            if (node == tail)
            {
                Node* before_tail = tail->prev;
                before_tail->next = nullptr;
                tail->next = head;
                head->prev = tail;
                tail->prev = nullptr;
                head = tail;
                tail = before_tail;
                return;
            }

            node->prev->next = node->next;
            node->next->prev = node->prev;
            node->next = head;
            head->prev = node;
            head = node;
        }

        void addToHead(Node* node)
        {
            if (head == nullptr)
            {
                head = node;
                tail = head;
                return;
            }

            node->next = head;
            head->prev = node;
            head = node;
        }

        void deleteTail()
        {
            if (head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }

            Node* beforeLast = tail->prev;
            delete tail;
            tail = beforeLast;
            tail->next = nullptr;
        }

        void deleteHead()
        {
            if (head == tail)
            {
                delete head;
                head = nullptr;
                tail = nullptr;
                return;
            }

            Node* beDeleted = head;
            head = head->next;
            head->prev = nullptr;
            delete beDeleted;
        }

        void deleteNode(Node* node)
        {
            if (node == head) 
            {
                deleteHead();
                return;
            }

            if (node == tail) 
            {
                deleteTail();
                return;
            }

            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }
};

class LRUCache {
public:
    int capacity;
    map<int, Node*> lrumap;
    DoublyLinkedList mylist;

    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) 
    {
        if (lrumap.count(key))
        {
            mylist.moveToHead(lrumap[key]);
            return lrumap[key]->mypair.second;
        }
        return -1;
    }
    
    void put(int key, int value) 
    {
        if (lrumap.count(key))
        {
            mylist.deleteNode(lrumap[key]);
            Node* node = new Node(key, value);
            lrumap[key] = node;
            mylist.addToHead(node);
            return;
        }

        if (lrumap.size() == capacity)
        {
            int prohibited_key = mylist.tail->mypair.first;
            lrumap.erase(prohibited_key);
            mylist.deleteTail();
        }

        Node* newNode = new Node(key, value);
        lrumap.insert({key, newNode});
        mylist.addToHead(newNode);
    }
};

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    LRUCache* obj = new LRUCache(2);
    obj->put(1,1);
    obj->put(2,2);
    std::cout << obj->get(1);

    obj->put(3,3);

    std::cout << obj->get(2);
    
    return 0;
}