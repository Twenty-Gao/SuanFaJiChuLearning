#include<iostream>
using namespace std;
//������������дһ�����򣬶Ը�����������N��N<=100��
//Ѱ�����е���Ԫ��
//ʹ��a**3 = b**3+c**3+d**3.
//����1<a,b,c,d<=N
//ö�٣�


int main(){
	int n;
//����N
	cin>>n; 
// a ��С����ʼ������bcd��ֵ��С��a��Ϊ�˷�ֹ�ظ������cֻ������С��b��ֵ��dֻ������С��c��ֵ 
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
