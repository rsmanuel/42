LIBFT = ./libft/libft.a

N_TEMP = temp.a

NAME = libftprintf.a

SRCS =  ft_printf.c \
		char.c \
		ft_aux.c \
		ft_aux2.c \
		int.c \
		parse.c \
		print.c \
		string.c \
		struct.c \
		hex.c \
		uint.c \
		pointer.c \
		
SURPL_O = 	ft_printf.o \
		char.o \
		ft_aux.o \
		ft_aux2.0 \
		int.o \
		parse.o \
		print.o \
		string.o \
		struct.o \
		hex.o \
		uint.o \
		pointer.o \

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = -I./includes

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
	ar -rcs $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME)

clean :
	$(MAKE) clean -C ./libft
	rm -rf $(SURPL_O) 
	rm -rf $(OBJS)

fclean : clean
	$(MAKE) fclean -C ./libft
	rm -rf $(NAME)

re : fclean all
