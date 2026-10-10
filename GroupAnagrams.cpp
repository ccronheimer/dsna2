/*

Given a list of strings group the anagrams together.

Anagram is the following

s = "cab"
t = "bac"

return an array of array of strings that are grouped as anagrams

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

class Solution {

public:

    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> strs) {
      
      /*
            Detect anagram if length is the same and after sorting they are the same
            
            [cat, tab, bat, tac]
            
            We can't really compare each str like we do with validAnagram so we need another look up strategy.

            1. sort the str and store as a key in a map along with that value
                q. Should the values in the array also be sorted or stored as is?

                <act, [cat, tac]>
                <abt, [tab, bat]>

            define the map 

            for str in strs {
    
                if map.find(str.sort()) {
                    
                    Get reference to array at key 

                    map.getValue
                }
            }
      */

        std::unordered_map<std::string, std::vector<std::string>> map;
       
        for(int i = 0; i < strs.size(); i++) {
           
            std::string real_val = strs[i];

            std::cout << "Storing real value: " << real_val << '\n';
            // act
            std::sort(strs[i].begin(), strs[i].end());

            std::string key = strs[i]; 

            std::cout << "checking real value: " << real_val << '\n';

            std::cout << "Searching for key: " << key << '\n';

            // use auto because map.find returns a pair<key, value> type
            auto it = map.find(key);

            // If the iterator does not reach the end of the map
            if(it != map.end()) {
                
                std::cout << "Key exists in map: " << it->first << '\n';
                 
                // Get the array of strings (anagrams) at this key
                std::vector<std::string>& vals = it->second;
                std::cout << "Pushing " << real_val << '\n';
                vals.push_back(real_val);
                
            } else {
                
               map[strs[i]] = {real_val};

            } 
        }

        std::cout << "Looping through the map" << '\n';
        
        std::vector<std::vector<std::string>> res = {};

        for(const auto& pair : map) {
             
            res.push_back(pair.second);

        }

        for(const std::vector<std::string> anagrams : res) {

           std::cout << '[';
           for(std::string anagram : anagrams) {
              
              std::cout << anagram << ',';
           }

           std::cout << ']' << '\n';
        }

         return res;
    } 
};

int main() {

    Solution s;
    
    s.groupAnagrams({"cat", "tab", "bat", "atb"});
    
}
