#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
    	//��ȡs��p���ַ����ĳ��� 
        int sLen = s.size(), pLen = p.size();

		//�ô��������Ҫ�ҵ��ַ������ȴ���Ѱ�ҵ��ַ������ȣ��Ͳ�������λ�� 
        if (sLen < pLen) {
            return vector<int>();
        }

        vector<int> ans;
        vector<int> sCount(26);
        vector<int> pCount(26);
//        �ܴ����������ַ��������ֵ��һ������
//		���� �ó�ÿ����ĸ������ 
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
//     ��̬�����Ȼ����ֱ���ж��಻��� 
        if (sCount == pCount) {
            ans.emplace_back(0);
        }

        for (int i = 0; i < sLen - pLen; ++i) {
        	//����������������ʴ�s��ɾ��
			//��������ʺ�plen���ĵ��������ȥ 
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
	// ���þ�̬����
	// �������󲢵��ú���
	Solution sol;
	vector<int> result = sol.findAnagrams(s, p);
	for(int i =0 ;i<result.size();i++){
		cout<<result[i];
	}
	
}
