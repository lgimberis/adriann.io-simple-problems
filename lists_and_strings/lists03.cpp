#include <vector>
#include <iostream>
#include <algorithm>
//Ex3 Check whether an element occurs in a list
template<typename T, template <typename, typename=std::allocator<T>> typename C>
bool is_present(const C<T>& c, T t){
  return (std::find(c.begin(), c.end(), t) != c.end());
}

int main(){
	std::vector<int> v = {4,3,0,17};
	std::cout<<"V: ";
	for(auto x:v)
		std::cout<<x<<" ";
	std::cout<<"\n4 is present: "<<is_present(v,4);
	std::cout<<"\n2 is present: "<<is_present(v,2);
	std::cout<<"\n";
	return 0;
}
