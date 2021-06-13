#include <iostream>
#include <graphics.h>
#include <conio.h>
#include<stdio.h>
#include<string.h>
#include<easyx.h>
#include<fstream>
#include"menu.h"
#include"users.h"
#include<istream>
#include<string>
#include<stdlib.h>
#include<cstdio>
#include<iomanip>

using namespace std;

HWND hWnd;

struct Menuu
{
	char name[100];
	float price;
} chaocai[100], chaofan[100], mian[100];

struct recent
{
	char name[100];
	int piece;
}recentorder[100];

void quickSortprice(Menuu* num, Menuu* l, Menuu* r)
{
	if (l >= r)     //先检查左右条件
		return;
	Menuu* i = l;
	Menuu* j = r;
	Menuu x = *l;//充当标记位
	while (i < j)
	{

		while (i < j && j->price >= x.price)//从右向左找到第一个小于x的
			j--;
		if (i < j)
		{
			*i = *j;
			i++;
		} //填坑之后i++

		while (i < j && i->price <= x.price)//从左向右找第一个大于x的数

			i++;
		if (i < j)
		{
			*j = *i;
			j--;
		}
	}
	*i = x;
	//把最开始取出来的x放到i处
	quickSortprice(num, l, i - 1);//以i为中间值，分左右两部分递归调用
	quickSortprice(num, i + 1, r);
}

void quickmain()
{
	char c;
	int line0 = 0;
	int line1 = 0;
	int line2 = 0;//记录每种菜的行数（个数）
	ifstream ofile0;
	ofile0.open("chaocai.txt");//ofile用来将文档中的菜写入结构体数组
	fstream get1("chaocai.txt", ios::in);
	while (get1.get(c))
	{
		if (c == '\n')
			line0++;
	}
	if (ofile0)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line0; i++)
		{
			ofile0 >> chaocai[i].name >> chaocai[i].price;
		}
	}
	ofile0.close();

	Menuu* l0 = &chaocai[0];
	Menuu* r0 = &chaocai[line0 - 1];

	quickSortprice(chaocai, l0, r0);

	ofstream file0;//file用来存储快排后的菜
	file0.open("quickSortprice0.txt");
	fstream get11("quickSortprice0.txt", ios::app);
	if (file0)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line0; i++)
		{
			file0 << chaocai[i].name << ' ' << chaocai[i].price << endl;
		}
	}
	file0.close();

	ifstream ofile1;
	ofile1.open("chaofan.txt");
	fstream get2("chaofan.txt", ios::in);
	while (get2.get(c))
	{
		if (c == '\n')
			line1++;
	}
	if (ofile1)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line1; i++)
		{
			ofile1 >> chaofan[i].name >> chaofan[i].price;
		}
	}
	ofile1.close();

	Menuu* l1 = &chaofan[0];
	Menuu* r1 = &chaofan[line1 - 1];

	quickSortprice(chaofan, l1, r1);

	ofstream file1;
	file1.open("quickSortprice1.txt");
	fstream get22("quickSortprice1.txt", ios::app);
	if (file1)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line1; i++)
		{
			file1 << chaofan[i].name << ' ' << chaofan[i].price << endl;
		}
	}
	file1.close();

	ifstream ofile2;
	ofile2.open("mian.txt");
	fstream get3("mian.txt", ios::in);
	while (get3.get(c))
	{
		if (c == '\n')
			line2++;
	}
	if (ofile2)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line2; i++)
		{
			ofile2 >> mian[i].name >> mian[i].price;
		}
	}
	ofile2.close();

	Menuu* l2 = &mian[0];
	Menuu* r2 = &mian[line2 - 1];

	quickSortprice(mian, l2, r2);

	ofstream file2;
	file2.open("quickSortprice2.txt");
	fstream get33("quickSortprice2.txt", ios::app);
	if (file2)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line2; i++)
		{
			file2 << mian[i].name << ' ' << mian[i].price << endl;
		}
	}
	file2.close();
}

int showrecentorder()
{
	initgraph(500, 800);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(NULL, "4.jpg");
	settextcolor(BLACK);
	char c;
	int line = 0;
	rectangle(400, 700, 434, 720);
	outtextxy(402, 702, "返回");
	outtextxy(12, 20, "用户：");
	outtextxy(12, 50, "菜名");
	outtextxy(212, 50, "数量");
	char user[100];

	ifstream file;
	file.open("recentuser.txt");
	if (file)  //条件成立，则说明文件打开成功
		file >> user;
	file.close();
	outtextxy(60, 20, user);

	ifstream rfile;
	rfile.open("recentorder.txt");
	fstream get1("recentorder.txt", ios::in);
	while (get1.get(c))
	{
		if (c == '\n')
			line++;
	}
	if (rfile)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line; i++)
		{
			rfile >> recentorder[i].name >> recentorder[i].piece;
		}
	}
	rfile.close();
	for (int i = 0; i < line; i++)
	{
		char p[1000];
		sprintf_s(p, "%d", recentorder[i].piece);
		outtextxy(12, 80 + i * 30, recentorder[i].name);
		outtextxy(212, 80 + i * 30, p);
	}
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x >= 400 && m.x <= 434 && m.y >= 700 && m.y <= 720)
			{
				return 1;
			}
		}
	}
	_getch();
	closegraph();
}

