#include<iostream>
using namespace std;

void incredible_sort(int n, int k)
{
int arr[k+1];
for(int i=0; i<=k; i++)
arr[i]=0;
int x;
for(int i=0; i<n; i++)
	{
	cin>>x;
	arr[x]++;
	}
for(int i=k; i>0; i--)
while (arr[i]>0) 
	{
	cout<<i<<' ';
	arr[i]--;
	}
}

int main()
{
int n, k;
cin>>n>>k;
incredible_sort(n,k);
return 0;
}
