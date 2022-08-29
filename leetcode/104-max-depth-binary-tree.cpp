//https://leetcode.com/problems/maximum-depth-of-binary-tree/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
//Find maximum depth of binary tree
// 3 main approaches:
// 1. recursive DFS
// 2. iterative DFS
// 3. iterative BFS

// Time complexity O(n)
// Space complexity O(n) in worst case. The best case is log2(n).
#include <queue>
#include <stack>
class Solution {
public:
//     recursive DFS
    int maxDepth_recursive_DFS(TreeNode* root) {
        if (!root)
            return 0;
        return 1 + max(maxDepth(root->left), maxDepth(root->right));
    }
//     iterative DFS
    int maxDepth_iterative_DFS(TreeNode* root) {
        if (!root)
            return 0;
        int res = 1;
        std::stack<std::pair<TreeNode*, int>> sta;
        sta.push({root, 1});
        while(!sta.empty()){
            auto[node, depth] = sta.top();
            sta.pop();
            if (node){
                res = std::max(res, depth);
                    sta.push({node->left, depth + 1});
                    sta.push({node->right, depth + 1});
            }

        }
        return res;
    }
//     iterative BFS
    int maxDepth_iterative_BSF(TreeNode* root) {
        if (!root)
            return 0;
        int d = 0;
        int N = 1;
        std::queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int q_size = q.size();
            for (int i = 0; i < q_size; i++){
                TreeNode* current = q.front();
                q.pop();
                if (current->left){
                    q.push(current->left);
                    N++;
                }
                if(current->right){
                    q.push(current->right);
                    N++;
                }
                // std::cout << "i=" << i << " "<< current->val << " ";
            }
            // std::cout << std::endl;
            d++;
        }
        // std::cout << "N=" << N << " d=" << d << '\n';
        return d;
    }
};
