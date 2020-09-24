#include <stdio.h>
#include <iostream> 

int cube[6][3][3] //색깔 : 흰색(0), 빨강(1), 노랑(2), 주황(3), 파랑(4), 초록(5)

//큐브 공식 참고 사이트 : https://m.blog.naver.com/bluebirdkids/220691361547 
void UO(){ //윗면 시계방향 (up original) 방향회전 참고 사이트 : https://cube3x3.com/%ED%81%90%EB%B8%8C%EB%A5%BC-%EB%A7%9E%EC%B6%94%EB%8A%94-%EB%B0%A9/ 
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

void UU(){ //윗면 역시계방향 (up unverse)
	
}

void LO(){ //왼면 시계방향 (left original) 
	
}

void LU(){ //왼면 역시계방향 (left unverse) 
	
}

void FO(){ //앞면 시계방향 (front original) 
	
}

void FU(){ //앞면 시계방향 (front original)
	
}

void RO(){ //오른면 시계방향 (right original) 
	
}

void RU(){ //오른면 시계방향 (right original)
	
}

void BO(){ //뒷면 시계방향 (back original) 
	
}

void BU(){ //뒷면 시계방향 (back original)
	
}

void DO(){ //아랫면 시계방향 (down original) 
	
}

void DU(){ //아랫면 시계방향 (down original)
	
}

int main(){
	int i, j, k;
	for(i = 0; i < 6; i++){				//면 
		for(j = 0; j < 3; j++){			//열 
			for(k = 0; k < 3; k++){		//행 
				scanf("%d", &cube[i][j][k]); 
			}
		}
	}
	//1단계 십자 맞추기 
}
