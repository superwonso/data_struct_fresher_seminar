/*
모르겠습니다!!
모르겠습니다!!
모르겠습니다!!
모르겠습니다!!
모르겠습니다!!
모르겠습니다!!
*/


//랩실에서 잘자요
#include<stdio.h>
#include<stdlib.h>

int main(){
    int N, M, blank=0,ink=0;
    scanf("%d %d", &N, &M);
    int *arr=(int*)malloc(sizeof(int)*N);
    int *arr2=(int*)malloc(sizeof(int)*M);

    for(int n=0;n<N;n++)
        arr[n]=1;
    for(int n=0;n<M;n++)
        scanf("%d", &arr2[n]);

    for(int n=0;n<M;n++){
        if(arr[arr2[n]-1]==1){
            arr[arr2[n]-1]=0;
            blank++;
        }
    }
    blank=N-blank;

    int seq=0, s=-1,l=-1;

    for(int n=0;n<N;n++){
        if(arr[n]==1){
            if(s==-1){
                s=n;
                seq++;
            }
            else{
                if(n-s+1)
                seq++;
            }
        }
        if(blank==0)
            break;
    }
    return 0;
}
