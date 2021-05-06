NAME := btree

SRCS := Tree.class.cpp main.cpp

OBJS := $(SRCS:.cpp=.o)

CXX := g++

CXXFLAGS := -std=c++98 -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) -o $@

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJS)
	@echo "\033[0;32m[INFO] $(OBJS) removed\033[0m"

fclean: clean
	@rm -rf $(NAME)
	@echo "\033[0;32m[INFO] $(NAME) removed\033[0m"

re: fclean all