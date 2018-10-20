#include <iostream>

inline int recursiveSum(int max){
  if(max % 3 == 0 || max % 5 == 0){
    return max+recursiveSum(max-1);
  }
  return (max>1 ? recursiveSum(max-1) : 0);
}

int main(){
  std::cout<<"Please enter a number: ";
  int num;
  std::cin>>num; //Much simpler here than getline
  std::cout<<"The sum of numbers 1 to "<<num<<" inclusive using only\n"<<
    "multiples of 3 or 5 is "<<recursiveSum(num)<<'\n';
  return 0;
}
