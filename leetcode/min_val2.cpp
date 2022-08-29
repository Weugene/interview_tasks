// 5. Write a code which demonstrates LCA problem solution.
#include <iostream>
#include <vector>
#include <stack>

using namespace std;
// A Binary Tree node
struct Node
{
	int key;
	struct Node *left, *right;
};

// Utility function creates a new binary tree node with given key
Node * newNode(int k)
{
	Node *temp = new Node;
	temp->key = k;
	temp->left = temp->right = nullptr;
	return temp;
}


// Your code here


//    100
//   /   \
//  20   30
//  /\   /\
// 4  5 6  7
Node* lca(Node* root, int left, int right){
    if (root == nullptr)
        return nullptr;
    if (root->key > left && root->key > right)
        return lca(root->left, left, right);
    if (root->key < left && root->key < right)
        return lca(root->right, left, right);
    return root;
}

int findLCA(Node* root, int left, int right){
    Node* res = lca(root, left, right);
    return res->key;
}

// int findLCA(Node* root, int left, int right){
//     if (root == nullptr)
//         return -1;
//     std::stack<std::pair<Node*, int>> my_stack;
//     my_stack.push({root, root->key}); // here we push min element

//     int minvalue;
//     while(!my_stack.empty()){
//         auto[node, cost] = my_stack.top();
//         my_stack.pop();
//         minvalue = std::min(cost, node->key);
//         // std::cout << minvalue << " " << cost << std::endl;
//         if (node){
//             if (node->key != left)
//                 my_stack.push({node->left, std::min(minvalue, node->left->key)});
//             if (node->key != right)
//                 my_stack.push({node->right, std::min(minvalue,node->right->key)});
//         }
//     }
//     return minvalue;
// } 


// Driver program to test above functions
int main()
{
	// Let us create the Binary Tree shown in above diagram.
	Node * root = newNode(100);
	root->left = newNode(20);
	root->right = newNode(30);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->right->left = newNode(6);
	root->right->right = newNode(7);
    cout << "LCA(20, 30) = " << findLCA(root, 20, 30) << endl; // 100
	cout << "LCA(4, 5) = " << findLCA(root, 4, 5) << endl; // 20
	cout << "LCA(4, 6) = " << findLCA(root, 4, 6) << endl; // 100
	cout << "LCA(30, 4) = " << findLCA(root, 30, 4) << endl; // 100
	cout << "LCA(20, 4) = " << findLCA(root, 20, 4) << endl; // 20
	cout << "LCA(4, 4) = " << findLCA(root, 4, 4) << endl; // 4
	cout << "LCA(9, 10) = " << findLCA(root, 9, 10) << endl; // -1
	return 0;
}

