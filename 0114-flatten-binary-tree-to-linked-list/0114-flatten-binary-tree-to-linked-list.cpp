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
    vector<TreeNode*> preorder;
    void preorderArray(TreeNode* root){
        if(root == NULL){
            return;
        }
        preorder.push_back(root);
        preorderArray(root->left);
        preorderArray(root->right);
    }
    void flatten(TreeNode* root) {
        preorderArray(root);
        int n = preorder.size();
        
        TreeNode* temp = root;
        for (int i = 0; i < n; i++) {
            preorder[i]->left = NULL;

            if (i + 1 < n){ 
                preorder[i]->right = preorder[i + 1];
            }
            else{
                preorder[i]->right = NULL;
            }
        }
    }
};