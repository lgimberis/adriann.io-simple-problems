#include <iostream>
#include <cstdlib>

int main(int argc, char** argv){
  int MAX_NUMBER = 1000;
  if(argc>1) MAX_NUMBER=std::strtol(argv[1],nullptr,0);
  if(MAX_NUMBER < 2) return 1;
  
  std::cout<<"Selecting a secret number between 1 and "<<MAX_NUMBER<<'\n';
  int secretNumber = rand()%MAX_NUMBER;
  int guess = -1;
  int previousGuess;
  int tries=0;
  
  while(guess != secretNumber){
    previousGuess=guess;
    std::cout<<"Guess the secret number: ";
    std::cin>>guess;
    if(previousGuess!=guess) ++tries;
    if(guess>secretNumber){
      std::cout<<"Too large\n";
    } else if (guess < secretNumber){
      std::cout<<"Too small\n";
    }
  }
  
  if(tries<2) std::cout<<"First try!\n";
  else std::cout<<"That's right. Took "<<tries<<" guesses\n";
  return 0;
}
  
