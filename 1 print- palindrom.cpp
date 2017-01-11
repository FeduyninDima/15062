#include<iostream>
using namespace std;


int N_ones(int n)
{
n/=2;
int x = 1;
for(int i=1; i<n; i++)
	{	
	x *= 10;
	x++;
	}
return x;
}

void reverse_print(int k)
{
while(k>0)
	{
	cout<<k % 10;
	k/=10;
	}
}

int sum_of_digs(int k)
{
int sum = 0;
while(k > 0)
	{
	sum += k % 10;
	k /= 10;
	}
return sum;
}

void print_palindrom(int n)
{
if (n % 2 == 0)
{
	

	int x = 1;
	for(int i=1; i<n/2; i++)
	{	
	x *= 10;
	x++;
	}
	
	int r = x;

	for(int i = r; i <= r * 9; i++)
		{
		if (sum_of_digs(i) % 9 == 0)
			{
			cout<<i; 
			reverse_print(i); 
			cout<<endl;
			}
		} 
} else
if (n % 2 != 0)
	{
	n--;
	int x = 1;
	for(int i=1; i<n/2; i++)
	{	
	x *= 10;
	x++;
	}
	
	int r = x;
	for(int i = r; i <= r * 9; i++)
		{
		cout<<i;
		cout<<9-(sum_of_digs(i)*2 % 9);
		reverse_print(i); 
		cout<<endl;
		} 
	}
return ;
}

int main()
{
int n;
cin>>n;
print_palindrom(n);
return 0;
}
