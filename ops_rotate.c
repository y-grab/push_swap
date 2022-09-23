/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:29:16 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:29:16 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_all *all, int i)
{
	if (all->a)
		all->a = all->a->next;
	if (i == 1)
		write(1, "ra\n", 3);
}

void	rb(t_all *all, int i)
{
	if (all->b)
		all->b = all->b->next;
	if (i == 1)
		write(1, "rb\n", 3);
}

void	rr(t_all *all, int i)
{
	ra(all, 0);
	rb(all, 0);
	if (i == 1)
		write(1, "rr\n", 3);
}
