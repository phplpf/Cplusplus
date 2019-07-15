#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *is_mime(char path[]){
        int i=0;
        char *types=NULL;
        char *files=NULL;
        for(i=strlen(path);i>0;i--){
                if(path[i]=='/'){
                        files=&path[i+1];
                        break;
                }
        }
        for(i=strlen(files);i>0;i--){
                if(files[i]=='.'){
                   types=&files[i+1];
                   break;
                }
        }
        return types;
}

int main(void){
	char *buf=NULL;
	char path_file[128] ="/home/lpf/code/Cplusplus/uc/web/html/index.html";
	buf=is_mime(path_file);
	printf("%s \n",buf);
	
	
	/*	
 *
 *
 *	FILE *file = fopen(path_file,"r");
	fread(buf,1024,1,file);
	printf("%s \n",buf);
	fclose(file);
	*/
	return 0;
}
