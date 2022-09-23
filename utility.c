/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:43:59 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:43:59 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_all	*init_all(t_all *all, int argc, char **argv)
{
	all = (t_all *)malloc(sizeof(t_all));
	all->a = NULL;
	all->b = NULL;
	all->ac = argc;
	all->av = argv;
	all->q = 0;
	all->m = 0;
	all->t_q = 0;
	all->max = 0;
	all->r_max = 0;
	all->rr_max = 0;
	all->max_flag = 0;
	all->min = 0;
	all->r_min = 0;
	all->rr_min = 0;
	all->min_flag = 0;
	all->post_r = 0;
	return (all);
}

int	find_stk_len(t_all *all, char stk_name)
{
	t_stk	*stk;
	t_stk	*end;
	int		len;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	len = 0;
	if (stk)
	{
		if (stk_name == 'a')
			end = all->a->prev;
		else
			end = all->b->prev;
	}
	while (stk)
	{
		len++;
		if (stk == end)
			break ;
		stk = stk->next;
	}
	return (len);
}

int	is_digit(int c)
{
	return (c >= '0' && c <= '9');
}

int	check_if_sorted(t_all *all)
{
	t_stk	*tmp;
	t_stk	*end;

	end = all->a->prev;
	if (!all->a || all->b)
		return (0);
	tmp = all->a;
	while (1)
	{
		if (tmp == end)
			break ;
		if (tmp->num > tmp->next->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	reset_score(t_all *all)
{
	all->max = 0;
	all->r_max = 0;
	all->rr_max = 0;
	all->max_flag = 0;
	all->min = 0;
	all->r_min = 0;
	all->rr_min = 0;
	all->min_flag = 0;
}
