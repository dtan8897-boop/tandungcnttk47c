#include <stdio.h>
int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        int price, money;
        scanf("%d %d", &price, &money);
        int change = money - price;

        int d10, d5, d1, found = 0;

        for (d10 = change / 10; d10 >= 0 && !found; d10--) {
            for (d5 = 0; d5 < 2 && !found; d5++) {
                for (d1 = 0; d1 < 5 && !found; d1++) {
                    if (10*d10 + 5*d5 + d1 == change) {
                        printf("%d = %d * 10 + %d * 5 + %d * 1\n", change, d10, d5, d1);
                        found = 1;
                    }
                }
            }
        }
    }
    return 0;
}

