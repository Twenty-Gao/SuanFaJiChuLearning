#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //这是我自己写的方法
    //     vector<int> out = [];
    // m * = vlaue for vlaue in p;
    // plus += value for value in p;
    // for(int i = 0;i<s.len()-2;i++{
    //     if(s[i]*s[i+1]*s[i+2]==m && s[i]+s[i+1]+s[i+2] == plus)
    //     out.appned(i);
    // }
	if (s.size() < p.size()){
            return vector<int>();
        }
    // return out;
    std::vector<int> out;
    //定义变量查看每个单词的数量
    int p_numbers[26] = {0};
    int s_numbers[26] = {0};
    //定义一个队列
    //其实不需要定义一个队列，因为我发现 动态数组就是一个队列 
    std::queue<char> q;
    for (int i = 0 ;i<p.size();i++){
        q.push(s[i]);
        p_numbers[int(p[i])-97]++;
        int x = int(s[i])-97;
        s_numbers[int(s[i])-97]++;
    }
    int len = 0;
    len = p.size();
//查看数组是否相等
    bool flag = true;
    for(int i =0 ;i<26;i++){
        if(p_numbers[i]!=s_numbers[i]){
            flag = false;
        }
    }
    if (flag){
        out.push_back(0);
		}

    //对队列进行变换
    for (int i =len;i<s.size();i++){
        int s_number  = int(q.front())-97;
        s_numbers[s_number]--;
//        cout<<s_number<<endl;

		q.push(s[i]);
		q.pop();
		cout<<q.back()<<endl;
        s_number  = int(q.back())-97;
        s_numbers[s_number]++;
//		cout<<s_number<<endl;
        flag = true;
            for(int j =0 ;j<26;j++){
                if(p_numbers[j]!=s_numbers[j]){
                    flag = false;
                }
            }
            if (flag){
                out.push_back(i-len+1);}
    }
    return out;
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
		cout<<"结果="<<result[i];
	}
	
}


