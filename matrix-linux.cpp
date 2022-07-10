#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<stdlib.h>
#define CONFIGFILENAME "matrixaccount.dat"//定义配置文件名 
#define MATRIX "matrix" 
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
string readfile(void)//读入数据 
{
	ifstream ifs;
	ifs.open("matrixaccount.dat",ios::in);
	string user;
	getline(ifs,user);
	ifs.close();
	return user;
} 
void start(string a)//启动主程序 
{
	string command;
	command="./matrix -k "+a;
	system(command.c_str());
}
void download(void)//下载matrix 
{
	system("wget https://gitcode.net/chearlai/matrix/-/blob/master/linux/i386/matrix");
	system("wget https://gitcode.net/chearlai/matrix/-/blob/master/linux/i386/matrix_env");
}
void write(string a)
{
	system("touch matrixaccount.dat");
	ofstream ofs;
	ofs.open("matrixaccount.dat",ios::out);
	ofs << a;
	ofs.close(); 
}
int main()
{
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
	cout<<"请按任意键继续..."<<endl; 
	system("read -n 1");
	//起始页部分
	system("clear");
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
		download(); 
		cout<<"下载完成，准备启动..."<<endl;
		start(user);
		cout<<"matirx启动成功，游戏结束前请勿关闭此窗口！"<<endl;
	}
}

