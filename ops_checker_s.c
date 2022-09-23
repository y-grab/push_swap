/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_checker_s.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 15:45:15 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 15:45:42 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa_c(t_all *all, int i)
{
	long int	tmp;

	if (all->a && all->a->next != all->a)
	{
		tmp = all->a->num;
		all->a->num = all->a->next->num;
		all->a->next->num = tmp;
	}
	if (i == 1)
		write(1, "sa\n", 3);
	return (0);
}

int	sb_c(t_all *all, int i)
{
	long int	tmp;

	if (all->b && all->b->next != all->b)
	{
		tmp = all->b->num;
		all->b->num = all->b->next->num;
		all->b->next->num = tmp;
	}
	if (i == 1)
		write(1, "sb\n", 3);
	return (0);
}

int	ss_c(t_all *all, int i)
{
	sa_c(all, 0);
	sb_c(all, 0);
	if (i == 1)
		write(1, "ss\n", 3);
	return (0);
}
