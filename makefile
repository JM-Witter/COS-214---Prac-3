all:
	g++ -std=c++11 -Werror -Wall *.cpp -o eventflow

run: all
	./eventflow

memory:
	g++ -std=c++11 -Werror -Wall *.cpp -o eventflow
	valgrind --leak-check=full ./eventflow
