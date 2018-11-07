#include<vector>
#include<algorithm>

const int DEFAULT_BASE=10;

//All DigitLists hold their digits in reversed order
//Contents are only corrected when they are removed from
//the DigitList to be printed.
//In operations between DigitList they remain reversed.
//Hence bool flag in get being forced to true for public access.

//Used
//printing of DigitList
//Conversion of DigitList to another base and then printing

class DigitList{

	//Define a class for each digit (rather than int),
	//to handle overflow implicitly
  private:
	class Digit{
		int value;
		int base;
		bool positive;
	public:
	  Digit(int v, int b):value{v},base{b} {}
		int add(int);
		int multiply(int);
		int get(){return this->value;}
		int base(){return this->base;}
	};
private:
	std::vector<Digit> dl;
	int base;
	//std::vector<int> get(int,bool);
	bool printSpacing=false;
public:
	DigitList(int);
  //DigitList(std::vector<int> v,int b):dl{v},base{b} {}
	
	//const std::vector<int>& get(int,bool);
	//	inline std::vector<int> get(int){return this->get(int,true);}
	//inline std::vector<int> get(){return this->get(this->base,true);}
	//int getBase(){return this->base;}
	DigitList operator+(DigitList o);
	//DigitList operator-(DigitList o); //TODO
	DigitList operator*(DigitList o);
	void spaced(bool b){this->printSpacing=b;}
	std::ostream& operator<<(std::ostream&);
};


