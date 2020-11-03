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

void R(){		//오른쪽으로 큐브 통체로 90도 돌리기
    int temp[3][3] , i, j;
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
    for(i = 0; i < 3; i++){
        for(j = 0 ;j < 3; j++){
            temp[i][j] = cube[1][i][j];
            cube[1][i][j] = cube[2][i][j];
            cube[2][i][j] = cube[3][i][j];
            cube[3][i][j] = cube[4][i][j];
            cube[4][i][j] = temp[i][j];
        }
    }
}

void L(){		//왼쪽으로 큐브 통체로 90도 돌리기
    int temp[3][3] , i, j;
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
    for(i = 0; i < 3; i++){
        for(j = 0 ;j < 3; j++){
            temp[i][j] = cube[1][i][j];
            cube[1][i][j] = cube[4][i][j];
            cube[4][i][j] = cube[3][i][j];
            cube[3][i][j] = cube[2][i][j];
            cube[2][i][j] = temp[i][j];
        }
    }
}

void U(){
    int i, j, temp[3][3];
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            temp[i][j] = cube[0][i][j];
            cube[0][i][j] = cube[1][i][j];
            cube[1][i][j] = cube[5][i][j];
            cube[5][i][j] = cube[3][2-i][2-j];
            cube[3][2-i][2-j] = temp[i][j];
        }
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

void D(){
    int i, j, temp[3][3];
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
    for(i = 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            temp[i][j] = cube[0][i][j];
            cube[0][i][j] = cube[3][2-i][2-j];
            cube[3][2-i][2-j] = cube[5][i][j];
            cube[5][i][j] = cube[1][i][j];
            cube[1][i][j] = temp[i][j];
        }
    }
}

void step2(){
	int i, j, k;
    int cnt = 0;
    while(cnt < 2){
        cnt = 0;
        UO();
        for(i = 1; i <= 4; i++){
        	if(cube[i][0][1] == cube[i][1][1]){
        		cnt++;
			}
		}
	}
    while(cube[1][1][1] != 1){
        L();
    }
	if(cnt == 2){
		while(1){
			R();
			if(cube[2][0][1] != cube[2][1][1] && cube[1][0][1] != cube[1][1][1] && cube[3][0][1] == cube[3][1][1] && cube[4][0][1] == cube[4][1][1]){
				break;
			}
			if(cube[2][0][1] != cube[2][1][1] && cube[4][0][1] != cube[4][1][1] && cube[1][0][1] == cube[1][1][1] && cube[3][0][1] == cube[3][1][1]){
				break;
			}
		}
		
		if(cube[1][0][1] != cube[1][1][1]){
			RO();RO();UU();RO();RO();UO();RO();RO();
		}
		else{
			RO();RO();UO();UO();RO();RO();UO();UO();RO();RO();
		}
	}
}

void step3(){
    int temp;
    D();D();
    temp = 4;
    while(temp--){
    	if(cube[5][0][2] == 0 || cube[1][2][2] == 0 || cube[2][2][0] == 0){
    		while(cube[0][2][2] != 0 && cube[1][0][2] != 0 && cube[2][0][0] != 0){
    			UO();
			}
			RO();
			UO();
			RU();
		}
	}
	temp = 4;
	while(temp--){
		if(cube[1][0][2] == 0){
		}
	}
}


