#include<iostream>
#include<string>
#include <cstring>
using namespace std;


//��12öӲ�ң�������11ö��Һ�1ö�ٱҡ��ٱҺ���ҵ�������ͬ������֪���ٱұ�����ػ��Ǳ�����ᡣ
//������һ����ƽ�������β���������
//�����ҳ��ٱ����ỹ����

//ö����24�ֿ���
//1.��Ϊ�� 2.��Ϊ�ص� 


//������� 
bool  isFale(char coin,bool weight, string left[], string right[], char result[][7]){
		
		//�����뷨�����ǣ����ҵļ������δ����������ƽ����У��������ʵ�ʵĽ����ͬ�����ʧ��
		
		//����ʦ�ķ����Ƿ�������������ƽ�Ľ�����Ƴ��ٱ�Ӧ���ڵ�λ�ã���λ����û�мٱң������ʧ��
		//��ƽ���Ϊu���Ҽ���Ϊ��ң���ô��Ӧ�����ұ�,��������ұ������ʧ�� 
		//��ƽ���Ϊu���Ҽ���Ϊ�رң���ô��Ӧ�������,���������������ʧ�� 
		//��ƽ���Ϊe����ô��ƽ��Ӧ��û�мٱң��������ƽ�������ʧ�� 
		//��ƽ���Ϊd, �Ҽ���Ϊ��ң���ô��Ӧ�������,���������������ʧ�� 
		//��ƽ���Ϊd���Ҽٱ�Ϊ�رң���ô��Ӧ�����ұ�,��������ұ������ʧ��  
		
		//������ƽ��� 
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
	
	//������ƽ���
	std::string left[3];
	std::string right[3];
	char result[3][7];
	for(int i = 0;i < 3;i++){
		cin>>left[i]>>right[i]>>result[i];
	}

	for(char coin = 'A';coin <= 'L';coin++){
		if(isFale(coin,false,left,right,result)){
			cout<<coin<<"�Ǽٱң��˼ٱ�Ϊ���"<<endl;
		}
		else if(isFale(coin,true,left,right,result)){
			cout<<coin<<"�Ǽٱң��˼ٱ�Ϊ�ر�"<<endl;
		}
	}
	
	
} 
