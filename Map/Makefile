DEBUG =  -fsanitize=address # -g
FLAG = --std=c++98 -Wall -Werror -Wextra 
all: 
	@ echo "---------std--------" && c++  -D NS=std $(DEBUG) $(FLAG) main.cpp && ./a.out && rm -fr a.out a.out.*
main2: 
	@ echo "---------std--------" && c++  -D NS=std $(DEBUG) $(FLAG) main2.cpp && ./a.out && rm -fr a.out a.out.*