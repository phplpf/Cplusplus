#include <stdio.h>

int main()
{
    int arr[]={1,2,3,4,5};
    int *p = arr;//随机访问（下标访问）
    int (*ptr)[3];
    int arr1[] = {10,20,30};
    ptr = &arr1;
    printf("%d\n",sizeof(arr));
    printf("%d\n",sizeof(p));
    printf("%d\n",*(arr+1));
    printf("%d\n",*(p+1));
    printf("%d\n",sizeof(ptr));
    printf("%p\n",ptr);
    printf("%d\n",*((int*)ptr+1));
    int array[2][3] = {{5,15,25},{6,16,26}};
    int *pp = NULL;
    pp = array[0];
    int (*p_ptr)[3];
    p_ptr = array;
    printf("%d\n",*pp);
    printf("%d\n",*(pp+1));
    printf("%d\n",*(array[0]+1));
    //数组最直接的访问方式是通过下标访问
    //下标访问又叫随机访问
    printf("%d\n",array[1][1]);
    printf("%d\n",*(array[0]+3));
    printf("%d\n",*(*(p_ptr+1)));
    return 0;
}
