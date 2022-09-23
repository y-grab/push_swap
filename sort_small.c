/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 17:27:02 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/11 13:50:07 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_all *all)
{
	if (all->a->num > all->a->next->num)
		sa(all, 1);
}

void	sort_three(t_all *all)
{
	get_max(all, 'a');
	if (all->a->num == all->max)
		ra(all, 1);
	if (all->a->next->num == all->max)
		rra(all, 1);
	if (all->a->num > all->a->next->num)
		sa(all, 1);
}

void	sort_four(t_all *all)
{
	t_stk	*stk_a;

	stk_a = all->a;
	get_min_max(all, 'a');
	while (stk_a->num != all->min)
	{
		ra(all, 1);
		stk_a = stk_a->next;
	}
	pb(all, 1);
	sort_three(all);
	pa(all, 1);
}

void	sort_five(t_all *all)
{
	t_stk	*stk_a_end;
	t_stk	*tmp;
	int		flag;

	flag = 0;
	stk_a_end = all->a->prev;
	get_median(all, 'a');
	while (flag != 1)
	{
		if (all->a == stk_a_end)
			flag = 1;
		if (all->a->num < all->m)
			pb(all, 1);
		else
			ra(all, 1);
	}
	sort_three(all);
	tmp = all->b->next;
	if (all->b->num < tmp->num)
		sb(all, 1);
	pa(all, 1);
	pa(all, 1);
}

void	sort_small(t_all *all)
{
	if (all->initial_size == 2)
		sort_two(all);
	else if (all->initial_size == 3)
		sort_three(all);
	else if (all->initial_size == 4)
		sort_four(all);
	else if (all->initial_size == 5)
		sort_five(all);
}
