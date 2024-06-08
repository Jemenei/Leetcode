#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest_sum = nums[0] + nums[1] + nums[2];
        
        for (int i = 0; i < nums.size() - 2; ++i) {
            int left = i + 1;
            int right = nums.size() - 1;
            
            while (left < right) {
                int current_sum = nums[i] + nums[left] + nums[right];
                
                if (current_sum == target) {
                    return current_sum;
                }
                
                if (abs(current_sum - target) < abs(closest_sum - target)) {
                    closest_sum = current_sum;
                }
                
                if (current_sum < target) {
                    ++left;
                } else {
                    --right;
                }
            }
        }
        
        return closest_sum;
    }
};

int main() {
    Solution solution;
    vector<int> nums;
    nums.push_back(-1);
    nums.push_back(2);
    nums.push_back(1);
    nums.push_back(-4);
    int target = 1;
    cout << "Closest sum to target: " << solution.threeSumClosest(nums, target) << endl;

    return 0;
}
