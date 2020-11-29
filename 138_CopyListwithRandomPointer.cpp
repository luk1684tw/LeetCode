#include <iostream>
#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> hashTable;
        Node* temp = head;
        while (temp != nullptr) {
            Node* newNode = new Node(temp->val);
            hashTable[temp] = newNode;
            temp = temp->next;
        }
        temp = head;
        while (temp != nullptr) {
            hashTable[temp]->random = hashTable[temp->random];
            hashTable[temp]->next = hashTable[temp->next];
            temp = temp->next;
        }
        return hashTable[head];
    }
};