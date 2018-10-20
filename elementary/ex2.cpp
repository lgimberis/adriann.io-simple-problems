#include <iostream>
#include <string>

int main(){
  std::string name;
  std::cout<<"Can I have your name? ";
  std::getline(std::cin, name);
  if(name=="Alice"||name=="Bob") std::cout<<"Hello, "<<name<<'\n';
  return 0;
}
