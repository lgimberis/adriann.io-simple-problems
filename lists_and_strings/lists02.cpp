#include <list>
#include <vector>
#include <iostream>

//Ex2 Reverse a list preferably inplace
template<typename T, template <typename, typename=std::allocator<T>> typename C>
void reverse_inplace(C<T>& c){
  T temp;
  auto front=c.begin();
  auto back=c.rbegin();
  //std::iterator<std::forward_iterator_tag, T> front=l.begin();
  //std::reverse_iterator<T> back=l.begin();
  for(auto i=0;i<c.size()/2;++i){
    temp=*front;
    *front=*back;
    *back=temp;
    ++front;
    ++back;
  }
}

template<typename C>
void print_all(C c){
	for(auto x : c)
		std::cout<<x<<" ";
	std::cout<<"\n";
}

int main(){
	std::list<int> l = {1, 2, 3, 4, 5, 6, 7};
	std::vector<int> v = {1, 2, 3, 4, 5, 6, 7};

	std::cout<<"List before: ";
	print_all(l);
	reverse_inplace(l);
	std::cout<<"List after: ";
	print_all(l);

	std::cout<<"Vector before: ";
	print_all(v);
	reverse_inplace(v);
	std::cout<<"Vector after: ";
	print_all(v);
	return 0;
}
