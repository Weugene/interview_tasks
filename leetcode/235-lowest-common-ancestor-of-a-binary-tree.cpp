/**
 * Definition for a binary tree node.
https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
 */
 #include <vector>
 #include <iostream>
 #include <math.h>
 #include <tuple>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution {
public:
    //iterative method
    TreeNode* lowestCommonAncestorIterative(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* cur = root;
        while(cur){
            if (p->val > cur->val && q->val > cur->val){ // go right
                // cout << "RIGHT: p=" << p->val << " q=" << q->val << " v=" << cur->val << endl;
                cur = cur->right;
            } else if (p->val < cur->val && q->val < cur->val){ // go left
                // cout << "LEFT: p=" << p->val << " q=" << q->val << " v=" << cur->val << endl;
                cur = cur->left;
            } else { // one of the node is found
                // cout << "FOUND: p=" << p->val << " q=" << q->val << " v=" << cur->val << endl;
                return cur;
            }
        }
        return cur;
    }
    // recursive method
    // 1. start from root
    // 2. comparing values choose direction
    //    a. both are greater root value => go right
    //    b. both are less root value => go left
    //    c. otherwise => return root (the current root is LCA). Return value (signal) went up.
    TreeNode* lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (p->val > root->val && q->val > root->val){ // go right
            return lowestCommonAncestor(root->right, p, q);
        }else if (p->val < root->val && q->val < root->val){ // go left
            return lowestCommonAncestor(root->left, p, q);
        } else { // one of the node is found
            return root;
        }
        return root;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool iterative = false;
        if (iterative)
            return lowestCommonAncestorIterative(root, p, q); // iterative approach
        else
            return lowestCommonAncestorRecursive(root, p, q); // recursive approach
    }
    int LCA(TreeNode* root, int p, int q){
        TreeNode *pp = new TreeNode(p);
        TreeNode *qq = new TreeNode(q);
        TreeNode* lca = lowestCommonAncestor(root, pp, qq);
        std::cout << lca->val << std::endl;
        return lca->val;
    }
};
// answer how to define the level from perfect binary tree:
// level = floor(log2(index + 1)),
// where index = [0,N), root level = 0
//https://stackoverflow.com/questions/10721583/how-can-i-calculate-the-level-of-a-node-in-a-perfect-binary-tree-from-its-depth

int getLevel(int index){
    return floor(log2(index + 1));
}
int getStartIndex(int level){
    return (1 << level) -1;
}
int getEndIndex(int level){
    return (1 << (level + 1) ) - 2;
}
bool checkEndIndex(int index){
    int level = getLevel(index);
    return index == (1 << (level + 1) ) - 2;
}

auto getParentIndex(int index){
    return floor((index - 1)/2.0);
}

std::tuple<int, int> getChildIndices(int index){
    return {2*index + 1, 2*index + 2};
}

int count_digit(int number) {
   return int(log10(number) + 1);
}

TreeNode* insertPoint(std::vector<int>& array, int i){
    TreeNode* root = nullptr;
    if (i < array.size()){
        root = new TreeNode(array[i]);
        root->left = insertPoint(array, 2*i + 1);
        root->right = insertPoint(array, 2*i + 2);
    }
    return root;
}

void PrintTree(TreeNode* root){
    if (!root)
        return;
    
    std:: cout << root->val << " ";
    PrintTree(root->left);
    PrintTree(root->right);
}
int main(){
    // std::vector<int> array {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> array {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    TreeNode* root = insertPoint(array, 0);
    PrintTree(root);
    for (int i = 0; i < array.size(); i++){
        std::cout << array[i] << " ";
        if (checkEndIndex(i)){
            std::cout << "\n";
        }
    }
    std::cout << "\n";

    Solution sol;
    std::cout << "LCA(4, 7) = " << sol.LCA(root, 4, 7) << std::endl;
    std::cout << "LCA(3, 5) = " << sol.LCA(root, 3, 5) << std::endl;
}
/*
          6
      /       \
     2         8 
   /  \      /  \
  0    4    7    9 
 / \  / \  / \  / \
-1 -1 3  5
*/
