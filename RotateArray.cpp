/*
 .             i
    [1,2,3,4,5,6,7] k = 10
    [5,6,7,1,2,3,4]
                            20

    20 % 7
    
    20 = 7 + 7 + 6
    = 6


    int real_pos = 0;

    while ()

    
*/

#include <vector>
#include <iostream>
#include <utility>


int main() {

    std::vector<int> nums = {1,2,3,4,5,6,7};
                            //     1 
    int k = 3;
    int j = k % nums.size(); //  % 8 = 3   
    std::vector<int> res(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        
        j = (k + i) % nums.size(); 
        /*
             5 % 7 = 5
             6 % 7 = 6
             7 % 7 = 0
             8 % 7 = 1
             7 % 7 = 7

        */

        res[j] = nums[i];

    }

    nums = std::move(res);


    for (int num : res) {
        std::cout << num << ',';
    }

}