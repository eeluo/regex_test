//regex.cpp - 用正则表达式验证电子邮件地址
#include <iostream>
#include <cstdlib>
#include <string>
#include <regex>  // regular expression 正则表达式
//#include <stdio.h>
using namespace std;
bool is_email_valid( string email_address);
bool is_tel_valid(string tel_number);
bool is_id_valid(string id_number);

int main(int argc, char *argv[])
{
	string email_address;//电子邮件
	string tel_number;//电话号码
	string id_number;//身份证号码

	// 输入文件结尾符（Windows用Ctrl+Z，UNIX用Ctrl+D）结束循环
	cout << "请输入您的电子邮箱" << endl;
	cout << "要求电子邮箱中不含空格，且以数字或字母开头" << endl;
	cin >> email_address;	
	bool email_result = is_email_valid(email_address);
	if (email_result)
	{
		cout << "您输入的电子邮件地址合法" << endl;
	}
	else
	{
		cout << "您输入的电子邮件地址不合法" << endl << endl;
	}
	
	cout << "请输入您的固定电话或手机号码" << endl;
	cout << "手机号码为11位数字，固定电话可以含3-4位区号，用-隔开，也可以是7-8位的直播号码" << endl;
	cin >> tel_number;
	bool tel_result = is_tel_valid(tel_number);
	if (tel_result)
	{
		cout << "您输入的号码合法" << endl;
	}
	else
	{
		cout << "您输入的号码不合法" << endl << endl;
	}
	cout << "请输入您的身份证号码" << endl;
	cout << "身份证号码必须是18位数字，或者17位数字且最后一位为x或X" << endl;
	cin >> id_number;
	bool id_result = is_id_valid(id_number);
	if (id_result)
	{
		cout << "您输入的身份证号码合法" << endl;
	}
	else
	{
		cout << "您输入的身份证号码不合法" << endl << endl;
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