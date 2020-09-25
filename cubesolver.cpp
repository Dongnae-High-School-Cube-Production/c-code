#include <stdio.h>
int cube[6][3][3]; //색깔 : 흰색(0), 빨강(1), 파랑(2), 주황(3), 초록(4), 노랑(5)

//큐브 공식 참고 사이트 : https://m.blog.naver.com/bluebirdkids/220691361547 
void UO(){ // 윗면 시계방향 (up original) 방향회전 참고 사이트 : https://cube3x3.com/%ED%81%90%EB%B8%8C%EB%A5%BC-%EB%A7%9E%EC%B6%94%EB%8A%94-%EB%B0%A9/ 
	int temp[3][3], i, j;
	
	for(i=0 ; i < 3; i++){
		temp[0][i] = cube[1][0][i];
	}
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

void UU(){ // 윗면 역시계방향 (up unverse)
	int temp[3][3], i, j;
	
	for(i = 0 ; i < 3; i++){
		temp[0][i] = cube[4][0][i];
	}
	for(i = 3; i >= 1; i--){
		for(j = 0; j < 3; j++){
			cube[i+1][0][j] = cube[i][0][j];
		}
	}
	for(j = 0; j < 3; j++){
			cube[1][0][j] = temp[0][j];
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[0][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[0][i][j] = temp[j][2-i];
		}
	}
}

void LO(){ //왼면 시계방향 (left original) 
	int temp[3][3], i, j,cnt=2;
	
	for(i = 0 ; i < 3; i++){
		temp[i][0] = cube[1][i][0];
	}
	for(j = 0; j < 3; j++){
		cube[1][j][0] = cube[0][j][0];
		cube[0][j][0] = cube[3][cnt][2];
		cube[3][cnt--][2] = cube[5][j][0];
		cube[5][j][0] = temp[j][0];
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[4][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[4][i][j] = temp[2-j][i];
		}
	}
}

void LU(){ //왼면 역시계방향 (left unverse) 
	int temp[3][3], i, j ,cnt=2;
	
	for(i = 0; i < 3; i++){
		temp[i][0] = cube[1][i][0];
	}
	for(j = 0;j < 3; j++){
		cube[1][j][0] = cube[5][j][0];
		cube[5][j][0] = cube[3][cnt][2];
		cube[3][cnt--][2] = cube[0][j][0];
		cube[0][j][0] = temp[j][0];
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[4][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[4][i][j] = temp[j][2-i];
		}
	}
}
void FO(){ //앞면 시계방향 (front original) 
	int temp[3][3], i ,j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[1][i][j];
		}
	}
	for(i  = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[1][i][j] = temp[2-j][i];
		}
	}
	for(i = 0; i < 3; i++){
		temp[0][i] = cube[0][2][i];
	}
	for(i = 0 ; i < 3; i++){
		cube[0][2][i] = cube[4][2-i][2];
		cube[4][2-i][2] = cube[5][0][2-i];
		cube[5][0][2-i] = cube[2][i][0];
		cube[2][i][0] = temp[0][i];
	}
}

void FU(){ //앞면 시계방향 (front original)
	int temp[3][3], i, j;
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[1][i][j];
		}
	}
	for(i  = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[1][i][j] = temp[j][2-i];
		}
	}
	for(i = 0; i < 3; i++){
		temp[0][i] = cube[0][2][i];
	}
	for(i = 0; i < 3; i++){
		cube[0][2][i] = cube[2][i][0];
		cube[2][i][0] = cube[5][0][2-i];
		cube[5][0][2-i] = cube[4][2-i][2];
		cube[4][2-i][2] = temp[0][i];
	}
}

void RO(){ //오른면 시계방향 (right original) 
	int temp[3][3], i, j;
	for(i = 0; i < 3; i++){
		temp[0][i] = cube[0][i][2];
	}
	for(i = 0;i < 3; i++){
		cube[0][i][2] = cube[1][i][2];
		cube[1][i][2] = cube[5][i][2];
		cube[5][i][2] = cube[3][2-i][0];
		cube[3][2-i][0] = temp[0][i];
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[2][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[2][i][j] = temp[2-j][i];
		}
	}
}

void RU(){ //오른면 역시계방향 (right original)
	int temp[3][3], i, j;
	for(i = 0; i < 3; i++){
		temp[0][i] = cube[0][i][2];
	}
	for(i = 0; i < 3; i++){
		cube[0][i][2] = cube[3][2-i][0];
		cube[3][2-i][0] = cube[5][i][2];
		cube[5][i][2] = cube[1][i][2];
		cube[1][i][2] = temp[0][i];
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[2][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[2][i][j] = temp[j][2-i];
		}
	}
}

