#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> quadruplets;
        int n = nums.size();
        if (n < 4) return quadruplets;

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n - 3; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;

            long long minSumFirst = (long long)nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3];
            if (minSumFirst > target) break;

            long long maxSumFirst = (long long)nums[i] + nums[n - 3] + nums[n - 2] + nums[n - 1];
            if (maxSumFirst < target) continue;

            for (int j = i + 1; j < n - 2; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;

                long long minSumSecond = (long long)nums[i] + nums[j] + nums[j + 1] + nums[j + 2];
                if (minSumSecond > target) break;

                long long maxSumSecond = (long long)nums[i] + nums[j] + nums[n - 2] + nums[n - 1];
                if (maxSumSecond < target) continue;

                int left = j + 1, right = n - 1;
                while (left < right) {
                    long long total = (long long)nums[i] + nums[j] + nums[left] + nums[right];

                    if (total == target) {
                        quadruplets.push_back({nums[i], nums[j], nums[left], nums[right]});
                        
                        ++left;
                        --right;
                        while (left < right && nums[left] == nums[left - 1]) ++left;
                        while (left < right && nums[right] == nums[right + 1]) --right;
                    } 
                    else if (total < target) {
                        ++left;
                    } 
                    else {
                        --right;
                    }
                }
            }
        }

        return quadruplets;
    }
};
