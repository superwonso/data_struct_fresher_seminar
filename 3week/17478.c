#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void set_string(char strings[5][100]){
    strcpy(strings[0], "\"����Լ��� ������?\"");
    strcpy(strings[1], "\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.");
    strcpy(strings[2], "���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.");
    strcpy(strings[3], "���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"");
    strcpy(strings[4], "��� �亯�Ͽ���.");
};

void recursion(int N, int n, char strings[5][100]){
    char ub[]="____";
    if(n==0){
        for(int k=0;k<(N-n);k++)
            printf("%s", ub);
        printf("\"����Լ��� ������?\"\n");
        for(int k=0;k<(N-n);k++)
            printf("%s", ub);
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");
        for(int k=0;k<(N-n);k++)
            printf("%s", ub);
        printf("��� �亯�Ͽ���.\n");
    }
    else{
        for(int i=0;i<5;i++){
            if(i==4) recursion(N, (n-1), strings);
            if(n!=N){
                for(int k=0;k<(N-n);k++)
                printf("%s", ub);
            }
            printf("%s\n",strings[i]);
        }
    }

};

int main(){
    int n;
    char strings[5][100];
    set_string(strings);

    scanf("%d", &n);
    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    recursion(n, n, strings);
    return 0;
}