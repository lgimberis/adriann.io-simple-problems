#include <vector>
#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>

//Ex 8: Print all prime numbers
//I will instead be printing numbers up to a reasonable limit
//Optimising for large numbers, so this may look a bit goofy

int main(int argc, char** argv){
  int MAX = 1000000;
  if(argc>1){
    MAX = std::strtol(argv[1],nullptr,0);
    if(MAX<3) return 1;
    std::cout<<"Proceeding with N="<<MAX<<std::endl;
  } else {
    std::cout<<"ex8 <max number>\nProceeding with N=1e6\n";
  }
  
  std::vector<int> primes;
  int nextSquareRoot=1;
  int nextSquare=0;
  int nextIndex=0;
  bool isPrime=true;

  std::clock_t start = clock();

  //Fill up the primes vector with every prime
  for(int p=2; p<MAX; ++p){
    //Choose the next index that we need to loop to
    while(p>=nextSquare){
      ++nextSquareRoot;
      nextSquare=nextSquareRoot*nextSquareRoot;
      while(nextIndex<primes.size()){
	if(primes[nextIndex]>nextSquareRoot-1) break;
	++nextIndex;
      }
    } 

    //Perform the check for whether p is prime
    for(int pos=0;pos<nextIndex;++pos){
      if(p%primes[pos]==0){
	isPrime=false;
	break;
      }
    }
    
    //Act based on this
    if(isPrime){
      primes.push_back(p);
    } else {
      isPrime=true;
    }
  }

  //All processing complete
  std::clock_t end = clock();
  std::cout<<"Finished processing after "<<
    (double(end-start)/CLOCKS_PER_SEC)<<" seconds (CPU time)\n";

  //Output to a file 
  std::ofstream out("ex8_out.txt");
  auto normalout=std::cout.rdbuf(out.rdbuf());

  for(int x: primes)
    std::cout<<x<<" ";  

  std::cout<<'\n';
  //Print termination message to console
  std::cout.rdbuf(normalout);
  std::cout<<"Program completed successfully. I think.\n";
  return 0;
}
