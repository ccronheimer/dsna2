/*
You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of 
the ith line are (i, 0) and (i, height[i]).

Find two lines that together with the x-axis form a container, such that the container contains the most water.

Return the maximum amount of water a container can store.

Notice that you may not slant the container.

area = w * h

questions

- is the input array sorted?

a [1, 2, 1, 5] 
       . i  j 


area = 1 * 3 -> 3
area = 2 * 2 -> 4 
area = 
maxArea = 4

while (l != r) {

int width = r - l;

    if (height[l] >= heights[r]) {        
         area = heights[r] * width;
         r--;
    } else {
        area = l * width;
        l++;
    }

 if area > maxArea: maxArea = area

}

area = minHeight of the two heights (water will overflow) * width

we want to maximize the height and the width

maxArea = 0; 
minHeight = 0;


*/
#include <iostream>
#include <vector>

class Solution {

    public: 

        /*
            [5, 2, 5, 1, 5]
                l        r

            width = 3
            minHeight = 2
            area = 2 * 3 -> 6
            maxArea = 20
            
        */
        int maxContainer(std::vector<int>& heights) {
           
            int maxArea = 0;
            int l = 0;
            int r = heights.size() - 1;
            int area = 0;
            int width = 0; 

            while (l != r) {

                width = r - l;

                if (heights[l] < heights[r]) {

                    area = heights[l] * width;
                    l++;

                } else {

                    area = heights[r] * width;
                    r--;
                }

                if (area > maxArea) maxArea = area;
            }

            return maxArea;

        }
};

int main() {

    std::vector<std::vector<int>> test_cases {
        {5, 2, 5, 1, 5},
        {1, 1},
        {1, 8, 6, 2, 5, 4, 8, 3, 7}
    };

    Solution s;

    for (auto test : test_cases) {
       int maxArea = s.maxContainer(test);

       std::cout << maxArea << '\n';
    }

return 0;
}






