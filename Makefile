# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 17:25:56 by lyanga            #+#    #+#              #
#    Updated: 2025/06/03 03:44:03 by lyanga           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name
NAME	=	$(OUTDIR)/libftprintf.a
# cc options
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
DEBUG	=	-g -O0 
# remove
RM		=	rm -f
# archive
AR		=	ar rcs
# outdir, by default it's current dir
OUTDIR ?= .

# **************************************************************************** #
# srcs

LIBFTDIR = libft


SRCSPATH	=	./
OBJSPATH	=	./
BONUSPATH	=	./
BOBJSPATH	=	./
INC			=	./

SRCS		=	ft_printf.c ft_printf_vars.c ft_printf_getpaddedstr.c ft_printf_getargstr.c	\
				ft_printf_getargstr_c.c ft_printf_getargstr_s.c \
				ft_printf_getargstr_di.c ft_printf_getargstr_u.c ft_printf_getargstr_xx.c

BONUSSRCS	=	ft_printf.c ft_printf_vars.c

SRCSNAME	=	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME	=	$(SRCSNAME:.c=.o)
OBJS		=	$(addprefix $(OBJSPATH), $(OBJSNAME))

BSRCSNAME 	=	$(subst $(BONUSPATH), , $(BONUSSRCS))
BOBJSNAME	= 	$(BSRCSNAME:.c=.o)
BOBJS		= 	$(addprefix $(BOBJSPATH), $(BOBJSNAME))

# **************************************************************************** #
# rules

all: $(NAME) p_printf_logo clean
	@printf "\n$(B)$(MAG)$(NAME) is finished compiling$(D)\n"

p_printf_logo:
	@printf "      .-.                                     .-. \n"
	@printf " 42- / -'  /               .-.          /    / -' \n"
	@printf "   -/-----/---   .-.  ).--.\`-'.  .-.---/----/--   \n"
	@printf "   /     /       /  )/    /    )/   ) /    /      \n"
	@printf "\`.'     /._____./\`-'/  _.(__. '/   ( /  \`.'       \n"
	@printf "          \`==='/                    \`- lyanga AAAA\n"

addlibft:
	$(MAKE) -C $(LIBFTDIR) extern OBJSPATH=../ BOBJSPATH=../

test: fclean $(NAME)
	@cc test.c -L. -lftprintf
	@$(RM) *.o
	@./a.out

$(NAME): $(OBJS) addlibft 
	@$(AR) $(NAME) *.o

$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	@$(CC) $(DEBUG) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(GRE)█$(D)"

$(BOBJSPATH)%.o: $(BONUSPATH)%.c
	@mkdir -p $(dir $@) # 2> /dev/null || true
	@$(CC) $(DEBUG) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(YEL)█$(D)"

b: $(OBJS) $(BOBJS) addlibft
	@$(AR) $(NAME) *.o

bonus: b p_printf_logo clean

clean:
	@$(RM) $(OBJS) $(BOBJS)
	@$(RM) *.o
	@echo "$(B)Cleaned$(D)"


fclean:	clean
	@$(RM) $(NAME)
	@echo "$(B)FCleaned$(D)"

re:	fclean all

.PHONY: all clean fclean re bonus p_bar p_bar_bonus p_bar_close p_printf_logo b bonus

# **************************************************************************** #
# text colours

B		=	$(shell tput bold)
BLA		=	$(shell tput setaf 0)
RED		=	$(shell tput setaf 1)
GRE		=	$(shell tput setaf 2)
YEL		=	$(shell tput setaf 3)
BLU		=	$(shell tput setaf 4)
MAG		=	$(shell tput setaf 5)
CYA		=	$(shell tput setaf 6)
WHI		=	$(shell tput setaf 7)
D		=	$(shell tput sgr0)
BEL		=	$(shell tput bel)
CLR		=	$(shell tput el 1)
