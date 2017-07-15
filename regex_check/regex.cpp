//regex.cpp - ��������ʽ��֤�����ʼ���ַ
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>  // regular expression ������ʽ
//#include <stdio.h>
using namespace std;
bool is_email_valid( string email_address);
bool is_tel_valid(string tel_number);
bool is_id_valid(string id_number);

int main(int argc, char *argv[])
{
	string email_address;//�����ʼ�
	string tel_number;//�绰����
	string id_number;//���֤����

	// �����ļ���β����Windows��Ctrl+Z��UNIX��Ctrl+D������ѭ��
	cout << "���������ĵ�������" << endl;
	cout << "Ҫ����������в����ո��������ֻ���ĸ��ͷ" << endl;
	cin >> email_address;	
	bool email_result = is_email_valid(email_address);
	if (email_result)
	{
		cout << "������ĵ����ʼ���ַ�Ϸ�" << endl;
	}
	else
	{
		cout << "������ĵ����ʼ���ַ���Ϸ�" << endl << endl;
	}
	
	cout << "���������Ĺ̶��绰���ֻ�����" << endl;
	cout << "�ֻ�����Ϊ11λ���֣��̶��绰���Ժ�3-4λ���ţ���-������Ҳ������7-8λ��ֱ������" << endl;
	cin >> tel_number;
	bool tel_result = is_tel_valid(tel_number);
	if (tel_result)
	{
		cout << "������ĺ���Ϸ�" << endl;
	}
	else
	{
		cout << "������ĺ��벻�Ϸ�" << endl << endl;
	}
	cout << "�������������֤����" << endl;
	cout << "���֤���������18λ���֣�����17λ���������һλΪx��X" << endl;
	cin >> id_number;
	bool id_result = is_id_valid(id_number);
	if (id_result)
	{
		cout << "����������֤����Ϸ�" << endl;
	}
	else
	{
		cout << "����������֤���벻�Ϸ�" << endl << endl;
	}
	system("pause");
	cin.get();
	return 0;

}

bool is_email_valid( string email_address)
{
	regex pattern("\\w+([-+.]\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*");
	return regex_match(email_address, pattern);
}
bool is_tel_valid(string tel_number)
{
	regex pattern("((\\d{11})|(\\d{7,8})|(\\d{4}|\\d{3})-(\\d{7,8}))");
	return regex_match(tel_number, pattern);
}
bool is_id_valid(string id_number)
{
	regex pattern("(\\d{18})|(\\d{17}(\\d|X|x))");
	return regex_match(id_number, pattern);
}