int begin()
{

	initgraph(1024, 559);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(NULL, "3.jpg");
	settextcolor(BLACK);
	setcolor(BLACK);
	fillrectangle(500, 250, 610, 300);
	char s1[] = "注册";
	outtextxy(540, 270, s1);
	fillrectangle(500, 350, 610, 400);
	char s2[] = "登录";
	outtextxy(540, 363, s2);
	fillrectangle(500, 450, 610, 500);
	char s3[] = "管理员";
	outtextxy(530, 463, s3);

	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x >= 500 && m.x <= 610 && m.y >= 250 && m.y <= 300)
			{
				return 0;
			}

			if (m.x >= 500 && m.x <= 610 && m.y >= 350 && m.y <= 400)
			{
				return 1;
			}

			if (m.x >= 500 && m.x <= 610 && m.y >= 450 && m.y <= 500)
			{
				return 2;
			}
		}
	}
	_getch();
	closegraph;
}

int newacc()
{
	initgraph(750, 700);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(NULL, "5.png");
	settextcolor(BLACK);
	ofstream file;
	file.open("users.txt", ios::app);
	if (file)  //条件成立，则说明文件打开成功
	{
		char number[10];
		char key1[20];
		char key2[20];
		InputBox(number, 10, "请输入账号（用户名）");
		ifstream infile;
		infile.open("users.txt");
		fstream get1("users.txt", ios::in);
		char c;
		int line = 0;
		while (get1.get(c))
		{
			if (c == '\n')
				line++;
		}
		users user[100];
		if (infile)  //条件成立，则说明文件打开成功
		{
			for (int i = 0; i < line; i++)
			{
				getline(infile, user[i].singleuser, ' ');
				getline(infile, user[i].password, '\n');
			}
		}
		int target = -1;
		for (int i = 0; i < line; i++)
		{
			if (number == user[i].singleuser)
			{
				target = 0;
				break;
			}
		}
		if (target == 0)
		{

			outtextxy(300, 300, "该用户名已存在");
			setcolor(RED);
			rectangle(100, 500, 170, 520);
			outtextxy(105, 502, "重新注册");
			rectangle(500, 500, 550, 520);
			outtextxy(508, 502, "退出");
			MOUSEMSG m;
			while (1)
			{
				m = GetMouseMsg();
				if (m.uMsg == WM_LBUTTONDOWN)
				{
					if (m.x >= 100 && m.x <= 170 && m.y >= 500 && m.y <= 520)
					{
						return 2;
					}
					if (m.x >= 500 && m.x <= 550 && m.y >= 500 && m.y <= 520)
					{
						return 0;
					}
				}
			}
		}
		if (target == -1)
		{
			InputBox(key1, 20, "请输入密码");
			InputBox(key2, 20, "请再次输入密码");
			if ((string)key1 == (string)key2)
			{
				outtextxy(300, 300, "已创建新用户：");
				file << number << ' ' << key1 << endl;
				setcolor(RED);
				rectangle(100, 500, 170, 520);
				outtextxy(105, 502, "开始点菜");
				rectangle(500, 500, 550, 520);
				outtextxy(508, 502, "退出");
				MOUSEMSG m;
				while (1)
				{
					m = GetMouseMsg();
					if (m.uMsg == WM_LBUTTONDOWN)
					{
						if (m.x >= 100 && m.x <= 170 && m.y >= 500 && m.y <= 520)
						{
							ofstream file;
							file.open("recentuser.txt");
							fstream get22("recentuser.txt", ios::app);
							if (file)  //条件成立，则说明文件打开成功
								file << number << endl;
							file.close();
							return 1;
						}
						if (m.x >= 500 && m.x <= 550 && m.y >= 500 && m.y <= 520)
						{
							return 0;
						}
					}
				}
			}
			else
			{
				outtextxy(300, 300, "两次输入的密码不一致");
				setcolor(RED);
				rectangle(100, 500, 170, 520);
				outtextxy(105, 502, "重新注册");
				rectangle(500, 500, 550, 520);
				outtextxy(508, 502, "退出");
				MOUSEMSG m;
				while (1)
				{
					m = GetMouseMsg();
					if (m.uMsg == WM_LBUTTONDOWN)
					{
						if (m.x >= 100 && m.x <= 170 && m.y >= 500 && m.y <= 520)
						{
							return 2;
						}

						if (m.x >= 500 && m.x <= 550 && m.y >= 500 && m.y <= 520)
						{
							return 0;
						}
					}
				}
			}
		}
		infile.close();
	}
	file.close();
	_getch();
	closegraph;
	return 0;
}

