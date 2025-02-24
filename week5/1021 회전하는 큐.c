#include <stdio.h>

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    
    int deque[51];
    for (int i = 0; i < n; i++){
        deque[i] = i + 1;
    }
    int size = n;
    int ans = 0;
    
    while(m--){
        int target;
        scanf("%d", &target);
        
        int idx = 0;
        for (int i = 0; i < size; i++){
            if(deque[i] == target){
                idx = i;
                break;
            }
        }
        
        if(idx <= size - idx){
            ans += idx;
        } else {
            ans += (size - idx);
        }
        
        int newDeque[51];
        int pos = 0;
        for (int i = idx + 1; i < size; i++){
            newDeque[pos++] = deque[i];
        }
        for (int i = 0; i < idx; i++){
            newDeque[pos++] = deque[i];
        }
        for (int i = 0; i < pos; i++){
            deque[i] = newDeque[i];
        }
        size--; 
    }
    
    printf("%d\n", ans);
    return 0;
}
