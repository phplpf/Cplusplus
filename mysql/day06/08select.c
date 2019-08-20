#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL mysql;
    MYSQL_RES* res;
    unsigned int num_fields,num_rows;
    MYSQL_FIELD* fields;
    MYSQL_ROW row;
    mysql_init(&mysql);
    if(!(mysql_real_connect(&mysql,"","root","tarena","choose",0,NULL,0))){
      printf("连接失败,%s\n",mysql_error(&mysql));
        return -1;
    }
    mysql_query(&mysql,"set character set utf8");
    if(!mysql_query(&mysql,"select s.student_no 学号,s.student_name 姓名,c.class_name 班级 from classes c,student s where c.class_no=s.class_no")){
      res=mysql_store_result(&mysql);
      if(res){
        num_fields = mysql_num_fields(res);
        num_rows = mysql_num_rows(res);
        fields = mysql_fetch_fields(res);
        int i,j;
        printf("------------------------------\n");
        for(i=0;i<num_fields;i++)
            printf("%s\t",fields[i].name);
        printf("\n------------------------------\n");
        for(i=0;i<num_rows;i++){
           row = mysql_fetch_row(res);
           for(j=0;j<num_fields;j++)
              printf("%s\t",row[j]);
           printf("\n");
        }
        printf("------------------------------\n");
        mysql_free_result(res);
      }
    } 
    mysql_close(&mysql);
    return 0;
}
