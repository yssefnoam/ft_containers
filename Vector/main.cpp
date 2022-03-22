#include <iostream>
#include <vector>
#include <ctime>
#include "vector.hpp"
#include <sys/time.h>
#include <unistd.h>
#define EQUAL(x) ((x) ? (std::cout << "\033[1;32mAC\033[0m\n") : (std::cout << "\033[1;31mWA\033[0m\n"))
#define TIME_FAC 20 // the ft::vector methods can be slower up to std::vector methods * TIME_FAC (MAX 20)

time_t get_time(void)
{
    struct timeval time_now;

    gettimeofday(&time_now, NULL);
    time_t msecs_time = (time_now.tv_sec * 1e3) + (time_now.tv_usec / 1e3);
    return (msecs_time);
}
int main()
{
    std::vector<std::string> v1(10, "string2");          // fill constructor
    std::vector<std::string> v2;                         // empty constructor
    std::vector<std::string> v3(v1.begin(), v1.end());   // range constructor with normal iterators
    std::vector<std::string> v4(v3);                     // copy constructor
    std::vector<std::string> v5(v1.rbegin(), v1.rend()); // range constructor with reverse iterators
    /*-----------------------------------------------------*/
    /*------------------ ft::vectors ---------------------*/
    ft::vector<std::string> ft_v1(10, "string2");
    ft::vector<std::string> ft_v2;
    ft::vector<std::string> ft_v3(ft_v1.begin(), ft_v1.end());
    std::cout << "################################" << std::endl;
    ft::vector<std::string> ft_v4(ft_v3);
    ft::vector<std::string> ft_v5(ft_v1.rbegin(), ft_v1.rend());
    /*----------------------------------------------------*/
    EQUAL(v1.size() == ft_v1.size() && v2.size() == ft_v2.size() && v3.size() == ft_v3.size() && v4.size() == ft_v4.size() && v5.size() == ft_v5.size());
}