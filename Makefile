all:
	cc -D BUFFER_SIZE=10 -c -g get_next_line.c get_next_line_utils.c get_next_line.h
f fclean:
	rm -rf *.o *.h.gch *.a
re: f all

bonus:
	cc -D BUFFER_SIZE=10 -c -g get_next_line_bonus.c get_next_line_utils_bonus.c get_next_line_bonus.h

