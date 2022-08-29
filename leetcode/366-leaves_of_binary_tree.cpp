#include<iostream>
#include <vector>
#include <map>
#include <string>
// https://leetcode.com/problems/find-leaves-of-binary-tree/
// DFS
// Time O(n)
// Space O(n)
using Input = std::vector<int>;
using Output = std::vector<std::vector<int>>;
using Map = std::map<int, std::vector<int>>;

struct Data{
    Input input;
    Output output;
};


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

/* Helper function that allocates a
new node */
TreeNode* newNode(int data)
{
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = data;
    node->left = node->right = nullptr;
    return node;
}

// Function to insert nodes in level order
TreeNode* insertLevelOrder(const std::vector<int>& arr,
                       int i, int n)
{
      TreeNode *root = nullptr;
    // Base case for recursion
    if (i < n)
    {
        root = newNode(arr[i]);
          
        // insert left child
        root->left = insertLevelOrder(arr,
                   2 * i + 1, n);
  
        // insert right child
        root->right = insertLevelOrder(arr,
                  2 * i + 2, n);
    }
    return root;
}
    
// Function to print tree nodes in
// InOrder fashion
void inOrder(TreeNode* root)
{
    if (root != nullptr)
    {
        inOrder(root->left);
        std::cout << root->val <<" ";
        inOrder(root->right);
    }
}

int iterate(TreeNode* root, Map& mem){
    if (root == nullptr) 
        return 0;
    int left = iterate(root->left, mem);
    int right = iterate(root->right, mem);
    mem[std::max(left, right)].push_back(root->val);
    return std::max(left, right) + 1;
}

Output findLeaves(TreeNode *node){
    std::vector<std::vector<int>> result;
    std::map<int, std::vector<int>> mem;
    iterate(node, mem);
    int level = 0;
    while(mem[level].size()>0){
        result.emplace_back(mem[level]);
        level += 1;
    }
    return result;
}
int main(){
    std::vector<Data> testData = {
        {{1,2,3,4,5}, {{4,5,3},{2},{1}}},
        {{ 1, 2, 3, 4, 5, 6, 6, 6, 6 }, {{6, 6, 5, 6, 6}, {4, 3}, {2}, {1}}}
    };

    for (auto& data : testData){
        TreeNode* tree = insertLevelOrder(data.input, 0, data.input.size());
        inOrder(tree);
        std::cout << "\n";
        auto result = findLeaves(tree);
        for (auto& vec: result){
            for(auto& el: vec)
            {
                std::cout << el << " ";
            }
            std::cout << "\n";
        }
        // std::cout << data.input << " " << (tree) << std::endl;
    }
}
