#include <stdio.h>
#include<string.h>
#define N 2010 //amount
#define M 5010 //len

int amount, times;
int arr[N][M]; //0号位是长度

void f_link() {
    char op[10];
    int x, y;
    scanf("%s", op);
    scanf("%d%d", &x, &y);
    if (*op == 'b') {
        for (int i = 1; i <= arr[y][0]; i++) {
            arr[x][++arr[x][0]] = arr[y][i];
        }
        arr[y][0] = 0;
    } else if (*op == 'f') {
        for (int i = 1; i <= arr[x][0]; i++) {
            arr[x][i + arr[y][0]] = arr[x][i];
        }
        for (int i = 1; i <= arr[y][0]; i++) {
            arr[x][i] = arr[y][i];
        }
        arr[x][0] += arr[y][0];
        arr[y][0] = 0;
    }
}

void f_cut() {
    int x, p, q;
    scanf("%s", x);
    scanf("%d%d", &p, &q);
    if (p > q || p <= 0 || p > arr[x][0] || q <= 0 || q > arr[x][0]) {
        return;
    } else {
        for (int i = 0; i <= q - p; i++) {
            arr[x][p + i] = arr[x][q + 1 + i];
        }
        arr[x][0] = arr[x][0] - (q - p) - 1;
    }
}

void f_rotate() {
    int x, p, q;
    scanf("%d%d%d", &x, &p, &q);
    if (p > q || p <= 0 || p > arr[x][0] || q <= 0 || q > arr[x][0]) {
        return;
    } else {
        int temp = arr[x][q];
        for (int i = 1; i <= q - p; i++) {
            arr[x][p + i] = arr[x][p + i - 1];
        }
        arr[x][p] = temp;
    }
}

void f_reverse() {
    int x, p, q;
    scanf("%d%d%d", &x, &p, &q);
    if (p > q || p <= 0 || p > arr[x][0] || q <= 0 || q > arr[x][0]) {
        return;
    } else {
        int temp = arr[x][q];
        for (int i = 1; i <= q - p; i++) {
            arr[x][p + i] = arr[x][p + i - 1];
        }
        arr[x][p] = temp;
    }
}

int main(void) {
    scanf("%d%d", &amount, &times);
    for (int i = 1; i <= amount; i++) {
        scanf("%d", &arr[i][0]);
        for (int j = 1; j <= arr[i][0]; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
    while (times--) {
        char op[20] = {0};
        scanf("%s", op);
        if (*op == 'l') {
            f_link();
        } else if (*op == 'c') {
            f_cut();
        } else if (*(op + 1) == 'o') {
            f_rotate();
        } else if (*(op + 1) == 'e') {
            f_reverse();
        }
    }

    for (int i = 1; i <= amount; i++) {
        if (arr[i][0] != 0) {
            for (int j = 1; j <= arr[i][0]; j++) {
                printf("%d", arr[i][j]);
                if (j != arr[i][0]) {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }
    return 0;
}
