CC=			gcc
CFLAGS=		\
			-g\
			-Wall\
			-Werror\
			-Wextra\
			-fsanitize=address

SRCS=		\
			get_next_line.c\
			get_next_line_utils.c\
			main.c

CVARS=		BUFFER_SIZE=1

OBJS=		$(patsubst %.c,%.o,$(SRCS))

all: test
	./a.out	

objs: $(OBJS)

%.o: %.c
	$(CC) $(CFLAGS) -D $(CVARS) -c $^ -o $@ 

test: $(OBJS)
	$(CC) $(CFLAGS) -D $(CVARS) $(OBJS)

clean: 
	$(RM) $(OBJS)

fclean: clean
	$(RM) a.out

re: fclean all

.PHONY: all test clean fclean re