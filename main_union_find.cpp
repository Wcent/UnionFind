// UnionFindSets.cpp : �������̨Ӧ�ó������ڵ㡣

#include <iostream>
#include <stdlib.h>

using namespace std;


// ���鼯 ~ union-find sets
// ~
int find(int *p, int len, int x);

int main()
{
	int g[8][8];
	memset(g, 0, sizeof(int)*8*8);
	/*
	g[1][2] = 1;
	g[1][6] = 1;
	g[2][3] = 1;
	g[3][5] = 1;
	g[3][6] = 1;
//	g[3][7] = 1;
//	g[4][5] = 1;
	g[4][7] = 1;
	*/
	
	g[1][6] = 1;
	g[2][4] = 1;
	g[3][4] = 1;
	g[5][6] = 1;
	g[4][5] = 1;
//	g[5][7] = 2;
	
	// ��ʼ���������
	int root[8];
	for(int i=0; i<8; i++)
		root[i] = i;
		
	for(i=0; i<8; i++)
	{
		for(int j=0; j<8; j++)
		{
			// ���ӵĶ���ϲ�Ϊͬһ���ϣ�������ͬ
			if(g[i][j] == 1)
			{
				int x = find(root, 8, i);
				int y = find(root, 8, j);
				if(x > y)
					root[x] = y;
				else if(x < y)
					root[y] = x;
			}
		}
	}

	for(i=0; i<8; i++)
		cout<<"root["<<i<<"] = "<<root[i]<<endl;
	cout<<endl;
	
	int a = 2;
	int b = 5;
	cout<<a<<" & "<<b<<" are in the same sets?"<<endl;
	if(find(root, 8, a) == find(root, 8, b))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	a = 3;
	b = 4;
	cout<<a<<" & "<<b<<" are in the same sets?"<<endl;
	if(find(root, 8, a) == find(root, 8, b))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	a = 4;
	b = 6;
	cout<<a<<" & "<<b<<" are in the same sets?"<<endl;
	if(find(root, 8, a) == find(root, 8, b))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	a = 5;
	b = 7;
	cout<<a<<" & "<<b<<" are in the same sets?"<<endl;
	if(find(root, 8, a) == find(root, 8, b))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	a = 4;
	b = 7;
	cout<<a<<" & "<<b<<" are in the same sets?"<<endl;
	if(find(root, 8, a) == find(root, 8, b))
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	cout<<endl;
	for(i=0; i<8; i++)
		cout<<"find("<<i<<") = "<<find(root, 8, i)<<endl;
	cout<<endl;
	
	return 0;
}

// ��·��ѹ���Ĳ���
int find(int *p, int len, int x)
{
	if(x < 0 || x >= len)
		return -1;

	// ѹ��
	if(x != p[x])
		p[x] = find(p, len, p[x]);
	return p[x];
}

