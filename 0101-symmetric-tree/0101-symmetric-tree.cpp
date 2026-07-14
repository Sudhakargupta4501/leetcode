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
  bool Miror(TreeNode* A , TreeNode* B)
  {
if(A == NULL && B == NULL) return true;

if(A == NULL || B == NULL)
return false;

if(A->val != B->val) return false;

return Miror(A->left,B->right) && Miror(A->right, B->left);

  }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return Miror(root->left,root->right);
    }
};