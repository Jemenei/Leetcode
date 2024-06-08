#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

class Solution {
public:
    vector<vector<int> > fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        set<vector<int> > uniqueQuadruplets;
        vector<vector<int> > output;

        for(int i = 0; i < n - 3; i++) {
            for(int j = i + 1; j < n - 2; j++) {
                long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
                int low = j + 1, high = n - 1;
                
                while(low < high) {
                    if((long long)nums[low] + (long long)nums[high] < newTarget) {
                        low++;
                    } else if((long long)nums[low] + (long long)nums[high] > newTarget) {
                        high--;
                    } else {
                        vector<int> quadruplet;
                        quadruplet.push_back(nums[i]);
                        quadruplet.push_back(nums[j]);
                        quadruplet.push_back(nums[low]);
                        quadruplet.push_back(nums[high]);
                        uniqueQuadruplets.insert(quadruplet);
                        low++; 
                        high--;
                    }
                }
            }
        }

        for(set<vector<int> >::iterator it = uniqueQuadruplets.begin(); it != uniqueQuadruplets.end(); ++it) {
            output.push_back(*it);
        }
        
        return output;
    }
};

int main() {
    Solution solution;

    vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(0);
    nums1.push_back(-1);
    nums1.push_back(0);
    nums1.push_back(-2);
    nums1.push_back(2);

    int target1 = 0;
    vector<vector<int> > res1 = solution.fourSum(nums1, target1);
    cout << "Output for nums = [1,0,-1,0,-2,2], target = 0:" << endl;
    for (size_t i = 0; i < res1.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < res1[i].size(); j++) {
            cout << res1[i][j];
            if (j < res1[i].size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    vector<int> nums2;
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(2);

    int target2 = 8;
    vector<vector<int> > res2 = solution.fourSum(nums2, target2);
    cout << "Output for nums = [2,2,2,2,2], target = 8:" << endl;
    for (size_t i = 0; i < res2.size(); i++) {
        cout << "[";
        for (size_t j = 0; j < res2[i].size(); j++) {
            cout << res2[i][j];
            if (j < res2[i].size() - 1) cout << ",";
        }
        cout << "] ";
    }
    cout << endl;

    return 0;
}
