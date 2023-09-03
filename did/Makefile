NAME			=	did

SRCS			=	main.cpp	utils.cpp	Did.cpp
LIB				=	Did.hpp

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

.PHONY:			all clean fclean re