#include <stdio.h>
    in = 0;
typedef int (FUNC1)(int in);
typedef int(FUNC2)(int *, int *, int*);
int inc(int a)
{
    printf("%d\n", a);
    return(++a);
}
int multi(int *a, int *b, int *c){
    return(*c = *a**b);//11*10
}

void show(FUNC2 fun, int arg1, int *arg2)
{
    FUNC1 *p = &inc;
    int temp = p(arg1);
    fun(&temp, &arg1, arg2);
    printf("%d\n", *arg2);
    printf("%d\n", temp);
    printf("%d\n", arg1);
}

int main() {
    int a;
    show(multi, 10, &a);
    return 0;
}

