#include<queue>

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//  //递归法
// class Solution {
// public:
//     int getdepth(TreeNode* node){
//         if(node == nullptr) return 0;
//         int leftdepth = getdepth(node->left);
//         int rightdepth = getdepth(node->right);
//         int depth = 1 + max(leftdepth, rightdepth);
//         return depth;
//     }
// public:
//     int maxDepth(TreeNode* root) {
//         return getdepth(root);
//     }
// };

//迭代法
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        std::queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
            }
        }
        return depth;
    }
};