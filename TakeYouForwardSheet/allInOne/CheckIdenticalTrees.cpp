bool identicalTrees(TreeNode* p,TreeNode* q){
    if((p == NULL && q != NULL) || (p != NULL && q == NULL)){
        return false;
    }
    if(p == NULL && q == NULL){
        return true;
    }
    if(p->val != q->val){
        return false;
    }
    return (identicalTrees(p->left,q->left) && identicalTrees(p->right,q->right));
}