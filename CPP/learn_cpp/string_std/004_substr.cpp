#include<iostream>
#include<string>


using namespace std;

int main(){

  string str1 = "pagadala";
  string str2 = "bharath reddy" ;

  string result = str1 + " " + str2;
  cout << result << endl;
  cout << str1.length() << endl;
  cout << str2.size() << endl;


  cout << str1.substr(2,3) << endl;



return 0;
}
