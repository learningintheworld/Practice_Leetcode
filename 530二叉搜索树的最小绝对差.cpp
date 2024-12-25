#include<stack>
#include<climits>
#include<algorithm>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int getMinimumDifference(TreeNode* root) {
        std::stack<TreeNode*> st;
        TreeNode* cur = root;
        TreeNode* pre  = nullptr;
        int result = INT_MAX;
        while(cur != nullptr || !st.empty()){
            if(cur != nullptr){
                st.push(cur);
                cur = cur->left;
            }else{
                cur = st.top();
                st.pop();
                if(pre != nullptr){
                    result = std::min(result, cur->val - pre->val);
                }
                pre = cur;
                cur = cur->right;
            }
        }
        return result;
    }
};