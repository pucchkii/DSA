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
    int countNodes(TreeNode* root) {
        if(root==nullptr) return 0;

        int lh=findHLeft(root);
        int rh=findHRight(root);

        if(lh==rh) return (1<<lh)-1;

        return 1+countNodes(root->left)+countNodes(root->right);
        
    }
    int findHLeft(TreeNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->left;
        }
        return cnt;
    }
    int findHRight(TreeNode* node){
        int cnt=0;
        while(node){
            cnt++;
            node=node->right;
        }
        return cnt;
    }
};