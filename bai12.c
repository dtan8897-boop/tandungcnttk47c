#include <stdio.h>

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int N, M, K;
        scanf("%d %d %d", &N, &M, &K);

        if (M >= N && K >= M)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

