#include <iostream>
#include <vector>
#include <queue>
using namespace std; 

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    	
    	//优先队列
		priority_queue<pair<int, int>> q;
		vector<int> result;
		for(int i =0;i<k;i++){
			q.emplace(nums[i],i);
		}
		result.push_back(q.top().first);
		
		for(int i = k;i<nums.size();i++){
			q.emplace(nums[i],i);
			while(q.top().second < i){
				q.pop(); 
			}
			result.push_back(q.top().first);
		}
		return result;
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
