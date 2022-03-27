DEBUG =  -fsanitize=address
FLAG = --std=c++98 -Wall -Werror -Wextra
main1: 
	@ echo "---------std--------" && c++  -D NS=std $(DEBUG) $(FLAG) main1.cpp && ./a.out && rm -fr a.out a.out.*
main2: 
	@ echo "---------std--------" && c++  -D NS=std $(DEBUG) $(FLAG) main2.cpp && ./a.out && rm -fr a.out a.out.*