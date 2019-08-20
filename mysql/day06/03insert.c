#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL* mysql;
    mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql,"","root","tarena","choose",0,NULL,0);
    // 设置字符集
    mysql_query(mysql,"set character set utf8");
    // 插入数据
    if(mysql_query(mysql,"insert into student values('2018110','小林','13512345678',1)")){
        printf("插入失败\n");
    }
    else{
        printf("插入成功\n");
    }
    // 关闭连接
    mysql_close(mysql);
    return 0;
}