void BO(){ //뒷면 시계방향 (back original) 
	int temp[3][3], i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			temp[i][j] = cube[3][i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cube[3][i][j] = temp[2 - j][i];
		}
	}
	for(i = 0; i < 3; i++){
		temp[0][i] = cube[0][0][i];
	}
	for(i = 0; i < 3; i++){
		cube[0][0][i] = cube[2][i][2];
		cube[2][i][2] = cube[5][2][2-i];
		cube[5][2][2-i] = cube[4][2-i][0];
		cube[4][2-i][0] = temp[0][i];
	}
}

void BU(){ //뒷면 시계방향 (back original)
	int temp[3][3], i, j;
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			temp[i][j] = cube[3][i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		for (j = 0; j < 3; j++) {
			cube[3][i][j] = temp[j][2 - i];
		}
	}
	for(i = 0; i < 3; i++){
		temp[0][i] = cube[0][0][i];
	}
	for(i = 0; i < 3; i++){
		cube[0][0][i] = cube[4][2-i][0];
		cube[4][2-i][0] = cube[5][2][2-i];
		cube[5][2][2-i] = cube[2][i][2];
		cube[2][i][2] = temp[0][i]; 
	}
}

void DO(){ //아랫면 시계방향 (down original)  
	int temp[3][3], i, j;
	
	for(i=0;i<3;i++){
		temp[0][i] = cube[1][2][i];
	}
	for(i=0;i<3;i++){
		cube[1][2][i] = cube[4][2][i];
		cube[4][2][i] = cube[3][2][i];
		cube[3][2][i] = cube[2][2][i];
		cube[2][2][i] = temp[0][i];
	}
	
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[5][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[5][i][j] = temp[2-j][i];
		}
	}
}

void DU(){ //아랫면 역시계방향 (down original)
	int temp[3][3], i, j;
	
	for(i=0;i<3;i++){
		temp[0][i] = cube[1][2][i];
	}
	for(i=0;i<3;i++){
		cube[1][2][i] = cube[2][2][i];
		cube[2][2][i] = cube[3][2][i];
		cube[3][2][i] = cube[4][2][i];
		cube[4][2][i] = temp[0][i];
	}
	
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			temp[i][j] = cube[5][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			cube[5][i][j] = temp[j][2-i];
		}
	}
}

void L(){		//왼쪽으로 90도 큐브 통체로 
	int temp[3][3] , i, j;
	for(i = 0; i < 3; i++){
		for(j = 0 ;j < 3; j++){
			temp[i][j] = cube[0][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0 ;j < 3; j++){
			cube[0][i][j] = temp[2-j][i];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0 ;j < 3; j++){
			temp[i][j] = cube[5][i][j];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0 ;j < 3; j++){
			cube[5][i][j] = temp[j][2-i];
		}
	}
	for(i = 0; i < 3; i++){
		for(j = 0 ;j < 3; j++){
			temp[i][j] = cube[1][i][j];
			cube[2][i][j] = cube[1][i][j];
			cube[2][i][j] = cube[3][i][j];
			cube[3][i][j] = cube[4][i][j];
			cube[4][i][j] = temp[i][j];
		}
	}
}

int main(){
	int i, j, k;
	for(i = 0; i < 6; i++){				//면 
		for(j = 0; j < 3; j++){			//열 
			for(k = 0; k < 3; k++){		//행 
				cube[i][j][k] = i*10+j*3+k+1;
			}
		}
	}
	LO();
	for(i = 0; i < 6; i++){				 //test for functions work right
		printf("\nside : %d\n", i);
		for(j = 0; j < 3; j++){			 
			for(k = 0; k < 3; k++){		 
				printf("%d", cube[i][j][k]); 
			}
			printf("\n");
		}
	} 
}

/*
input 
0 0 0
0 0 0
0 0 0
1 1 1
1 1 1
1 1 1
2 2 2
2 2 2
2 2 2
3 3 3
3 3 3
3 3 3
4 4 4
4 4 4
4 4 4
5 5 5
5 5 5
5 5 5
0 0 0
0 0 0
0 0 0
1 1 1
1 1 1
1 1 1
2 2 2
2 2 2
2 2 2
3 3 3
3 3 3
3 3 3
3 4 9
2 5 8
1 6 7
5 5 5
5 5 5
5 5 5
*/
