#include "menu.h"
#include<iostream>
#include<iomanip>

using namespace std;

void menu::getnum(int i)              //¼��˵ı�ź���
{
	num = i;
}



void menu::getname(string Name)       //¼��˵�����
{
	name = Name;
}



void menu::getprice(float Price)      //¼��˵ĵ���
{
	price = Price;
}



void menu::getkind(string Kind)       //¼��˵����
{
	kind = Kind;
}



void menu::getsort(int SORT)          // ¼������˵�����
{
	sort = SORT;
}

void menu::menudisplay()              //�˵�����Ϣ��ʾ
{
	cout << setw(3) << num << setw(22) << name << setw(16) << kind << setw(16) << price << endl;
}



void  menu::selectdisplay()           //������Ĳ˽������

{
	cout << setw(3) << num << setw(24) << name << setw(16) << kind << setw(16) << price << setw(19) << sort << endl;
}
