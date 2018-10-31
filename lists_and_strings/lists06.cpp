#include <string>
#include <iostream>

//Ex6 Check whether a string is a palindrome
std::string is_palindrome(std::string s){
  auto length=s.size();
  for(auto p=0; p<length/2; ++p){
    if(s[p]!=s[length-p-1]) return "No";
  }
  return "Yes";
}

int main(){
	std::string not_palindrome="palindrome";
	std::string palindrome="racecar";

	std::cout<<"Is "<<palindrome<<" a palindrome? "<<
		is_palindrome(palindrome)<<"\n";
	std::cout<<"Is "<<not_palindrome<<" a palindrome? "<<
		is_palindrome(not_palindrome)<<"\n";
	return 0;
}