void step4(){

    int i,j,k,count=0;
    while(1){
        if(cube[0][0][1]!=cube[0][1][1] && cube[0][1][0]!=cube[0][1][1] && cube[0][2][1]!=cube[0][1][1] && cube[0][1][2]!=cube[0][1][1]){
            if(cube[1][0][1]!=cube[0][1][1]&&cube[2][0][1]!=cube[0][1][1]&&cube[3][0][1]!=cube[0][1][1]&&cube[4][0][1]!=cube[0][1][1])break;
        }
        if(cube[1][0][1]==cube[0][1][1]||cube[0][2][1]==cube[0][1][1]){
            if(cube[1][1][2]!=cube[0][1][1]&&cube[2][1][0]!=cube[0][1][1]){
                UO();RO();UU();RU();FO();RU();FU();RO();
                continue;
            }
            else if(cube[1][1][0]!=cube[0][1][1]&&cube[4][1][2]!=cube[0][1][1]){
                UU();LU();UO();LO();FU();LO();FO();LU();
                continue;
            }
            else{
                L();
            }
        }
        else if((cube[1][1][0]==cube[0][1][1]||cube[4][1][2]==cube[0][1][1]) && (cube[1][1][2]==cube[0][1][1]|| cube[2][1][0]==cube[0][1][1])) L();
        else UO();
    }
    int cnt=0,all=0,change=0;
    while(1){
        if(change>=4){
            L();
            change=0;
        }
        if(cnt>=4) break;

        if(cube[1][0][1]==cube[1][1][1] && cube[0][2][1]==cube[2][1][1]){
            UO();RO();UU();RU();FO();RU();FU();RO();
            cnt++;
            change=0;
            continue;
        }
        if(cube[1][0][1]==cube[1][1][1]&& cube[0][2][1]==cube[4][1][1]){
            UU();LU();UO();LO();FU();LO();FO();LU();
            cnt++;
            change=0;
            continue;
        }
        UO();
        change++;
    }
}


void step5(){
    int temp;
    temp = 4;
    while(temp--){
        if(cube[0][1][0] == 5){
            break;
        }
    }
    if(temp == 0){
        FO();RO();UO();RU();UU();FU();
    }
    if(cube[0][1][2] == 5){
        if(cube[0][2][1] != 5){
            FO();RO();UO();RU();UU();FU();
        }
    }
    else{
        if(cube[0][2][1] == 5){
            R();
        }
        FO();RO();UO();RU();UU();FU();FO();RO();UO();RU();UU();FU();
    }
}

void step6(){
    int temp,cnt=0,i,j;
    for(i= 0; i < 3; i++){
        for(j = 0; j < 3; j++){
            if(cube[0][i][j] == 5){
                cnt++;
            }
        }
    }
    if(cnt == 5){
        while(cube[1][0][0] == 5 && cube[1][0][2] == 5){
            UO();
        }
        temp = 3;
        while(temp--){
            FO();RU();FU();LO();FO();RO();FU();LU();
        }
    }
    else if(cnt == 6){
        while(cube[0][2][2] != 5){
            UO();
        }
        if(cube[3][0][0] == 5){
            temp = 2;
            while(temp--){
                FO();RU();FU();LO();FO();RO();FU();LU();
            }
        }
        else{
            UO();UO();
            temp = 2;
            while(temp--){
                FO();RU();FU();LO();FO();RO();FU();LU();
            }
        }
    }
    else if(cnt == 7){
        temp = 0;
        while(cube[0][0][2] != 5 && cube[0][2][2] != 5){
            UO();
            temp++;
            if(temp > 5){
                break;
            }
        }
        if(temp == 5){
            while(cube[1][0][0] != 5){
                temp = 1;
                while(temp--){
                    FO();RU();FU();LO();FO();RO();FU();LU();
                }
            }
        }
        else{
            if(cube[2][0][0] == 5){
                temp = 2;
                while(temp--){
                    FO();RU();FU();LO();FO();RO();FU();LU();
                }
            }
            else{
                UO();UO();
                temp = 2;
                while(temp--){
                    FO();RU();FU();LO();FO();RO();FU();LU();
                }
            }
        }

    }
}

int main() {
  
    //흰색(0), 빨강(1), 파랑(2), 주황(3), 초록(4), 노랑(5)
    int i,j,k;
    for(i = 0; i <6; i++){
    	for(j = 0 ; j < 3; j++){
    		for(k = 0; k < 3; k++){
    			scanf("%d", &cube[i][j][k]);
			}
		}
	}

    step3();
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
