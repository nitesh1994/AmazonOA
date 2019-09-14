struct Node {
    int key;
    int val;
    Node *p, *n;
    Node(int k, int v) :key(k), val(v), p(NULL), n(NULL) {};
};

class LRUCache {
private:
    int capacity;
    int size;
    unordered_map<int, Node*> lTable;
    Node *head, *tail;
public:
    LRUCache(int cap) {
        capacity = cap;
        size = 0;
        head = NULL;
        tail = NULL;
    }
    
    int get(int key) {
        if (lTable.find(key) != lTable.end()) {
            moveToHead(lTable[key]);
            return head->val;
        }
        return -1;
    }
    
    void moveToHead(Node *n) {
        if (n == head) return;
        else if (n == tail) {
            tail = n->p;
            n->p->n = NULL;
            n->p = NULL;
            n->n = head;
            head->p = n;
            head = n;
        } else {
            Node *prev = n->p;
            Node *next = n->n;
            prev->n = next;
            next->p = prev;
            n->p = NULL;
            n->n = head;
            head->p = n;
            head = n;
        }
    }
    
    void addToHead (Node *n) {
        n->p = NULL;
        n->n = head;
        head->p = n;
        head = n;
    }
    
    void removeTail () {
        tail = tail->p;
        delete (tail->n);
        tail->n = NULL;
    }
    
    void showMap () {
        unordered_map<int, Node*>::iterator it = lTable.begin();
        while(it != lTable.end()) {
            cout << it->first << ": " << it->second->key << " " << it->second->val  << endl; 
            it++;
        }
        // cout << "###\n";
    }
    
    void showQ () {
        Node *it = head;
        while (it) {
            cout << "(" << it->key << " " << it->val << ") ";
            it = it->n;
        }
        cout << "\n";
        
        it = tail;
        while (it) {
            cout << "(" << it->key << " " << it->val << ") ";
            it = it->p;
        }
        cout << "\n";
    }
    
    void put(int key, int value) {
        Node* t = new Node(key, value);
        if (size == 0) {
            head = t;
            tail = t;
            size++;
            lTable[key] = t;
        } else if (size < capacity) {
            if (lTable.find(key) != lTable.end()) {
                moveToHead(lTable[key]);
                head->val = value;
            } else {
                lTable[key] = t;
                addToHead(t);
                size++;
            }
        } else {
            if (lTable.find(key) != lTable.end()) {
                moveToHead(lTable[key]);
                head->val = value;
            } else {
                lTable[key] = t;
                addToHead(t);
                lTable.erase(tail->key);
                removeTail();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
