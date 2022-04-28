#include "Vector/vector.hpp"
#include "Stack/stack.hpp"
#include "Map/map.hpp"
#include <deque>
#include <iostream>
#include <sys/time.h>
#include <vector>
#include <map>
#include <stack>

#define NS std

void	print_time(timeval start, timeval end)
{
	long ms_start, ms_end;
	ms_start = (((start.tv_sec * 1000000) + (start.tv_usec)) / 1000);
	ms_end = (((end.tv_sec * 1000000) + (end.tv_usec)) / 1000);
	std::cout << "time is = " << ms_end - ms_start << std::endl;
}

void vector_tests()
{
	{
		std::cout << "vector constructors test" << std::endl;
				// constructors used in the same order as described above:
  		NS::vector<int> first;                                // empty vector of ints
  		NS::vector<int> second (4,100);                       // four ints with value 100
  		NS::vector<int> third (second.begin(),second.end());  // iterating through second
  		NS::vector<int> fourth (third);                       // a copy of third

  		// the iterator constructor can also be used to construct from arrays:
  		int myints[] = {16,2,77,29};
  		NS::vector<int> fi(myints, myints + sizeof(myints) / sizeof(int) );

  		std::cout << "The contents of fiNSh are:";
  		for (NS::vector<int>::iterator it = fi.begin(); it != fi.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
	{
		std::cout << "vector operator= test" << std::endl;
		NS::vector<int> foo (3,0);
  		NS::vector<int> bar (5,0);

  		bar = foo;
  		foo = NS::vector<int>();

  		std::cout << "Size of foo: " << int(foo.size()) << std::endl;
  		std::cout << "Size of bar: " << int(bar.size()) << std::endl;
	}
	{
		std::cout << "vector begin() test" << std::endl;
		NS::vector<int> myvector;
  		for (int i=1; i<=5; i++) myvector.push_back(i);

  		std::cout << "myvector contains:";
  		for (NS::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
	{
		std::cout << "vector end() test" << std::endl;
		NS::vector<int> myvector;
  		for (int i=1; i<=5; i++) myvector.push_back(i);
		
  		std::cout << "myvector contains:";
  		for (NS::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
	{
		std::cout << "vector rbegin() test" << std::endl;
		NS::vector<int> myvector (5);  // 5 default-constructed ints
		
  		int i=0;
		
  		NS::vector<int>::reverse_iterator rit = myvector.rbegin();
  		for (; rit!= myvector.rend(); ++rit)
  		  *rit = ++i;
		
  		std::cout << "myvector contains:";
  		for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
	{
		std::cout << "vector rend() test" << std::endl;
		NS::vector<int> myvector (5);  // 5 default-constructed ints
		
  		NS::vector<int>::reverse_iterator rit = myvector.rbegin();
		
  		int i=0;
  		for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
  		  *rit = ++i;
		
  		std::cout << "myvector contains:";
  		for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
	{
		std::cout << "vector Size() test" << std::endl;
		NS::vector<int> myints;
  		std::cout << "0. size: " << myints.size() << std::endl;

  		for (int i=0; i<10; i++) myints.push_back(i);
  		std::cout << "1. size: " << myints.size() << std::endl;

  		myints.insert (myints.end(),10,100);
  		std::cout << "2. size: " << myints.size() << std::endl;

  		myints.pop_back();
  		std::cout << "3. size: " << myints.size() << std::endl;
	}
	{
		std::cout << "vector max_size() test" << std::endl;
		NS::vector<int> myvector;
		
  		// set some content in the vector:
  		for (int i=0; i<100; i++) myvector.push_back(i);
		
  		std::cout << "size: " << myvector.size() << "\n";
  		std::cout << "capacity: " << myvector.capacity() << "\n";
  		std::cout << "max_size: " << myvector.max_size() << "\n";
	}
	{
		std::cout << "vector resize() test" << std::endl;
		NS::vector<int> myvector;

  		// set some initial content:
  		for (size_t i=1;i<10;i++) myvector.push_back(i);

  		myvector.resize(5);
  		myvector.resize(8,100);
  		myvector.resize(12);

  		std::cout << "myvector contains:";
  		for (size_t i=0;i < myvector.size();i++)
  		  std::cout << ' ' << myvector[i];
  		std::cout << std::endl;
	}
	{
		std::cout << "vector capacity() test" << std::endl;
		NS::vector<int> myvector;

  		// set some content in the vector:
  		for (int i=0; i<100; i++) myvector.push_back(i);

  		std::cout << "size: " << (int) myvector.size() << std::endl;
  		std::cout << "capacity: " << (int) myvector.capacity() << std::endl;
  		std::cout << "max_size: " << (int) myvector.max_size() << std::endl;
	}
	{
		std::cout << "vector empty() test" << std::endl;
		NS::vector<int> myvector;
  		int sum (0);

  		for (int i=1;i<=10;i++) myvector.push_back(i);

  		while (!myvector.empty())
  		{
  		   sum += myvector.back();
  		   myvector.pop_back();
  		}

  		std::cout << "total: " << sum << std::endl;
	}
	{
		std::cout << "vector reserve() test" << std::endl;
		NS::vector<int>::size_type sz;

		NS::vector<int> foo;
		sz = foo.capacity();
		std::cout << "making foo grow:\n";
		for (int i=0; i<100; ++i) {
			foo.push_back(i);
			if (sz!=foo.capacity()) {
				sz = foo.capacity();
				std::cout << "capacity changed: " << sz << std::endl;
			}
		}
		NS::vector<int> bar;
		sz = bar.capacity();
		bar.reserve(100);   // this is the only difference with foo above
		std::cout << "making bar grow:\n";
		for (int i=0; i<100; ++i) {
			bar.push_back(i);
			if (sz!=bar.capacity()) {
				sz = bar.capacity();
				std::cout << "capacity changed: " << sz << std::endl;
			}
		}
	}
	{
		std::cout << "vector operator[] test" << std::endl;
		NS::vector<int> myvector (10);   // 10 zero-initialized elements

  		NS::vector<int>::size_type sz = myvector.size();

  		// assign some values:
  		for (unsigned i=0; i<sz; i++) myvector[i]=i;

  		// reverse vector using operator[]:
  		for (unsigned i=0; i<sz/2; i++)
  		{
  		  int temp;
  		  temp = myvector[sz-1-i];
  		  myvector[sz-1-i]=myvector[i];
  		  myvector[i]=temp;
  		}

  		std::cout << "myvector contains:";
  		for (unsigned i=0; i<sz; i++)
  		  std::cout << ' ' << myvector[i];
  		std::cout << std::endl;
	}
	{
		std::cout << "vector at() test" << std::endl;
		NS::vector<int> myvector (10);   // 10 zero-initialized ints

		// assign some values:
		for (unsigned i=0; i<myvector.size(); i++)
		  myvector.at(i)=i;
		
		std::cout << "myvector contains:";
		for (unsigned i=0; i<myvector.size(); i++)
		  std::cout << ' ' << myvector.at(i);
		std::cout << std::endl;

	}
	{
		std::cout << "vector front() test" << std::endl;
		NS::vector<int> myvector;

  		myvector.push_back(78);
  		myvector.push_back(16);

  		// now front equals 78, and back 16

  		myvector.front() -= myvector.back();

  		std::cout << "myvector.front() is now " << myvector.front() << std::endl;
	}
	{
		std::cout << "vector back() test" << std::endl;
		NS::vector<int> myvector;
		
  		myvector.push_back(10);
		
  		while (myvector.back() != 0)
  		{
  		  myvector.push_back ( myvector.back() -1 );
  		}
		
  		std::cout << "myvector contains:";
  		for (unsigned i=0; i<myvector.size() ; i++)
  		  std::cout << ' ' << myvector[i];
  		std::cout << std::endl;
	}
	{
		std::cout << "vector assign() test" << std::endl;
		NS::vector<int> first;
  		NS::vector<int> second;
  		NS::vector<int> third;

  		first.assign (7,100);             // 7 ints with a value of 100

  		NS::vector<int>::iterator it;
  		it=first.begin()+1;

  		second.assign (it,first.end()-1); // the 5 central values of first

  		int myints[] = {1776,7,4};
  		third.assign (myints,myints+3);   // assigning from array.

  		std::cout << "Size of first: " << int (first.size()) << std::endl;
  		std::cout << "Size of second: " << int (second.size()) << std::endl;
  		std::cout << "Size of third: " << int (third.size()) << std::endl;
	}
	{
		std::cout << "vector push_back() test" << std::endl;
		NS::vector<int> myvector;
		int myints[] = {1776,7,4};
		myvector.push_back(myints[0]);
		myvector.push_back(myints[1]);
		myvector.push_back(myints[2]);
		std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
	}
	{
		std::cout << "vector pop_back() test" << std::endl;
		NS::vector<int> myvector;
  		int sum (0);
  		myvector.push_back (100);
  		myvector.push_back (200);
  		myvector.push_back (300);

  		while (!myvector.empty())
  		{
  		  sum+=myvector.back();
  		  myvector.pop_back();
  		}

  		std::cout << "The elements of myvector add up to " << sum << std::endl;
	}
	{
		std::cout << "vector insert() test" << std::endl;
		NS::vector<int> myvector (3,100);
  		NS::vector<int>::iterator it;

  		it = myvector.begin();
  		it = myvector.insert ( it , 200 );

  		myvector.insert (it,2,300);

  		// "it" no longer valid, get a new one:
  		it = myvector.begin();

  		NS::vector<int> anothervector (2,400);
  		myvector.insert (it+2,anothervector.begin(),anothervector.end());

  		int myarray [] = { 501,502,503 };
  		myvector.insert (myvector.begin(), myarray, myarray+3);

  		std::cout << "myvector contains:";
  		for (it=myvector.begin(); it<myvector.end(); it++)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
	{
		std::cout << "vector erase() test" << std::endl;
		NS::vector<int> myvector;

  		// set some values (from 1 to 10)
  		for (int i=1; i<=10; i++) myvector.push_back(i);

  		// erase the 6th element
  		myvector.erase (myvector.begin()+5);

  		// erase the first 3 elements:
  		myvector.erase (myvector.begin(),myvector.begin()+3);

  		std::cout << "myvector contains:";
  		for (unsigned i=0; i<myvector.size(); ++i)
  		  std::cout << ' ' << myvector[i];
  		std::cout << std::endl;
	}
	{
		std::cout << "vector swap() test" << std::endl;
		NS::vector<int> foo (3,100);   // three ints with a value of 100
  		NS::vector<int> bar (5,200);   // five ints with a value of 200

  		foo.swap(bar);

  		std::cout << "foo contains:";
  		for (unsigned i=0; i<foo.size(); i++)
  		  std::cout << ' ' << foo[i];
  		std::cout << std::endl;

  		std::cout << "bar contains:";
  		for (unsigned i=0; i<bar.size(); i++)
  		  std::cout << ' ' << bar[i];
  		std::cout << std::endl;
	}
	{
		std::cout << "vector clear() test" << std::endl;
		NS::vector<int> myvector;
  		myvector.push_back (100);
  		myvector.push_back (200);
  		myvector.push_back (300);
		
  		std::cout << "myvector contains:";
  		for (unsigned i=0; i<myvector.size(); i++)
  		  std::cout << ' ' << myvector[i];
  		std::cout << std::endl;
		
  		myvector.clear();
  		myvector.push_back (1101);
  		myvector.push_back (2202);
		
  		std::cout << "myvector contains:";
  		for (unsigned i=0; i<myvector.size(); i++)
  		  std::cout << ' ' << myvector[i];
  		std::cout << std::endl;
	}
	{
		std::cout << "vector get_allocator() test" << std::endl;
		NS::vector<int> myvector;
  		int * p;
  		unsigned int i;

  		// allocate an array with space for 5 elements using vector's allocator:
  		p = myvector.get_allocator().allocate(5);

  		// construct values in-place on the array:
  		for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

  		std::cout << "The allocated array contains:";
  		for (i=0; i<5; i++) std::cout << ' ' << p[i];
  		std::cout << std::endl;

  		// destroy and deallocate:
  		for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
  		myvector.get_allocator().deallocate(p,5);
	}
	{
		std::cout << "vector relational operators test" << std::endl;
		NS::vector<int> foo (3,100);   // three ints with a value of 100
  		NS::vector<int> bar (2,200);   // two ints with a value of 200

  		if (foo==bar) std::cout << "foo and bar are equal\n";
  		if (foo!=bar) std::cout << "foo and bar are not equal\n";
  		if (foo< bar) std::cout << "foo is less than bar\n";
  		if (foo> bar) std::cout << "foo is greater than bar\n";
  		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
	}
	{
		std::cout << "vector Non-member function overloads swap test" << std::endl;
  		NS::vector<int> foo (3,100);   // three ints with a value of 100
  		NS::vector<int> bar (5,200);   // five ints with a value of 200
		
  		swap(bar, foo);
		
  		std::cout << "foo contains:";
  		for (NS::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
		
  		std::cout << "bar contains:";
  		for (NS::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
  		  std::cout << ' ' << *it;
  		std::cout << std::endl;
	}
}

void	stack_tests()
{
	{
		std::cout << "stack constructors test" << std::endl;
		std::deque<int> mydeque (3,100);          // deque with 3 elements
  		NS::vector<int> myvector (2,200);        // vector with 2 elements

  		NS::stack<int> first;                    // empty stack
  		NS::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

  		NS::stack<int,NS::vector<int> > third;  // empty stack using vector
  		NS::stack<int,NS::vector<int> > fourth (myvector);

  		std::cout << "size of first: " << first.size() << std::endl;
  		std::cout << "size of second: " << second.size() << std::endl;
  		std::cout << "size of third: " << third.size() << std::endl;
  		std::cout << "size of fourth: " << fourth.size() << std::endl;
	}
	{
		std::cout << "stack empty() test" << std::endl;
		NS::stack<int> mystack;
  		int sum (0);

  		for (int i=1;i<=10;i++) mystack.push(i);

  		while (!mystack.empty())
  		{
  		   sum += mystack.top();
  		   mystack.pop();
  		}

  		std::cout << "total: " << sum << std::endl;
	}
	{
		std::cout << "stack size() test" << std::endl;
		NS::stack<int> myints;
		std::cout << "0. size: " << myints.size() << std::endl;

	  	for (int i=0; i<5; i++) myints.push(i);
	  	std::cout << "1. size: " << myints.size() << std::endl;

	  	myints.pop();
	  	std::cout << "2. size: " << myints.size() << std::endl;

	}
	{
		std::cout << "stack top() test" << std::endl;
		NS::stack<int> mystack;

  		mystack.push(10);
  		mystack.push(20);

  		mystack.top() -= 5;

  		std::cout << "mystack.top() is now " << mystack.top() << std::endl;
	}
	{
		std::cout << "stack push() test" << std::endl;
		NS::stack<int> mystack;

  		for (int i=0; i<5; ++i) mystack.push(i);

  		std::cout << "Popping out elements...";
  		while (!mystack.empty())
  		{
  		   std::cout << ' ' << mystack.top();
  		   mystack.pop();
  		}
  		std::cout << std::endl;
	}
	{
		std::cout << "stack pop() test" << std::endl;
		NS::stack<int> mystack;

  		for (int i=0; i<5; ++i) mystack.push(i);
		
  		std::cout << "Popping out elements...";
  		while (!mystack.empty())
  		{
  		   std::cout << ' ' << mystack.top();
  		   mystack.pop();
  		}
  		std::cout << std::endl;
	}
}

bool fncomp (char lhs, char rhs) { return lhs<rhs; }
struct classcomp {
bool operator() (const char& lhs, const char& rhs) const
{return lhs<rhs;}
};

void	map_tests()
{
	{
		std::cout << "map constructors test" << std::endl;
		NS::map<char,int> first;

  		first['a']=10;
  		first['b']=30;
  		first['c']=50;
  		first['d']=70;

  		NS::map<char,int> second (first.begin(),first.end());

  		NS::map<char,int> third (second);

  		NS::map<char,int,classcomp> fourth;                 // class as Compare

  		bool(*fn_pt)(char,char) = fncomp;
  		NS::map<char,int,bool(*)(char,char)> fiNSh (fn_pt);
	}
	{
		std::cout << "map operator= test" << std::endl;
		NS::map<char,int> first;
  		NS::map<char,int> second;

  		first['x']=8;
  		first['y']=16;
  		first['z']=32;

  		second=first;                // second now contains 3 ints
  		first=NS::map<char,int>();  // and first is now empty

  		std::cout << "Size of first: " << first.size() << std::endl;
  		std::cout << "Size of second: " << second.size() << std::endl;
	}
	{
		std::cout << "map begin() test" << std::endl;
		NS::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;
		// show content:
		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map end() test" << std::endl;
		NS::map<char,int> mymap;

		mymap['b'] = 100;
		mymap['a'] = 200;
		mymap['c'] = 300;

		// show content:
		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
			std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map rbegin() test" << std::endl;
		NS::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		// show content:
		NS::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << std::endl;
	}
	{
		std::cout << "map rend() test" << std::endl;
		NS::map<char,int> mymap;

		mymap['x'] = 100;
		mymap['y'] = 200;
		mymap['z'] = 300;
		// show content:
		NS::map<char,int>::reverse_iterator rit;
		for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
			std::cout << rit->first << " => " << rit->second << std::endl;
	}
	{
		std::cout << "map empty() test" << std::endl;
		NS::map<char,int> mymap;

		mymap['a']=10;
		mymap['b']=20;
		mymap['c']=30;		
		while (!mymap.empty())
		{
		  std::cout << mymap.begin()->first << " => " << mymap.begin()->second << std::endl;
		  mymap.erase(mymap.begin());
		}
	}
	{
		std::cout << "map size() test" << std::endl;
		NS::map<char,int> mymap;
		mymap['a']=101;
		mymap['b']=202;
		mymap['c']=302;
		std::cout << "mymap.size() is " << mymap.size() << std::endl;
	}
	{

		std::cout << "map max_size() test" << std::endl;
		int i;
  		NS::map<int,int> mymap;

  		if (mymap.max_size()>1000)
  		{
  		  for (i=0; i<1000; i++) mymap[i]=0;
  		  std::cout << "The map contains 1000 elements.\n";
  		}
  		else std::cout << "The map could not hold 1000 elements.\n";
	}
	{
		std::cout << "map operator[] test" << std::endl;
		NS::map<char,std::string> mymap;

		mymap['a']="an element";
		mymap['b']="another element";
		mymap['c']=mymap['b'];		
		std::cout << "mymap['a'] is " << mymap['a'] << std::endl;
		std::cout << "mymap['b'] is " << mymap['b'] << std::endl;
		std::cout << "mymap['c'] is " << mymap['c'] << std::endl;
		std::cout << "mymap['d'] is " << mymap['d'] << std::endl;		
		std::cout << "mymap now contains " << mymap.size() << " elements.\n";
	}
	{
		std::cout << "map insert() test" << std::endl;
		NS::map<char,int> mymap;

		// first insert function version (single parameter):
		mymap.insert ( NS::pair<char,int>('a',100) );
		mymap.insert ( NS::pair<char,int>('z',200) );
		
		NS::pair<NS::map<char,int>::iterator,bool> ret;
		ret = mymap.insert ( NS::pair<char,int>('z',500) );
		if (ret.second==false) {
		  std::cout << "element 'z' already existed";
		  std::cout << " with a value of " << ret.first->second << std::endl;
		}
		
		// second insert function version (with hint position):
		NS::map<char,int>::iterator it = mymap.begin();
		mymap.insert (it, NS::pair<char,int>('b',300));  // max efficiency inserting
		mymap.insert (it, NS::pair<char,int>('c',400));  // no max efficiency inserting
	
		// third insert function version (range insertion):
		NS::map<char,int> anothermap;
		anothermap.insert(mymap.begin(),mymap.find('c'));
	
		// showing contents:
		std::cout << "mymap contains:\n";
		for (it=mymap.begin(); it!=mymap.end(); ++it)
		  std::cout << it->first << " => " << it->second << std::endl;
	
		std::cout << "anothermap contains:\n";
		for (it=anothermap.begin(); it!=anothermap.end(); ++it)
		  std::cout << it->first << " => " << it->second << std::endl;
	}
	{

		std::cout << "map erase() test" << std::endl;
		NS::map<char,int> mymap;
  		NS::map<char,int>::iterator it;

  		// insert some values:
  		mymap['a']=10;
  		mymap['b']=20;
  		mymap['c']=30;
  		mymap['d']=40;
  		mymap['e']=50;
  		mymap['f']=60;

  		it=mymap.find('b');
  		mymap.erase (it);                   // erasing by iterator

  		mymap.erase ('c');                  // erasing by key

  		it=mymap.find ('e');
  		mymap.erase ( it, mymap.end() );    // erasing by range

  		// show content:
  		for (it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map swap() test" << std::endl;

		NS::map<char,int> foo,bar;

  		foo['x']=100;
  		foo['y']=200;
		
  		bar['a']=11;
  		bar['b']=22;
  		bar['c']=33;
		
  		foo.swap(bar);
		
  		std::cout << "foo contains:\n";
  		for (NS::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
		
  		std::cout << "bar contains:\n";
  		for (NS::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map clear() test" << std::endl;
		NS::map<char,int> mymap;

  		mymap['x']=100;
  		mymap['y']=200;
  		mymap['z']=300;
		
  		std::cout << "mymap contains:\n";
  		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
		
  		mymap.clear();
  		mymap['a']=1101;
  		mymap['b']=2202;
		
  		std::cout << "mymap contains:\n";
  		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map key_comp() test" << std::endl;
		NS::map<char,int> mymap;

  		NS::map<char,int>::key_compare mycomp = mymap.key_comp();

  		mymap['a']=100;
  		mymap['b']=200;
  		mymap['c']=300;

  		std::cout << "mymap contains:\n";

  		char highest = mymap.rbegin()->first;     // key value of last element

  		NS::map<char,int>::iterator it = mymap.begin();
  		do {
  		  std::cout << it->first << " => " << it->second << std::endl;
  		} while ( mycomp((*it++).first, highest) );

  		std::cout << std::endl;
	}
	{
		std::cout << "map value_comp() test" << std::endl;
		NS::map<char,int> mymap;

  		mymap['x']=1001;
  		mymap['y']=2002;
  		mymap['z']=3003;

  		std::cout << "mymap contains:\n";

  		NS::pair<char,int> highest = *mymap.rbegin();          // last element

  		NS::map<char,int>::iterator it = mymap.begin();
  		do {
  		  std::cout << it->first << " => " << it->second << std::endl;
  		} while ( mymap.value_comp()(*it++, highest) );
	}
	{
		std::cout << "map find() test" << std::endl;
		NS::map<char,int> mymap;
  		NS::map<char,int>::iterator it;

  		mymap['a']=50;
  		mymap['b']=100;
  		mymap['c']=150;
  		mymap['d']=200;

  		it = mymap.find('b');
  		if (it != mymap.end())
  		  mymap.erase (it);

  		// print content:
  		std::cout << "elements in mymap:" << std::endl;
  		std::cout << "a => " << mymap.find('a')->second << std::endl;
  		std::cout << "c => " << mymap.find('c')->second << std::endl;
  		std::cout << "d => " << mymap.find('d')->second << std::endl;
	}
	{
		std::cout << "map count() test" << std::endl;
		NS::map<char,int> mymap;
  		char c;

  		mymap ['a']=101;
  		mymap ['c']=202;
  		mymap ['f']=303;

  		for (c='a'; c<'h'; c++)
  		{
  		  std::cout << c;
  		  if (mymap.count(c)>0)
  		    std::cout << " is an element of mymap.\n";
  		  else 
  		    std::cout << " is not an element of mymap.\n";
  		}
	}
	{
		std::cout << "map lower_bound() test" << std::endl;
		NS::map<char,int> mymap;
  		NS::map<char,int>::iterator itlow,itup;

  		mymap['a']=20;
  		mymap['b']=40;
  		mymap['c']=60;
  		mymap['d']=80;
  		mymap['e']=100;

  		itlow=mymap.lower_bound ('b');  // itlow points to b
  		itup=mymap.upper_bound ('d');   // itup points to e (not d!)

  		mymap.erase(itlow,itup);        // erases [itlow,itup)
  		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map upper_bound() test" << std::endl;
		NS::map<char,int> mymap;
  		NS::map<char,int>::iterator itlow,itup;

  		mymap['a']=20;
  		mymap['b']=40;
  		mymap['c']=60;
  		mymap['d']=80;
  		mymap['e']=100;

  		itlow = mymap.lower_bound ('b');  // itlow points to b
  		itup = mymap.upper_bound ('d');   // itup points to e (not d!)

  		mymap.erase(itlow,itup);        // erases [itlow,itup)

  		// print content:
  		for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
	}
	{
		std::cout << "map equal_range() test" << std::endl;
		NS::map<char,int> mymap;

  		mymap['a']=10;
  		mymap['b']=20;
  		mymap['c']=30;

  		NS::pair<NS::map<char,int>::iterator,NS::map<char,int>::iterator> ret;
  		ret = mymap.equal_range('b');

  		std::cout << "lower bound points to: ";
  		std::cout << ret.first->first << " => " << ret.first->second << std::endl;

  		std::cout << "upper bound points to: ";
  		std::cout << ret.second->first << " => " << ret.second->second << std::endl;

	}
	{
		std::cout << "map get_allocator() test" << std::endl;
		int psize;
  		NS::map<char,int> mymap;
  		NS::pair<const char,int>* p;

  		// allocate an array of 5 elements using mymap's allocator:
  		p=mymap.get_allocator().allocate(5);

  		// assign some values to array
  		psize = sizeof(NS::map<char,int>::value_type)*5;

  		std::cout << "The allocated array has a size of " << psize << " bytes.\n";

  		mymap.get_allocator().deallocate(p,5);
	}
	{
		std::cout << "map relational operators test" << std::endl;
		NS::map<char,int> foo,bar;
  		foo['a']=100;
  		foo['b']=200;
  		bar['a']=10;
  		bar['z']=1000;

  		// foo ({{a,100},{b,200}}) vs bar ({a,10},{z,1000}}):
  		if (foo==bar) std::cout << "foo and bar are equal\n";
  		if (foo!=bar) std::cout << "foo and bar are not equal\n";
  		if (foo< bar) std::cout << "foo is less than bar\n";
  		if (foo> bar) std::cout << "foo is greater than bar\n";
  		if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
  		if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";

	}
	{
		std::cout << "map non_member overload swap() test" << std::endl;
		NS::map<char,int> foo,bar;

  		foo['x']=100;
  		foo['y']=200;
		
  		bar['a']=11;
  		bar['b']=22;
  		bar['c']=33;
		
  		swap(foo,bar);
		
  		std::cout << "foo contains:\n";
  		for (NS::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
		
  		std::cout << "bar contains:\n";
  		for (NS::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
  		  std::cout << it->first << " => " << it->second << std::endl;
	}

    {
        timeval start, end;

        std::cout << "((((((((((std map time))))))" << std::endl;
		std::map<int,int> second;
        gettimeofday(&start, NULL);
        for (int i = 0; i != 1000;i++)
            second.insert(std::make_pair(i, i));
        gettimeofday(&end, NULL);
        second.erase(second.begin(), second.end());
        print_time(start, end);

        std::cout << "((((((((((ft map time)))))))" << std::endl;
		ft::map<int,int> first;
        gettimeofday(&start, NULL);
        for (int i = 0; i != 1000;i++)
            first.insert(ft::make_pair(i, i));
        gettimeofday(&end, NULL);
        first.erase(first.begin(), first.end());
        print_time(start, end);

    }
}

int main()
{
	timeval start, end;
	
	gettimeofday(&start, NULL);
	std::cout << "-----------------Vector Tests--------------------" << std::endl;
	vector_tests();
	std::cout << "-----------------Stack Tests--------------------" << std::endl;
	stack_tests();
	std::cout << "-----------------Map Tests--------------------" << std::endl;
	map_tests();
	gettimeofday(&end, NULL);
	// print_time(start, end);
	// while (1);
	
	return 0;
}