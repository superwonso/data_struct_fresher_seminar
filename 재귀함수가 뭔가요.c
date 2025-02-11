#include <stdio.h>
#include <string.h>

void print_s(int ans, char ander[]) {
	char *s[6] = {
		"\"재귀함수가 뭔가요?\"\n",
		"\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n",
		"마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n",
		"그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n",
		"\"재귀함수는 자기 자신을 호출하는 함수라네\"\n",
		"라고 답변하였지.\n"
	};
	char anser[300];
	
	if (ans == 0) {
		strcpy(anser, ander);
		strcat(anser, s[0]);
		printf("%s", anser);
		for (int i = 4;i < 6;i++) {
			strcpy(anser, ander);
			strcat(anser, s[i]);
			printf("%s", anser);
		}
		return;
	}
	else {
		for (int i = 0;i < 4;i++) {
			strcpy(anser, ander);
			strcat(anser, s[i]);
			printf("%s", anser);
		}
		strcpy(anser, ander);
		strcat(anser, s[5]);
		strcat(ander, "____");
		print_s(ans - 1, ander);
		printf("%s", anser);
		return;
	}
	
}

int main() {
	

	int ans;
	char ander[210]="";
	scanf("%d", &ans);
	printf("%s", "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
	print_s(ans, ander);
}