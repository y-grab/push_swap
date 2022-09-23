/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:28:50 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:28:50 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_all *all, int i)
{
	long int	tmp;

	if (all->a)
	{
		tmp = all->a->num;
		stk_del_top(all, 'a');
		stk_add_top(all, 'b', tmp);
	}
	if (i == 1)
		write(1, "pb\n", 3);
}

void	pa(t_all *all, int i)
{
	long int	tmp;

	if (all->b)
	{
		tmp = all->b->num;
		stk_del_top(all, 'b');
		stk_add_top(all, 'a', tmp);
	}
	if (i == 1)
		write(1, "pa\n", 3);
}
