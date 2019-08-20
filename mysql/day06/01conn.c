#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL mysql;
    mysql_init(&mysql);
    // 连接
    if(!(mysql_real_connect(&mysql,"","root","tarena","choose",0,NULL,0))){
        printf("连接失败\n");
        return -1;
    }
    printf("连接成功\n");
    /* 执行对数据库的操作 */
    // 关闭连接
    mysql_close(&mysql);
    return 0;
}
