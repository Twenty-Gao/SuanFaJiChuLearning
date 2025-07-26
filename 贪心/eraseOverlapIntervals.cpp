#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>  // ����sort����
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

	// ���μ��ǰһ��ĩβ�ͺ�һ����λ��ֵ 
	// ����ǰһ����ĩβ 
	int pre = intervals[0][1] ;
	for (int i=0;i<n-1;i++){
		if(pre> intervals[i+1][0]){
			// ǰ����ں��� ����ĩβ��С������
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
	// ���þ�̬����
	// �������󲢵��ú���
	Solution sol;
	int result = sol.eraseOverlapIntervals(intervals);
	cout<<result;
	
}
