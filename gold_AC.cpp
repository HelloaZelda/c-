#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long n;
	cin>>n;
	long long a[n+1],a5=0,a10=0,a20=0;
	bool b[n+1];
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]==5)
			a5++;
		if(a[i]==10)
			a10++;
		if(a[i]==20)
			a20++;
		if(a[i]!=5)//’“«Æ 
		{
			if(a[i]==20)
			{
				if(a10>=1&&a5>=1)
				{
					b[i]=1;
					a10--;
					a5--;
				}
				else if(a5>=3)
				{
					a5-=3;
					b[i]=1;
				}
			}
			if(a[i]==10)
			{
				if(a5>=1)
				{
					a5--;
					b[i]=1;
				}
			}
		}
		else//≤ª’“ 
		{
			b[i]=1;
		}
	}
	
	for(int i=1;i<=n;i++)
	{
		if(b[i]==0)
		{
			cout<<"No";
			return 0;
		}
	}
	cout<<"Yes";
	return 0;
}
