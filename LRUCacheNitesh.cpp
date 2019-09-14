class Node{
    public:
    Node* next;
    Node* prev;
    int key_;
    int val;
    Node(int key1, int val1): key_(key1), val(val1), prev(NULL), next(NULL){
        
    }
    int getValue() {
        return val;
    }
    
    int getKey() {
        return key_;
    }
    
    void putVal(int val1) {
        val=val1;
    }
};
class LRUCache {
public:
    map<int, Node*> hash;
    int cap;
    Node* head;
    Node* tail;
    int cnt;
    LRUCache(int capacity) {
        head=new Node(0,0);
        tail=new Node(0,0);
        head->next=tail;
        tail->prev=head;
        cnt=0;
        cap=capacity;
    }
    void addNode(Node* node) {
        node->prev=head;
        node->next=head->next;
        
        head->next->prev=node;
        head->next=node;
        
    }   
    
    void removeNode(Node* node) {
        Node* prev=node->prev;
        Node* next=node->next;
        
        prev->next=next;
        next->prev=prev;
    }
    
    void moveToHead(Node* node) {
        // All the recently accessed node will be in the front
        removeNode(node);
        addNode(node);
    }
    Node* popTail() {
        Node* prev=tail->prev;
        removeNode(prev);
        return prev;
    }
    int get(int key) {
        
        // First find the value
        
        if(hash.find(key) != hash.end()) {
            //cout<<hash.size();
            Node* temp=hash.find(key)->second;
            moveToHead(temp);
            return temp->getValue(); 
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        Node* node;
        if(hash.find(key) == hash.end()) node=NULL;
        else{
            node=hash.find(key)->second;
        }
        
        if(!node) {
            node=new Node(key, value);
            hash.insert(make_pair(key,node));
            addNode(node);
            ++cnt;
            
            if(cnt> cap) {
                Node* popd=popTail();
                hash.erase(popd->getKey());
                --cnt;
            }
            
        }
        else {
            node->putVal(value);
            moveToHead(node);
        }
        
        
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
