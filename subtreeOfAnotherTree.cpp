class Solution {
public:
    
    
    bool isSubtree(TreeNode* s, TreeNode* t) {
     
        if(!s || !t) return s == t;
        return check(s, t) ? true : isSubtree(s->left, t) || isSubtree(s->right, t);
    }
    
    bool check(TreeNode* s, TreeNode* t){
        if(!s || !t) return s == t;
        return s->val == t->val ? check(s->left, t->left) && check(s->right, t->right) : false;
    }
};
