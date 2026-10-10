/*
Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

example 1:

Input: nums = [1,2,3,1]

Output: true

Explanation:

The element 1 occurs at the indices 0 and 3.

Example 2:

Input: nums = [1,2,3,4]

Output: false

Explanation:

All elements are distinct.

Example 3:

Input: nums = [1,1,1,3,3,4,3,2,4,2]

Output: true

*/


#include <iostream>
#include <array>

bool findDuplicates(int nums[]) {
    std::cout << nums[0] << '\n';
   
    for (int i = 0; i < 5; i++) {   
        
    std::cout << nums[i] << '\n';
    
    std::cout << &nums[i] << '\n';
}

    return false;
}

int main() {

    int a = 5;
   
    int nums[] = {1, 2, 1, 3};

    findDuplicates(nums);

    for (int i = 0; i < nums.size(nums); i++) {
        
    }

    std::cout << nums;

    int num = 100;

    int* addressOfNum = &num;
    int valueOfNum = *addressOfNum;

    std::cout << valueOfNum;

return 0;
}

