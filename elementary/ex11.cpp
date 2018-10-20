#include <iostream>
#include <iomanip>
#include <ctime>

const int UPPERLIMIT=1000000;
const double DENOM_STEP=4.0;
const double EXTRA_TERM=2.0;

int main(){
  std::cout<<"Here is the value of the sum of 4*(-1)^(x+1) / (2x-1)\n"<<
    "from x=1 to x="<<UPPERLIMIT<<":\n";
  double sum=0.0;
  double denom=1.0;

  std::clock_t start = std::clock();
  for(int twox=1; twox<UPPERLIMIT/2; ++twox){
    sum += 1/(denom*(denom+EXTRA_TERM));
    denom += DENOM_STEP;
  }
  std::clock_t end = std::clock();
  sum*=8;
  std::cout<<std::setprecision(10)<<sum<<'\n';
  std::cout<<"Took "<<double(end-start)/CLOCKS_PER_SEC<<" (CPU Time)\n";
  return 0;
}
