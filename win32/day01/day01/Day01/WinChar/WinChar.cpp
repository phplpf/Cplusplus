//#define UNICODE
#include <stdio.h>
#include <windows.h>
void C_char()
{
	char* pszText = "Hello char";
	printf("%s\n",pszText);
}
void W_char()
{
	wchar_t* pszText = L"Hello wchar";
	int nLen = wcslen(pszText);
	wprintf(L"%s,%d\n",pszText,nLen);
}
//#define WIDECHAR
void T_char()
{
/*#ifdef WIDECHAR
	wchar_t* pszText = L"Hello";
	wprintf(L"%s\n",pszText);
#else
	char* pszText = "Hello";
	printf("单:%s\n",pszText);
#endif*/
	TCHAR* pszText = __TEXT("Hello");
#ifdef UNICODE
	wprintf(L"%s\n",pszText);
#else
	printf("单:%s\n",pszText);
#endif
}
void PrintUnicode()
{
	wchar_t* pszText = L"珠市口";
//	wprintf(L"%s\n",pszText);
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
  //  WriteConsole(hOutput,pszText,wcslen(pszText),NULL,NULL);

	for( int nHeight = 0; nHeight<256; nHeight++ ){
		for( int nLow = 0; nLow<256; nLow++ ){
			wchar_t nWchar = nHeight*256 + nLow;
			WriteConsole(hOutput,&nWchar,1,NULL,NULL);
		}
		printf("\n");
	}
}
int main(void )
{
	PrintUnicode();
//	T_char();
//	C_char();
//	W_char();
	getchar();
	return 0;
}