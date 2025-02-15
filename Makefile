all:
	cc -c -g get_next_line.c get_next_line_utils.c get_next_line.h
f fclean:
	rm -rf *.o *.h.gch *.a
re: f all
