#include <stdio.h>

void func(int n, int depth) {
    for (int i = 0; i < depth; i++) printf("____");
    printf("\"����Լ��� ������?\"\n");

    if (n == 0) {
        for (int i = 0; i < depth; i++) printf("____");
        printf("\"����Լ��� �ڱ� �ڽ��� ȣ���ϴ� �Լ����\"\n");

        for (int i = 0; i < depth; i++) printf("____");
        printf("��� �亯�Ͽ���.\n");
        return;
    }

    for (int i = 0; i < depth; i++) printf("____");
    printf("\"�� ����. �������� �� �� ����⿡ �̼��� ��� ������ ����� ������ �־���.\n");

    for (int i = 0; i < depth; i++) printf("____");
    printf("���� ������� ��� �� ���ο��� ������ ������ �߰�, ��� �����Ӱ� ����� �־���.\n");

    for (int i = 0; i < depth; i++) printf("____");
    printf("���� ���� ��κ� �ǾҴٰ� �ϳ�. �׷��� ��� ��, �� ���ο��� �� ���� ã�ƿͼ� ������.\"\n");

    func(n - 1, depth + 1);

    for (int i = 0; i < depth; i++) printf("____");
    printf("��� �亯�Ͽ���.\n");
}

int main() {
    int n;
    scanf("%d", &n);

    printf("��� �� ��ǻ�Ͱ��а� �л��� ������ �������� ã�ư� ������.\n");
    func(n, 0);

    return 0;
}