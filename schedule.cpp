#include<iostream>
using namespace std;

void schedule(int n)
{
int counter = 1;
int *beginning = new int [n];
int *ending = new int [n];
for(int i=0; i<n; i++)
cin>>beginning[i]>>ending[i];
int end_of_pair = ending[0];
for(int i=0; i<n; i++)
if(beginning[i] >= end_of_pair)
	{
	end_of_pair = ending[i];
	counter++;
	}
cout<<counter;
}

int main()
{
int n;
cin>>n;
schedule(n);
return 0;
}
