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
    bool exec_throwed = false;
    ft::vector<std::string> ft_v1(10, "string2");
    ft::vector<char> ft_v2;
    try
    {
        ft_v1.reserve(ft_v1.max_size() + 1);
        std::cout << "work1" << std::endl;
    }
    catch (std::length_error const &e)
    {
        (void)e;
        exec_throwed = true;
    }
    if (exec_throwed)
        std::cout << "work2" << std::endl;
}