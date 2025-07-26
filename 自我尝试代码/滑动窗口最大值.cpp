#include <iostream>
#include <vector>
using namespace std; 


//≥¨ ±¡À 
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	vector<int> out;
        vector<int> chuangkou;
        int max = nums[0];
        for(int i=0;i<k;i++){
        	if(max<nums[i]){
        		max = nums[i];
			}
        	chuangkou.push_back(nums[i]);
        	
		}
		out.push_back(max);
		for(int i = k;i<nums.size();i++){
			chuangkou.erase(chuangkou.begin());
			chuangkou.push_back(nums[i]);
			bool flag = false;
			if(max == nums[i-k]){
					if(max<nums[i]){
        			max = nums[i];
        			flag = true;
			}
			}
			else{
				max = nums[i];
        		for(int j=0;j< k;j++){
        			if(max<chuangkou[j]){
        				max = chuangkou[j];
			}
			}
			
			
		}
		if (!flag){
			max = nums[i];
        		for(int j=0;j< k;j++){
        			if(max<chuangkou[j]){
        				max = chuangkou[j];
			}
		}}
		out.push_back(max);
    }
    return out;
}
};


int main(){
	vector<int> nums = {1,-1};
	int k = 1 ;
	Solution sol;
	vector<int> result = sol.maxSlidingWindow(nums,k);

	for (int i =0;i<result.size();i++){
		cout<<result[i];
	}
	
	
}
