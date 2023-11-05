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
    void inTraversal(TreeNode* root, vector<int> &v){
        if(root == nullptr) return;
        inTraversal(root->left,v);
        v.push_back(root->val);
        inTraversal(root->right,v);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> v;
        inTraversal(root,v);
        return v;
    }
};