#include <iostream>
#include <vector>
#include "vector.hpp"
#include <sys/time.h>


time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
#include <iterator> //for std::istream_iterator 


int main()
{


            time_t start, end;
                std::vector<std::string> v(100, "hello");
                std::vector<std::string> v1(1e6, "string2");
                start = get_time();
                v1.reserve(1e6 + 200);
                v1.insert(v1.begin() + 1e5, v.begin(), v.end());
                end = get_time();
                std::cout << end - start << std::endl;
                /*------------------ ft::vectors ---------------------*/
                ft::vector<std::string> ft_v(100, "hello");
                ft::vector<std::string> ft_v1(1e6, "string2");
                start = get_time();
                ft_v1.reserve(1e6 + 200);
                ft_v1.insert(ft_v1.begin() + 1e5, ft_v.begin(), ft_v.end());
                end = get_time();
                std::cout << end - start << std::endl;
            // std::istream_iterator<int> begin(std::cin), end;
            // std::cout << "after cin iterator" << std::endl;
            // // std::vector<int> v(begin, end);
            // std::vector<int>::difference_type

            // std::cout << "after v" << std::endl;
            // // std::vector<int> a(9,9);
            // v.insert(v.begin(), begin, end);
            // std::cout << "cap = "<< v.capacity() << std::endl;
}