#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
    	vector<int> num(size, 1);
        for(int i = 0 ;i<ratings.size()-1;i++){
            if (ratings[i]<ratings[i+1]){
                num[i+1] = num[i] + 1;
            }
        }

        for(int i = ratings.size()-1 ;i>0;i--){
            if (ratings[i]<ratings[i-1]){
                 num[i-1] = max(num[i-1], num[i] + 1)
            }
        }

        return counts;
    }
};


int main(){
    vector<int> ratings = {1,3,2,2,1};
    Solution sol;                
    cout << sol.candy(ratings);  
}
	
