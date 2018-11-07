#include "digitlist.h"


DigitList::DigitList(int in){
	this->base=BASE_DEFAULT;
	int denom=1;
	while(in>denom){
		this->dl.push_back(Digit(in/denom -
		    in/(this->base*denom)*this->base),this->base);
		denom*=this->base;
	}
}
/*
std::vector<int> DigitList::get(int base, bool doReverse=false){
	//It is simpler to implement algorithms where the units
	//column is the first element.

	//For the case when the bases are equal.
	if(base==this->base){
		if(doReverse){
			std::vector<int> temp{this->dl};
			std::reverse(temp.begin(),temp.end());
			return temp;
		} return this->dl;
	}

	//Need to convert base; store final in out
	DigitList out;
	//the value of each base1 digit in turn in base2
	DigitList digit;
	//the value of base1^x in base2, where x=0,1,2,...
	DigitList offset(1,base);
	//the value of base1 in base2
	DigitList scale(this->base, base);
	for(auto it=this->dl.begin();it<this->dl.end();++it){
		//For each digit in the input
		digit(*it,base);
		out=digit*offset+out; //Increment out by the value of that digit
		offset=scale*offset;
	}
	return out.get(doReverse);
	}*/

DigitList DigitList::operator+(DigitList o){
	auto other=o.get(this->base,false);
	auto oit=other.begin();
	auto thisit=this->dl.begin();
	std::vector<Digit>sum;
	Digit temp;
	int carry=0;

	while(thisit!=this->dl.end()||oit!=other.end()){
		sum.push_back(Digit(0,this->base));
		carry = sum.back()->add(carry);
		if(thisit!=this->dl.end()){
			carry += sum.back()->add(thisit->get());
			++thisit;
		}
		if(oit!=other.end()){
			carry += sum.back()->add(oit->get());
			++oit;
		}
	}
	while(carry>0){
		sum.push_back(Digit(0,this->base));
		carry = sum.back()->add(carry);
	}
	return DigitList(sum,this->base);
}

DigitList DigitList::operator*(DigitList o){
	std::vector<int> other=o.get(this->base);
	std::vector<int> out(max(other.size(),this->dl.size())){0};
	auto outit=out.begin();
	int carry=0;
	
	for(auto selfit=this->dl.begin();selfit<this->dl.end();++selfit){
		outit=out.begin();
		for(auto oit=other.begin();oit<other.end();++oit){
			*outit+=(*selfit * *oit + carry)%this->base;
			carry=(*selfit * *oit + carry - *outit)/this->base;
			++outit;
		}
		if(carry>0){
			if(oit==out.end()){
				out.push_back(carry);
			}
			else {
				if(this->base-carry<*oit){
					
	}
	return DigitList(out,this->base);
}


			int DigitList::Digit::add(int i){
	//Assumes same base.
	this->value+=i;
	int carry=0;
	while(this->value>=this->base){
		this->value-=this->base;
		++carry;
	} return carry;
}
