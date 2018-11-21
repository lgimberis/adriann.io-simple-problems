#include <string>
#include <iostream>
#include <sstream>

//This example isn't perfect; You could add regex for punctuation,
//and considerations of capital letters, or even words that do
//not sound quite right (over->veroay?)
//But I won't.

std::string toPigLatin(std::string in){
	in.push_back(*in.begin());
	in.push_back('a');
	in.push_back('y'); // :) if it looks stupid but works...
	in.erase(in.begin());
	return in;
}

void printMessageAsPigLatin(std::string message){
	std::istringstream words{message};
	std::string word;
	while(std::getline(words, word, ' '))
		std::cout<<toPigLatin(word)<<" ";
	std::cout<<'\n';
}

int main(){
	std::string message="The quick brown fox jumps over the lazy dog";
	printMessageAsPigLatin(message);
	return 0;
}
