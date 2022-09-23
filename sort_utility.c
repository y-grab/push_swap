/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utility.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:24:53 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:24:53 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rb_and_pa(t_all *all)
{
	if (all->r_min >= 0)
		while (all->r_min--)
			rb(all, 1);
	else if (all->rr_min >= 0)
		while (all->rr_min--)
			rrb(all, 1);
	else if (all->r_max >= 0)
		while (all->r_max--)
			rb(all, 1);
	else if (all->rr_max >= 0)
		while (all->rr_max--)
			rrb(all, 1);
	pa(all, 1);
	if (all->min_flag)
		ra(all, 1);
	if (all->max_flag || !all->b)
		all->post_r++;
	reset_score(all);
}

void	push_min_max(t_all *all, t_stk *stk, t_stk *stk_end)
{
	while (1)
	{
		while (stk->num != all->min && stk->num != all->max)
			stk = stk->next;
		if (stk->num == all->min || stk->num == all->max)
		{
			rb_and_pa(all);
			break ;
		}
		else
			stk = stk->next;
		if (stk == stk_end)
			break ;
		stk = all->b;
	}
}
