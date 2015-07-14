//============================================================================
// Name        : cut_rod.cpp
// Author      : Heracles-Fox
// Version     :
// Copyright   : Your copyright notice
// Description : cut_rod problems
//============================================================================
#include <iostream>
using namespace std;
static int steps = 0;
int cut_rod(int *p, int n)
{
	if (n == 0)
		return 0;
	int q = 0;
	for (int i = 1; i <= n; i++)
	{
		int v = p[i]+cut_rod(p, n - i);
		q = q > v ? q : v;
		steps++;
	}
	return q;
}
int memoized_cut_rod_aux(int *p,int n,int *r)
{
	if(r[n]>=0) return r[n];	
	int q=n==0?0:-1;
	for (int i=1;i<=n;i++)
	{
		int v=p[i]+memoized_cut_rod_aux(p,n-i,r);
		q=q>v?q:v;
	}
	r[n]=q;
	return q;
}
int memoized_cut_rod(int *p,int n)
{
	int *r=new int[n+1];
	for(int i=0;i<=n;i++)
	{
		r[i]=-1;
	}
	int value= memoized_cut_rod_aux(p,n,r);
	delete [] r;
	return value;
}

int main()
//int test()
{
	int a[] =
	{ 0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int b=0;
	cout<<"Please input a number:(less than 10)\n";
	cin>>b;
	//int cc = cut_rod(a, b);
	int cc=memoized_cut_rod(a,b);
	cout << "optimal cut:"<<cc << "\n steps:" << steps<<"\n";
	system("pause");
}
