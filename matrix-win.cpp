#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
//#include<urlmon.h>
#define CONFIGFILENAME "matrixaccount.dat"//���������ļ��� 
#define MATRIX "matrix.exe" 
using namespace std;
bool datafile(void)//�ж��Ƿ�������е������ļ� 
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
bool mainfile(void)//�ж��Ƿ�������е�matrix������ 
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
bool network(void)//�ж��Ƿ�������е��������� 
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
string readfile(void)//�������� 
{
	ifstream ifs;
	ifs.open(CONFIGFILENAME,ios::in);
	string user;
	getline(ifs,user);
	ifs.close();
	return user;
} 
void start(string a)//���������� 
{
	string command;
	command="start matrix.exe -k "+a;
	system(command.c_str());
}
void downloadM(void)//����matrix 
{
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/matrix.exe");
	system("certutil -urlcache -split -f https://gitcode.net/to/matrix/-/raw/master/windows/matrix_env.exe");
}
void downloadN(void)//�������� 
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
	system("title matrix��Ƕ");	
	cout<<"|---\\            /---|        ----       --------   -----|       -      \\      /"<<endl;
    cout<<"|    \\          /    |       /    \\          |      |    |       |       \\    /"<<endl;
    cout<<"|     \\        /     |      /      \\         |      -----|       |        \\  / "<<endl;
    cout<<"|      \\      /      |     /        \\        |      |\\           |         \\/"<<endl;
    cout<<"|       \\    /       |    /----------\\       |      | \\          |         /\\ "<<endl;
    cout<<"|        \\--/        |   /            \\      |      |  \\         |        /  \\"<<endl;
	cout<<"##############################################################"<<endl;
	cout<<"                       matrix�Զ�����                         "<<endl;
	cout<<"matrix��mcer.cn�ṩ��Դ��������ԴΪgitcode.net/chearlai/matrix"<<endl;
	cout<<"   ��������xzh767�������ѿ�Դ��github.com/xzh767/auto-matrix  "<<endl;
	cout<<"##############################################################"<<endl;
	system("pause");
	//��ʼҳ����
	system("cls");
	system("rd %userprofile%\\AppData\\Local\\Microsoft\\Windows\\INetCache /s /q");//���inet���棬��һ���������Һܳ�ʱ�� 
	cout<<"���ڼ�Ȿ���Ƿ���������������������ļ�..."<<endl;
	string user;
	if(datafile())
	{
		cout<<"���ô��ڣ����ڵ���..."<<endl;
		user=readfile();
	} 
	else
	{
		cout<<"û���Ѵ��ڵ������ļ���"<<endl;
		cout<<"���������ƾ֤��û����� mcer.cn/shop/370.html����!"<<endl;
		cin>>user; 
		write(user);
	}
	//����ƾ֤����
	cout<<"���ڼ���Ƿ����tap��������..."<<endl;
	if(network()) 
	{
		cout<<"�������ڣ��������أ�"<<endl; 
	}
	else
	{
		cout<<"û��������������ʼ����..."<<endl;
		downloadN();
		cout<<"����������װ��ɣ�"<<endl; 
	}
	cout<<"���ڼ���Ƿ����Ѿ����غõ�matrix..."<<endl;
	if(mainfile())
	{
		cout<<"��⵽���е�matrix,׼������������..."<<endl;
		start(user);
		cout<<"matirx�����ɹ�����Ϸ����ǰ����رմ˴��ڣ�"<<endl; 
	}
	else
	{
		cout<<"����û��matrix,��������..."<<endl;
		downloadM(); 
		cout<<"������ɣ�׼������..."<<endl;
		start(user);
		cout<<"matirx�����ɹ�����Ϸ����ǰ����رմ˴��ڣ�"<<endl;
	}
}

