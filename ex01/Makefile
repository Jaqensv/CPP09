NAME = RPN
SOURCES = main.cpp \
		RPN.cpp \

OBJECTS = $(SOURCES:.cpp=.o)

CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

all: ${NAME}

${NAME}: ${OBJECTS}
	@$(CXX) $(CXXFLAGS) -g3 -o ${NAME} ${OBJECTS}

%.o: %.cpp
	@$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f ${OBJECTS}
	
fclean: clean
	@rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re