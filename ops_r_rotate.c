/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_r_rotate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:43 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:29:43 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_all *all, int i)
{
	if (all->a)
		all->a = all->a->prev;
	if (i == 1)
		write(1, "rra\n", 4);
}

void	rrb(t_all *all, int i)
{
	if (all->b)
		all->b = all->b->prev;
	if (i == 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_all *all, int i)
{
	rra(all, 0);
	rrb(all, 0);
	if (i == 1)
		write(1, "rrr\n", 4);
}
