#include<iostream>
#include<string>
using namespace std;



int main(){
   
	string str = "find the word in this sentence  ,  bharath";

	size_t pos = str.find("word");

	if(pos!= string::npos){
	
	cout << "fouun 'word' at pos :: " << pos << endl;

	}



	cout << "---------------"<< endl;

	cout<< string::npos <<endl;


return 0;
}
