#include<iostream>
#include<string>


using namespace std;

int main(){
  string str = "hello";


  cout << str << endl;
  cout << 1 << " "<< str[1] << endl;
  cout << 5 << " " << str.at(4) << endl;
  cout << str.length() << endl;
  cout << str.size() << endl;

  string str1 = " hello0  ";
  string str2 = " worldd" ;

  string result = str1 + " " + str2;
  cout << result << endl;
  cout << result.length() << endl;
  cout << result.size() << endl;



return 0;
}
