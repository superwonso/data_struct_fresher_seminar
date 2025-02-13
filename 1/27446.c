#include <stdio.h>

int main() 
{
    int N, M;
    scanf("%d %d", &N, &M);

    int pages[M];
    for (int i = 0; i < M; i++) 
    {
        scanf("%d", &pages[i]);
    }

    int d[N];
    int d_size = 0; 
    int found;

    for (int i = 1; i <= N; i++) 
	{
        found = 0;
        for (int j = 0; j < M; j++) 
        {
            if (pages[j] == i) 
            {
                found = 1;
                break;
            }
        }
        if (!found) 
        {
            d[d_size++] = i; 
        }
    }

    int last = 0;  
    int result = 0; 

    for (int i = 0; i < d_size; i++) 
	{
        if (last) 
        {
            result += (d[i] - last) * 2 < 7 ? (d[i] - last) * 2 : 7;
        } else 
        {
            result += 7; 
        }
        last = d[i];
    }

    printf("%d\n", result);

    return 0;
}
