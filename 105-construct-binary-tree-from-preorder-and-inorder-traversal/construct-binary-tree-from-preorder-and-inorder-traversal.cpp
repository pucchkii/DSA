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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int> mpp;
        for(int i=0 ; i<inorder.size() ; i++){
            mpp[inorder[i]]=i;
        }

        if(preorder.size()!=inorder.size()){
            return nullptr;
        }

        return buildTreePreIn(preorder,0,preorder.size()-1,
                                inorder,0,inorder.size()-1,mpp);
        
    }
    TreeNode* buildTreePreIn(vector<int>& preorder,int ps, int pe, 
                            vector<int>& inorder,int is, int ie,
                            map<int,int> &mpp){
        if(ps>pe || is>ie) return nullptr;
        TreeNode* root= new TreeNode(preorder[ps]);

        int inRoot=mpp[root->val];
        int numsLeft=inRoot-is;

        root->left=buildTreePreIn(preorder,ps+1,ps+numsLeft,inorder,is,inRoot-1,mpp);
        root->right=buildTreePreIn(preorder,ps+numsLeft+1,pe,inorder,inRoot+1,ie,mpp);

        return root;
    }
};