#include<iostream>

long long fibonacci(int n)
{
  if(n<=1)
	  return n;

  return fibonacci(n-1)+fibonacci(n-2);


}


int main()
{
  int n;

  std::cout << "enter the number of terms in fibonacci\n";
  std::cin  >> n;

  for(int i=0; i<n ; i++)
  {
    std::cout << fibonacci(i) << "   ";
    if(i%10 ==0)
    {
	    std::cout  << "\n";
    }
  }

  std::cout << std::endl;




return 0;
}
