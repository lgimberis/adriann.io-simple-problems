#include <iostream>
#include <iomanip>

const int MAX=12;
const int MAXWIDTH=3;

void printHeader(){
  std::cout<<std::setw(MAXWIDTH)<<"X";
  std::cout<<"||";
  for(int i=1; i<=MAX; ++i){
    std::cout<<std::right<<std::setw(MAXWIDTH)<<i;
    std::cout<<"|";
  }
  std::cout<<'\n';
  std::cout<<std::setfill('=')<<std::setw(2+(MAX+1)*(MAXWIDTH+1));
  std::cout<<'\n';
  std::cout<<std::setfill(' ');
}

void printRow(int rowNum){
  std::cout << std::right << std::setw(MAXWIDTH) << rowNum;
  std::cout << "||";
  for(int i=1; i<=MAX; ++i){
    std::cout<<std::right<<std::setw(MAXWIDTH)<<i*rowNum;
    std::cout<<"|";
  }
  std::cout<<'\n';
}

int main(){
  const int MAX = 12;
  const int MAXWIDTH = 3;
  printHeader();
  for(int i=1; i<=MAX; ++i){
    printRow(i);
  }
  return 0;
}
