#include <afxwin.h>
#include <stdio.h>

// –¥»Î£¨¥Ê¥¢
void Store()
{
	CFile file;
	file.Open("mfcserial.dat",CFile::modeCreate|CFile::modeWrite);
	CArchive ar(&file,CArchive::store);
	ar<<100<<12.25<<'A';
	ar.Close();
	file.Close();
}
//∂¡»°£¨º”‘ÿ
void Load()
{  
	CFile file;
	file.Open("mfcserial.dat",CFile::modeRead);
	CArchive ar(&file,CArchive::load);
	long nValue;
	double dValue;
	char cValue;
	ar>>nValue>>dValue>>cValue;
	ar.Close();
	file.Close();
	printf("%d,%f,%c\n",nValue,dValue,cValue);
}
int main()
{
	Store();
	Load();
	return 0;
}