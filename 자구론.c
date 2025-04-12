#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX 600000

char left[MAX], right[MAX];
int leftTop = 0, rightTop = 0;

int main() {
    char initial[MAX];
    int n;

    scanf("%s", initial);
    scanf("%d", &n);
    getchar(); 

    for (int i = 0; initial[i] != '\0'; i++) {
        left[leftTop++] = initial[i];
    }

    for (int i = 0; i < n; i++) {
        char cmd;
        scanf("%c", &cmd);

        if (cmd == 'L') {
            if (leftTop > 0) {
                right[rightTop++] = left[--leftTop];
            }
        }
        else if (cmd == 'D') {
            if (rightTop > 0) {
                left[leftTop++] = right[--rightTop];
            }
        }
        else if (cmd == 'B') {
            if (leftTop > 0) {
                --leftTop; 
            }
        }
        else if (cmd == 'P') {
            char ch;
            scanf(" %c", &ch); 
            left[leftTop++] = ch;
        }
        getchar(); 
    }

    for (int i = 0; i < leftTop; i++) {
        printf("%c", left[i]);
    }
    for (int i = rightTop - 1; i >= 0; i--) {
        printf("%c", right[i]);
    }

    return 0;
}
