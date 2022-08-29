//https://leetcode.com/problems/diameter-of-binary-tree/
/*
Given the root of a binary tree, return the length of the diameter of the tree.

The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.

The length of a path between two nodes is represented by the number of edges between them.
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

class Solution {
    int dfs(TreeNode* root){ // returns Height
        if (!root)
            return -1;
        int Hleft = dfs(root->left);
        int Hright = dfs(root->right);
        maxD = std::max(maxD, Hleft + Hright + 2);
        return std::max(Hleft, Hright) + 1;
    }

    int maxD = 0;
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return maxD;
    }
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
int main(){
    std::vector<int> array {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode* root = insertPoint(array, 0);
    Solution sol;
    std::cout << "Diameter of tree: " << sol.diameterOfBinaryTree(root);
}
