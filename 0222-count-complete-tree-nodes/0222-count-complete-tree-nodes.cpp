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
 #include<cmath>
class Solution {
public: 
    ///formula to count nodes in a perfect tree =  2^(n-1) - 1 where n = height+1 ( ie height plus the root)
    int countingNodes(TreeNode* root){
        int count = 0;
        if(root == NULL){
            return count;
        }
        int nl = 0;
        int nr = 0;

        TreeNode* temp = root;
        while(temp -> left != NULL){
            nl++;
            temp = temp -> left;
        }

        temp = root;
        while(temp -> right != NULL){
            nr++;
            temp = temp -> right;
        }

        //nl and nr count the no of nodes on the left and right of root. to include the root we increment 1,
        nl++;
        nr++;

        if(nl == nr){
            count += (pow(2,nl) - 1);
            return count;
        }
        else{
            count++;
            count += countingNodes(root -> left);
            count += countingNodes(root -> right);
        }
        return count;
    }

    int countNodes(TreeNode* root) {
        return countingNodes(root);
    }
};