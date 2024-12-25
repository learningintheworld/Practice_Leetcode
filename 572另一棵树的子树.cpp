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

class Solution {
public:
    //判断两个二叉树是否相同
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
public:
    //层序遍历root 找到和subRoot跟节点值一样的节点，然后再进行相同的树的判断
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        std::queue<TreeNode*>que;
        if(root==nullptr&&subRoot==nullptr)return true;
        if(root==nullptr||subRoot==nullptr)return false;
        que.push(root);
        while(!que.empty()){
            int size=que.size();
            for(int i=0;i<size;i++){
                TreeNode* node=que.front();que.pop();
                if(node->val==subRoot->val){
                    bool result = isSameTree(node,subRoot);//判断是否完全相似
                    if(result)return result;//如果相似则直接返回true，否则继续寻找
                }
                if(node->left)que.push(node->left);
                if(node->right)que.push(node->right);
            }
        }
        return false;
    }
};