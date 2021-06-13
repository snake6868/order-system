#ifndef MENU_H
#define MENU_H
#include <string>

using namespace std;

class menu                            //创建Cmenu类  菜的属性
{
	int num;                        //菜的编号
	string  name;                   //菜名
	float price;                    //菜的单价
	string kind;                    //菜的种类
	int sort;                       //菜的数量

public:
	void getnum(int i);             //录入菜的编号

	void getname(string Name);      //录入菜的名字

	void getprice(float Price);     //录入菜的单价

	void getkind(string Kind);      //录入菜的类别

	void getsort(int SORT);         //录入所点菜的数量

	void menudisplay();             //菜谱显示

	void selectdisplay();           //对所点的菜进行输出

	int returnnum()               //返回菜的编号
	{
		return num;
	}

	string returnname()             //返回菜名
	{
		return name;
	}

	float  returnprice()            //返回菜的单价
	{
		return price;
	}

	string returnkind()             //返回菜的类别
	{
		return kind;
	}

	int  returnsort()               //返回菜的数量
	{
		return sort;
	}

};

#endif // MENU_H

