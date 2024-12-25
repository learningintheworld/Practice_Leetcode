#include<vector>
//#include<iostream>
/*
#include<tr1/memory>
struct A
{
};

std::tr1::shared_ptr<A> yuxinwei(new A());
*/

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
private:
    int maxCount = 0;
    int count = 0;
    TreeNode* pre = nullptr;
    std::vector<int> result;
    void searchBST(TreeNode* cur){
        if(cur == nullptr) return;
        searchBST(cur->left);
        if(pre == nullptr){
            count = 1;
        }else if(pre->val == cur->val){
            count++;
        }else{
            count = 1;
        }
        pre = cur;
        if(count == maxCount){
            result.push_back(cur->val);
        }
        if(count > maxCount){
            maxCount = count;
            result.clear();
            result.push_back(cur->val);
        }
        searchBST(cur->right);
        return;
    }
public:
    std::vector<int> findMode(TreeNode* root) {
        //count = 0;
        //maxCount = 0;
        //TreeNode* pre = nullptr;
        //result.clear();

        searchBST(root);
        return result;
    }
};