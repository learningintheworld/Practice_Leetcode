#include<queue>
#include<vector>

//Definition for a binary tree node.
struct TreeNode {
   int val;
   TreeNode *left;
   TreeNode *right;
   TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//递归法
// class Solution {
// public:
//     bool compare(TreeNode* left, TreeNode* right){
//         if (left == nullptr && right != nullptr) return false;
//         else if (left != nullptr && right == nullptr) return false;
//         else if (left == nullptr && right == nullptr) return true;
//         else if (left->val != right->val) return false;

//         bool outside = compare(left->left, right->right);
//         bool inside = compare(left->right, right->left);
//         bool isSame = outside && inside;
//         return isSame;
//     }
// public:
//     bool isSymmetric(TreeNode* root) {
//         if (root == nullptr) return true;
//         return compare(root->left, root->right);
//     }
// };

//迭代法
class Solution{
public:
    bool isSymmetric(TreeNode* root){
        if (root == nullptr) return true;
        std::queue<TreeNode*> que;
        que.push(root->left);
        que.push(root->right);

        while(!que.empty()){
            TreeNode* leftNode = que.front(); que.pop();
            TreeNode* rightNode = que.front(); que.pop();
            if(!leftNode && !rightNode){
                continue;
            }

            if (!leftNode || !rightNode || (leftNode->val != rightNode->val)){
                return false;
            }

            que.push(leftNode->left);
            que.push(rightNode->right);
            que.push(leftNode->right);
            que.push(rightNode->left);
        }
        return true;
    }
};
/*输入的是一棵二叉树的根节点，不是数组
std::vector<int> root = {1, 2, 2, 3, 4, 4, 3};
Solution::isSymmetric(root);
*/