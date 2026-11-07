/*

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] 
is the number of days you have to wait after the ith day to get a warmer temperature. 
If there is no future day for which this is possible, keep answer[i] == 0 instead.

Can use the index of each temperature to get the span
Can use the temperature to check if it meets higher temp req

Example 1
                       0  1 
Input: temperatures = [73,74,75,71,69,72,76,73]

   0   1   2    3 
 [1, 1, 2, 0]
   3   1    1   0
                i

 res = [2, 1, 0, 0]
 stack = [2] 

Output: [1,1,4,2,1,1,0,0]
Example 2:

Input: temperatures = [30,40,50,60]
Output: [1,1,1,0]
Example 3:

Input: temperatures = [30,60,90]
Output: [1,1,0]


unorder

*/

#include <vector>
#include <iostream>
#include <stack>

class Solution {

public:
    
    std::vector<int> dailyTemperatures(std::vector<int>& temperatures) {
        
        std::vector<int> temp_span (temperatures.size());
        std::stack<int> stack;

        for (int temp_idx = 0; temp_idx < temperatures.size(); temp_idx++) {
            
           while (!stack.empty() && temperatures[stack.top()] < temperatures[temp_idx]) {

               temp_span[stack.top()] = temp_idx - stack.top();
               stack.pop();

           }

           stack.push(temp_idx);

        }

        return temp_span;
    }
};

int main() {

    Solution s;

    std::vector<std::vector<int>> test_cases = {
        {70, 80},
        {70, 72, 20, 10, 100},
        {30, 60, 90},
        {},
        {1},
        {73, 74, 75, 71, 69, 72, 76, 73}
    };

    for (auto test : test_cases) {
        
        std::vector<int> span = s.dailyTemperatures(test);

        for (auto span_i : span) {
            std::cout << span_i << ',';
        }

        std::cout << '\n';
    }

}