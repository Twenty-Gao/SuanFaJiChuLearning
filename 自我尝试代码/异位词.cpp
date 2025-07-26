#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        //�������Լ�д�ķ���
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
    //��������鿴ÿ�����ʵ�����
    int p_numbers[26] = {0};
    int s_numbers[26] = {0};
    //����һ������
    //��ʵ����Ҫ����һ�����У���Ϊ�ҷ��� ��̬�������һ������ 
    std::queue<char> q;
    for (int i = 0 ;i<p.size();i++){
        q.push(s[i]);
        p_numbers[int(p[i])-97]++;
        int x = int(s[i])-97;
        s_numbers[int(s[i])-97]++;
    }
    int len = 0;
    len = p.size();
//�鿴�����Ƿ����
    bool flag = true;
    for(int i =0 ;i<26;i++){
        if(p_numbers[i]!=s_numbers[i]){
            flag = false;
        }
    }
    if (flag){
        out.push_back(0);
		}

    //�Զ��н��б任
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
	// ���þ�̬����
	// �������󲢵��ú���
	Solution sol;
	vector<int> result = sol.findAnagrams(s, p);
	for(int i =0 ;i<result.size();i++){
		cout<<"���="<<result[i];
	}
	
}


