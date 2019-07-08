#ifndef P_NET_H_
#define P_NET_H_
//头文件的包含
#include <p_file.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
//定义类型
typedef struct sockaddr SA;
typedef struct sockaddr_in SA4;
//函数的声明
int s_bind(int domain, int type,in_port_t port);
int n_accept(int);
int h_accept(int);
#endif

