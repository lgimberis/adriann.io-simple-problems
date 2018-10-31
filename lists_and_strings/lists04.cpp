#include <vector>
#include <iostream>
//Ex4 Return elements on odd positions
template <typename T, template<typename, typename=std::allocator<T>> typename C>
C<T> all_odd_indices_elements(const C<T>& in){
  C<T> out;
  bool odd=false; //Indices start at 0 in C++, easy change regardless
  for(T t: in){
    if(odd)
      out.push_back(t);
    odd=!odd;  
  }
  return out;
}

int main(){
	std::vector<int> v={1,2,3,4,5};
	std::cout<<"Vector before: ";
	for(auto x:v)
		std::cout<<x<<" ";
	std::vector<int> v2=all_odd_indices_elements(v);
	std::cout<<"\nVector after: ";
	for(auto x:v2)
		std::cout<<x<<" ";
	std::cout<<"\n";
	return 0;
}
