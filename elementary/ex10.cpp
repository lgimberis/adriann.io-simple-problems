#include <iostream>
#include <ctime>

const int QUANTITY=20;
const int LEAP_YEAR_INTERVAL=4;

int main(){
  std::time_t now = time(0);
  tm* ltm = std::localtime(&now);
  int year = 1900 + ltm->tm_year;
  int firstLeapYear = year + LEAP_YEAR_INTERVAL - year%LEAP_YEAR_INTERVAL;
  std::cout<<"Here are the next "<<QUANTITY<<" leap years.\n";
  for(int i=0; i<QUANTITY; ++i)
    std::cout<<firstLeapYear+i*LEAP_YEAR_INTERVAL<<'\n';
  return 0;
}
