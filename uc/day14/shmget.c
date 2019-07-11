#include <p_stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

int main(int argc,char *argv[]){
    
    //申请一个system v ipc的键值
    key_t key=ftok(argv[1],31);
    if(key==-1)E_MSG("ftok",-1);
    printf("key=0x%x\n",key);
    //使用key的值获取一个共享内存段
    //如果不存在，创建共享内存段。如果存在，返回共享内存端的id
    int shmid=shmget(key,1024,IPC_CREAT|0644);
    if(shmid==-1)E_MSG("shmget",-1);
    printf("shmid=%d\n",shmid);
    return 0;
}
