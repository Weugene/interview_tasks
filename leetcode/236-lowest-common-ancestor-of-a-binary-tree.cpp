/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include <bitset>

class Solution {
private:
    /**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int getHighestOne(unsigned int num) {
    int count = 0;
    while(num >>= 1) ++count;
    return count;
}
public:
    // recursive method
    // Time Complexity: O(n)
    // Auxiliary Space: O(h) where h is the height of the tree.
    // 1. start from root
    // if root in (Null, p, q) return root;
    // run left branch
    // run right branch
    // if both not Null => the current node 'root' is answer
    // otherwise return not null 
    TreeNode* lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case
        if (!root)
            return nullptr;
        if (root==p || root==q)
            return root;
        // Look for keys in left and right subtrees
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        // If both of the above calls return Non-NULL nodes, then one
        // key is present in once subtree and other is present
        // in other, So this node is the LCA
        if (left && right)
            return root;
        // Otherwise check if left subtree or right subtree is LCA
        // return (left != nullptr) ? left : right;
        // here we guarantee that one of them is nullptr
        return (TreeNode*)((unsigned long long int)left + (unsigned long long int)right);
    }
};
