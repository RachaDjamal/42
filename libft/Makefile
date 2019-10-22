SRCS = ft_isdigit.c ft_memmove.c ft_strlcpy.c ft_substr.c ft_atoi.c ft_isprint.c ft_memset.c ft_strlen.c ft_tolower.c ft_bzero.c ft_itoa.c ft_split.c ft_toupper.c ft_calloc.c ft_memccpy.c ft_strchr.c ft_strncmp.c ft_isalnum.c ft_memchr.c ft_strdup.c ft_strnstr.c ft_isalpha.c ft_memcmp.c ft_strjoin.c ft_strrchr.c ft_isascii.c ft_memcpy.c ft_strlcat.c ft_strtrim.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_strmapi.c

BONUS = ft_lstnew_bonus.c ft_lstsize_bonus.c ft_lstlast_bonus.c ft_lstadd_front_bonus.c ft_lstadd_back_bonus.c ft_lstdelone_bonus.c ft_lstclear_bonus.c ft_lstiter_bonus.c ft_lstmap_bonus.c

HDRS = libft.h

OBJS = ${SRCS:.c=.o}

OBJSBONUS = ${BONUS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror

RM = rm -f

NAME = libft.a

AR = ar rcs

all : ${NAME}


.c.o :	${HDRS}
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME) :	${OBJS}
			${AR} ${NAME} ${OBJS}

bonus :		${OBJS} ${OBJSBONUS}
			${AR} ${NAME} ${OBJS} ${OBJSBONUS}

clean :
		${RM} ${OBJS} ${OBJSBONUS}

fclean :	clean
			${RM} ${NAME}

re : fclean all

.PHONY : all clean fclean re
