#include<iostream>
#include<vector>
using namespace std;
struct TreeNode {
    int val;
    vector<TreeNode*>children;
    TreeNode(int v){
        this->val = v;
    }
};
double maxSumAvg(TreeNode* root, TreeNode** res, double& val, int& size){
    if(root == NULL)
        return 0;
    if(root->children.empty())
        return 0;
    else{
        double subtreeSum = 0;
        for(int i=0;i<root->children.size();i++){
            subtreeSum += maxSumAvg(root->children[i], res, val, size);
        }
        
        double sum = 0;
        double avg =0;
        int currentSize=0;
        if(subtreeSum==0){
            for(int i=0;i<root->children.size();i++){
                TreeNode* temp = root->children[i];
                sum=sum+temp->val;
            }
            
            sum=sum+root->val+subtreeSum;
            currentSize= 1+root->children.size();
            avg = sum/currentSize;
        }
        else{
            sum=sum+root->val+subtreeSum;
            currentSize= 1+size;
            avg = sum/currentSize;
        }
        cout<<subtreeSum<<"\n";
        if(avg > val){
            val = avg;
            *res = root;
        }
        if(subtreeSum==0)
        size = size + currentSize;
        else 
        size=currentSize;
        cout<<root->val<<" "<<sum<<" "<<size<<" "<<currentSize<<" "<<avg<<"\n";
        return sum;
    }
}

void printTree(TreeNode* root){
    
    if(!root) return;
    cout<<root->val<<'\t';
    for(int i=0;i<root->children.size();++i){
        printTree(root->children[i]);
    }
}
int main() {
	//cout<<"GfG!";
	
	TreeNode* root = new TreeNode(2000);
	TreeNode* root1 = new TreeNode(12);
	TreeNode* root2 = new TreeNode(18);
	TreeNode* root3 = new TreeNode(11);
	TreeNode* root4 = new TreeNode(2);
	TreeNode* root5 = new TreeNode(3);
	TreeNode* root6 = new TreeNode(15);
	TreeNode* root7 = new TreeNode(8);
	TreeNode* root8 = new TreeNode(200);
	TreeNode* root9 = new TreeNode(100);
	root->children.push_back(root1);root->children.push_back(root2);
	root1->children.push_back(root3);root1->children.push_back(root4);root1->children.push_back(root5);
	root2->children.push_back(root6);root2->children.push_back(root7);
	root5->children.push_back(root8);
	root5->children.push_back(root9);
	printTree(root);
	TreeNode* res = NULL;
	double val = 0;
	int size = 0;
	double ans = maxSumAvg(root,&res,val,size);
	if(res)
	cout<<res->val;
	return 0;
}
