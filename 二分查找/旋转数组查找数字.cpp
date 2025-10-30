#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int mid = 0;
        
        while(l<r){
            mid = l+ (r-l)/2;
            if(nums[l]<nums[mid] && target<nums[mid]){
                r = mid;
            }
            else if (nums[l]<nums[mid] && target >nums[mid]){
                l = mid;
            }
            else if (nums[r]>=nums[mid] && target < nums[mid]){
                r = mid;
            }
            else if (nums[r]>=nums[mid] && target>nums[mid]){
                l = mid;
            }
            else if (target == nums[mid]){
                return true;
            }
            else if (nums[mid] == nums[l]){
                l++;
            }
        }
        if (target == nums[mid]){
                return true;
            }
            return false;

    }
};


int main() {
    // 示例：含重复元素的旋转数组
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int target = 2;
    
    Solution solution;
    bool found = solution.search(nums, target);
    
    if (found) {
        cout << "目标值 " << target << " 存在于数组中" << endl;
    } else {
        cout << "目标值 " << target << " 不存在于数组中" << endl;
    }
    
    return 0;
}

