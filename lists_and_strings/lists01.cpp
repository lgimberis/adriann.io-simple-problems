#include <list>
#include <vector>
#include <iostream>

//Ex1 Return largest element in a list
template<typename T, template <typename, typename=std::allocator<T>> typename C>
T largest_element(const C<T> c){
  bool init=false;
  T max;
  for(const T x : c) {
    if(!init || x>max) {
      max=x;
      init=true;
    }
  }
  return max;
}

int main(){
	std::list<int> l = {1, 6, 8, 11};
	std::vector<int> v = {101, 17, -8, 993};
	std::cout<<"Largest element of l: "<<largest_element(l)<<" expect 11\n";
	std::cout<<"Largest element of v: "<<largest_element(v)<<" expect 993\n";
	return 0;
}
