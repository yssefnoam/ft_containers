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
            // ft::vector<std::string> ft_v;

            // ft_v.insert(ft_v.begin() + 1, 3, "str");
            // for (size_t i = 0; i!= ft_v.size(); i++)
            //     std::cout << ft_v[i] << std::endl;

    //     std::cout  << "size = " << v.size() << "\n";
    //     std::cout  << "Address = " << &(*v.begin()) << "\n";

    //     std::cout  << "ft size = " << ft_v.size() << "\n";
    //     std::cout  << "ft Address = " << &(*ft_v.begin()) << "\n";
    //         v.insert(v.begin() + 10, 100, "hello");
    //         ft_v.insert(ft_v.begin() + 10, 100, "hello");
    //     std::cout  << "size = " << v.size() << "\n";
    //     std::cout  << "Address = " << &(*v.begin()) << "\n";
        
    //     std::cout  << "ft size = " << ft_v.size() << "\n";
    //     std::cout  << "ft Address = " << &(*ft_v.begin()) << "\n";
    //     //  ft::vector <int>::iterator lkabi =  v.erase(v.begin() + 4, v.begin() + 10);
    //     for (size_t i = 0; i < v.size(); ++i)
    //             str += v[i];
    //         for (size_t i = 0; i < ft_v.size(); ++i)
    //             ft_str += ft_v[i];

    //      std::cout << str<<  std::endl << std::endl;
    //      std::cout << ft_str<<  std::endl;
    //      if (str == ft_str)
    //         std::cout<< "Wooorkssss" << std::endl;
    // }

}