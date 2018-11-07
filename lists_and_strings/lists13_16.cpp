#include "convenient.h"
#include "digitlist.h"

int main(){
	//Ex 14: Convert a number to a list of digits
	int a_number=19390131;
	DigitList ex14(a_number);
	std::cout<<"Here is a number:\n";
	std::cout<<a_number;
	std::cout<<"\nHere it is as a digit list:\n";
	std::cout<<ex14.spaced(true);

	//Ex15: Add, subtract, and multiply two lists of digits
	int another_number=28410023;
	DigitList ex15(another_number);
	std::cout<<"\n\nHere is another number:\n";
	std::cout<<another_number;
	std::cout<<"\nHere it is in digit list form after "<<
		"operations with the first number.\n";
	std::cout<<"+: "<<(ex14+ex15).spaced(true);
	std::cout<<"\n-: "<<(ex14-ex15).spaced(true);
	std::cout<<"\n*: "<<(ex14*ex15);

	//Ex16: Convert a number to another base
	std::cout<<"\n\nHere is another number in base 8:\n";
	std::cout<<another_number.convert(8);
	std::cout<<"\nHere it is in base 16:\n";
	std::cout<<another_number.convert(16);

	//Ex13: Print the first hundred fibonacci numbers
	std::cout<<"\n\nHere are the first hundred "<<
		"fibonacci numbers:\n";
	const int NUMBER=100;
	DigitList first(1);
	DigitList second(1);
	std::cout<<"1\n1\n"; // :)
	bool doFirst=true;
  for(int i=2; i<NUMBER; ++i){
		if(doFirst){
			first=first+second;
			std::cout<<first<<"\n";
		}
		else{
			second=first+second;
			std::cout<<second<<"\n";
		} doFirst=!doFirst;
	}
	std::cout<<"\n";
	return 0;
}
	
