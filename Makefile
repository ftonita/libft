SRCS = ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strncmp.c \
		ft_split.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_strnstr.c \
		ft_atoi.c \
		ft_calloc.c \
		ft_strdup.c

OBJ=$(SRCS:.c=.o)

NAME = libft.a

FLAGS = -Wall -Wextra -Werror -c -I.

$(CC) = gcc

$(NAME):
	@$(CC) $(FLAGS) $(SRCS)
	@ar -rc $(NAME) $(OBJ)
	@ranlib $(NAME)
re: fclean $(NAME)
clean:
	@rm -f $(OBJ) $(NAME)
fclean: 
	@rm -f $(NAME)
rm:
	@fclean all
list:
	@ar -t $(NAME)
.PHONY:
	@all clean fclean rm