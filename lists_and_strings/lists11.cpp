#include <vector>
#include <list>
#include <iostream>
#include <numeric>
#include "convenient.h"

template <typename T, template<typename, typename=std::allocator<T>> typename C>
C<T> sorted_merge(const C<T>& c1, const C<T>& c2){
	C<T> csorted;
	auto iterator1 = c1.begin();
	auto iterator2 = c2.begin();
	while(iterator1 != c1.end() || iterator2 != c2.end()){
		if(iterator2==c2.end()){
			csorted.push_back(*iterator1);
			++iterator1;
		} else if(iterator1==c1.end()) {
			csorted.push_back(*iterator2);
			++iterator2;
		} else {
			if(*iterator1 < *iterator2){
				csorted.push_back(*iterator1);
				++iterator1;
			} else {
				csorted.push_back(*iterator2);
				++iterator2;
			}
		}
	}
	return csorted;
}


int main(){
	std::vector<int> v1(20);
	std::vector<int> v2(20);
	create_container_random_int(v1, 0, 999);
	create_container_random_int(v2, 0, 999);
	std::sort(v1.begin(), v1.end());
	std::sort(v2.begin(), v2.end());

	std::cout<<"Input vectors: \n";
	print_container(v1);
	std::cout<<"\n";
	print_container(v2);
	std::cout<<"Merged vector: \n";
	print_container(sorted_merge(v1,v2));
	return 0;
}
