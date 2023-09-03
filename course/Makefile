NAME			=	ucourse

SRCS			=	main.cpp	ucourse.cpp	utils.cpp
LIB				=	ucourse.h

OBJS			=	$(SRCS:%.cpp=%.o)

CC				= 	c++
RM				= 	rm -rf

all:			$(NAME)

$(NAME):		$(OBJS) $(LIB)
				$(CC) $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)

norm:
				norminette *.[ch]

.PHONY:			all clean fclean re bonus