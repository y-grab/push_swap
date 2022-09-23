/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:58:42 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 19:36:01 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct stk
{
	int			num;
	struct stk	*next;
	struct stk	*prev;
}	t_stk;

typedef struct atoi_stk
{
	long	num;
	int		i;
	int		len;
	int		sign;
}	t_atoi;

typedef struct all
{
	char	*line;
	char	**av;
	int		ac;
	int		stk_len;
	int		initial_size;
	long	q;
	long	m;
	long	t_q;
	long	max;
	int		r_max;
	int		rr_max;
	int		max_flag;
	long	min;
	int		r_min;
	int		rr_min;
	int		min_flag;
	int		post_r;

	t_stk	*a;
	t_stk	*b;
}			t_all;

//ops_checker
int		pa_c(t_all *all, int i);
int		pb_c(t_all *all, int i);
int		ra_c(t_all *all, int i);
int		rb_c(t_all *all, int i);
int		rr_c(t_all *all, int i);
int		rra_c(t_all *all, int i);
int		rrb_c(t_all *all, int i);
int		rrr_c(t_all *all, int i);
int		sa_c(t_all *all, int i);
int		sb_c(t_all *all, int i);
int		ss_c(t_all *all, int i);

int		ft_strcmp(const char *s1, const char *s2);
void	ft_strdel(char **s);
int		return_error(char **line, t_all *all);

//error exit
void	error_exit(t_all *all);
void	free_all(t_all *all);
void	free_stk(t_stk *stk);

// fill list
long	atoi_ps(char *str);
void	check_dups(t_all *all);
void	fill_list(t_all *all, char *str, int i, int j);
void	validate_args(t_all *all);
void	fill_stk_a(t_all *all);

//get min max
void	get_min(t_all *all, char stk_name);
void	get_max(t_all *all, char stk_name);
void	get_min_max(t_all *all, char stk_name);

//score
void	reset_score(t_all *all);
void	get_score(t_all *all, char stk_name);
void	score_to_top(t_all *all, char stk_name, int flag);
void	score_to_bottom(t_all *all, char stk_name, int flag);

//median
void	get_median(t_all *all, char stk_name);
void	push_median(t_all *all, int split);

//ops util
void	stk_del_top(t_all *all, char stk_name);
void	stk_add_top(t_all *all, char stk_name, int num);
void	stk_add_end(t_all *all, char stk_name, int num);

//ops
void	pb(t_all *all, int i);
void	pa(t_all *all, int i);
void	ra(t_all *all, int i);
void	rb(t_all *all, int i);
void	rr(t_all *all, int i);
void	rra(t_all *all, int i);
void	rrb(t_all *all, int i);
void	rrr(t_all *all, int i);
void	sa(t_all *all, int i);
void	sb(t_all *all, int i);
void	ss(t_all *all, int i);

//sort small
void	sort_two(t_all *all);
void	sort_three(t_all *all);
void	sort_four(t_all *all);
void	sort_five(t_all *all);
void	sort_small(t_all *all);

//sort big
void	sort_big(t_all *all);

//sort bigger
void	pick_quarter_and_pb(t_all *all);
void	sort_bigger(t_all *all);

//sort utility
void	rb_and_pa(t_all *all);
void	push_min_max(t_all *all, t_stk *stk, t_stk *stk_end);

//sort
void	sort(t_all *all);

//utility
t_all	*init_all(t_all *all, int argc, char **argv);
int		find_stk_len(t_all *all, char stk_name);
int		is_digit(int c);
int		check_if_sorted(t_all *all);

#endif