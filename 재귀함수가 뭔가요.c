#include <stdio.h>
#include <string.h>

void print_s(int ans, char ander[]) {
	char *s[6] = {
		"\"����Լ��� ������?\"\n",
		"\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n",
		"���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n",
		"���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n",
		"\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n",
		"��� �亯�Ͽ���.\n"
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
	printf("%s", "��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
	print_s(ans, ander);
}