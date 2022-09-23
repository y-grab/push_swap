# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 13:01:51 by ujicama           #+#    #+#              #
#    Updated: 2022/03/11 13:33:44 by ujicama          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	push_swap

BONUS	=	checker

SRC_PS	=	push_swap.c \
			error_exit.c \
			fill_list.c \
			get_min_max.c \
			get_median.c \
			get_score.c \
			get_score_utility.c \
			ops_push.c \
			ops_r_rotate.c \
			ops_rotate.c \
			ops_swap.c \
			ops_utility.c \
			sort.c \
			sort_big.c \
			sort_bigger.c \
			sort_small.c \
			sort_utility.c \
			utility.c \

SRC_CH	=	checker.c \
			checker_utility.c \
			ops_checker_p.c \
			ops_checker_r.c \
			ops_checker_rr.c \
			ops_checker_s.c \
			fill_list.c \
			utility.c \
			ops_utility.c \
			error_exit.c \

INC		=	-I includes -I libft

OBJDIR_PS	=	objs_ps

OBJDIR_CH	=	objs_ch

OBJS_PS	=	$(addprefix $(OBJDIR_PS)/,$(SRC_PS:.c=.o))

OBJS_CH	=	$(addprefix $(OBJDIR_CH)/,$(SRC_CH:.c=.o))

LFT		=	libft/libft.a

CFLAGS	=	-Werror -Wall -Wextra

.PHONY: all clean fclean re bonus

all : $(OBJDIR_PS) $(NAME)

bonus : $(OBJDIR_CH) $(BONUS)

$(OBJS_PS): $(OBJDIR_PS)/%.o: %.c
	gcc -c $(CFLAGS) $(INC) $< -o $@

$(OBJS_CH): $(OBJDIR_CH)/%.o: %.c
	gcc -c $(CFLAGS) $(INC) $< -o $@


$(OBJDIR_PS):
	@mkdir -p $@
	
$(OBJDIR_CH):
	@mkdir -p $@

$(LFT):
	make -C libft/

$(BONUS): $(LFT) $(OBJS_CH)
	cc $(CFLAGS) $^ -o $@ 

$(NAME): $(LFT) $(OBJS_PS)
	cc $(CFLAGS) $^ -o $@ 

clean:
	make -C libft clean
	/bin/rm -rf $(OBJDIR_PS) $(OBJDIR_CH)

fclean: clean
	make -C libft fclean
	/bin/rm -rf $(BONUS) $(NAME)

re: fclean all