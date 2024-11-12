#include<iostream>

void fibonacci(int n)
{
  long long  first=0,second =1;
  std::cout << "fib series :: \n";

  for(int i=1; i<n; i++)
  {
	  std::cout << first  << " " ;
	  long long next = first + second ;
	  first = second;
	  second = next;
  }
  std::cout  << std::endl;
}


int main()
{

   // what is fibonacci
   // starts with 0,1
   // 1,2,3,5,8,13,

	int n;
	std::cout << "enter number of terms \n";
	std::cin >> n;
	
	fibonacci(n);

return 0;
}
