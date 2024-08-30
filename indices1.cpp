#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if the complement exists in the map
            if (numMap.find(complement) != numMap.end()) {
                // Return the indices of the two numbers
                return {numMap[complement], i};
            }
            
            // Add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // If no soln is found
        return {};
    }
};

int main() {
    Solution solution;
    
    // Example 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.twoSum(nums1, target1);
    std::cout << "Output for Example 1: [" << result1[0] << ", " << result1[1] << "]" << std::endl;

    // Example 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.twoSum(nums2, target2);
    std::cout << "Output for Example 2: [" << result2[0] << ", " << result2[1] << "]" << std::endl;

    // Example 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.twoSum(nums3, target3);
    std::cout << "Output for Example 3: [" << result3[0] << ", " << result3[1] << "]" << std::endl;

    return 0;
}
