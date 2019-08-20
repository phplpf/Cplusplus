#include <stdio.h>
#include <mysql/mysql.h>
int main(void){
    MYSQL mysql;
    MYSQL_RES* res; // 结果集
    unsigned int num_fields, num_rows; // 列数、行数

    mysql_init(&mysql);// 初始化MYSQL对象
    // 建立连接
    mysql_real_connect(&mysql,"","root","tarena","choose",0,NULL,0);
    mysql_query(&mysql,
      "delete from student where 1=0");
    
    // 获取结果集
    res = mysql_store_result(&mysql);
    if(res){
      // 获取列数
      num_fields = mysql_num_fields(res);
      // 获取行数
      num_rows = mysql_num_rows(res);
      printf("列数:%d,行数:%d\n",
             num_fields,num_rows);
      // 释放结果集
      mysql_free_result(res);
    }
    else{
      num_fields = mysql_field_count(&mysql);
      if(num_fields)
          printf("结果集为空\n");
      else{
        printf("没有结果集产生\n");
        num_rows = mysql_affected_rows(&mysql);
        if(num_rows){
            printf("修改成功\n");
        }
      }
    }
    mysql_close(&mysql);// 关闭连接
    return 0;
}










