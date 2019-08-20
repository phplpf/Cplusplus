#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL mysql;
    char* ip = "192.168.60.128";
    char* user = "root";
    char* pwd = "tarena";
    char* db = "choose";
    mysql_init(&mysql);
    if(!(mysql_real_connect(&mysql,ip,user,pwd,db,0,NULL,0))){
        printf("连接失败\n");
    }
    else{
        printf("连接成功\n");
    }
    mysql_close(&mysql);
    return 0;
}
