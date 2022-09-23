/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_checker_p.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:43:35 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 15:43:48 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pb_c(t_all *all, int i)
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
	return (0);
}

int	pa_c(t_all *all, int i)
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
	return (0);
}
