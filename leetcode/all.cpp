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

// #include<iostream>
// #include <vector>
// #include <string>

// // Complexity: O(n^2) due to 2 for loops
// // Space: O(1)
// // https://leetcode.com/problems/longest-palindromic-substring/
// // sin consist of only digits and English letters
// // 1 <= sin.length <= 1000
// struct Data{
//     std::string sin;
//     std::string sout;
// };

// std::string get_palidrom(const std::string& s, int left, int right){

//     while(left >= 0 && right < s.size() && s[left] == s[right]){
//         left--;
//         right++;
//     }
//     return std::string(s.begin() + left +1, s.begin() +right);
// }
// std::string longestPalindrome(const std::string& sin) {
//     std:: string res = "";

//     for (int i=0; i < sin.size(); i++){
//         const auto& op1 = get_palidrom(sin, i, i);
//         const auto& op2 = get_palidrom(sin, i, i + 1);
//         // std::cout << "i=" << i << " " << op1 << " ..." << op2 << "\n";
//         if (op1.size() > res.size()){
//             res = op1;
//         }
//         if (op2.size() > res.size()){
//             res = op2;
//         }
//     }
//     return res;
// }

// int main(){
//     std::vector<int> input;
//     int k;
//     std::vector<Data> testData = {
//         {"babad", "bab"},
//         {"cbbd", "bb"},
//         {"babad", "bab"},
//         {"a", "a"}
//     };

//     std::cout << get_palidrom("bab", 2, 2) << "\n";
//     for (auto& data : testData){
//         std::cout << data.sin << " " << longestPalindrome(data.sin) << std::endl;
//     }
// }
// #include<iostream>
// #include <vector>
// #include <tuple>

// // Complexity: O(len(nums)*k)
// // Space: O(1)
// // https://leetcode.com/problems/max-consecutive-ones-iii/submissions/

// struct Data{
//     std::vector<int> nums; // nums[i] is either 0 or 1., 1 <= nums.length <= 10^5
//     int k; // 0 <= k <= nums.length
//     int output;
// };

// int longestOnes(std::vector<int>& nums, int& k){
//     int l = 0; //left pointer
//     int maxLen = 0; // max length
//     int zeros = 0; // number of changed zeros
//     for (int r = 0; r < nums.size(); r++ ){ //iteration over right pointer
//         if (nums[r] == 0){ // if right pointer points to zero
//             while(zeros >= k){ // we move left pointer until 
//                 if (nums[l] == 0){
//                     zeros--;
//                 }
//                 l++;
//             }
//             zeros += 1;
//         }
//         maxLen = std::max(maxLen, r - l + 1);
//     }
//     return maxLen;
// }

// int main(){
//     std::vector<int> input;
//     int k;
//     std::vector<Data> testData = {
//         {{1,1,1,0,0,0,1,1,1,1,0}, 2, 6},
//         {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10}
//     };

//     for (auto& data : testData){
//         std::cout << longestOnes(data.nums, data.k) << std::endl;
//     }
// }


// #include<iostream>
// #include <vector>
// #include <queue> // FIFO queue
// #include <set>
// struct C{
//     int m_x, m_y;
//     C(int x, int y): m_x(x), m_y(y){}
//     std::ostream& operator<<(std::ostream& os){
//         os << m_x << " " << m_y << "\n";
//         return os;
//     }
//     int length(const C& other)const{
//         return abs(other.m_x - m_x) + abs(other.m_y - m_y);
//     }
// };
// std::ostream& operator<<(std::ostream& os, const C& a)
// {
//      os << a.m_x << " " << a.m_y << "\n";
//     return os;
// }

// struct NW{
//     int n;
//     int w;
//     NW(int n_, int w_): n(n_), w(w_){}
// };

// int bfs(const int s, const int finish, const std::vector<std::vector<NW>>& adj){
//     int N = adj.size();
//     std::set<int> visited;
//     std::queue<std::pair<int, int>> queue;
//     queue.push({s,0});
//     while(!queue.empty()){
//         auto& [v, count] = queue.front(); 
//         queue.pop();
//         if (v == finish) {
//             return count;
//         }
//         // here we run looking up from a vertex v
//         for (auto& nw : adj[v]){
//             // If a vertex is visited?
//             if (!visited.contains(nw.n) ){
//                 // std::cout << nw.n << " " << v << std::endl;
//                 // add to the queue
//                 queue.push({nw.n, count + 1});
//             }
//         }
//     }

