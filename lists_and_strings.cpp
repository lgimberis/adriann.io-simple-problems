//v1 Implemented every exercise, but they are likely pretty bad.
#include <list>
#include <iostream>
#include <algorithm>
#include <string>

//Ex1 Return largest element in a list
template<typename T>
T largest_element(const std::list<T> l){
  bool init=false;
  T max;
  for(const T x : l) {
    if(!init || x>max) {
      max=x;
      init=true;
    }
  }
  return max;
}

//Ex2 Reverse a list preferably inplace
template<typename T>
void reverse_inplace(std::list<T>& l){
  T temp;
  auto front=l.begin();
  auto back=l.rbegin();
  //std::iterator<std::forward_iterator_tag, T> front=l.begin();
  //std::reverse_iterator<T> back=l.begin();
  for(auto i=0;i<l.size()/2;++i){
    temp=*front;
    *front=*back;
    *back=temp;
    ++front;
    ++back;
  }
}

//Ex3 Check whether an element occurs in a list
template<typename T>
bool is_present(const std::list<T> l, T t){
  return (std::find(l.begin(), l.end(), t) != l.end());
}

//Ex4 Return elements on odd positions
template <typename T>
std::list<T> all_odd_indices_elements(const std::list<T> in){
  std::list<T> out;
  bool odd=false; //Indices start at 0 in C++, easy change regardless
  for(T t: in){
    if(odd)
      out.push_back(t);
    odd=!odd;  
  }
  return out;
}

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

//Ex6 Check whether a string is a palindrome
bool is_palindrome(std::string s){
  auto length=s.size();
  for(auto p=0; p<length/2; ++p){
    if(s[p]!=s[length-p-1]) return false;
  }
  return true;
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
/*Issues with this
template<typename T>
T sum_recursion(std::list<T>l, typename std::list<T>::iterator start){
  T temp=*start;
  ++start;
  return (start==l.end()?temp:temp+sum_recursion(l,start));
  }*/

//Ex8 Apply an argument function to all elements of a list
template<typename T>
T squareFunc(T t){
  return t*t;
}
template<typename T, T (*onAllFunc)(T)>
void on_all(std::list<T>& l){
  for(T& t: l)
    t=onAllFunc(t);
}

//Ex9 Concatenate two lists
template<typename T>
std::list<T> list_concat(std::list<T> a, std::list<T> b){
  std::list<T> lazy{a};
  for(T t:b){
    lazy.push_back(t);
  }
  return lazy;
}

//Ex10 Combine two lists by alternatingly taking elements
template<typename T>
std::list<T> list_combine(std::list<T> a, std::list<T> b){
  std::list<T> result;
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

//For convenience of testing
template <typename T>
void print_test(const std::list<T> l){
  std::cout<<"Test list: \n";
  for(const T t:l)
    std::cout<<t<<" ";
  std::cout<<"\n";
}

int main(){
    std::list<int> test = {1,7,8,12,13,6,4};
    std::string not_palindrome="palindrome";
    std::string palindrome="racecar";
    print_test(test);
    //Test Ex1
    std::cout<<"\nEx 1:Largest element: "<<largest_element(test)<<std::endl;
    //Test Ex2
    std::cout<<"\nEx 2:Reversing list...\n";
    reverse_inplace(test);
    print_test(test);
    //3
    std::cout<<"\nIs 7 present? "<<is_present(test,7);
    std::cout<<"\nIs 0 present? "<<is_present(test,0);
    std::cout<<std::endl;
    //4
    std::cout<<"\nPrinting elements on odd positions...\n";
    std::list<int> odd = all_odd_indices_elements(test);
    print_test(odd);
    //5
    std::cout<<"\nSum of elements: "<<sum_all(test);
    //6
    std::cout<<"\n\nIs "<<not_palindrome<<" a palindrome? "<<is_palindrome(not_palindrome);
    std::cout<<"\nIs "<<palindrome<<" a palindrome? "<<is_palindrome(palindrome);
    //7
    std::cout<<"\n\nHere are three different sums: \n";
    std::cout<<"For:   "<<sum_for(test)<<"\nWhile: "<<sum_while(test);
    //std::cout<<"\nRecur: "<<sum_recursion(test,test.begin());
    //8
    std::cout<<"\n\nApplying a square to every element of test: \n";
    std::list<int> squared_test{test};
    on_all<int,squareFunc>(squared_test);
    print_test(squared_test);
    //9
    std::cout<<"\nConcatenating test and squared test\n";
    print_test(list_concat(test,squared_test));
    //10
    std::cout<<"\nCombining test and squared test\n";
    print_test(list_combine(test,squared_test));
    return 0;
}
