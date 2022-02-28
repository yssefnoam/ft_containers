// C++ program to find the type of iterator
#include <iostream>
#include <vector>

using namespace std;
template <class T>

// function to return the iterator type
string get_iterator_type(T it)
{
	// if the iterator category of (it) matches input
	if (typeid(typename iterator_traits<T>::iterator_category)
		== typeid(input_iterator_tag))
		return "Input";

	// if the iterator category of (it) matches output
	else if (typeid(typename iterator_traits<T>::iterator_category)
			== typeid(output_iterator_tag))
		return "Output";

	// if the iterator category of (it) matches forward
	else if (typeid(typename iterator_traits<T>::iterator_category)
			== typeid(forward_iterator_tag))
		return "Forward";

	// if the iterator category of (it) matches bidirectional
	else if (typeid(typename iterator_traits<T>::iterator_category)
			== typeid(bidirectional_iterator_tag))
		return "Bidirectional";

	// if the iterator category of (it) matches random_access
	else if (typeid(typename iterator_traits<T>::iterator_category)
			== typeid(random_access_iterator_tag))
		return "Random_Access";

	// if the iterator category of (it)
	// does not match any of the above
	return "Missing";
}

// Driver code
int main()
{
	vector<int> v;

	// iterator that will be checked
	vector<int>::reverse_iterator it = v.rbegin();

	cout << get_iterator_type(it) << " Iterator\n";

	return 0;
}
