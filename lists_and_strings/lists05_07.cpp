#include <list>
#include <iostream>

//Ex5: No idea what a running total is, but here is the sum
template <typename T>
T sum_all(const std::list<T> l){
  bool init=false;
  T sum;
  for(T t: l){
    sum = (init ? sum+t : t);
    init=true;
  }
  return sum;
}

//Ex7 Compute sum with a for-loop, while-loop, and recursion
template<typename T>
T sum_for(std::list<T> l){
  bool init=false;
  T sum;
  for(T t: l) {
    if(!init){
      init=true;
      sum=t;
    } else {
      sum+=t;
    }
  }
  return sum;
}
template<typename T>
T sum_while(std::list<T>l){
  auto pos=l.begin();
  T sum = *pos;
  while(++pos!=l.end())
    sum+=*pos;
  return sum;
}
template<typename T, template<typename,typename=std::allocator<T>> typename C>
inline T recursive_step(C<T> c, typename C<T>::iterator s, typename C<T>::iterator e){
	T temp=*s;
	++s;
	return (s==e?temp:temp+recursive_step(c,s,e));
}
template<typename T, template<typename,typename=std::allocator<T>> typename C>
T sum_recursion(C<T> c){
  return recursive_step(c,c.begin(),c.end());
}

int main(){
    std::list<int> test = {1,7,8,12,13,6,4};
		for(auto x:test)
			std::cout<<x<<" ";
    //5
    std::cout<<"\nSum of elements: "<<sum_all(test);
    //7
    std::cout<<"\n\nHere are three different sums: \n";
    std::cout<<"For:   "<<sum_for(test)<<"\nWhile: "<<sum_while(test);
    std::cout<<"\nRecur: "<<sum_recursion(test)<<"\n";
    return 0;
}
