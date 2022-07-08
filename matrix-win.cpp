#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
//#include<urlmon.h>
#define CONFIGFILENAME "matrixaccount.dat"//定义配置文件名 
#define MATRIX "matrix.exe" 
using namespace std;
bool datafile(void)//判断是否存在已有的配置文件 
{
	fstream _file;
    _file.open(CONFIGFILENAME, ios::in);
    if(!_file)
    {
	  return false;
    }
    else
    {
    	return true;
    }
}
bool mainfile(void)//判断是否存在已有的matrix主程序 
{
	fstream _file;
    _file.open(MATRIX, ios::in);
    if(!_file)
    {
	  return false;
    }
    else
    {
    	return true;
    }
}
bool network(void)//判断是否存在已有的网卡驱动 
{
	fstream _file;
    _file.open("c:\\Windows\\System32\\drivers\\tap0901.sys", ios::in);
    if(!_file)
    {
	  return false;
    }
    else
    {
    	return true;
    }
}
string readfile(void)//读入数据 
{
	ifstream ifs;
	ifs.open(CONFIGFILENAME,ios::in);
	string user;
	getline(ifs,user);
	ifs.close();
	return user;
} 
void start(string a)//启动主程序 
{
	string command;
	command="start matrix.exe -k "+a;
	system(command.c_str());
}
void downloadM(void)//下载matrix 
{
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/matrix.exe");
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/matrix_env.exe");
}
void downloadN(void)//下载网卡 
{
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/FIRST_RUN_THIS_SCRIPT.bat");
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/OemVista.inf");
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/tap_install.exe");
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/tap0901.sys");
	system("del run.bat");
	system("type NUL > run.bat");
	ofstream ofs;
	ofs.open("run.bat",ios::out);
	ofs << "@echo off"<<endl;
	ofs << "Net session >nul 2>&1 || powershell start-process FIRST_RUN_THIS_SCRIPT.bat -verb runas";
	ofs.close();
	system("run.bat");
}
void write(string a)
{
	system("type NUL > matrixaccount.dat");
	ofstream ofs;
	ofs.open("matrixaccount.dat",ios::out);
	ofs << a;
	ofs.close(); 
}
int main()
{
	system("@echo off");
	system("title matrix内嵌");	
	cout<<"|---\\            /---|        ----       --------   -----|       -      \\      /"<<endl;
    cout<<"|    \\          /    |       /    \\          |      |    |       |       \\    /"<<endl;
    cout<<"|     \\        /     |      /      \\         |      -----|       |        \\  / "<<endl;
    cout<<"|      \\      /      |     /        \\        |      |\\           |         \\/"<<endl;
    cout<<"|       \\    /       |    /----------\\       |      | \\          |         /\\ "<<endl;
    cout<<"|        \\--/        |   /            \\      |      |  \\         |        /  \\"<<endl;
	cout<<"##############################################################"<<endl;
	cout<<"                       matrix自动连接                         "<<endl;
	cout<<"matrix由mcer.cn提供，源程序下载源为gitcode.net/chearlai/matrix"<<endl;
	cout<<"   本程序由xzh767开发，已开源至github.com/xzh767/auto-matrix  "<<endl;
	cout<<"##############################################################"<<endl;
	system("pause");
	//起始页部分
	system("cls");
	system("rd %userprofile%\\AppData\\Local\\Microsoft\\Windows\\INetCache /s /q");//清除inet缓存，这一步困扰了我很长时间 
	cout<<"正在检测本机是否存在曾经创建过的配置文件..."<<endl;
	string user;
	if(datafile())
	{
		cout<<"配置存在，正在导入..."<<endl;
		user=readfile();
	} 
	else
	{
		cout<<"没有已存在的配置文件！"<<endl;
		cout<<"请输入你的凭证，没有请从 mcer.cn/shop/370.html购买!"<<endl;
		cin>>user; 
		write(user);
	}
	//读入凭证部分
	cout<<"正在检测是否存在tap网卡驱动..."<<endl;
	if(network()) 
	{
		cout<<"网卡存在，无需下载！"<<endl; 
	}
	else
	{
		cout<<"没有网卡驱动，开始下载..."<<endl;
		downloadN();
		cout<<"网卡驱动安装完成！"<<endl; 
	}
	cout<<"正在检测是否有已经下载好的matrix..."<<endl;
	if(mainfile())
	{
		cout<<"检测到已有的matrix,准备启动主程序..."<<endl;
		start(user);
		cout<<"matirx启动成功，游戏结束前请勿关闭此窗口！"<<endl; 
	}
	else
	{
		cout<<"本地没有matrix,正在下载..."<<endl;
		downloadM(); 
		cout<<"下载完成，准备启动..."<<endl;
		start(user);
		cout<<"matirx启动成功，游戏结束前请勿关闭此窗口！"<<endl;
	}
}

