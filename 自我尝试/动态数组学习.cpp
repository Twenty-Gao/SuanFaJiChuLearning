#include<iostream>
#include <vector>
using namespace std;
int main(){
	vector<int> a = {1,2,3};
	
	//打印动态数组
	for(int i =0; i<a.size();i++){
		cout<<a[i];
	} 
	cout<<endl;
	//添加数组的元素
	a.push_back(4);
	
	for(int i =0; i<a.size();i++){
		cout<<a[i];
	} 
	
	vector<int> b(26);
	vector<int> c(26);
	
	b[1] = 0;
	
	if (c==b){
		cout<<"相等";
	}
	
	
} 
