#include<iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> a = {1,2,3};
	
	//��ӡ��̬����
	for(int i =0; i<a.size();i++){
		cout<<a[i];
	} 
	cout<<endl;
	//��������Ԫ��
	a.push_back(4);
	
	for(int i =0; i<a.size();i++){
		cout<<a[i];
	} 
	
	vector<int> b(26);
	vector<int> c(26);
	
	b[1] = 0;
	
	if (c==b){
		cout<<"���";
	}
	
	
} 
