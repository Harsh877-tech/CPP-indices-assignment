#include <iostream>
#include <vector>
#include <unordered_map>

// Class containing the solution method
class Solution {
public:
    // Method to find the indices of two numbers that add up to the target
    std::vector<int> findIndices(std::vector<int>& nums, int target) {
        // Hash map to store numbers and their corresponding indices
        std::unordered_map<int, int> numMap;

        // Iterate through the vector
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];  // Calculate the complement
            
            // Check if the complement is already in the map
            if (numMap.find(complement) != numMap.end()) {
                // If found, return the indices of the complement and the current number
                return {numMap[complement], i};
            }
            
            // If not found, add the current number and its index to the map
            numMap[nums[i]] = i;
        }
        
        // Return an empty vector if no solution is found 
        return {};
    }
};

// Main function to test the solution
int main() {
    Solution solution;  // Create an instance of the Solution class
    
    // Test case 1
    std::vector<int> nums1 = {2, 7, 11, 15};
    int target1 = 9;
    std::vector<int> result1 = solution.findIndices(nums1, target1);
    std::cout << "Test Case 1 Output: [" << result1[0] << ", " << result1[1] << "]\n";

    // Test case 2
    std::vector<int> nums2 = {3, 2, 4};
    int target2 = 6;
    std::vector<int> result2 = solution.findIndices(nums2, target2);
    std::cout << "Test Case 2 Output: [" << result2[0] << ", " << result2[1] << "]\n";

    // Test case 3
    std::vector<int> nums3 = {3, 3};
    int target3 = 6;
    std::vector<int> result3 = solution.findIndices(nums3, target3);
    std::cout << "Test Case 3 Output: [" << result3[0] << ", " << result3[1] << "]\n";

    return 0;  // End of the main function
}
