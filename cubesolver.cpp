#include <stdio.h>
#include <iostream> 

int cube[6][3][3] //���� : ���(0), ����(1), ���(2), ��Ȳ(3), �Ķ�(4), �ʷ�(5)

//ť�� ���� ���� ����Ʈ : https://m.blog.naver.com/bluebirdkids/220691361547 
void UO(){ //���� �ð���� (up original) ����ȸ�� ���� ����Ʈ : https://cube3x3.com/%ED%81%90%EB%B8%8C%EB%A5%BC-%EB%A7%9E%EC%B6%94%EB%8A%94-%EB%B0%A9/ 
	int temp[3][3], i, j;
	temp[0][0] = cube[1][0][0];
	temp[0][1] = cube[1][0][1];
	temp[0][2] = cube[1][0][2];
	for(i = 1; i <= 3; i++){
		for(j = 0; j < 3; j++){
			cube[i][0][j] = cube[i+1][0][j];
		}
	}
	for(j = 0; j < 3; j++){
			cube[4][0][j] = temp[0][j];
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[0][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[0][i][j] = temp[2-j][i];
		}
	}
}

void UU(){ //���� ���ð���� (up unverse)
	
}

void LO(){ //�޸� �ð���� (left original) 
	
}

void LU(){ //�޸� ���ð���� (left unverse) 
	
}

void FO(){ //�ո� �ð���� (front original) 
	
}

void FU(){ //�ո� �ð���� (front original)
	
}

void RO(){ //������ �ð���� (right original) 
	
}

void RU(){ //������ �ð���� (right original)
	
}

void BO(){ //�޸� �ð���� (back original) 
	
}

void BU(){ //�޸� �ð���� (back original)
	
}

void DO(){ //�Ʒ��� �ð���� (down original) 
	
}

void DU(){ //�Ʒ��� �ð���� (down original)
	
}

int main(){
	int i, j, k;
	for(i = 0; i < 6; i++){				//�� 
		for(j = 0; j < 3; j++){			//�� 
			for(k = 0; k < 3; k++){		//�� 
				scanf("%d", &cube[i][j][k]); 
			}
		}
	}
	//1�ܰ� ���� ���߱� 
}
