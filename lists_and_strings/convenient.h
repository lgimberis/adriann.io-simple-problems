#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>

std::default_random_engine eng(std::clock());

//Works with integer types only
template <typename T, template<typename, typename=std::allocator<T>> typename C>
void create_container_random_int(C<T>& c, T minval, T maxval){
	std::uniform_int_distribution<T> dist(minval,maxval);
	for(auto i=c.begin(); i!=c.end(); ++i)
		*i=dist(eng);
}

template <typename T, template<typename, typename=std::allocator<T>> typename C>
void print_container(const C<T>& c){
	for(auto i:c)
		std::cout<<i<<" ";
	std::cout<<"\n";
	return;
}
