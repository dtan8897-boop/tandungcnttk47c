#include <stdio.h>
#include <ctype.h>
#include <string.h>
int isStrongPassword(char *pw) {
    int hasUpper=0, hasLower=0, hasDigit=0;
    if (strlen(pw) < 8) return 0;
    for (int i = 0; pw[i]; i++) {
        if (isupper(pw[i])) hasUpper = 1;
        else if (islower(pw[i])) hasLower = 1;
        else if (isdigit(pw[i])) hasDigit = 1;
    }
    return hasUpper && hasLower && hasDigit;
}
int main() {
    char pw[100];
    printf("Nhap mat khau: ");
    scanf("%s", pw);
    if (isStrongPassword(pw))
        printf("Mat khau manh\n");
    else
        printf("Mat khau yeu\n");
    return 0;
}

