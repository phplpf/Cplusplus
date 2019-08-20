#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL* mysql;
    char stuno[20];
    char stuname[10];
    char phone[20];
    int cno;
    char sqlstr[200];
    unsigned int num_rows; // 影响的行数
    mysql = mysql_init(NULL);
    mysql = mysql_real_connect(mysql,"","root","tarena","choose",0,NULL,0);
    // 设置字符集
    mysql_query(mysql,"set character set utf8");
    printf("请输入要修改的学生的学号:");
    scanf("%s",stuno);
    printf("请输入新的姓名:");
    scanf("%s",stuname);
    printf("请人数新的联系方式:");
    scanf("%s",phone);
    printf("请输入新的班号:");
    scanf("%d",&cno);
    sprintf(sqlstr,"update student set student_name='%s',student_contact='%s',class_no=%d where student_no='%s'",stuname,phone,cno,stuno);
//    printf("%s\n",sqlstr);
    // 更新数据
    if(mysql_query(mysql,sqlstr)){
        printf("修改失败,%s\n",mysql_error(mysql));
    }
    else{
        num_rows = mysql_affected_rows(mysql);
        if(num_rows)
            printf("修改成功\n");
        else
            printf("不存在学号为%s的学生\n",stuno);
    }
    // 关闭连接
    mysql_close(mysql);
    return 0;
}
