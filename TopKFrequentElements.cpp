/*

Given array of int nums [1, 2, 1] and an int k, return the k most frequent elements.

ex = [1, 2, 1]
k = 1

return [1]

ex = [1, 2, 2, 2, 1]

return [2, 1] 


*/

#include <vector> 
#include <iostream>
#include <unordered_map>
#include <queue>


struct Compare {

   // functor?
   bool operator() (const std::vector<int>& a, const std::vector<int>& b) {
            
        return a[1] < b[1];
   }

};

class Solution {

public:
   

   std::vector<int> topKFrequent(std::vector<int> nums, int k) {
        
        // Store the counts of each number in a map because we will use the count to push to a priority queue           // pop off the priortiy queue up to k and that would be the k most frequent
        
        std::unordered_map<int, int> map;

        for (int num : nums) {
               
             auto it = map.find(num);

             // Can't find the key
             if (it == map.end()) {
              
              // add the key
                map[num] = 1;

             } else {
               
               map[num] = it->second + 1;

             }

        }
        
        // type, container, comparator
        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, Compare> pq;

        for(auto pair : map) {
            
            std::cout << "Pushing " << pair.first << ": " << pair.second << '\n';
            
            pq.push({pair.first, pair.second});

        }

        std::vector<int> res;
           
        int popped = 0;

        while (!pq.empty() && popped != k) {
           
            std::vector<int> pair = pq.top();

            res.push_back(pair[0]); 

            pq.pop();

            popped += 1;
        }

        return res;
   }
};

int main() {

    Solution s;

    std::vector<int> res = s.topKFrequent({1, 1, 2, 2, 2}, 1);

    for (int num : res) {
        
        std::cout << num << '\n';
    
    }
    
    return 0;

}
