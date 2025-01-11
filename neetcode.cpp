//NEETCODE 150- Contains Duplicates

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

