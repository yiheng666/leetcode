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
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return constructMax(nums,0,nums.size()-1);
    }
    TreeNode* constructMax(vector<int> &nums,int low,int high){
        if (low > high) return nullptr;
        int index=-1,max=INT_MIN;

        for (int i=low;i<=high;i++){
            if (max < nums[i]){
                max = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = constructMax(nums,low,index-1);
        root->right = constructMax(nums,index+1,high);
        return root;
    }
};