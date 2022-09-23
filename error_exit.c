/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 16:46:07 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/27 16:46:07 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(t_all *all)
{
	write(2, "Error\n", 6);
	free_all(all);
	exit(-1);
}

void	free_all(t_all *all)
{
	if (all)
	{
		if (all->a)
			free_stk(all->a);
		if (all->b)
			free_stk(all->b);
		free(all);
	}
}

void	free_stk(t_stk *stk)
{
	t_stk	*next_elem;
	t_stk	*elem_to_free;

	if (stk)
	{
		next_elem = stk->next;
		while (next_elem != stk)
		{
			elem_to_free = next_elem;
			next_elem = next_elem->next;
			free(elem_to_free);
		}
		free(next_elem);
	}
}
