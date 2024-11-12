#include<iostream>

int main()
{

	int num;
	bool is_prime = true;


	std::cout << "enter the numnber \n";
	std::cin >> num;


	for(int i=2;i<num;i++)
	{
	  if(num % i == 0)
	  {
	  
		  is_prime = false;
		  break;
	  }
	
	}
	if(is_prime)
	{
		std::cout <<  "it is a prim e'\n";
	}
	else
	{
		std::cout << "mope \n";
	}



return 0;
}
