class TrieNode{
    
    char st;
    bool isEnd;
    
    
    public:
    TrieNode* children[26];
    TrieNode(char c): st(c), isEnd(false) {
        for(int i=0; i<26; ++i) children[i]=NULL;
    }
    
    TrieNode* hasChar(char c) {
        return children[c-'a'];
    }
    
    bool End() {
        return isEnd;
    }
    
    void markEnd() {
        isEnd=true;
    }
    
    TrieNode* insertChar(char c) {
        
        if(children[c-'a'] != NULL) return children[c-'a'];
        
        return children[c-'a'] = new TrieNode(c);
    }
};



class WordDictionary {
public:
    /** Initialize your data structure here. */
    TrieNode* root;
    WordDictionary() {
        root= new TrieNode('\0');
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TrieNode* node=root;
        
        for(char c: word) {
            node=node->insertChar(c);
        }
        node->markEnd();
    }
    
    bool check(string word, int index, TrieNode* root) {
        
        if(index == word.size() && root && root->End() ) {
            return true;
        }
        
        if(index == word.size()) return false;
        
        if(word[index] != '.' && root && root->hasChar(word[index]) == NULL) return false;
        
        if(word[index] != '.' && root) return check(word, index+1, root->hasChar(word[index]));
        
        // There is a dot here
        bool x=false;
        for(int i=0; i<26; ++i ) {

            if(root->children[i]) {
                x=check(word, index+1, root->children[i]);
                if(x)
                    return true;
            }
            
        }
        
        return x;
        
        
    }
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        
        if(word.find('.') ==string::npos) {
            TrieNode* node=root;
            for(char c: word) {
                node=node->hasChar(c);
                if(!node) return false;
            }
            return node!=NULL && node->End();
        }
        else {
            return check(word, 0, root);
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
