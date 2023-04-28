NAME    =   libftprintf.a
RM      =   rm -f
CC      =   cc
CFLAGS  =   -Wall -Werror -Wextra
SRCS    =   ft_printf_utils_cs_id.c ft_printf_utils_uhex.c ft_printf_utils_p.c\
            ft_printf.c \

OBJS    =   $(SRCS:.c=.o)
INCLUDE =   ft_printf.h
LIB     =   ar rcs
all:    $(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
	$(LIB) -r $@ $?

%.o:%.c
	$(CC) -c $(CFLAGS) $?
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all
.PHONY: re fclean clean
