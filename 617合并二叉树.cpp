#include<queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

//创建root1和root2
TreeNode* root1 = new TreeNode(1);//复杂，算了

/*
//递归法
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
    //确定递归函数的参数和返回值
        //确定终止条件
        if (root1 == nullptr)
        {
            return root2;
        }
        if (root2 == nullptr)
        {
            return root1;
        }
        //确定单层递归逻辑
        root1->val += root2->val;   //中

        root1->left = mergeTrees(root1->left, root2->left); //左
        root1->right = mergeTrees(root1->right, root2->right);  //右
        return root1;
    }
};
*/

//迭代法
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1 == nullptr) return root2;
        if(root2 == nullptr) return root1;
        std::queue<TreeNode*> que;
        que.push(root1);
        que.push(root2);
        while (!que.empty())
        {
            TreeNode* node1 = que.front(); que.pop();
            TreeNode* node2 = que.front(); que.pop();
            node1->val += node2->val;

            //如果两棵树左节点都不为空，加入队列
            if(node1->left != nullptr && node2->left != nullptr){
                que.push(node1->left);
                que.push(node2->left);
            }
            //如果两棵树右节点都不为空，加入队列
            if(node1->right != nullptr && node2->right != nullptr){
                que.push(node1->right);
                que.push(node2->right);
            }

            //当root1的左节点为空，root2的左节点不为空时，就赋值过去
            if(node1->left == nullptr && node2->left != nullptr){
                node1->left = node2->left;
            }
            //当root1的右节点为空，root2的右节点不为空时，就赋值过去
            if(node1->right == nullptr && node2->right != nullptr){
                node1->right = node2->right;
            }
        }
        return root1;
    }
};