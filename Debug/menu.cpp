#include "menu.h"
#include<iostream>
#include<iomanip>

using namespace std;

void menu::getnum(int i)              //录入菜的编号函数
{
	num = i;
}



void menu::getname(string Name)       //录入菜的名字
{
	name = Name;
}



void menu::getprice(float Price)      //录入菜的单价
{
	price = Price;
}



void menu::getkind(string Kind)       //录入菜的类别
{
	kind = Kind;
}



void menu::getsort(int SORT)          // 录入所点菜的数量
{
	sort = SORT;
}

void menu::menudisplay()              //菜单的信息显示
{
	cout << setw(3) << num << setw(22) << name << setw(16) << kind << setw(16) << price << endl;
}



void  menu::selectdisplay()           //对所点的菜进行输出

{
	cout << setw(3) << num << setw(24) << name << setw(16) << kind << setw(16) << price << setw(19) << sort << endl;
}
