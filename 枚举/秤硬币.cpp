#include<iostream>
#include<string>
#include <cstring>
using namespace std;


//有12枚硬币，其中有11枚真币和1枚假币。假币和真币的重量不同，但不知道假币比真币重还是比真币轻。
//现在用一架天平称了三次并告诉你结果
//请你找出假币是轻还是重

//枚举有24种可能
//1.币为轻 2.币为重的 


//检验假设 
bool  isFale(char coin,bool weight, string left[], string right[], char result[][7]){
		
		//常规想法可能是：将币的假设依次带入给出的天平结果中，若结果与实际的结果不同则假设失败
		
		//郭老师的方法是反过来，根据天平的结果反推出假币应该在的位置，若位置上没有假币，则假设失败
		//天平结果为u，且假设为轻币，那么币应当在右边,如果不在右边则假设失败 
		//天平结果为u，且假设为重币，那么币应当在左边,如果不在左边则假设失败 
		//天平结果为e，那么天平上应该没有假币，如果在天平上则假设失败 
		//天平结果为d, 且假设为轻币，那么币应当在左边,如果不在左边则假设失败 
		//天平结果为d，且假币为重币，那么币应当在右边,如果不在右边则假设失败  
		
		//遍历天平结果 
		for (int i = 0; i < 3; i++){
			if(result[i][0] == 'u' && !weight){ 
				if(!strchr(right[i].c_str(),coin)){
					return false;
				}
			}
			else if(result[i][0] == 'u' && weight){
				if(!strchr(left[i].c_str(),coin)){
					return false;
				}
			}
			else if(result[i][0] == 'e'){
				if(strchr((right[i]+left[i]).c_str(),coin)){
					return false;
				}
			}
			else if(result[i][0] == 'd' && !weight){
				if(!strchr(left[i].c_str(),coin)){
					return false;
				}
			}
			else if(result[i][0] == 'd' && weight){
				if(!strchr(right[i].c_str(),coin)){
					return false;
				}
			}
		}
		
		
		return true;
		 
		
	}
	
int main(){
	
	//输入天平结果
	std::string left[3];
	std::string right[3];
	char result[3][7];
	for(int i = 0;i < 3;i++){
		cin>>left[i]>>right[i]>>result[i];
	}

	for(char coin = 'A';coin <= 'L';coin++){
		if(isFale(coin,false,left,right,result)){
			cout<<coin<<"是假币，此假币为轻币"<<endl;
		}
		else if(isFale(coin,true,left,right,result)){
			cout<<coin<<"是假币，此假币为重币"<<endl;
		}
	}
	
	
} 
