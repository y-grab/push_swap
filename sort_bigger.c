/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_bigger.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:42:48 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/26 15:42:48 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pick_q_and_pb(t_all *all)
{
	if (all->b && all->b->num > (all->m / 4) * 7)
		rb(all, 1);
	else if (all->b && all->b->num > (all->m / 4) * 5)
		rb(all, 1);
	else if (all->b && all->b->num > (all->m / 4) * 3)
		rb(all, 1);
	else if (all->b && all->b->num > all->q / 2)
		rb(all, 1);
	pb(all, 1);
}

void	push_q(t_all *all, t_stk *stk_a, int step)
{
	t_stk	*stk_a_end;
	int		flag;

	stk_a_end = all->a->prev;
	flag = 0;
	get_min_max(all, 'a');
	while (flag != 1)
	{
		if (stk_a == stk_a_end)
			flag = 1;
		if (step == 1 && stk_a->num <= all->q)
			pick_q_and_pb(all);
		else if (step == 2 && stk_a->num > all->q && stk_a->num <= all->m)
			pick_q_and_pb(all);
		else if (step == 3 && stk_a->num > all->m && stk_a->num <= all->t_q)
			pick_q_and_pb(all);
		else if (step == 4 && stk_a->num > all->t_q)
			pick_q_and_pb(all);
		else if (step == 4 && stk_a->num == all->min)
			break ;
		else
			ra(all, 1);
		stk_a = all->a;
	}
	reset_score(all);
}

void	sort_bigger(t_all *all)
{
	int	step;

	step = 1;
	get_median(all, 'a');
	while (all->a)
	{
		push_q(all, all->a, step);
		while (all->b)
		{
			get_min_max(all, 'b');
			get_score(all, 'b');
			if (all->b && (all->r_min >= 0 || all->rr_min >= 0
					|| all->r_max >= 0 || all->rr_max >= 0))
				push_min_max(all, all->b, all->b->prev);
		}
		while (--all->post_r)
			ra(all, 1);
		step++;
		if (step == 5)
			break ;
	}
}
