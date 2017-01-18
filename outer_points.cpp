#include<iostream>
using namespace std;

void outer_points(int n, int m)
{
int point, counter;
int *left_limit = new int [n];
int *right_limit = new int [n];
for(int i=0; i<n; i++)
cin>>left_limit[i]>>right_limit[i];

for(int i=0; i<m; i++)
	{
	cin>>point;
	counter = 0;
	for(int j=0; j<n; j++)
		if((point>=left_limit[j])&&(point<=right_limit[j])) counter++;
	cout<<n-counter<<' ';
	}
cout<<endl;
return ;
}

int main()
{
int n, m;
cin>>n>>m;
outer_points(n,m);
return 0;
}
