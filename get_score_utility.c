/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score_utility.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 17:05:30 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 18:12:58 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	help_score_to_top(t_all *all, char stk_name, int flag)
{
	t_stk	*tmp;
	int		n;

	if (stk_name == 'a')
		tmp = all->a;
	else
		tmp = all->b;
	if (flag == 1)
		n = all->min;
	else
		n = all->max;
	while (tmp->num != n)
	{
		if (flag == 1)
			all->r_min++;
		else
			all->r_max++;
		tmp = tmp->next;
	}
}

void	score_to_top(t_all *all, char stk_name, int flag)
{
	t_stk	*stk;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	if (stk)
		help_score_to_top(all, stk_name, flag);
}

void	help_score_to_bottom(t_all *all, char stk_name, int flag)
{
	t_stk	*tmp;
	int		n;

	if (stk_name == 'a')
		tmp = all->a->prev;
	else
		tmp = all->b->prev;
	if (flag == 1)
		n = all->min;
	else
		n = all->max;
	while (tmp->num != n)
	{
		if (flag == 1)
			all->rr_min++;
		else
			all->rr_max++;
		tmp = tmp->prev;
	}
	if (flag == 1)
		all->rr_min++;
	else
		all->rr_max++;
}

void	score_to_bottom(t_all *all, char stk_name, int flag)
{
	t_stk	*stk;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	if (stk)
		help_score_to_bottom(all, stk_name, flag);
}
