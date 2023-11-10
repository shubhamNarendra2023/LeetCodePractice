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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(root == NULL)    return postorder;
        stack<TreeNode*> st1,st2;
        st1.push(root);

        //Push in stack 1 and stack 2
        while(!st1.empty()){
            root = st1.top();
            st1.pop();
            st2.push(root);

            //Check for left element exist
            if(root->left != NULL){
                st1.push(root->left);
            }
            //Check for right element exist
            if(root->right != NULL){
                st1.push(root->right);
            }
        }

        //Transfer stack 2 all elements to postorder answer vector
        while(!st2.empty()){
            postorder.push_back(st2.top()->val);
            st2.pop();
        }

        return postorder;
    }
};