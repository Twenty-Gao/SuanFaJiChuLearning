#include<iostream>
using namespace std;
//for 语句实现
 
//人体有体力、情商、智商的高峰日子；
//它们分每隔23天、28天和33天出现一次； 
//给定三个高峰出现的日子p、e和i（不一定是第一次出现高峰的日子）
//再给定另一个指定的日子d； 
//任务是：输出日子d后，下一次三个高峰落在同一天的日子（用距离d的天数表示）
//所求日子小于等于 21252
int main(){
	// 某一天next_d是体力的高峰日子：(next_d-p)%23==0 
    //某一天next_d是情商的高峰日子：(next_d-e)%28==0
	//某一天next_d是智商的高峰日子：(next_d-i)%33==0
	
	//输入
	int p,e,i,d = 0;
	cin>>p>>e>>i>>d; 
	
	int next_d = d + 1;
	
	//这是没有简化的方法 
//	while(next_d <= 21252){
//		if((next_d-p)%23==0 && (next_d-e)%28==0 && (next_d-i)%33==0){
//			break; 
//		}
//} 

	 for(;next_d<=21252;next_d++){
	 	if((next_d-p)%23==0){
	 		for(;next_d<=21252;next_d+=23){
	 			if((next_d-e)%28==0){
	 				for(;next_d<=21252;next_d+=23*28){
	 					if((next_d-i)%33==0){
	 							cout<<next_d-d;
	 							break;
						 }
	 				}
				 }
		 }
	}
}
	 	
	 		
	 			
	return 0;
} 
