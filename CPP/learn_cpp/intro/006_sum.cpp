#include<iostream>

int main()
{
	int n,sum=0;
	std::cout << "enter numer to find sum of n numbers\n";
	std::cin >> n;


	for(int i=1;i<=n;i++)
	{
	
	
		sum += i;
	}
	std::cout << "sum of " << n << "==" << sum <<std::endl;

return 0;
}
