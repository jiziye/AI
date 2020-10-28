//批量获取文件中的文件名称, 包括“文件路径+文件名+文件扩展名”，
//不包括子文件夹名，读取文件名在cmd终端显示，并保存在一个fileName.txt文件中。

#include<iostream>
#include<vector>
#include<time.h>
#include<sys/io.h>
#include <fstream>  //文件操作
using namespace std;
 
 
//for reading file
void getFiles( string path, vector<string>& files );
void getFilesName( string path, vector<string>& files );
char* str2char(string src) ;
 
int main()
{
	//测试文件路径
	char path1[300]="C:\\Users\\admin\\Pictures";
 
	vector<string> filenames1;
	getFiles( path1, filenames1);
 
	vector<string> filenames2;
	getFilesName(path1, filenames2 );
 
	//新建一个.txt文件，用于保存文件名
	ofstream ofn("FileName.txt");  
 
	int numImg=filenames2.size();
	for (int file_i=0;file_i<numImg;  file_i++)
	{
		string b1 =filenames1[file_i].c_str();
		string b2 =filenames2[file_i].c_str();
 
		char * test_b1=str2char(b1);
		char * testChar=str2char(b2);
 
 
		char noSuffixName[100];
		//仅读取文件名，不包括文件扩展名，如文件名为0_0_272.jpg,则读取文件名noSuffixName="0_0_272"
		int	indexPoint = b2.find_first_of('.',0); 
		//int	indexPointEnd = b.find_first_of('.',0); 
		for(int j=0;j<indexPoint;j++){
			noSuffixName[j]=testChar[j];
		}
		noSuffixName[indexPoint]='\0';//输入结束符
 
		//显示提取的文件名称
		cout<<"noSuffixName:"<<noSuffixName<<endl;//文件名称 （不包括文件扩展名）
		cout<<"fileName:"<<testChar<<endl;//文件名称+文件扩展名
		cout<<"pathFileName:"<<test_b1<<endl;//路径+文件名称+文件扩展名
		//将文件名称保存到.txt文件
		ofn<<"noSuffixName:"<<noSuffixName<<endl;   
		ofn<<"fileName:"<<testChar<<endl;
		ofn<<"pathFileName:"<<test_b1<<endl;
 
 	    system("pause");//程序暂停，按任意键继续
 
	}
 
	ofn.close(); 
 
 
return 0;
 
}
 
 
void getFiles( string path, vector<string>& files )
{
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					getFiles( p.assign(path).append("\\").append(fileinfo.name), files );
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_findclose(hFile);
	}
}
 
void getFilesName( string path, vector<string>& files )
{
	//文件句柄
	long   hFile   =   0;
	//文件信息
	struct _finddata_t fileinfo;
	string p;
	if((hFile = _findfirst(p.assign(path).append("\\*").c_str(),&fileinfo)) !=  -1)
	{
		do
		{
			//如果是目录,迭代之
			//如果不是,加入列表
			if((fileinfo.attrib &  _A_SUBDIR))
			{
				if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
					//getFiles( p.assign(path).append("\\").append(fileinfo.name), files );
						getFiles( fileinfo.name, files );
			}
			else
			{
				//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
				files.push_back(fileinfo.name);
			}
		}while(_findnext(hFile, &fileinfo)  == 0);
		_fclose(hFile);
	}
}
 
char* str2char(string src) 
{
	char *dst = new char[255];
	int i; 
	for(i=0;i <=src.length();i++) 
		dst[i]=src[i]; 
	dst[i] = '\0';
	return dst;
}
 
 
