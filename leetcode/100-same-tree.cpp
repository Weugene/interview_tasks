//https://leetcode.com/problems/same-tree/
/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.
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
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (!p && !q){
            return true;
        }
        if(!p || !q || p->val != q->val){
            return false;
        }
        return (this->isSameTree(p->left, q->left) &&
                this->isSameTree(p->right, q->right));
    }
};


int main(){
    std::vector<int> array {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode* rootp = insertPoint(array, 0);
    TreeNode* rootq = insertPoint(array, 0);
    Solution sol;
    std::cout << "Is same trees rootp ? rootq: " << std::boolalpha << sol.isSameTree(rootp, rootq);
    array.emplace_back(10);
    TreeNode* rootk = insertPoint(array, 0);
    Solution sol;
    std::cout << "Is same trees rootp ? rootk: " << std::boolalpha << sol.isSameTree(rootp, rootk);
}
