#include "convenient.h"

template<typename C>
C selection_sort(C in, bool verbose=false){
	C out;
	typename C::iterator minval_it;
	while(in.size()>0){
	  minval_it = std::min_element(in.begin(), in.end());
		out.push_back(*minval_it);
		in.erase(minval_it);
		if(verbose)
			print_container(in);
	}
	return out;
}


template<typename C>
void insertion_sort(C& in, bool verbose=false){
	in.reserve(in.size()+1);
	auto current = in.begin();
	auto sorted_start = in.rend();
	typename C::reverse_iterator unsorted_end;
	typename C::value_type temp;

	while(current != in.end()){
		unsorted_end= typename C::reverse_iterator{current};
		//Find the first spot for which current value is larger than the rest
		while(*unsorted_end>*current&& unsorted_end!=sorted_start){++unsorted_end;}
	  temp = *current;
		current=in.erase(current);
		in.insert(unsorted_end.base(), temp);
		++current;
		if(verbose)
			print_container(in);
	}
}


template<typename C>
typename C::reverse_iterator quicksort_pivot(C& c, typename C::iterator left, typename C::reverse_iterator right){
	typename C::value_type pivot = *left;
	--left;
	--right;
	while(true){
		++left;
		while(*left<pivot)
			++left;

		++right;
		while(*right>pivot)
			++right;

		if(std::distance(left, right.base())<2)
			return right;

		std::swap(*left, *right);
	}
}

template<typename C>
void quicksort(C& c, typename C::iterator left, typename C::reverse_iterator right){
	if(std::distance(left, right.base()) > 1){
			auto pivot = quicksort_pivot(c, left, right);
			quicksort(c, left, pivot);
			quicksort(c, pivot.base(), right);
	}
}
template<typename C>
void quicksort(C& c){
	quicksort(c, c.begin(), c.rbegin());
}
		

int main(){
	std::vector<int> example(50);
	create_container_random_int(example, 100, 999);
	std::cout<<"Random list:\n";
	print_container(example);
	std::cout<<"\nSelection sort: \n";
	print_container(selection_sort(example));
	
	std::vector<int> exampleCopy{example};
	std::cout<<"\nInsertion sort: \n";
	insertion_sort(exampleCopy);
	print_container(exampleCopy);
	
	exampleCopy=std::vector<int>{example};
	std::cout<<"\nQuick sort: \n";
	quicksort(exampleCopy);
	print_container(exampleCopy);
	return 0;
}

