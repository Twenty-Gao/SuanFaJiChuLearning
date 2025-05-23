#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	//获取s和p的字符串的长度 
        int sLen = s.size(), pLen = p.size();

		//好聪明，如果要找的字符串长度大于寻找的字符串长度，就不存在异位词 
        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
//        很聪明，两个字符串相减的值是一个整数
//		这里 得出每个字母的数量 
        for (int i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];
            ++pCount[p[i] - 'a'];
        }
        
        
		std::cout << "sCount=[";
	    for (size_t i = 0; i < sCount.size(); ++i) {
	        std::cout << sCount[i];
	        if (i != sCount.size() - 1) {
	            std::cout << ", ";
	        }
	    }
	    std::cout << "]" << std::endl;
	    std::cout << "pCount=[";
	    for (size_t i = 0; i < pCount.size(); ++i) {
	        std::cout << pCount[i];
	        if (i != pCount.size() - 1) {
	            std::cout << ", ";
	        }
	    }
	    std::cout << "]" << std::endl;
//     动态数组居然可以直接判断相不相等 
        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
        	//将遍历到的这个单词从s中删除
			//将这个单词后plen个的单词添加上去 
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];

            if (sCount == pCount) {
                ans.emplace_back(i + 1);
            }
        }

        return ans;
    }
};


int main(){
	string s = "cbaebabacd";
	string p = "abc";
	// 调用静态方法
	// 创建对象并调用函数
	Solution sol;
	vector<int> result = sol.findAnagrams(s, p);
	for(int i =0 ;i<result.size();i++){
		cout<<result[i];
	}
	
}
