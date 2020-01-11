SRCS_NAME	=	ft_parser.c ft_parser_utils.c ft_conv_num_utils.c ft_conv_num.c ft_conv_c.c ft_printf.c

SRCS_LIBFT	=	$(addprefix libft_printf/, ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
				ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c \
				ft_itoa.c ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
				ft_lstlast_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \
				ft_memccpy.c ft_memchr.c ft_memcmp.c ft_memcpy.c \
				ft_memmove.c ft_memset.c ft_putchar_fd.c ft_putendl_fd.c \
				ft_putnbr_fd.c ft_putstr_fd.c ft_split.c ft_strchr.c \
				ft_strdup.c ft_strjoin.c ft_strjoin_free.c ft_strlcat.c ft_strlcpy.c \
				ft_strlen.c ft_strmapi.c ft_strncmp.c ft_strnstr.c \
				ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c \
				ft_toupper.c ft_lltoa_base.c ft_isdigit_w0.c)
				

SRC_PATH = ./

SRCS = $(addprefix $(SRC_PATH), $(SRCS_NAME), $(SRCS_LIBFT))

HEADER	=	./ft_printf.h

OBJ_NAME	=	${SRCS_NAME:.c=.o} ${SRCS_LIBFT:.c=.o}

OBJ = $(OBJ_NAME)

NAME	= libftprintf.a

CC		= cc

RM		= rm -rf

FLAG	= -Wall -Werror -Wextra -g3 #-fsanitize=address

all: $(OBJ_PATH) $(NAME)

$(NAME): $(OBJ) $(HEADER)
	@ar rcs $(NAME) $(OBJ)
	@echo "$'[32m\nCompiling effected successfully!"

%.o: $(SRC_PATH)%.c $(HEADER)
	@echo "$'[31mCompiling :$'[0m $<$'[0m"
	@gcc $(FLAG) -I ./includes  -c $< -o $@

clean:
	${RM} ${OBJ}

fclean: clean
	${RM} ${NAME}

re: fclean all

.PHONY: all clean fclean re bonus