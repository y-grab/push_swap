/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_min_max.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 17:28:16 by ujicama           #+#    #+#             */
/*   Updated: 2022/02/25 17:10:26 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_min(t_all *all, char stk_name)
{
	t_stk	*stk;
	t_stk	*tmp;
	t_stk	*end;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	tmp = stk;
	if (stk_name == 'a')
		end = all->a->prev;
	else
		end = all->b->prev;
	all->min = all->max;
	while (1)
	{
		if (tmp->num <= all->min)
			all->min = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	get_max(t_all *all, char stk_name)
{
	t_stk	*stk;
	t_stk	*tmp;
	t_stk	*end;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	tmp = stk;
	all->max = tmp->num;
	if (stk_name == 'a')
		end = all->a->prev;
	else
		end = all->b->prev;
	while (1)
	{
		if (tmp->num > all->max)
			all->max = tmp->num;
		if (tmp == end)
			break ;
		tmp = tmp->next;
	}
}

void	get_min_max(t_all *all, char stk_name)
{
	t_stk	*stk;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	get_max(all, stk_name);
	get_min(all, stk_name);
}
