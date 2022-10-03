#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n,m;
	cin>>n>>m;
	long long a[n+2][m+2];
	bool b[n+2][m+2];
	for(long long i=0;i<n+2;i++)
	{
		for(long long j=0;j<m+2;j++)
		{
			a[i][j]=-1;
			b[i][j]=0;
		}
	}
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
			cin>>a[i][j];
	}
	long long t;
	cin>>t;
	for(long long i=1;i<=t;i++)
	{
		long long x1,y1,x2,y2;
		long long temp;
		cin>>x1>>y1>>x2>>y2;
		temp=a[x1][y1];
		a[x1][y1]=a[x2][y2];
		a[x2][y2]=temp;
	}
	long long sum=0;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(a[i][j]>a[i-1][j]&&a[i][j]>a[i][j-1]&&a[i][j]>a[i][j+1]&&a[i][j]>a[i+1][j])	
			{
				sum++; 
				b[i][j]=1;
			}
		}
	}
	cout<<sum<<endl;
	for(long long i=1;i<=n;i++)
	{
		for(long long j=1;j<=m;j++)
		{
			if(b[i][j]==1)
			{
				cout<<i<<" "<<j<<" "<<endl;
			}
		}
	}	
	return 0;
}