int Register()
{
	initgraph(750, 700);
	loadimage(NULL, "1.jfif");

	char number[10];
	char key[20];
	int line = 0;
	users user[100];
	ofstream file;
	file.open("users.txt", ios::app);
	if (file)  //条件成立，则说明文件打开成功
	{
		ifstream infile;
		infile.open("users.txt");
		fstream get1("users.txt", ios::in);
		char c;
		while (get1.get(c))
		{
			if (c == '\n')
				line++;
		}
		if (infile)  //条件成立，则说明文件打开成功
		{
			for (int i = 0; i < line; i++)
			{
				getline(infile, user[i].singleuser, ' ');
				getline(infile, user[i].password, '\n');
			}
		}
		infile.close();
	}
	file.close();
	InputBox(number, 10, "请输入账号(用户名）");
	int target = -1;
	for (int i = 0; i < line; i++)
	{
		if (number == user[i].singleuser)
		{
			target = i;
			break;
		}
	}
	if (target == -1)
	{
		outtextxy(300, 300, "该用户名不存在");
		rectangle(330, 500, 400, 520);
		outtextxy(335, 502, "重新登录");
		MOUSEMSG m;
		while (1)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x >= 330 && m.x <= 400 && m.y >= 500 && m.y <= 520)
				{
					return 2;
				}
			}
		}
	}
	InputBox(key, 20, "请输入密码");

	if ((string)key == user[target].password)
	{
		ofstream file;
		file.open("recentuser.txt");
		fstream get22("recentuser.txt", ios::app);
		if (file)  //条件成立，则说明文件打开成功
			file << number << endl;
		file.close();
		return 0;
	}

	else
	{
		outtextxy(330, 300, "密码错误");
		rectangle(330, 500, 400, 520);
		outtextxy(335, 502, "重新登录");
		MOUSEMSG m;
		while (1)
		{
			m = GetMouseMsg();
			if (m.uMsg == WM_LBUTTONDOWN)
			{
				if (m.x >= 330 && m.x <= 400 && m.y >= 500 && m.y <= 520)
				{
					return 2;
				}
			}
		}
	}
	_getch();
	closegraph;
}

