/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if (!root){
            return "#,";
        }
        string ans = to_string(root->val) + ",";
        ans += serialize(root->left);
        ans += serialize(root->right);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        stringstream ss(data);
        string item;
        while (getline(ss,item,','))
            q.push(item);
        return deser(q);
    }
    TreeNode* deser(queue<string> &q){
        string s = q.front();
        q.pop();
        if (s == "#"){
            return NULL;
        }
        TreeNode* root = new TreeNode(stoi(s));
        root->left = deser(q);
        root->right = deser(q);
        return root;
    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));