/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops_utility.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/22 16:25:20 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 16:55:03 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stk_del_top(t_all *all, char stk_name)
{
	t_stk		**top;
	t_stk		*tmp;

	if (stk_name == 'a')
		top = &all->a;
	else
		top = &all->b;
	if (*top)
	{
		if ((*top)->next == *top)
		{
			free(*top);
			*top = NULL;
		}
		else
		{
			tmp = *top;
			*top = (*top)->next;
			tmp->prev->next = *top;
			(*top)->prev = tmp->prev;
			free(tmp);
		}
	}
}

t_stk	**stk_add_top_help(t_all *all, t_stk **top, t_stk *tmp, int num)
{
	tmp = (t_stk *)malloc(sizeof(t_stk));
	if (!tmp)
		error_exit(all);
	tmp->next = *top;
	tmp->prev = (*top)->prev;
	(*top)->prev = tmp;
	tmp->prev->next = tmp;
	tmp->num = num;
	*top = (*top)->prev;
	return (top);
}

void	stk_add_top(t_all *all, char stk_name, int num)
{
	t_stk		**top;
	t_stk		*tmp;

	tmp = NULL;
	if (stk_name == 'a')
		top = &all->a;
	else
		top = &all->b;
	if (*top)
		stk_add_top_help(all, top, tmp, num);
	else
	{
		*top = (t_stk *)malloc(sizeof(t_stk));
		if (!(*top))
			error_exit(all);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->num = num;
	}
}

t_stk	*stk_add_end_help(t_all *all, t_stk **top, t_stk *tmp, int num)
{
	tmp = (t_stk *)malloc(sizeof(t_stk));
	if (!tmp)
		error_exit(all);
	tmp->next = *top;
	tmp->prev = (*top)->prev;
	(*top)->prev = tmp;
	tmp->prev->next = tmp;
	tmp->num = num;
	return (tmp);
}

void	stk_add_end(t_all *all, char stk_name, int num)
{
	t_stk		**top;
	t_stk		*tmp;

	tmp = NULL;
	if (stk_name == 'a')
		top = &all->a;
	else
		top = &all->b;
	if (*top)
		stk_add_end_help(all, top, tmp, num);
	else
	{
		*top = (t_stk *)malloc(sizeof(t_stk));
		if (!(*top))
			error_exit(all);
		(*top)->next = *top;
		(*top)->prev = *top;
		(*top)->num = num;
	}
}
