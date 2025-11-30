#include <stdio.h>
#include <string.h>

int main(){
    char s1[6], s2[6];
    scanf("%s%s", s1, s2);
    printf("s1 = %s\ns2 = %s\n", s1, s2);
    printf("%d\n", strlen(s1));
    strcat(s1, s2);
    printf("%s\n", s1);
}