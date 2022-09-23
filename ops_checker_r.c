/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_checker_r.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:44:00 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 15:44:19 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra_c(t_all *all, int i)
{
	if (all->a)
		all->a = all->a->next;
	if (i == 1)
		write(1, "ra\n", 3);
	return (0);
}

int	rb_c(t_all *all, int i)
{
	if (all->b)
		all->b = all->b->next;
	if (i == 1)
		write(1, "rb\n", 3);
	return (0);
}

int	rr_c(t_all *all, int i)
{
	ra_c(all, 0);
	rb_c(all, 0);
	if (i == 1)
		write(1, "rr\n", 3);
	return (0);
}