float takeorder()
{
	initgraph(1220, 844);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(NULL, "4.jpg");
	settextcolor(BLACK);

	char c;
	int line0 = 0;
	int line1 = 0;
	int line2 = 0;

	ifstream rfile0;
	rfile0.open("quickSortprice0.txt");
	fstream get1("quickSortprice0.txt", ios::in);
	while (get1.get(c))
	{
		if (c == '\n')
			line0++;
	}
	if (rfile0)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line0; i++)
		{
			rfile0 >> chaocai[i].name >> chaocai[i].price;
		}
	}
	rfile0.close();

	ifstream rfile1;
	rfile1.open("quickSortprice1.txt");
	fstream get2("quickSortprice1.txt", ios::in);
	while (get2.get(c))
	{
		if (c == '\n')
			line1++;
	}
	if (rfile1)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line1; i++)
		{
			rfile1 >> chaofan[i].name >> chaofan[i].price;
		}
	}
	rfile1.close();

	ifstream rfile2;
	rfile2.open("quickSortprice2.txt");
	fstream get3("quickSortprice2.txt", ios::in);
	while (get3.get(c))
	{
		if (c == '\n')
			line2++;
	}
	if (rfile2)  //条件成立，则说明文件打开成功
	{
		for (int i = 0; i < line2; i++)
		{
			rfile2 >> mian[i].name >> mian[i].price;
		}
	}
	rfile2.close();


	setcolor(RED);
	fillrectangle(10, 10, 80, 40);
	char s00[] = "炒菜类";
	outtextxy(16, 18, s00);

	setcolor(BLACK);
	for (int i = 0; i < line0; i++)
	{
		fillrectangle(10, 70 + 60 * i, 80, 100 + 60 * i);
		char p[1000];
		sprintf_s(p, "%f", chaocai[i].price);
		outtextxy(12, 80 + i * 60, chaocai[i].name);
		outtextxy(15, 105 + i * 60, p);
	}

	setcolor(RED);
	fillrectangle(110, 10, 180, 40);
	char s10[] = "炒饭类";
	outtextxy(116, 18, s10);

	setcolor(BLACK);
	for (int i = 0; i < line1; i++)
	{
		fillrectangle(110, 70 + 60 * i, 180, 100 + 60 * i);
		char p[1000];
		sprintf_s(p, "%f", chaofan[i].price);
		outtextxy(112, 80 + i * 60, chaofan[i].name);
		outtextxy(115, 105 + i * 60, p);
	}

	setcolor(RED);
	fillrectangle(210, 10, 280, 40);
	char s20[] = "面类";
	outtextxy(222, 18, s20);

	setcolor(BLACK);

	for (int i = 0; i < line2; i++)
	{
		fillrectangle(210, 70 + 60 * i, 280, 100 + 60 * i);
		char p[1000];
		sprintf_s(p, "%f", mian[i].price);
		outtextxy(220, 80 + i * 60, mian[i].name);
		outtextxy(215, 105 + i * 60, p);
	}

	int flag = 0;//用来判断输出的y坐标
	int keepflag[100][100] = { 0 };//用来锁定输出的y坐标（当这个菜被点过一次后）
	int count[100][100] = { 0 };//用来判断点菜的个数

	char out[] = "您点的菜为：                价格                  数量";
	outtextxy(400, 18, out);
	char sumout[] = "合计：";
	outtextxy(400, 600, sumout);

	fillrectangle(800, 20, 860, 50);
	settextcolor(BLUE);
	char exact[] = "确定";
	outtextxy(812, 28, exact);

	fillrectangle(800, 70, 880, 100);
	settextcolor(BLUE);
	char cancel[] = "重新点菜";
	outtextxy(810, 78, cancel);

	fillrectangle(800, 120, 880, 150);
	settextcolor(BLUE);
	char recent[] = "最近订单";
	outtextxy(810, 128, recent);

	MOUSEMSG m;
	float sum = 0;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			settextcolor(BLACK);
			if (m.x >= 800 && m.x <= 860 && m.y >= 20 && m.y <= 50)
			{
				ofstream write0;
				ifstream read0;
				write0.open("recentorder.txt", ios::trunc);				//用ios::app不会覆盖文件内容
				for (int i = 0; i < max(line0, line1, line2); i++)
				{
					if (count[0][i] != 0)
						write0 << chaocai[i].name << ' ' << count[0][i] << endl;
					if (count[1][i] != 0)
						write0 << chaofan[i].name << ' ' << count[1][i] << endl;
					if (count[2][i] != 0)
						write0 << mian[i].name << ' ' << count[2][i] << endl;
				}
				write0.close();
				read0.close();
				return sum;
			}
			if (m.x >= 800 && m.x <= 880 && m.y >= 70 && m.y <= 100)
			{
				return -1;
			}
			if (m.x >= 800 && m.x <= 880 && m.y >= 120 && m.y <= 150)
			{
				return -2;
			}

			for (int i = 0; i < line0; i++)
			{
				if (m.x >= 10 && m.x <= 80 && m.y >= (70 + i * 60) && m.y <= (100 + i * 60))
				{
					sum += chaocai[i].price;
					count[0][i]++;
					if (count[0][i] > 1)
					{
						char bor[10];
						sprintf_s(bor, "%d", count[0][i]);
						outtextxy(675, 40 + keepflag[0][i] * 20, bor);
					}
					else
					{
						keepflag[0][i] = flag;
						char p[1000];
						sprintf_s(p, "%f", chaocai[i].price);
						outtextxy(400, 40 + flag * 20, chaocai[i].name);
						outtextxy(565, 40 + flag * 20, p);
						outtextxy(675, 40 + flag * 20, "1");
						flag++;
					}
					char summ[100];
					sprintf_s(summ, "%f", sum);
					outtextxy(445, 600, summ);
				}

			}

			for (int i = 0; i < line1; i++)
			{
				if (m.x >= 110 && m.x <= 180 && m.y >= (70 + i * 60) && m.y <= (100 + i * 60))
				{
					sum += chaofan[i].price;
					count[1][i]++;
					if (count[1][i] > 1)
					{
						char bor[10];
						sprintf_s(bor, "%d", count[1][i]);
						outtextxy(675, 40 + keepflag[1][i] * 20, bor);
					}
					else
					{
						keepflag[1][i] = flag;
						outtextxy(400, 40 + flag * 20, chaofan[i].name);
						char p[1000];
						sprintf_s(p, "%f", chaofan[i].price);
						outtextxy(565, 40 + flag * 20, p);
						outtextxy(675, 40 + flag * 20, "1");
						flag++;
					}
					char summ[100];
					sprintf_s(summ, "%f", sum);
					outtextxy(445, 600, summ);
				}
			}

			for (int i = 0; i < line2; i++)
			{
				if (m.x >= 210 && m.x <= 280 && m.y >= (70 + i * 60) && m.y <= (100 + i * 60))
				{
					sum += mian[i].price;
					count[2][i]++;
					if (count[2][i] > 1)
					{
						char bor[10];
						sprintf_s(bor, "%d", count[2][i]);
						outtextxy(675, 40 + keepflag[2][i] * 20, bor);
					}
					else
					{
						keepflag[2][i] = flag;
						outtextxy(400, 40 + flag * 20, mian[i].name);
						char p[1000];
						sprintf_s(p, "%f", mian[i].price);
						outtextxy(565, 40 + flag * 20, p);
						outtextxy(675, 40 + flag * 20, "1");
						flag++;
					}
					char summ[100];
					sprintf_s(summ, "%f", sum);
					outtextxy(445, 600, summ);
				}
			}

		}
		if (m.uMsg == WM_RBUTTONDOWN)
		{
			settextcolor(BLACK);
			for (int i = 0; i < line0; i++)
			{
				if (m.x >= 10 && m.x <= 80 && m.y >= (70 + i * 60) && m.y <= (100 + i * 60))
				{
					if (count[0][i] > 0)
					{
						sum -= chaocai[i].price;
						count[0][i]--;
						char bor[10];
						sprintf_s(bor, "%d", count[0][i]);
						outtextxy(675, 40 + keepflag[0][i] * 20, bor);
					}
					char summ[100];
					sprintf_s(summ, "%f", sum);
					outtextxy(445, 600, summ);
				}
			}
			for (int i = 0; i < line1; i++)
			{
				if (m.x >= 110 && m.x <= 180 && m.y >= (70 + i * 60) && m.y <= (100 + i * 60))
				{
					if (count[1][i] > 0)
					{
						sum -= chaofan[i].price;
						count[1][i]--;
						char bor[10];
						sprintf_s(bor, "%d", count[1][i]);
						outtextxy(675, 40 + keepflag[1][i] * 20, bor);
					}
					char summ[100];
					sprintf_s(summ, "%f", sum);
					outtextxy(445, 600, summ);
				}
			}
			for (int i = 0; i < line2; i++)
			{
				if (m.x >= 210 && m.x <= 280 && m.y >= (70 + i * 60) && m.y <= (100 + i * 60))
				{
					if (count[2][i] > 0)
					{
						sum -= mian[i].price;
						count[2][i]--;
						char bor[10];
						sprintf_s(bor, "%d", count[2][i]);
						outtextxy(675, 40 + keepflag[2][i] * 20, bor);
					}
					char summ[100];
					sprintf_s(summ, "%f", sum);
					outtextxy(445, 600, summ);
				}
			}
		}
	}
	_getch();
	closegraph;
}

