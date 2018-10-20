#include <iostream>
#include <string>
#include <algorithm>

inline int recursiveSum(int num){
  return (num>1 ? num+recursiveSum(num-1) : 1);
}

inline int recursiveProduct(int num){
  return (num>1 ? num*recursiveProduct(num-1) : 1);
}

int main(){
  int num;
  std::cout<<"Please enter a number: ";
  std::cin>>num;
  std::cout<<"Compute the sum of 1-"<<num<<", or the product of 1-"<<
    num<<"?\n";
  std::string choice;
  std::cin>>choice;
  
  if(choice=="sum"){
    int sum = recursiveSum(num);
    std::cout<<"The sum of 1 to "<<num<<" is "<<sum<<'\n';
  } else if(choice=="product"){
    int product = recursiveProduct(num);
    std::cout<<"The product of 1 to "<<num<<" is "<<product<<'\n';
  } else std::cout<<"Enter either 'sum' or 'product'\n";
  return 0;
}
