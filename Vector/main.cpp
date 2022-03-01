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

	int a[5] = {1,2,3,4,5};
	ft::iterator<int> it(a);
	// std::vector<int> vec(a, a+5);
	// std::vector<int>::iterator it = vec.begin();
	// it++;
	// std::cout << *it << std::endl;
	// std::vector<int>::iterator it2(it);
	// std::cout << *it2 << std::endl;

	// --it;
	// if (it == it2)
	// 	std::cout << "equal" << std::endl;
	
	// std::cout << it.base() << std::endl;
	// std::cout << it2.base() << std::endl;

}