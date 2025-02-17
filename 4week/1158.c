#include<stdio.h>

int main() {
    int N, K, check[5002] = {0, }, cur;
    scanf("%d %d", &N, &K);
    cur = K;
    printf("<%d", cur);
    check[cur] = 1;
    for(int i=0; i<N-1; i++) {          //원형 테이블의 값이 모두 1이 될 때까지 반복
        for(int j=0; j<K; j++) {        //K의 값만큼 0을 찾아 1로 바꿔준다.
            while(1) {
                cur++;
                if(cur > N) cur = 1;    //원형 테이블의 크기보다 커지면 1로 인덱스를 바꿔준다.
                if(!check[cur]) break;  //check값이 0이면 멈춘다.
            }
        }
        printf(", %d", cur);
        check[cur] = 1;                 //check값을 1로 바꿔준다.
    }
    printf(">");
}