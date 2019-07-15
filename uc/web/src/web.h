#ifndef WEB_H_
#define WEB_H_
typedef struct{
    char method[32];
    char path[128];
    char proto[32];

}req_t;
typedef struct{
    int code; //404 200
    char *f_typ;// text/html  image/png
}res_t;

#endif
