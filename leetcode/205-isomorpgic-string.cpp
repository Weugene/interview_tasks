// https://leetcode.com/problems/isomorphic-strings/submissions/
// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
#include <unordered_map>
#include <string>
#include <iostream>
class Solution {
public:
    bool isIsomorphic(std::string s, std::string t) {
        if (s.size() != t.size())
            return false;
        
        std::unordered_map<char, char> mapping_s_t, mapping_t_s;
        for (int i = 0; i < s.size(); i++){
            // Case 1: No mapping exists in either of the dictionaries
            if (mapping_s_t.count(s[i])==0 && mapping_t_s.count(t[i])==0){
                mapping_s_t[s[i]] = t[i];
                mapping_t_s[t[i]] = s[i];
            }else if (mapping_s_t.count(s[i])==0 && mapping_t_s.count(t[i])>0) // Case 2: Ether mapping doesn't exist in s
                return false;
            else if (mapping_s_t.count(s[i])>0 && mapping_t_s.count(t[i])==0) // Case 3: Ether mapping doesn't exist in t
                return false;
            else if (mapping_s_t.at(s[i]) != t[i] ||
                      mapping_t_s.at(t[i]) != s[i]){ // Case 4: Mapping exists and it doesn't match in either of the dictionaries or both
                return false;
            }
        }
        return true;
    }
};

int main(){
    Solution sol;
    std::cout << std::boolalpha << "egg ? add =>" << sol.isIsomorphic("egg", "add") << "\n";
    std::cout << std::boolalpha << "egg ? add =>" << sol.isIsomorphic("foo", "bar") << "\n";
}
