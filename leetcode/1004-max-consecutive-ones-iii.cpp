#include<iostream>
#include <vector>
#include <tuple>

// Complexity: O(len(nums)*k)
// Space: O(1)
// https://leetcode.com/problems/max-consecutive-ones-iii/submissions/

struct Data{
    std::vector<int> nums; // nums[i] is either 0 or 1., 1 <= nums.length <= 10^5
    int k; // 0 <= k <= nums.length
    int output;
};

int longestOnes(std::vector<int>& nums, int& k){
    int l = 0; //left pointer
    int maxLen = 0; // max length
    int zeros = 0; // number of changed zeros
    for (int r = 0; r < nums.size(); r++ ){ //iteration over right pointer
        if (nums[r] == 0){ // if right pointer points to zero
            while(zeros >= k){ // we move left pointer until 
                if (nums[l] == 0){
                    zeros--;
                }
                l++;
            }
            zeros += 1;
        }
        maxLen = std::max(maxLen, r - l + 1);
    }
    return maxLen;
}

int main(){
    std::vector<int> input;
    int k;
    std::vector<Data> testData = {
        {{1,1,1,0,0,0,1,1,1,1,0}, 2, 6},
        {{0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1}, 3, 10}
    };

    for (auto& data : testData){
        std::cout << longestOnes(data.nums, data.k) << std::endl;
    }
}
