//Lists 18: Implement binary search
#include <iostream>
#include <vector>
#include <algorithm>

template<typename T, template<typename, typename=std::allocator<T>> typename C>
typename C<T>::const_iterator binarySearch(const C<T>& container, T value){
	auto width = container.size()/2;
	auto middle = container.begin();

	while(*middle != value){
		if(*middle < value){
			std::advance(middle, (container.end()-middle)/2);
		} else if(*middle > value){
			std::advance(middle, -(middle-container.begin())/2);
		}
	}
	return middle;
}

int main(){
	std::vector<int> testSortedList{1, 11, 23, 108, 253, 10032};
	std::cout<<"23 is at position "
					 <<binarySearch(testSortedList,23)-testSortedList.begin()
					 <<'\n';
	return 0;
}
