#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
#include<stdlib.h>
#define CONFIGFILENAME "matrixaccount.dat"//���������ļ��� 
#define MATRIX "matrix" 
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
string readfile(void)//�������� 
{
	ifstream ifs;
	ifs.open("matrixaccount.dat",ios::in);
	string user;
	getline(ifs,user);
	ifs.close();
	return user;
} 
void start(string a)//���������� 
{
	string command;
	command="./matrix -k "+a;
	system(command.c_str());
}
void download(void)//����matrix 
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
	cout<<"                       matrix�Զ�����                         "<<endl;
	cout<<"matrix��mcer.cn�ṩ��Դ��������ԴΪgitcode.net/chearlai/matrix"<<endl;
	cout<<"   ��������xzh767�������ѿ�Դ��github.com/xzh767/auto-matrix  "<<endl;
	cout<<"##############################################################"<<endl;
	cout<<"�밴���������..."<<endl; 
	system("read -n 1");
	//��ʼҳ����
	system("clear");
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
		download(); 
		cout<<"������ɣ�׼������..."<<endl;
		start(user);
		cout<<"matirx�����ɹ�����Ϸ����ǰ����رմ˴��ڣ�"<<endl;
	}
}

