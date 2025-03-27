#include<iostream>
using namespace std;
//完美立方：编写一个程序，对给定的正整数N（N<=100）
//寻找所有的四元组
//使得a**3 = b**3+c**3+d**3.
//其中1<a,b,c,d<=N
//枚举：


int main(){
	int n;
//输入N
	cin>>n; 
// a 从小到大开始遍历；bcd的值都小于a；为了防止重复输出，c只遍历不小于b的值，d只遍历不小于c的值 
	for(int a_number = 4; a_number <= n; a_number++){
		for(int b_number = 1; b_number < a_number; b_number++){
			for(int c_number = b_number; c_number < a_number; c_number++){
				for(int d_number = c_number; d_number < a_number; d_number++){
					if(a_number*a_number*a_number == b_number*b_number*b_number+c_number*c_number*c_number+d_number*d_number*d_number){
						cout<<"Cube="<<a_number<<",Triple=("<<b_number<<","<<c_number<<","<<d_number<<")"<<endl;
				}
			}
		}
	}
}
}