int superRegister()
{
	initgraph(1000, 700);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(NULL, "2.png");
	setcolor(RED);

	rectangle(245, 250, 330, 270);
	outtextxy(248, 251, "添加一个菜");
	rectangle(245, 300, 330, 320);
	outtextxy(248, 301, "删除一个菜");
	rectangle(245, 350, 330, 370);
	outtextxy(248, 351, " 修改价格");
	rectangle(710, 250, 780, 270);
	outtextxy(713, 251, "最新订单");
	hWnd = GetHWnd();
	MOUSEMSG m;
	while (1)
	{
		m = GetMouseMsg();
		if (m.uMsg == WM_LBUTTONDOWN)
		{
			if (m.x >= 245 && m.x <= 330 && m.y >= 250 && m.y <= 270)
			{
				int flag = -1;
				char newkind[10];
				while (flag == -1)
				{
					InputBox(newkind, 10, "请输入新菜的种类（0：炒菜，1：炒饭，2：面类）");
					int r;
					sscanf_s(newkind, "%d", &r);

					if (r == 0)
					{
						flag = 0;
					}
					else if (r == 1)
					{
						flag = 1;
					}
					else if (r == 2)
					{
						flag = 2;
					}
					else
					{
						MessageBox(hWnd, "请输入正确的数据", "错误", MB_OK);
						flag = -1;
					}

				}

				if (flag == 0)
				{
					int target;
					char newname[10];
					do
					{
						target = 0;
						InputBox(newname, 10, "请输入新菜的名字");
						char c;
						int line0 = 0;//记录每种菜的行数（个数）
						ifstream ofile0;
						ofile0.open("chaocai.txt");//ofile用来将文档中的菜写入结构体数组
						fstream get1("chaocai.txt", ios::in);
						while (get1.get(c))
						{
							if (c == '\n')
								line0++;
						}
						if (ofile0)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < line0; i++)
							{
								ofile0 >> chaocai[i].name >> chaocai[i].price;
							}
						}
						ofile0.close();

						for (int i = 0; i < line0; i++)
						{
							if (chaocai[i].name == (string)newname)
							{
								target = 1;
								MessageBox(hWnd, "已有这道菜", "错误", MB_OK);
								break;
							}
						}
					} while (target == 1);
					char newprice[10];
					InputBox(newprice, 10, "请输入新菜的价格");
					ofstream write0;
					ifstream read0;
					write0.open("chaocai.txt", ios::app);				//用ios::app不会覆盖文件内容
					write0 << newname << ' ' << newprice << endl;
					write0.close();
					read0.close();
					MessageBox(hWnd, "添加成功", "添加成功", MB_OK);
				}

				if (flag == 1)
				{
					int target;
					char newname[10];
					do
					{
						target = 0;
						InputBox(newname, 10, "请输入新菜的名字");
						char c;
						int line1 = 0;//记录每种菜的行数（个数）
						ifstream ofile1;
						ofile1.open("chaofan.txt");//ofile用来将文档中的菜写入结构体数组
						fstream get2("chaofan.txt", ios::in);
						while (get2.get(c))
						{
							if (c == '\n')
								line1++;
						}
						if (ofile1)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < line1; i++)
							{
								ofile1 >> chaofan[i].name >> chaofan[i].price;
							}
						}
						ofile1.close();

						for (int i = 0; i < line1; i++)
						{
							if (chaofan[i].name == (string)newname)
							{
								target = 1;
								MessageBox(hWnd, "已有这道菜", "错误", MB_OK);
								break;
							}
						}
					} while (target == 1);
					char newprice[10];
					InputBox(newprice, 10, "请输入新菜的价格");
					ofstream write1;
					ifstream read1;
					write1.open("chaofan.txt", ios::app);				//用ios::app不会覆盖文件内容
					write1 << newname << ' ' << newprice << endl;
					write1.close();
					read1.close();
					MessageBox(hWnd, "添加成功", "添加成功", MB_OK);
				}

				if (flag == 2)
				{
					int target;
					char newname[10];
					do
					{
						target = 0;
						InputBox(newname, 10, "请输入新菜的名字");
						char c;
						int line2 = 0;//记录每种菜的行数（个数）
						ifstream ofile2;
						ofile2.open("mian.txt");//ofile用来将文档中的菜写入结构体数组
						fstream get3("mian.txt", ios::in);
						while (get3.get(c))
						{
							if (c == '\n')
								line2++;
						}
						if (ofile2)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < line2; i++)
							{
								ofile2 >> mian[i].name >> mian[i].price;
							}
						}
						ofile2.close();

						for (int i = 0; i < line2; i++)
						{
							if (mian[i].name == (string)newname)
							{
								target = 1;
								MessageBox(hWnd, "已有这道菜", "错误", MB_OK);
								break;
							}
						}
					} while (target == 1);
					char newprice[10];
					InputBox(newprice, 10, "请输入新菜的价格");
					ofstream write2;
					ifstream read2;
					write2.open("mian.txt", ios::app);				//用ios::app不会覆盖文件内容
					write2 << newname << ' ' << newprice << endl;
					write2.close();
					read2.close();
					MessageBox(hWnd, "添加成功", "添加成功", MB_OK);
				}
			}

			if (m.x >= 245 && m.x <= 330 && m.y >= 300 && m.y <= 320)
			{
				int flag = -1;
				char oldkind[10];
				while (flag == -1)
				{
					InputBox(oldkind, 10, "请输入删除菜的种类（0：炒菜，1：炒饭，2：面类）");
					int r;
					sscanf_s(oldkind, "%d", &r);

					if (r == 0)
					{
						flag = 0;
					}
					else if (r == 1)
					{
						flag = 1;
					}
					else if (r == 2)
					{
						flag = 2;
					}
					else
					{
						MessageBox(hWnd, "请输入正确的数据", "错误", MB_OK);
						flag = -1;
					}

				}
				char oldname[10];
				InputBox(oldname, 10, "请输入删除菜的名字");

				if (flag == 0)
				{
					char c;
					int line0 = 0;//记录每种菜的行数（个数）
					ifstream ofile0;
					ofile0.open("chaocai.txt");//ofile用来将文档中的菜写入结构体数组
					fstream get1("chaocai.txt", ios::in);
					while (get1.get(c))
					{
						if (c == '\n')
							line0++;
					}
					if (ofile0)  //条件成立，则说明文件打开成功
					{
						for (int i = 0; i < line0; i++)
						{
							ofile0 >> chaocai[i].name >> chaocai[i].price;
						}
					}
					ofile0.close();
					int target = -1;
					for (int i = 0; i < line0; i++)
					{
						if (chaocai[i].name == (string)oldname)
						{
							target = i;
						}
					}
					if (target == -1)
						MessageBox(hWnd, "没有这道菜", "错误", MB_OK);
					else
					{
						ofstream file0;//file用来存储快排后的菜
						file0.open("chaocai.txt");
						fstream get11("chaocai.txt", ios::trunc);
						if (file0)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < target; i++)
								file0 << chaocai[i].name << ' ' << chaocai[i].price << endl;
							for (int i = target + 1; i < line0; i++)
								file0 << chaocai[i].name << ' ' << chaocai[i].price << endl;
						}
						file0.close();
						MessageBox(hWnd, "删除成功", "删除成功", MB_OK);
					}
				}
				if (flag == 1)
				{
					char c;
					int line1 = 0;//记录每种菜的行数（个数）
					ifstream ofile1;
					ofile1.open("chaofan.txt");//ofile用来将文档中的菜写入结构体数组
					fstream get1("chaofan.txt", ios::in);
					while (get1.get(c))
					{
						if (c == '\n')
							line1++;
					}
					if (ofile1)  //条件成立，则说明文件打开成功
					{
						for (int i = 0; i < line1; i++)
						{
							ofile1 >> chaofan[i].name >> chaofan[i].price;
						}
					}
					ofile1.close();
					int target = -1;
					for (int i = 0; i < line1; i++)
					{
						if (chaofan[i].name == (string)oldname)
						{
							target = i;
						}
					}
					if (target == -1)
						MessageBox(hWnd, "没有这道菜", "错误", MB_OK);
					else
					{
						ofstream file1;//file用来存储快排后的菜
						file1.open("chaofan.txt");
						fstream get22("chaofan.txt", ios::trunc);
						if (file1)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < target; i++)
								file1 << chaofan[i].name << ' ' << chaofan[i].price << endl;
							for (int i = target + 1; i < line1; i++)
								file1 << chaofan[i].name << ' ' << chaofan[i].price << endl;
						}
						file1.close();
						MessageBox(hWnd, "删除成功", "删除成功", MB_OK);
					}
				}
				if (flag == 2)
				{
					char c;
					int line2 = 0;//记录每种菜的行数（个数）
					ifstream ofile2;
					ofile2.open("mian.txt");//ofile用来将文档中的菜写入结构体数组
					fstream get3("mian.txt", ios::in);
					while (get3.get(c))
					{
						if (c == '\n')
							line2++;
					}
					if (ofile2)  //条件成立，则说明文件打开成功
					{
						for (int i = 0; i < line2; i++)
						{
							ofile2 >> mian[i].name >> mian[i].price;
						}
					}
					ofile2.close();
					int target = -1;
					for (int i = 0; i < line2; i++)
					{
						if (mian[i].name == (string)oldname)
						{
							target = i;
						}
					}
					if (target == -1)
						MessageBox(hWnd, "没有这道菜", "错误", MB_OK);
					else
					{
						ofstream file2;//file用来存储快排后的菜
						file2.open("mian.txt");
						fstream get11("mian.txt", ios::trunc);
						if (file2)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < target; i++)
								file2 << mian[i].name << ' ' << mian[i].price << endl;
							for (int i = target + 1; i < line2; i++)
								file2 << mian[i].name << ' ' << mian[i].price << endl;
						}
						file2.close();
						MessageBox(hWnd, "删除成功", "删除成功", MB_OK);
					}
				}
			}

			if (m.x >= 245 && m.x <= 330 && m.y >= 350 && m.y <= 370)
			{
				int flag = -1;
				char changekind[10];
				while (flag == -1)
				{
					InputBox(changekind, 10, "请输入要修改的菜的种类（0：炒菜，1：炒饭，2：面类）");
					int r;
					sscanf_s(changekind, "%d", &r);

					if (r == 0)
					{
						flag = 0;
					}
					else if (r == 1)
					{
						flag = 1;
					}
					else if (r == 2)
					{
						flag = 2;
					}
					else
					{
						MessageBox(hWnd, "请输入正确的数据", "错误", MB_OK);
						flag = -1;
					}
				}
				if (flag == 0)
				{
					int target;
					char changename[10];
					int line0;//记录每种菜的行数（个数）
					do
					{
						line0 = 0;
						target = -1;
						InputBox(changename, 10, "请输入想修改的菜的名字");
						char c;
						ifstream ofile0;
						ofile0.open("chaocai.txt");//ofile用来将文档中的菜写入结构体数组
						fstream get1("chaocai.txt", ios::in);
						while (get1.get(c))
						{
							if (c == '\n')
								line0++;
						}
						if (ofile0)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < line0; i++)
							{
								ofile0 >> chaocai[i].name >> chaocai[i].price;
							}
						}
						ofile0.close();

						for (int i = 0; i < line0; i++)
						{
							if (chaocai[i].name == (string)changename)
							{
								target = i;
								break;
							}
						}
						if (target == -1)
							MessageBox(hWnd, "没有这道菜", "错误", MB_OK);
					} while (target == -1);

					char newprice[10];
					float pp;
					InputBox(newprice, 10, "请输入想修改的菜的价格");
					sscanf_s(newprice, "%f", &pp);
					chaocai[target].price = pp;
					ofstream file0;//file用来存储快排后的菜
					file0.open("chaocai.txt");
					fstream get11("chaocai.txt", ios::trunc);
					if (file0)  //条件成立，则说明文件打开成功
					{
						for (int i = 0; i < line0; i++)
						{
							file0 << chaocai[i].name << ' ' << chaocai[i].price << endl;
						}
					}
					file0.close();
					MessageBox(hWnd, "修改成功", "修改成功", MB_OK);
				}
				if (flag == 1)
				{
					int target;
					char changename[10];
					int line1;//记录每种菜的行数（个数）
					do
					{
						line1 = 0;
						target = -1;
						InputBox(changename, 10, "请输入想修改的菜的名字");
						char c;
						ifstream ofile1;
						ofile1.open("chaofan.txt");//ofile用来将文档中的菜写入结构体数组
						fstream get2("chaofan.txt", ios::in);
						while (get2.get(c))
						{
							if (c == '\n')
								line1++;
						}
						if (ofile1)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < line1; i++)
							{
								ofile1 >> chaofan[i].name >> chaofan[i].price;
							}
						}
						ofile1.close();

						for (int i = 0; i < line1; i++)
						{
							if (chaofan[i].name == (string)changename)
							{
								target = i;
								break;
							}
						}
						if (target == -1)
							MessageBox(hWnd, "没有这道菜", "错误", MB_OK);
					} while (target == -1);

					char newprice[10];
					float pp;
					InputBox(newprice, 10, "请输入想修改的菜的价格");
					sscanf_s(newprice, "%f", &pp);
					chaofan[target].price = pp;
					ofstream file1;//file用来存储快排后的菜
					file1.open("chaofan.txt");
					fstream get22("chaofan.txt", ios::trunc);
					if (file1)  //条件成立，则说明文件打开成功
					{
						for (int i = 0; i < line1; i++)
						{
							file1 << chaofan[i].name << ' ' << chaofan[i].price << endl;
						}
					}
					file1.close();
					MessageBox(hWnd, "修改成功", "修改成功", MB_OK);
				}
				if (flag == 2)
				{
					int target;
					char changename[10];
					int line2;//记录每种菜的行数（个数）
					do
					{
						line2 = 0;
						target = -1;
						InputBox(changename, 10, "请输入想修改的菜的名字");
						char c;
						ifstream ofile2;
						ofile2.open("mian.txt");//ofile用来将文档中的菜写入结构体数组
						fstream get3("mian.txt", ios::in);
						while (get3.get(c))
						{
							if (c == '\n')
								line2++;
						}
						if (ofile2)  //条件成立，则说明文件打开成功
						{
							for (int i = 0; i < line2; i++)
							{
								ofile2 >> mian[i].name >> mian[i].price;
							}
						}
						ofile2.close();

						for (int i = 0; i < line2; i++)
						{
							if (mian[i].name == (string)changename)
							{
								target = i;
								break;
							}
						}
						if (target == -1)
							MessageBox(hWnd, "没有这道菜", "错误", MB_OK);
					} while (target == -1);

					char newprice[10];
					float pp;
					InputBox(newprice, 10, "请输入想修改的菜的价格");
					sscanf_s(newprice, "%f", &pp);
					mian[target].price = pp;
					ofstream file2;//file用来存储快排后的菜
					file2.open("mian.txt");
					fstream get33("mian.txt", ios::trunc);
					if (file2)  //条件成立，则说明文件打开成功
					{
						for (int i = 0; i < line2; i++)
						{
							file2 << mian[i].name << ' ' << mian[i].price << endl;
						}
					}
					file2.close();
					MessageBox(hWnd, "修改成功", "修改成功", MB_OK);
				}
			}

			if (m.x >= 710 && m.x <= 780 && m.y >= 250 && m.y <= 270)
			{
				return 1;
			}
		}
	}
	_getch();
	closegraph;
}

