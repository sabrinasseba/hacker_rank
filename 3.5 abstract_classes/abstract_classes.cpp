#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
#include <set>
#include <cassert>
using namespace std;

struct Node{
   Node* next;
   Node* prev;
   int value;
   int key;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   map<int,Node*> mp; //map the key to the node in the linked list
   int cp;  //capacity
   Node* tail; // double linked list tail pointer
   Node* head; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
    LRUCache(int capacity) {
        cp = capacity;
        head = nullptr;
        tail = nullptr;
    }

    void set(int key, int value) override {
        // Se ja estiver na cache
        if (mp.find(key) != mp.end()) {
            Node* node = mp[key];
            node->value = value;
            // Move node para o topo (mais recentemente usado)
            remove(node);
            insertAtFront(node);
        } else {
            // Se a cache esta cheia
            if (mp.size() == cp) {
                // Remove o menos recentemente usado (tail)
                mp.erase(tail->key);
                remove(tail);
            }
            // Cria novo node e adiciona no inicio
            Node* node = new Node(key, value);
            insertAtFront(node);
            mp[key] = node;
        }
    }

    int get(int key) override {
        if (mp.find(key) == mp.end()) return -1;
        Node* node = mp[key];
        // Move node para o topo (mais recentemente usado)
        remove(node);
        insertAtFront(node);
        return node->value;
    }

private:
    void remove(Node* node) {
        if (node->prev) node->prev->next = node->next;
        else head = node->next;

        if (node->next) node->next->prev = node->prev;
        else tail = node->prev;
    }

    void insertAtFront(Node* node) {
        node->next = head;
        node->prev = nullptr;
        if (head) head->prev = node;
        head = node;
        if (!tail) tail = head;
    }
};


int main() {
   int n, capacity,i;
   cin >> n >> capacity;
   LRUCache l(capacity);
   for(i=0;i<n;i++) {
      string command;
      cin >> command;
      if(command == "get") {
         int key;
         cin >> key;
         cout << l.get(key) << endl;
      } 
      else if(command == "set") {
         int key, value;
         cin >> key >> value;
         l.set(key,value);
      }
   }
   return 0;
}