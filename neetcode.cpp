// NEETCODE 150- Valid Anagrams 

class Solution {
public:
    bool isAnagram(string s, string t) {
        // attempt at a hashing method

        unordered_map<char, int> example;

        // insert string s while also updating count value for repeat characters
        for (int i = 0; i < s.length(); i++) {
            char key = s[i];

            // Search the key
            auto it = example.find(key);

            // Checking if key present or not
            if (it != example.end())
                example[key]++;
            else
                example.insert({key, 1});
        }

        for (int i = 0; i < t.length(); i++) {
            auto it = example.find(t[i]);

            if (it != example.end()){
                example[t[i]]--;
                if (example[t[i]] == 0)
                    example.erase(t[i]);
            }
            else
                return false;
        }

        if (example.empty())
            return true;
        else
            return false;    
    }
};

// NEETCODE 150- Contains Duplicates

#include <vector>

class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // need to make sure vector is sorted 
        std::sort (nums.begin(), nums.end());
        for(int i = 0; i < nums.size()-1; i++){
            if (nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};

