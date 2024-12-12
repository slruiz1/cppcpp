#include <bits/stdc++.h>

#if 0
5 2
set 1 2
set 2 3
set 3 0
get 2
get 3
#endif

using namespace std;

struct Node{
   Node* prev;
   Node* next;
   int key;
   int value;
   Node(Node* p, Node* n, int k, int val):prev(p),next(n),key(k),value(val){};
   Node(int k, int val):prev(NULL),next(NULL),key(k),value(val){};
};

class Cache{
   
   protected: 
   virtual ~Cache() = default;

   map<int,Node*> mp{}; //map the key to the node in the linked list
   int cp{0};  //capacity
   Node* tail{nullptr}; // double linked list tail pointer
   Node* head{nullptr}; // double linked list head pointer
   virtual void set(int, int) = 0; //set function
   virtual int get(int) = 0; //get function

};

class LRUCache : public Cache {
public:
    LRUCache(int cap) : Cache() {
        cp = cap;
        head = nullptr;
        tail = nullptr;
    }
    virtual ~LRUCache() {
        for (map<int,Node*>::iterator iter = mp.begin();
            iter != mp.end(); ++iter) {
            delete iter->second;
        }
    }
    void set(int,int) override;
    int get(int) override;
};

void LRUCache::set(int key, int val) {
    map<int,Node*>::iterator iter = mp.find(key);
    if (iter != mp.end()) {
        if (iter->second) {  // hit!
            iter->second->value = val; // set value
        }
    } else {
        if (mp.size() == (size_t)cp && tail) {
            // remove last recently used node
            mp.erase(tail->key);
            if (head == tail) {
                delete tail;
                head = tail = nullptr;
            } else {
                Node* node = tail;
                tail = node->prev;
                tail->next = node->next;
                delete node;                
            }
        }
        Node* node = new Node(key, val); // miss!
        iter = mp.insert(iter, make_pair(key, node));
        if (head) {
            node->next = head;
            head->prev = head->prev;
            head->prev = node;
        }
        head = node;
        if (!tail)
            tail = head;
    }
}

int LRUCache::get(int key) {
    int val = -1;
    map<int,Node*>::const_iterator citer = mp.find(key);
    if (citer != mp.end()) {
        Node* node = citer->second;
        if (node) {
            val = node->value;
            // move to the head of the list if needed
            if (head != node) {
                if (node->prev)
                    node->prev->next = node->next;
                if (node->next)
                    node->next->prev = node->prev;
                node->next = head;
                head->prev = head->prev;
                head->prev = node;                
            }
        }
    }
    return val;
}

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
