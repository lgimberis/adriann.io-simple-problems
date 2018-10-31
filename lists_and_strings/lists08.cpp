#include <list>
#include <vector>
#include <iostream>
#include <numeric>

//Ex8 Apply an argument function to all elements of a list
template<typename T>
T squareFunc(T t){
  return t*t;
}
template<typename T, template<typename,typename=std::allocator<T>
															> typename C, T (*onAllFunc)(T)>
void on_all(C<T>& c){
  for(T& t: c)
    t=onAllFunc(t);
}

int main(){
	std::cout<<"Applying a square to every element of test: \n";
	std::list<int> l(20);
	std::iota(l.begin(),l.end(),1);
	for(auto x:l)
		std::cout<<x<<" ";
	std::cout<<"\n";
	
	on_all<int,std::list,squareFunc>(l);
	for(auto x:l)
		std::cout<<x<<" ";
	std::cout<<"\n";
	return 0;
}
