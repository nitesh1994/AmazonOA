/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node() {}

    Node(int _val, Node* _next, Node* _random) {
        val = _val;
        next = _next;
        random = _random;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        
        unordered_map<Node*, Node*> mp;
        
        Node* temp=head;
        
        while(temp!=NULL){
            mp[temp]=new Node(temp->val, temp->next, temp->random);
            temp=temp->next;
        }
        
        unordered_map<Node*,Node*>::iterator it=mp.begin();
        for(;it!=mp.end();++it){
            if(it->second->next!=NULL)
                it->second->next=mp[it->second->next];
            if(it->second->random!=NULL)
                it->second->random=mp[it->second->random];
        }
        
        return mp[head];
    }
};
