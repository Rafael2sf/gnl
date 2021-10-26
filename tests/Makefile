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

SRCSB=		\
			get_next_line_bonus.c\
			get_next_line_utils_bonus.c\
			main_bonus.c

CVARS=		BUFFER_SIZE=103

OBJS=		$(patsubst %.c,%.o,$(SRCS))
OBJSB=		$(patsubst %.c,%.o,$(SRCSB))

all: m b

%.o: %.c
	$(CC) $(CFLAGS) -D $(CVARS) -c $^ -o $@ 

m: $(OBJS)
	$(CC) $(CFLAGS) -D $(CVARS) $(OBJS) -o m.out

b: $(OBJSB)
	$(CC) $(CFLAGS) -D $(CVARS) $(OBJSB) -o b.out

clean: 
	$(RM) $(OBJS) $(OBJSB)

fclean: clean
	$(RM) m.out b.out

re: fclean all

.PHONY: all m b clean fclean re