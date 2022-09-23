/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_checker_rr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:44:32 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 15:44:48 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra_c(t_all *all, int i)
{
	if (all->a)
		all->a = all->a->prev;
	if (i == 1)
		write(1, "rra\n", 4);
	return (0);
}

int	rrb_c(t_all *all, int i)
{
	if (all->b)
		all->b = all->b->prev;
	if (i == 1)
		write(1, "rrb\n", 4);
	return (0);
}

int	rrr_c(t_all *all, int i)
{
	rra_c(all, 0);
	rrb_c(all, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
	return (0);
}
