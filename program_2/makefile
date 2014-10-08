all:
	gcc main.c -o main
run:
	valgrind --tool=memcheck --leak-check=full --show-leak-kinds=all ./main