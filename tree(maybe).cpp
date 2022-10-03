#include<bits/stdc++.h>
using namespace std;
int n,m,tree[2000010],tree1[2000010];
int lowbit(int k)
{
	return k & -k;
}
void add(int x,int k)
{
    while(x<=n)
    {
        tree[x]+=k;
        x+=lowbit(x);
    }
}
int sum(int x)
{
    int ans=0;
    while(x!=0)
    {
        ans+=tree[x];
        x-=lowbit(x);
    }
    return ans;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a;
        cin>>a;
        add(i,a);
        tree1[i]=a;
    }
    
    for(int i=1;i<=n;i++)
    {
    	for(int j=i;j<=n;j++)
    	{
    		int mmax=0,summ=0;
    		for(int z=i;z<=j;z++)
    		{
    			if(tree1[z]>mmax)
    			{
    				mmax=tree1[z];
				}
			}
    		for(int z=i;z<=j;z++)
    		{
    			if(tree1[z]==mmax)
    			{
    				summ++;
				}
			}
			//cout<<summ*(sum(j)-sum(i-1))<<" "<<summ<<" "<<i<<" "<<j<<" "<<mmax<<endl; 
			m+=summ*(sum(j)-sum(i-1));
			
		}
	}
	cout<<m%998244353;
}