//     return -1;
// }

// int taxicabLength(const int i, const int j, const std::vector<C>& coord){
//     return coord[i].length(coord[i]);
// }

// int main(){
// 	int N;
// 	std::cin >> N;
//     std::vector<C> coord;
//     coord.reserve(N);
//     int x, y;
// 	for (int i = 0; i < N; i++){
//         std::cin >> x >> y; // (2≤n≤1000)
// 		coord.emplace_back(x, y);
//         // std::cout << coord[i];
//     }
//     int k;
//     std::cin >> k; // k < 2*10^9
//     int A, B;
//     std::cin >> A >> B;
//     A--; B--;

//     std::vector<std::vector<NW>> adj;
//     adj.resize(N);
//     for (int i = 0; i < N; i++){
//         // std::cout << "i=" << i << ": [";
//         for (int j = 0; j < N; j++){
//             int w = coord[i].length(coord[j]);
//             if ((i != j) && w <= k){
//                 adj[i].emplace_back(j, w);
//                 // std::cout << " " << j;
//             }
//         }
//         // std::cout << " ]" << std::endl;
//     }
//     auto cost = bfs(A, B, adj);
//     std::cout << cost;
// }


// template<std::size_t Size>
// class A
// {

//  public:
//     int m_i;
//     int m_N;
//     std::bitset<Size> m_bitset;
    
//     A(int i, int N) : m_i(i-1), m_N(N), m_bitset(std::bitset<Size>(i-1)) {
//     }
//     bool check_good(){
//         std::stack<bool> mystack;
//         if (m_bitset.count() != m_N/2)
//             return false;
//         for (int i = 0; i < m_N; i++){
//             // std::cout << "m_bitset[" << i << "]:" << m_bitset[i] << std::endl;
//             if (m_bitset[i])
//                 mystack.push(m_bitset[i]);
//             else if (mystack.size() > 0)
//                 mystack.pop();
//             else
//                 return false;
//         }
//         if (mystack.empty())
//             return true;
//         else
//             return false;

//     }
//     // needs body 
//     friend std::ostream & operator<<( std::ostream & Out , int)
//     {
//         return Out;
//     }
// };

// char parenthesis(char in) {return (in == '0') ? '(' : ')'; }
// template<std::size_t Size>
// std::ostream& operator<<(std::ostream& out, const A<Size>& a) // overload for xyz not int
// {
//     std::string binary = std::bitset<Size>(a.m_i).to_string().substr(Size - a.m_N, Size);
//     for (auto c : binary){
//         out << parenthesis(c);
//     }
//     // out<< " => " << binary; // use out not cout
//     return out;  // and don't forget to return out as well
// }
// int main(){
// 	int N;
// 	std::cin >> N;
//     N *=2;
// 	for (int i = 0; i < 2 << (N-1); i++){
// 		A<23> a(i, N);
//         if (a.check_good() ) std::cout << a << std::endl;
//     }
// }

// void paren_gen(std::string&& s, int l, int r, int pairs){
//     if (l == pairs && r == pairs){
//         std::cout << s << "\n";
//     }else{
//         if (l < pairs){
//             paren_gen(s + "(", l + 1, r, pairs);
//         }
//         if (r < pairs){
//             paren_gen(s + ")", l, r + 1, pairs);
//         }    
//     }
// }

// int main(){
// 	int N;
// 	std::cin >> N;
//     paren_gen("", 0, 0, N);
// }
// let n = Int(readLine()!)
//  func skobki(_ s:String,_ l: Int,_ r: Int,_ pairs: Int){
//    if l == pairs && r == pairs{
    
//      print(s)
//    }
//    else{
//      if l < pairs {
//        skobki(s+"(",l+1,r,pairs)
//      }
//       if r < l {
//        skobki(s+")",l,r+1,pairs)
//      }
//    }
//  }
// skobki("",0,0,n!)
