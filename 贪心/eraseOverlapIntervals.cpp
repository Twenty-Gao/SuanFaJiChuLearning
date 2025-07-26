#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>  // 用于sort函数
using namespace std;


class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
	int counts = 0;
	// sort the list
	int n = intervals.size();
	
	sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b){
		return a[0]<b[0];
	});

	// 依次检查前一个末尾和后一个首位的值 
	// 保存前一个的末尾 
	int pre = intervals[0][1] ;
	for (int i=0;i<n-1;i++){
		if(pre> intervals[i+1][0]){
			// 前面大于后面 则保留末尾较小的数据
			 if(pre<= intervals[i+1][1]){
			 	pre = pre;
			 }
			 else{
			 	pre = intervals[i+1][1];
			 }
			 counts++;
		}
		else{
			pre = intervals[i+1][1];
		}
		
	}
	
	return counts;
	 
	} 
};


int main(){
	vector<vector<int>> intervals = {{1,2},{1,2},{1,2},{1,2}};
	// 调用静态方法
	// 创建对象并调用函数
	Solution sol;
	int result = sol.eraseOverlapIntervals(intervals);
	cout<<result;
	
}
