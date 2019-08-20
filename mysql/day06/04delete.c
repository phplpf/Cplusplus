#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL* mysql;
    char stuno[20];
    char sqlstr[200];
    unsigned int num_rows; // 影响的行数
    mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql,"","root","tarena","choose",0,NULL,0);
    // 设置字符集
    mysql_query(mysql,"set character set utf8");
    printf("请输入要删除的学生的学号:");
    scanf("%s",stuno);
    sprintf(sqlstr,"delete from student where student_no='%s'",stuno);
//    printf("%s\n",sqlstr);
    // 删除数据
    if(mysql_query(mysql,sqlstr)){
        printf("删除失败\n");
    }
    else{
        num_rows = mysql_affected_rows(mysql);
        if(num_rows)
            printf("删除成功\n");
        else
            printf("不存在学号为%s的学生\n",stuno);
    }
    // 关闭连接
    mysql_close(mysql);
    return 0;
}
