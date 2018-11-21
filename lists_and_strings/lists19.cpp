#include<string>
#include<vector>
#include<iostream>
#include<iomanip>
#include<sstream>

void print_box(std::vector<std::string> contents){
	unsigned int longest = 0;
	for(auto s:contents)
		longest = (longest > s.size() ? longest : s.size());
	std::cout<<std::string(longest+4,'*')<<'\n';
	for(auto s:contents)
		std::cout<<"* "<<std::left<<std::setw(longest)<<s<<" *\n";
	std::cout<<std::string(longest+4,'*')<<"\n\n";
}

std::vector<std::string> message_to_vector(std::string message){
	std::vector<std::string> vector;
	std::istringstream words{message};
	std::string word;
	while(std::getline(words, word, ' '))
		vector.push_back(word);
	return vector;
}
	
int main(){
	print_box(message_to_vector("Hello World In A Frame"));
	print_box(message_to_vector(""));
	print_box(message_to_vector("\n\n\n"));
	
	return 0;
}
