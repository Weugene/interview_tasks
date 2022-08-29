#include <unordered_map>
#include <iostream>
#include <vector>

class Solution {
    std::unordered_map<int, int> m_map;
public:
    // Approach 1: Two-pass Hash Table
    std::vector<int> twoSum2(std::vector<int>& nums, int target) {
        std::vector<int> sol;
        for(int i = 0; i < nums.size(); i++)
            m_map[nums[i]] = i;

        for(int i1 = 0; i1 < nums.size(); i1++){
            int key = target - nums[i1];
            if(m_map.count(key) > 0 && m_map.at(key) != i1){
                    return {i1, m_map.at(key)};
            }
        }
        return sol;
    }
    //Approach 2: One-pass Hash Table
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::vector<int> sol;

        for(int i1 = 0; i1 < nums.size(); i1++){
            int key = target - nums[i1];
            if(m_map.count(key) > 0){
                return {i1, m_map.at(key)};
            }
            m_map[nums[i1]] = i1;
        }
        return sol;
    }
};

int main(){
    std::vector<int> array {6, 2, 8, 0, 4, 7, 9, -1, -1, 3, 5};
    Solution sol;
    int target = 10;
    auto vec = sol.twoSum(array, target);
    int i1 = vec[0];
    int i2 = vec[1];
    std::cout << "target = n1 + n2 => " << target << " = " << array[i1] << " + " << array[i2] << std::endl;
}
