//Lists 18: Implement binary search
#include "convenient.h"

template<typename C, typename V>
typename C::const_iterator binarySearch(const C& c, V v){
	auto left = c.begin();
	auto right = c.end();
	auto width = c.size()/2+c.size()%2; //Round up; Never change by 0
	auto middle = c.begin();
	std::advance(middle, width);

	while(*middle != v){
		if(*middle > v){
			width = std::distance(left, middle);
			right = middle;
			std::advance(middle,-width/2-width%2);
		} else {
			width = std::distance(middle, right);
			left = middle;
			std::advance(middle, width/2+width%2);
		}
	}
	return middle;
}

int main(){
	//Set up a sorted list with a randomly position value to find
	std::vector<int> testSortedList(20);
	create_container_random_int(testSortedList, 1, 99);
	int toFind_value = *testSortedList.begin();
	std::cout<<"Here is an unsorted list; "<<toFind_value<<" will be located:\n";
	print_container(testSortedList);
	std::sort(testSortedList.begin(), testSortedList.end());
	std::cout<<"After sorting:\n";
	print_container(testSortedList);

	//Use the binary search
	std::cout<<toFind_value<<" is at position "<<
		std::distance(testSortedList.cbegin(),binarySearch(testSortedList,
																											toFind_value))<<'\n';
	return 0;
}
