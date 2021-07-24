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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return build(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1);
    }
    TreeNode* build(vector<int>& inorder,int inLeft,int inRight,vector<int>& postorder,int postLeft,int postRight){
        if (inLeft > inRight || postLeft > postRight) return nullptr;
        int val = postorder[postRight],index= -1;
        for (int i=inLeft;i<=inRight;i++){
            if (val == inorder[i]){
                index = i;
                break;
            }
        }
        TreeNode* root = new TreeNode(val);
        root->left = build(inorder,inLeft,index-1,postorder,postLeft,postLeft+index-inLeft-1);
        root->right = build(inorder,index+1,inRight,postorder,postLeft+index-inLeft,postRight-1);
        return root;
    }
};