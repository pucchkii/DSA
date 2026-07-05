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
class BSTIterator{
    stack<TreeNode*> myStack;

    bool reverse=true;
public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse=isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode* curr=myStack.top();
        myStack.pop();
        if(!reverse) pushAll(curr->right);
        else pushAll(curr->left);
        return curr->val;
    }
private:
    void pushAll(TreeNode* root){
        for(; root!=nullptr; ){
            myStack.push(root);
            if(reverse){
                root=root->right;
            }else{
                root=root->left;
            }
        }
    }
};
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        //next
        BSTIterator l(root,false);
        //for before
        BSTIterator r(root,true);
        
        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j==k) return true;
            else if(i+j<k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};