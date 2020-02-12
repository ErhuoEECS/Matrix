#include<iostream>
#include<windows.h>
#include<cmath>
using namespace std;
#define BUFFER(buff,i,j,n)  *((buff)+(j)+(i)*(n))
#define INF 1E-5
int n(0);
//初始化行列式
void det_in(double* p)
{
	cout << "输入行列式各元素" << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> BUFFER(p, i, j, n);
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "\t" << BUFFER(p, i, j, n);
		}
		cout << endl;
	}
	cout << "完成" << endl;
}
//转换为上三角
double det_deal(double* p)
{
	double k(0), temp(0);
	double ans(1);

	for (int i = 1; i < n; i++)   //i控制主对角线
	{
		temp = BUFFER(p, i - 1, i - 1, n);//用主对角线元素消去下三角
		if (fabs(temp) <= INF)
		{
			for (int x = i; x < n; x++)
			{
				if (BUFFER(p, i, i, n) > INF)
				{
					for(int y = 0;y < n;y++)
					BUFFER(p, i - 1, y, n) += BUFFER(p, i, y, n);
				}
			}
		}
		temp = BUFFER(p, i - 1, i - 1, n);
		if (fabs(temp) > INF)
		{
			for (int j = i; j < n; j++)//每一行相应列的元素
			{
				k = BUFFER(p, j, i - 1, n) / temp;//获得倍数
				for (int t = i - 1; t < n; t++)  //t控制运算时每一行的各列
				{
					BUFFER(p, j, t, n) -= k * (BUFFER(p, i - 1, t, n));
				}
			}
		}
		ans *= BUFFER(p, i, i, n);
	}
	return ans*(*p);
}

int main(void)
{
	unsigned flag(1);
	char isprime;
	while (flag)
	{
		cout << "输入阶数" << endl;
		cin >> n;
		double* pdet = (double*)malloc(sizeof(double) * n * n);     //连续内存空间，代替数组储存
		det_in(pdet);
		system("pause");
		cout << "该行列式结果是：" << endl;
		cout << det_deal(pdet) << endl;
		free(pdet);
		system("pause");
		cout << "是否继续？(Y/N)" << endl;
		cin >> isprime;
		switch(isprime)
		{
		case 'Y':
		case 'y':
			break;
		case 'N':
		case 'n':
			flag = 0;
			break;
		default:
			exit(0);
		}
	}
	return 0;
}
