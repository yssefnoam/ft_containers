# DEBUG =  -fsanitize=address
FLAG = --std=c++98 -Wall -Werror -Wextra
all: 
	@ echo "---------std--------" && c++ -D NS=std $(DEBUG) $(FLAG) main.cpp && ./a.out && rm -fr a.out a.out.*