#include <stdio.h>
#include <mysql/mysql.h>
void addstu(MYSQL mysql);  // 添加学生
void delstu(MYSQL mysql);  // 删除学生
void modifystu(MYSQL mysql); // 修改学生信息
void stulist(MYSQL mysql); // 显示学生列表
void searchstubyno(MYSQL mysql); // 查询指定学生
int main(void){
    MYSQL mysql;
    mysql_init(&mysql);
    if(!(mysql_real_connect(&mysql,"","root","tarena","choose",0,NULL,0))){
        printf("连接失败,%s\n",mysql_error(&mysql));
        return -1;
    }
    // 设置字符集
    mysql_query(&mysql,"set character set utf8");
    int option,flag=1;
    printf("\t欢迎使用学生管理系统\n");
    while(flag){
        printf("\n1. 添加学生\n");
        printf("2. 删除学生\n");
        printf("3. 修改学生信息\n");
        printf("4. 学生列表\n");
        printf("5. 查询指定学生\n");
        printf("0. 退出\n");
        printf("请选择:");
        scanf("%d",&option);
        switch(option){
        case 1:
          printf("学生管理系统 ---> 添加学生\n");
          addstu(mysql);
          break;
        case 2:
          printf("学生管理系统 ---> 删除学生\n");
          delstu(mysql);
          break;
        case 3:
          printf("学生管理系统 ---> 修改学生信息\n");
          modifystu(mysql);
          break;
        case 4:
          printf("学生管理系统 ---> 学生列表\n");
          stulist(mysql);
          break;
        case 5:
          printf("学生管理系统 ---> 查询指定学生\n");
          searchstubyno(mysql);
          break;
        case 0:
          printf("Bye\n");
          flag=0;
          mysql_close(&mysql);// 关闭连接
          break;
        }
    }
    return 0;
}
void addstu(MYSQL mysql){
    char stuno[10],stuname[20],phone[20];
    int cno;
    char sqlstr[200];
    printf("请输入学号:");
    scanf("%s",stuno);
    printf("请输入姓名:");
    scanf("%s",stuname);
    printf("请输入手机号码:");
    scanf("%s",phone);
    printf("请输入班号:");
    scanf("%d",&cno);
    sprintf(sqlstr,"insert into student values('%s','%s','%s',%d)",stuno,stuname,phone,cno);
//    printf("%s\n",sqlstr);
    if(mysql_query(&mysql,sqlstr))
        printf("插入失败,%s\n",mysql_error(&mysql));
    else
        printf("插入成功\n");
}
void delstu(MYSQL mysql){
    char stuno[10];
    char sqlstr[200];
    printf("请输入要删除学生的学号:");
    scanf("%s",stuno);
    sprintf(sqlstr,"delete from student where student_no='%s'",stuno);
//    printf("%s\n",sqlstr);
    if(mysql_query(&mysql,sqlstr))
        printf("删除失败,%s\n",mysql_error(&mysql));
    else
        if(mysql_affected_rows(&mysql))
            printf("删除成功\n");
        else
            printf("要删除的学生不存在\n");
}
void modifystu(MYSQL mysql){
    char stuno[10],stuname[20],phone[20];
    int cno;
    char sqlstr[200];
    printf("请输入要修改学生的学号:");
    scanf("%s",stuno);
    printf("请输入姓名:");
    scanf("%s",stuname);
    printf("请输入手机号码:");
    scanf("%s",phone);
    printf("请输入班号:");
    scanf("%d",&cno);
    sprintf(sqlstr,"update student set student_name='%s',student_contact='%s',class_no=%d where student_no='%s'",stuname,phone,cno,stuno);
//    printf("%s\n",sqlstr);
    if(mysql_query(&mysql,sqlstr))
        printf("修改失败,%s\n",mysql_error(&mysql));
    else{
        if(mysql_affected_rows(&mysql))
            printf("修改成功\n");
        else
            printf("该学号不存在\n");
    }
}
void stulist(MYSQL mysql){
   MYSQL_RES* res;
   MYSQL_FIELD* fields;
   MYSQL_ROW row;
   unsigned int num_fields,num_rows;
   char sqlstr[200];
   sprintf(sqlstr,"select student_no 学号,student_name 姓名,student_contact 联系方式,class_no 班号 from student");
   if(mysql_query(&mysql,sqlstr))
     printf("查询失败,%s\n",mysql_error(&mysql));
   else{
     res = mysql_store_result(&mysql);
     num_rows = mysql_num_rows(res);
     if(!num_rows){
         printf("学生列表为空\n");
         return;
     }
     num_fields = mysql_num_fields(res);
     fields = mysql_fetch_fields(res);
     int i=0,j=0;
     for(;i<num_fields;i++)
         printf("%s\t",fields[i].name);
     printf("\n");
     for(i=0;i<num_rows;i++){
        row = mysql_fetch_row(res);
        for(j=0;j<num_fields;j++)
            printf("%s\t",row[j]);
        printf("\n");
     }
     mysql_free_result(res);
   }
}
void searchstubyno(MYSQL mysql){
   MYSQL_RES* res;
   MYSQL_ROW row;
   unsigned int num_fields,num_rows;
   char stuno[20];
   char sqlstr[200];
   printf("请输入要查询的学生的学号:");
   scanf("%s",stuno);
   sprintf(sqlstr,"select * from student where student_no='%s'",stuno);
   if(mysql_query(&mysql,sqlstr))
     printf("查询失败,%s\n",mysql_error(&mysql));
   else{
     res = mysql_store_result(&mysql);
     num_rows = mysql_num_rows(res);
     if(!num_rows){
         printf("没有要查询的学生\n");
         return;
     }
     num_fields = mysql_num_fields(res);
     row = mysql_fetch_row(res);
     int i=0;
     for(;i<num_fields;i++)
         printf("%s\t",row[i]);
     printf("\n");
     mysql_free_result(res);
   }
}



















