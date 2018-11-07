#include <vector>
#include <cstdlib>
#include <algorithm>
#include "convenient.h"
//Lists 12: Write a function that rotates a list by k elements ACW

template<typename T, template<typename, typename=std::allocator<T>> typename C>
void rotate(C<T>& c, int n){
	if(n==0) return;

	auto start=c.begin();
	auto current=c.begin();
	auto previous=c.begin();
	T temp;
	for(int i=0;i<abs(n);++i){
		current=start;
		previous=start;
		std::advance(previous,i);
		temp = *previous;
		std::advance(current,n+i);
		while(current!=start){
			*previous=*current;
			std::advance(previous,n);
			if(previous>=c.end())std::advance(previous,-c.size());
			std::advance(current,n);
			if(current>=c.end())std::advance(current,-c.size());
		}
		*previous=temp;
	}
	return;
}

int main(){
	std::vector<int> v1(20);
	create_container_random_int(v1,0,999);
	std::cout<<"Vector: \n";
	print_container(v1);
	rotate(v1,3);
	std::cout<<"Vector rotated twice CW:\n";
	print_container(v1);
	rotate(v1,-1);
	std::cout<<"Vector now rotated once ACW:\n";
	print_container(v1);
	return 0;
}
	

