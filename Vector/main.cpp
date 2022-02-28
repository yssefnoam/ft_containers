// C++ program to find the type of iterator
#include <iostream>
#include <vector>
#include <list>


template <class T>

// function to return the iterator type
std::string get_iterator_type(T it)
{
	// if the iterator category of (it) matches input
	if (typeid(typename std::iterator_traits<T>::iterator_category)
		== typeid(std::input_iterator_tag))
		return "Input";

	// if the iterator category of (it) matches output
	else if (typeid(typename std::iterator_traits<T>::iterator_category)
			== typeid(std::output_iterator_tag))
		return "Output";

	// if the iterator category of (it) matches forward
	else if (typeid(typename std::iterator_traits<T>::iterator_category)
			== typeid(std::forward_iterator_tag))
		return "Forward";

	// if the iterator category of (it) matches bidirectional
	else if (typeid(typename std::iterator_traits<T>::iterator_category)
			== typeid(std::bidirectional_iterator_tag))
		return "Bidirectional";

	// if the iterator category of (it) matches random_access
	else if (typeid(typename std::iterator_traits<T>::iterator_category)
			== typeid(std::random_access_iterator_tag))
		return "Random_Access";

	// if the iterator category of (it)
	// does not match any of the above
	return "Missing";
}

// Driver code
int main()
{
	// std::vector<int> v;

	// iterator that will be checked
	// std::vector<int>::reverse_iterator it = v.rbegin();
	int *it;
	std::list<int> lst;
	std::vector<int>::iterator it;

	std::cout << get_iterator_type(lst.begin()) << " Iterator\n";

	return 0;
}
