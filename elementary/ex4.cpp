#include <iostream>

inline int recursiveSum(int max){
  return (max>1 ? max+recursiveSum(max-1) : max);
}

int main(){
  std::cout<<"Please enter a number: ";
  int num;
  std::cin>>num; //Much simpler here than getline
  std::cout<<"The sum of numbers 1 to "<<num<<" is "<<recursiveSum(num)<<'\n';
  return 0;
}
