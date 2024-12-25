#include<stack>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

 //迭代法
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        std::stack<TreeNode*> st;
        if(root == nullptr) return 0;
        st.push(root);
        int result = 0;
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->left != nullptr && node->left->left == nullptr && node->left->right == nullptr){
                result += node->left->val;
            }
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return result;
    }
};