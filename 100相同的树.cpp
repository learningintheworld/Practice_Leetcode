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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr) return true;
        if ((p != nullptr && q == nullptr) || (p == nullptr && q != nullptr)){
            return false;
        }
        std::queue<TreeNode*> que;
        que.push(p);
        que.push(q);

        while(!que.empty()){
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if(!leftNode && !rightNode){
                continue;
            }
            if(!leftNode || !rightNode || (leftNode->val != rightNode->val)){
                return false;
            }
            que.push(leftNode->left);
            que.push(rightNode->left);
            que.push(leftNode->right);
            que.push(rightNode->right);
        }
        return true;
    }
};