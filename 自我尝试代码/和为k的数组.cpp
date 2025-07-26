#include <iostream>
#include <vector> 
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int nlen = nums.size();
        int count =0;
        
        for(int i =0;i<nlen;i++){
        	int sum = 0;
        	for(int j=i;j<nlen;j++){
        		sum += nums[j];
        		if(sum==k){
        			count++;
				}
			}
		}
		
		return count;
    }
};

int main(){
	vector<int> nums = {1,1,1};
	int k = 2;

	Solution sol;
	int result = sol.subarraySum(nums,k);
	cout<<result;
}
