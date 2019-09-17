#include <stdio.h>
#include <afxwin.h>
void UseCFile()
{
	CFile file;
	try
	{
		// 1 新建或打开文件
		CFile file;
		file.Open("d:/mfcfile.txt",CFile::modeCreate|CFile::modeNoTruncate|CFile::modeReadWrite);
		// 2 写操作
		file.SeekToEnd();
		char szBuff[]="Hello World";
		file.Write(szBuff,strlen(szBuff));
		// 读操作
		file.SeekToBegin();
		char szRead[256]={0};
		int nRead = file.Read(szRead,256);
		printf("%s,%d\n",szRead,nRead);
		// 3 关闭文件
		file.Close();

	}
	catch (CFileException* e)
	{
		//异常处理
	}
	
}

void UseCFileFind(CString strPath)
{
	CFileFind find;
	// 1 开始查找
	BOOL bRet=find.FindFile(strPath+"/*.*");
	while (bRet)
	{
		bRet = find.FindNextFile();
		//CString strName=find.GetFileName();
		strPath = find.GetFilePath();
		if(find.IsDots())continue;
		if (find.IsDirectory())
		{
			printf("[%s]\n",strPath);
			UseCFileFind(strPath);
		}
		else
		{
			printf("%s\n",strPath);
		}
	}
	// 关闭查找
	find.Close();

}

int main()
{
	//UseCFile();
	UseCFileFind("d:");
	return 0;
}