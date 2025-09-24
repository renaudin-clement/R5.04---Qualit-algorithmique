deboggeur valgrinde
valgrind --tool=memcheck --leak-check=full ./prog

valgrind --tool=memcheck --leak-check=full --log-file=log ./prog