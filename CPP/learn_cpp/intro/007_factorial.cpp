#include<iostream>


int main()
{


	// factorial   n ! = n * n-1 * n-2 *...........* 1;
	
	int num;
	//int  fact;
	long long fact;


	std::cout<< "num \n";
	std::cin >> num ;
	std::cout<< num << "\n";


	fact =1;

	for(int i=1 ; i<=num; i++)
	{
	 fact = fact * i;	
	std::cout<< fact  << "\n" << std:: endl;
	}

	std::cout<< "=====================\nfactorial is :: " << fact  << "\n" << std:: endl;




return 0;
}
