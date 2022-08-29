//https://leetcode.com/problems/balanced-binary-tree/
/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/
#include <iostream>
#include <algorithm>
#include <vector>
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* insertPoint(std::vector<int>& array, int i){
    TreeNode* root = nullptr;
    if (i < array.size()){
				// pre-ordered tree = DLR
        root = new TreeNode(array[i]);
        root->left = insertPoint(array, 2*i + 1);
        root->right = insertPoint(array, 2*i + 2);
    }
    return root;
}

class Solution {
    int dfs(TreeNode* root){
        if (!root || !isBalancedVal)
            return -1;
        int Hleft = dfs(root->left);
        int Hright = dfs(root->right);
        if (abs(Hleft - Hright) > 1)
            isBalancedVal = false;
        return std::max(Hleft, Hright) + 1;
    }
    bool isBalancedVal = true;
public:
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return isBalancedVal;
    }
};

int main(){
    std::vector<int> array {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode* root = insertPoint(array, 0);
    Solution sol;
    std::cout << "Is balanced tree: " << std::boolalpha << sol.isBalanced(root);
}
