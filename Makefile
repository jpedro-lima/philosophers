NAME		= philo

CFLAGS		= -g3 -g -Wall -Werror -Wextra
LFLAGS		= -pthread
INCLUDES	= -I./includes

# source codes
SRCS_DIR	=	./srcs/
SRCS_LIST	=	philosophers.c		\
				data.c				\
				utils.c				\
				checkers.c			\
				ft_libft.c			\
				linked_list.c		\
				actions.c			\
				philosophers_life.c	\
				dinner_monitor.c	\
				simulator.c			\
				time.c
SRCS		=	$(addprefix $(SRCS_DIR),$(SRCS_LIST))

# objects
OBJS_DIR		= ./objects/
OBJS			= $(addprefix $(OBJS_DIR),$(SRCS_LIST:%.c=%.o))

#colors
GREEN			= \033[0;32m
YELLOW			= \033[0;33m
BLUE			= \033[0;34m
MAGENTA			= \033[0;35m
CYAN			= \033[0;36m
RESET			= \033[0m

all: $(NAME)

$(NAME): $(OBJS_DIR) $(OBJS)
	@printf "\n"
	@cc $(CFLAGS) $(OBJS) $(LFLAGS) -o $(NAME)
	@echo " $(CYAN)$(NAME): $(GREEN)Done!"
	@echo -n "$(RESET)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
	@cc $(CFLAGS) $(INCLUDES) -c $< -o $@
	@printf "$(YELLOW)Generating $(CYAN)$(NAME) $(YELLOW)objects... %-33.33s\r" $@

$(OBJS_DIR):
	@mkdir -p $(OBJS_DIR)

clean:
	@rm -rf $(OBJS_DIR)	

fclean: clean
	@rm -f $(NAME)

re: fclean all

val:
	valgrind --leak-check=full --show-leak-kinds=all -q ./$(NAME) 2 800 200 200 5

.PHONY: all clean fclean re val