void thankyou(float sum)
{
	initgraph(469, 570);
	setbkcolor(WHITE);
	cleardevice();
	loadimage(NULL, "6.jpg");
	settextcolor(BLACK);
	outtextxy(20, 20, "您本次共消费                              元");
	char summ[100];
	sprintf_s(summ, "%f", sum);
	outtextxy(130, 20, summ);
	_getch();
	closegraph;
}

int main()
{
	quickmain();
	int begin1 = begin();
	if (begin1 == 0)
	{
		int newacc1 = newacc();
		while (1)
		{
			if (newacc1 == 0)
				return 0;
			if (newacc1 == 1)
			{
				float takeorder1 = takeorder();
				while (1)
				{
					if (takeorder1 == -1)
					{
						takeorder1 = takeorder();
					}
					else
						thankyou(takeorder1);
				}
			}
			if (newacc1 == 2)
				newacc1 = newacc();
		}
	}
	if (begin1 == 1)
	{
		int register1 = Register();
		while (1)
		{
			if (register1 == 2)
				register1 = Register();
			if (register1 == 0)
			{
				float takeorder1 = takeorder();
				while (1)
				{
					if (takeorder1 == -1)
					{
						takeorder1 = takeorder();
					}
					else if (takeorder1 == -2)
					{
						int showrecentorder1 = showrecentorder();
						if (showrecentorder1 == 1)
							takeorder1 = takeorder();
					}
					else
						thankyou(takeorder1);
				}
			}
		}
	}
	if (begin1 == 2)
	{
		int superregister1 = superRegister();
		while (1)
		{
			if (superregister1 == 1)
			{
				int showrecentorder1 = showrecentorder();
				if (showrecentorder1 == 1)
					int superregister1 = superRegister();
			}
		}
	}
	return 0;
}