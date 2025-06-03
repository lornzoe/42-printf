# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lyanga <lyanga@student.42singapore.sg>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 17:25:56 by lyanga            #+#    #+#              #
#    Updated: 2025/06/03 18:54:35 by lyanga           ###   ########.fr        #
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

LIBFTPATH = libft/
LIBFTSRCS = ft_putstr_fd.c ft_putchar_fd.c ft_calloc.c ft_strchr.c ft_isdigit.c ft_atoi.c ft_ilen.c ft_strlen.c \
			ft_ptoa.c ft_strdup.c ft_substr.c ft_abs.c ft_itoa.c ft_strjoin.c ft_uitoa.c ft_uitoa_base.c \
			ft_isspace.c ft_strtrim.c ft_strlcpy.c ft_strrev.c ft_uilen_base.c
LIBFTINCLUDES = ./libft/
LIBFTSRCSNAME = $(subst $(LIBFTPATH), , $(LIBFTSRCS))
LIBFTOBJSNAME = $(LIBFTSRCS:.c=.o)
LIBFTOBJS	=	$(addprefix $(LIBFTPATH), $(LIBFTOBJSNAME))

SRCSPATH	=	src/
OBJSPATH	=	src/
BONUSPATH	=	bonus/
BOBJSPATH	=	bonus/
INC			=	header/

SRCS		=	ft_printf.c ft_printf_vars.c ft_printf_getpaddedstr.c ft_printf_getargstr.c	\
				ft_printf_getargstr_c.c ft_printf_getargstr_s.c \
				ft_printf_getargstr_di.c ft_printf_getargstr_u.c ft_printf_getargstr_xx.c \
				ft_printf_printarg.c

BONUSSRCS	=	ft_printf_bonus.c ft_printf_vars_bonus.c ft_printf_getpaddedstr_bonus.c ft_printf_getargstr_bonus.c	\
				ft_printf_getargstr_c_bonus.c ft_printf_getargstr_s_bonus.c \
				ft_printf_getargstr_di_bonus.c ft_printf_getargstr_u_bonus.c ft_printf_getargstr_xx_bonus.c \
				ft_printf_printarg_bonus.c

SRCSNAME	=	$(subst $(SRCSPATH), , $(SRCS))

OBJSNAME	=	$(SRCS:.c=.o)
OBJS		=	$(addprefix $(OBJSPATH), $(OBJSNAME))

BSRCSNAME 	=	$(subst $(BONUSPATH), , $(BONUSSRCS))
BOBJSNAME	= 	$(BONUSSRCS:.c=.o)
BOBJS		= 	$(addprefix $(BOBJSPATH), $(BOBJSNAME))

# **************************************************************************** #
# rules

all: $(NAME)
	@printf "$(B)$(MAG)$(NAME) is finished compiling$(D)\n"

addlibft:
	$(MAKE) -C $(LIBFTPATH)

$(NAME): fclean addlibft $(OBJS) 
	@printf "$(BLU)"
	$(AR) $(NAME) $(OBJS) $(LIBFTOBJS)
	@printf "$(D)"


$(OBJSPATH)%.o: $(SRCSPATH)%.c
	@printf "$(GRE)"
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(D)"

$(BOBJSPATH)%.o: $(BONUSPATH)%.c
	@printf "$(YEL)"
	$(CC) $(CFLAGS) -I$(INC) -c $< -o $@
	@printf "$(D)"

b: addlibft $(BOBJS)
	@printf "$(BLU)"
	$(AR) $(NAME) $(BOBJS) $(LIBFTOBJS)
	@printf "$(D)"

bonus: fclean b
	@printf "\n$(B)$(MAG)$(NAME) + bonus is finished compiling$(D)\n"
clean:
	$(MAKE) clean -C $(LIBFTPATH)
	$(RM) $(OBJS) $(BOBJS)
	@echo "$(B)Cleaned$(D)"


fclean:	clean
	$(MAKE) fclean -C $(LIBFTPATH)
	$(RM) $(NAME)
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
