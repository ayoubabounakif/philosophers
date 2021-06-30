# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aabounak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/03 10:02:19 by aabounak          #+#    #+#              #
#    Updated: 2021/06/03 10:02:19 by aabounak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FLAGS = -Wall -Wextra -Werror

LIBNAME = utilsLib.a

NAME = philo_one

EXEC = philo_one

SRCS = philo_one.c \
srcs/subroutines/constructors.c srcs/subroutines/runThreads.c srcs/subroutines/Destructor.c \
srcs/threadsRoutineMethods/__eat__.c \
srcs/threadsRoutineMethods/__sleep__.c \
srcs/threadsRoutineMethods/__think__.c \
srcs/threadsUtils/displayChangeOfStatus.c \
srcs/threadsUtils/getCurrentTime.c \

LIBS = -lpthread

all: $(NAME)

$(LIBNAME): $(SRC)
	make -C utilsLib/
	cp utilsLib/$(LIBNAME) ./

$(NAME): $(LIBNAME)
	@echo "Compilation in progress! DO NOT INTERRUPT!"
	gcc -g3 -fsanitize=address $(FLAGS) $(SRCS) utilsLib.a -o $(EXEC) $(LIBS)
	@echo "Compilation done! :)"

clean:
	make clean -C utilsLib/
	rm -f *.o

fclean: clean
	make fclean -C utilsLib/
	rm -f *.a
	rm -f $(EXEC)
	rm -rf $(EXEC).dSYM
	rm -rf .vscode

re: fclean all
