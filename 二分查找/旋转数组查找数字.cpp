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
    // ʾ�������ظ�Ԫ�ص���ת����
    vector<int> nums = {1,1,1,1,1,1,1,1,1,1,1,1,1,2,1,1,1,1,1};
    int target = 2;
    
    Solution solution;
    bool found = solution.search(nums, target);
    
    if (found) {
        cout << "Ŀ��ֵ " << target << " ������������" << endl;
    } else {
        cout << "Ŀ��ֵ " << target << " ��������������" << endl;
    }
    
    return 0;
}

