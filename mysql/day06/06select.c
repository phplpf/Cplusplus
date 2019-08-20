#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL mysql;
    MYSQL_RES* res;// 结果集
    unsigned int num_fields,num_rows;// 列数、行数
    MYSQL_FIELD* fields; // 字段的信息
    MYSQL_ROW row; // 接收结果集中的一行数据

    mysql_init(&mysql);
    if(!(mysql_real_connect(&mysql,"","root","tarena","choose",0,NULL,0))){
        printf("连接失败,%s\n",mysql_error(&mysql));
        return -1;
    }
    mysql_query(&mysql,"set character set utf8");
    //执行sql语句
    if(!mysql_query(&mysql,"select student_no 学号,student_name 姓名,class_no 班号 from student s")){
      res = mysql_store_result(&mysql);// 获取结果集
      num_fields = mysql_num_fields(res);// 获取列数
      num_rows = mysql_num_rows(res); // 获取行数
      fields = mysql_fetch_fields(res);
      int i=0,j=0;
/*      for(i=0;i<num_fields;i++){
          printf("%s\t%s\t%s\t%s\n",
             fields[i].name,fields[i].org_name,
             fields[i].table,fields[i].org_table);
      }*/
      printf("+---------------------------+\n");
      for(i=0;i<num_fields;i++)
          printf("%s\t",fields[i].name);
      printf("\n+----------------------------+\n");
      for(i=0;i<num_rows;i++){
         row = mysql_fetch_row(res);
         for(j=0;j<num_fields;j++){
            printf("%s\t",row[j]);
         }
         printf("\n");
      }
      printf("+---------------------------+\n");
      mysql_free_result(res);
    }
    
    mysql_close(&mysql);
    return 0;
}









