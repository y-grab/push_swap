/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:26:59 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 19:49:59 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	score_min(t_all *all, char stk_name)
{
	t_stk	*stk;
	int		flag;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	flag = 1;
	if (stk)
	{
		score_to_top(all, stk_name, flag);
		score_to_bottom(all, stk_name, flag);
		if (all->r_min <= all->rr_min)
			all->rr_min = -1;
		else
			all->r_min = -1;
	}
}

static void	score_max(t_all *all, char stk_name)
{
	t_stk	*stk;
	int		flag;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	flag = 2;
	if (stk)
	{
		score_to_top(all, stk_name, flag);
		score_to_bottom(all, stk_name, flag);
		if (all->r_max <= all->rr_max)
			all->rr_max = -1;
		else
			all->r_max = -1;
	}
}

void	get_score(t_all *all, char stk_name)
{
	t_stk	*stk;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	score_min(all, 'b');
	score_max(all, 'b');
	if (all->r_max != -1 && (all->r_max >= all->r_min
			&& all->r_max >= all->rr_min))
		all->r_max = -1;
	else if (all->rr_max != -1 && (all->rr_max >= all->r_min
			&& all->rr_max >= all->rr_min))
		all->rr_max = -1;
	else if (all->r_min != -1 && (all->r_min >= all->r_max
			&& all->r_min >= all->rr_max))
		all->r_min = -1;
	else if (all->rr_min != -1 && (all->rr_min >= all->r_max
			&& all->rr_min >= all->rr_max))
		all->rr_min = -1;
	if (all->r_min != -1 || all->rr_min != -1)
		all->min_flag = 1;
	else if (all->r_max != -1 || all->rr_max != -1)
		all->max_flag = 1;
}
