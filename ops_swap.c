/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:30:02 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:30:02 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_all *all, int i)
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
}

void	sb(t_all *all, int i)
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
}

void	ss(t_all *all, int i)
{
	sa(all, 0);
	sb(all, 0);
	if (i == 1)
		write(1, "ss\n", 3);
}
