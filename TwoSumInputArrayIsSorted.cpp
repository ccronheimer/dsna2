/*
You are given a 1-indexed array of integers numbers that is already sorted in non-decreasing order.

Find two numbers such that they add up to a specific target number. Let these two numbers be numbers[index1] and 
numbers[index2] where 1 <= index1 < index2 <= numbers.length.

Return the indices of the two numbers index1 and index2 as an integer array [index1, index2] of length 2.

The tests are generated such that there is exactly one solution. You may not use the same element twice.

Your solution must use only constant extra space.
 
Example 1:

Input: numbers = [2,7,11,15], target = 9
Output: [1,2]
Explanation: The sum of 2 and 7 is 9. Therefore, index1 = 1, index2 = 2. We return [1, 2].
Example 2:

Input: numbers = [2,3,4], target = 6
Output: [1,3]
Explanation: The sum of 2 and 4 is 6. Therefore index1 = 1, index2 = 3. We return [1, 3].
Example 3:

Input: numbers = [-1,0], target = -1
Output: [1,2]
Explanation: The sum of -1 and 0 is -1. Therefore index1 = 1, index2 = 2. We return [1, 2].


// with 4 we need a 2 to equal target 6 so let's find a two and return it's idx
int findDiff(std::vector<int>& nums, int target, int end_idx) {
   
    for (int i = 0; i < end_idx; i++) {
        
        if (nums[i] == target) {
            return i; 
        }
    } 
}

numbers = [2, 7, 11, 15] target = 9
         

        int end_idx = nums.size() - 1;

        // move the right window down
        // if the min num + max num greater than target then all nums in between will be greater than target        

        while (nums[start_idx] != nums[end_idx])  {
            
            while (nums[start_idx] + nums[end_idx] < target) start_idx++; 
            while (nums[start_idx] + nums[end_idx] > target) end_idx--; 

            if (nums[start_idx] + nums[end_idx] == target) return {start_idx, end_idx};

            }
        }

        // else they equal each other return indices
      
        return {start_idx, end_idx};

    we cannot store differences anywhere so we need to loop subarray multiple times
    1. find end idx such that num is less then or equal to target
    2. if the num[start_idx] + num[end_idx] > target we know that the end_idx is too big because nums in between will be bigger
    than the end_idx so no point in checking so decrease end idx
          
*/
#include <vector>
#include <iostream>
#include <utility>

class Solution {

    public: 

        std::vector<int> twoSum(std::vector<int>& numbers, int target) {

            int r = numbers.size() - 1;
            int l = 0;

            while (l != r) {

                while (numbers[l] + numbers[r] > target) r--;
                while (numbers[l] + numbers[r] < target) l++;

                if (numbers[l] + numbers[r] == target) break;

            }

            return {l, r};

        }
};


int main() {

    std::vector<std::pair<std::vector<int>, int>> test_cases = {
        {{1, 2}, 3},
        {{1, 5, 10, 11}, 15}
    };

    Solution s;

    for (auto test : test_cases) {

        auto res = s.twoSum(test.first, test.second);
        
        for (auto i : res) {
            std::cout << i << ',';
        }

        std::cout << '\n';
    }

}