/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<int, int> left;
    unordered_map<int, int> right;
    
    void maxLeft(TreeNode* root, int curr, int level) {
        if(!root) return;
        if (left.find(level) == left.end()) {
            left[level] = curr;
        } else {
            if(curr > left[level]) {
                left[level] = curr;
            }
        }
        
        maxLeft(root->left, curr*2, level + 1);
        maxLeft(root->right, curr*2 - 1, level + 1);
    }
    
    void maxRight(TreeNode* root, int curr, int level) {
        if(!root) return;
        if (right.find(level) == right.end()) {
            right[level] = curr;
        } else {
            if(curr > right[level]) {
                right[level] = curr;
            }
        }
        
        maxRight(root->left, curr*2-1, level + 1);
        maxRight(root->right, curr*2, level + 1);
    }
    
    int helper(TreeNode* root, int start) {
        maxLeft(root->left, 1, 1);
        maxRight(root->right, 1, 1);
        int max = 0;
        for(unordered_map<int, int>::iterator it = left.begin(); it != left.end(); it++) {
            int key = it->first;
            int value = it->second;
            
            if (right.find(key) == right.end()) {
                continue;
            }
            
            int temp = value + right[key];
            max = temp > max? temp : max;
        }
        left.clear();
        right.clear();
        return max;
    }
    
    int widthOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int c = 1;
        if(root->left && root->right) c = helper(root, root->val);
        int l = widthOfBinaryTree(root->left);
        int r = widthOfBinaryTree(root->right);
        return max(c, max(l,r));
    }
};
