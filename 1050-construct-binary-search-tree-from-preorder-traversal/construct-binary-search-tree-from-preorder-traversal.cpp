/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return buildTree(preorder,i,INT_MAX);
        
    }
    TreeNode* buildTree(vector<int>& a, int& i, int bound){
        if(i==a.size() || a[i]>bound) return nullptr;
        TreeNode* newNode=new TreeNode(a[i++]);
        newNode->left=buildTree(a,i,newNode->val);
        newNode->right=buildTree(a,i,bound);
        return newNode;
    }
};