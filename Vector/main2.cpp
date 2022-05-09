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
}