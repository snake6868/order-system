#ifndef MENU_H
#define MENU_H
#include <string>

using namespace std;

class menu                            //����Cmenu��  �˵�����
{
	int num;                        //�˵ı��
	string  name;                   //����
	float price;                    //�˵ĵ���
	string kind;                    //�˵�����
	int sort;                       //�˵�����

public:
	void getnum(int i);             //¼��˵ı��

	void getname(string Name);      //¼��˵�����

	void getprice(float Price);     //¼��˵ĵ���

	void getkind(string Kind);      //¼��˵����

	void getsort(int SORT);         //¼������˵�����

	void menudisplay();             //������ʾ

	void selectdisplay();           //������Ĳ˽������

	int returnnum()               //���ز˵ı��
	{
		return num;
	}

	string returnname()             //���ز���
	{
		return name;
	}

	float  returnprice()            //���ز˵ĵ���
	{
		return price;
	}

	string returnkind()             //���ز˵����
	{
		return kind;
	}

	int  returnsort()               //���ز˵�����
	{
		return sort;
	}

};

#endif // MENU_H

