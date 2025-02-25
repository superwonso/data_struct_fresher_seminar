#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int n, num, current = 1, top = -1;
    int check_no=0;
    scanf("%d", &n);

    int stack[n]; // 스택 배열
    char result[2 * n]; // 연산 저장 배열
    int resultIndex = 0; // 결과 배열 인덱스

    for (int i = 0; i < n; i++) 
	{
        scanf("%d", &num);

        while (current <= num) 
		{
            stack[++top] = current++;
            result[resultIndex++] = '+'; 
        }


        if (stack[top] == num) 
		{
            top--; // pop 수행
            result[resultIndex++] = '-';
        } else 
		{
            check_no = 1;
            break;
        }
    }

    if(check_no == 1)
    {
    	printf("NO\n");
	}
	else
	{
		for (int i = 0; i < resultIndex; i++) 
		{
        	printf("%c\n", result[i]);
    	}
	}    

    return 0;
}
