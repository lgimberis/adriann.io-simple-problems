#include <list>
#include <vector>
#include <iostream>

//Ex9 Concatenate two lists
template<typename T, template<typename,typename=std::allocator<T>> typename C>
C<T> list_concat(const C<T>& a, const C<T>& b){
  C<T> lazy{a};
  for(const T& t:b){
    lazy.push_back(t);
  }
  return lazy;
}

template<typename C>
void print_all(C c){
	for(auto x:c)
		std::cout<<x<<" ";
	std::cout<<"\n";
}

int main(){
	std::list<int> l1={1,2,3};
	std::list<int> l2={4,5,6};
	std::vector<int> v1={7,8,9};
	std::vector<int> v2={1,2,3};

	std::cout<<"Two lists and their concat: \n";
	print_all(l1);
	print_all(l2);
	print_all(list_concat(l1,l2));

	std::cout<<"Two vectors and their concat: \n";
	print_all(v1);
	print_all(v2);
	print_all(list_concat(v1,v2));

	return 0;
}
