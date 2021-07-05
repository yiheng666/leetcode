//PreOrder
void preorderTraversal(TreeNode* root){
	if (root){
		visit(root);
		PreOrder(root->left);
		PreOrder(root->right);
	}
}
//PreOrder
void preorderTraversal(TreeNode* root){
	stack<TreeNode*> st;
	auto p = root;
	while (p || st.empty()){
		if (p){
			st.push(p);
			visit(p->val);
			p = p->left;
		}
		else{
			auto node = st.top();
			st.pop();
			p = node->right;
		}
	}
}

