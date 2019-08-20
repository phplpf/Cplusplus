#include <windows.h>
int WinMain(HINSTANCE hInstance,HINSTANCE hPrevIns,
     LPSTR lpCmdLine,int nCmdShow)
{
    MessageBox(NULL,"Hello World!","Information",
        MB_ABORTRETRYIGNORE | MB_ICONINFORMATION);
    return 0;
}
/*
    CL.EXE -c Hello.c                      // 生成 Hello.obj
    RC.EXE Hello.rc                        // 生成 Hello.res
    LINK.EXE Hello.obj Hello.res user32.lib // 生成 Hello.exe
    Hello.exe
    完整的编译、链接的过程：
             CL.EXE
    .c/.cpp ---------> .obj | LINK.EXE
            RC.EXE          |-----------> .exe
    .rc   -----------> .res |
*/