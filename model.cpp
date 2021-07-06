//PreOrder
void preorderTraversal(TreeNode* root){
	if (root){
		visit(node->val);
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

//InOrder
void inorderTraversal(TreeNode* root){
	if (root){
		PreOrder(root->left);
		visit(node->val);
		PreOrder(root->right);
	}
}

//InOrder
void inorderTraversal(TreeNode* root){
	stack<TreeNode*> st;
	auto p = root;
	while (p || st.empty()){
		if (p){
			st.push(p);
			p = p->left;
		}
		else{
			auto node = st.top();
			st.pop();
			visit(node->val);
			p = node->right;
		}
	}
}

//PostOrder
void postorderTraversal(TreeNode* root){
	if (root){
		PreOrder(root->left);
		PreOrder(root->right);
		visit(node->val);
	}
}

//PostOrder
void postorderTraversal(TreeNode* root){
	TreeNode *p,*r;
	stack<TreeNode*> st;
	p = root,r = null;
	while (p || !st.empty()){
		if (P){
			st.push(p);
			p = p->left;
		}
		else{
			p = st.top();
			if (p->right && p->right != r){
				p = p->right;
				st.push(p);
				p = p->left;
			}
			else{
				p = st.top();
				st.pop();
				visit(p->val);
				r = p;
				p = null;
			}
		}
	}
}

//binary_search
int binary_search(int[] nums, int target) {
    int left = 0, right = nums.length - 1; 
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if ( nums[mid] == target) {
            return mid;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] < target) {
            left = mid + 1;
        }
    }
    return -1;
}

int left_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if ( nums[mid] == target) {
            right = mid - 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] < target) {
            left = mid + 1;
        }
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.length || nums[left] != target)
        return -1;
    return left;
}


int right_bound(int[] nums, int target) {
    int left = 0, right = nums.length - 1;
    while(left <= right) {
        int mid = left + (right - left) / 2;
        if ( nums[mid] == target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid - 1; 
        } else if(nums[mid] < target) {
            left = mid + 1;
        }
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}