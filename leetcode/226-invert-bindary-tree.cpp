//https://leetcode.com/problems/invert-binary-tree/
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
//Time complexity O(n)
//Space complexity O(h), h the height of tree = o(n)
class Solution {
public:
    TreeNode* invertTree_recursive(TreeNode* root) {
        if (!root)
            return nullptr;
        // swap the children
        TreeNode* tmp;
        tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        root->left = invertTree(root->left);
        root->right = invertTree(root->right);
        return root;
    }
    TreeNode* invertTree_iterative(TreeNode* root) {
        if (!root)
            return nullptr;
        std::deque<TreeNode*>queue;
        queue.push_back(root);
        while(!queue.empty()){
            TreeNode* current = queue.front();
            queue.pop_front();
            std::swap(current->left, current->right);
            if (current->left)
                queue.push_front(current->left);
            if (current->right)
                queue.push_back(current->right);
        }
        return root;
    }
};
