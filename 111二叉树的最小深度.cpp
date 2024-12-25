#include<algorithm>
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

//迭代法
class Solution {
public:
    int getDepth(TreeNode* node){
        if(node == nullptr) return 0;
        int leftDepth = getDepth(node->left);
        int rightDepth = getDepth(node->right);

        if(node->left == nullptr && node->right != nullptr){
            return 1 + rightDepth;
        }
        if(node->right == nullptr && node->left != nullptr){
            return 1 + leftDepth;
        }
        if(node->left == nullptr && node->right == nullptr){
            return 1 + std::min(leftDepth, rightDepth);
        }
        return -1;
    }

public:
    int minDepth(TreeNode* root) {
        return getDepth(root);
    }
};

//迭代法
class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        std::queue<TreeNode*> que;
        que.push(root);
        int depth = 0;

        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++){
                TreeNode* node = que.front();
                que.pop();
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                if(!node->left && !node->right){
                    return depth;
                }
            }
        }
        return depth;
    }
};