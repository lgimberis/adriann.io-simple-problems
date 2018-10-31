#include <list>
#include <vector>
#include <iostream>

//Ex10 Combine two lists by alternatingly taking elements
template<typename T, template<typename,typename=std::allocator<T>> typename C>
C<T> list_combine(C<T> a, C<T> b){
  C<T> result;
  auto pos_a = a.begin();
  auto pos_b = b.begin();
  bool more_a=true;
  bool more_b=true;
  while(more_a or more_b){
    if(pos_a!=a.end()){
      result.push_back(*pos_a);
      ++pos_a;
    } else {
      more_a = false;
    }
    if(pos_b!=b.end()){
      result.push_back(*pos_b);
      ++pos_b;
    } else {
      more_b = false;
    }
  }
  return result;
}

template<typename C>
void print_all(const C& c){
	for(auto x:c)
		std::cout<<x<<" ";
	std::cout<<"\n";
}

int main(){
	std::list<int> l1={1,2,3,4,5};
	std::list<int> l2={6,7,8,9,0};

	std::cout<<"Two lists and their combination: \n";
	print_all(l1);
	print_all(l2);
	print_all(list_combine(l1,l2));
	return 0;
}
