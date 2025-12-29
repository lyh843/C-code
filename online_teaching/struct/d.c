union Data {
    int   i;
    float f;
    char  str[20];
};
int main(){
    union Data d;

    d.i = 100;
    printf("%d\n", d.i);

    // 再存 float，会覆盖同一块内存
    d.f = 3.14;
    printf("%f\n", d.f);

    // 读 d.i 是未定义行为
    printf("%d\n", d.i);

    float b = 3.14;
    int *a = &b;
    float *c = &b;
    printf("%d\n", *a);
}