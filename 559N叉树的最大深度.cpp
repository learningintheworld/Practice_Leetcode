#include<queue>
#include<vector>

// Definition for a Node.
class Node {
public:
    int val;
    std::vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, std::vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

// //递归法
// class Solution {
// public:
//     int getdepth(Node* node){
//         if(node == nullptr) return 0;
//         int depth = 0;
//         for(int i = 0; i < node->children.size(); i++){
//             depth = max(depth, getdepth(node->children[i]));
//         }
//         return depth + 1;
//     }
// public:
//     int maxDepth(Node* root) {
//         int result = getdepth(root);
//         return result;
//     }
// };

//迭代法
class Solution {
public:
    int maxDepth(Node* root) {
        if(root == nullptr) return 0;
        int depth = 0;
        std::queue<Node*> que;
        que.push(root);

        while(!que.empty()){
            int size = que.size();
            depth++;
            for(int i = 0; i < size; i++){
                Node* node = que.front();
                que.pop();
                for(int j = 0; j < node->children.size(); j++){
                    if(node->children[j]) que.push(node->children[j]);
                }
            }
        }
        return depth;
    }
};
