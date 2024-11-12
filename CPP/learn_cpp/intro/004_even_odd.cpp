#include<iostream>

int main()
{

	int num;
	std::cout << "enter num \n";
	std::cin >> num ;
	std::cout <<  "u have enter number :: \n" ;
	std::cout  <<  num;

	if(num % 2 == 0)
	{
	       std::cout << "even number \n";
	}
	else
	{
		std::cout <<  "odd number \n";
	}
		
		
		return 0;
}
