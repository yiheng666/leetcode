void PreOrder(Bitree T){
	if (T){
		visit(T);
		PreOrder(T->left);
		PreOrder(T->right);
	}
}
