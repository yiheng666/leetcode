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
        return build(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1);
    }
    TreeNode* build(vector<int>& preorder,int preLeft,int preRight,vector<int>& inorder,int inLeft,int inRight){
        if (preLeft > preRight || inLeft > inRight) return nullptr;
        int val = preorder[preLeft],index = -1;
        for (int i=inLeft;i<=inRight;i++){
            if (val == inorder[i]){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(val);
        root->left = build(preorder,preLeft+1,preLeft+index-inLeft,inorder,inLeft,index-1);
        root->right = build(preorder,preLeft+index-inLeft+1,preRight,inorder,index+1,inRight);
        return root;
    }
};