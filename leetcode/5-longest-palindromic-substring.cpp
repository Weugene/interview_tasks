#include<iostream>
#include <vector>
#include <string>

// Complexity: O(n^2) due to 2 for loops
// Space: O(1)
// https://leetcode.com/problems/longest-palindromic-substring/
// sin consist of only digits and English letters
// 1 <= sin.length <= 1000
struct Data{
    std::string sin;
    std::string sout;
};

std::string get_palidrom(const std::string& s, int left, int right){

    while(left >= 0 && right < s.size() && s[left] == s[right]){
        left--;
        right++;
    }
    return std::string(s.begin() + left +1, s.begin() +right);
}
std::string longestPalindrome(const std::string& sin) {
    std:: string res = "";

    for (int i=0; i < sin.size(); i++){
        const auto& op1 = get_palidrom(sin, i, i);
        const auto& op2 = get_palidrom(sin, i, i + 1);
        // std::cout << "i=" << i << " " << op1 << " ..." << op2 << "\n";
        if (op1.size() > res.size()){
            res = op1;
        }
        if (op2.size() > res.size()){
            res = op2;
        }
    }
    return res;
}

int main(){
    std::vector<int> input;
    int k;
    std::vector<Data> testData = {
        {"babad", "bab"},
        {"cbbd", "bb"},
        {"babad", "bab"},
        {"a", "a"}
    };

    std::cout << get_palidrom("bab", 2, 2) << "\n";
    for (auto& data : testData){
        std::cout << data.sin << " " << longestPalindrome(data.sin) << std::endl;
    }
}
