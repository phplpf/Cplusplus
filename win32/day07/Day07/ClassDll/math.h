#pragma once   /* 等效于C语言中的头文件卫士 */  
#ifdef  CLASSDLL_EXPORT
#define EXT_CLASS _declspec(dllexport)   // dll
#else
#define EXT_CLASS _declspec(dllimport)  // exe
#endif
class  EXT_CLASS CMath{
public:
	int add( int m, int n );
	int sub( int m, int n );
};