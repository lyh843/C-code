#include<stdio.h>

int main(){
    int arr[3][4];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            arr[i][j] = i * 4 + j;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%p \t", &arr[i][j]);
        }
        printf("\n");
    }

    int **q = malloc(3 * sizeof(int *));
    for(int i = 0; i < 3; i++){
        q[i] = malloc(4 * sizeof(int));
    }
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            q[i][j] = i * 4 + j;
        }
    }

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d \t", *(*(q + i) + j));
        }
        printf("\n");
    }

    for(int i = 0; i < 3; i++){
        free(q[i]);
    }
    free(q);

    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d \t", *(*(arr + i) + j));
        }
        printf("\n");
    }

    int (*p)[4] = arr;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 4; j++){
            printf("%d \t", *(*(p + i) + j));
        }
        printf("\n");
    }

    int a = 1;
    int *point = &a;
    char* p1 = point;
    printf("%c\n", *p1);


}