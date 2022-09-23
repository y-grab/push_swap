/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_median.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 17:40:35 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 19:36:21 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	sort_array(long *array, int len)
{
	long	tmp;
	int		i;

	tmp = 0;
	i = 0;
	while (i < len - 1)
	{
		if (array[i] <= array[i + 1])
			i++;
		else
		{
			tmp = array[i];
			array[i] = array[i + 1];
			array[i + 1] = tmp;
			i = 0;
		}
	}
}

static void	find_median(t_all *all, t_stk *stk, char stk_name)
{
	long	*array;
	int		i;
	int		quarter_len;

	i = 0;
	all->stk_len = find_stk_len(all, stk_name);
	quarter_len = all->stk_len / 4;
	array = (long *)malloc(sizeof(long) * (all->stk_len + 1));
	if (!array)
		error_exit(all);
	while (i < all->stk_len)
	{
		array[i++] = stk->num;
		stk = stk->next;
	}
	sort_array(array, all->stk_len);
	all->q = array[quarter_len];
	all->m = array[quarter_len * 2];
	all->t_q = array[quarter_len * 3];
	free(array);
}

void	get_median(t_all *all, char stk_name)
{
	t_stk	*stk;

	if (stk_name == 'a')
		stk = all->a;
	else
		stk = all->b;
	find_median(all, stk, stk_name);
}

void	push_median(t_all *all, int split)
{
	t_stk	*stk;
	t_stk	*stk_a_end;
	int		flag;

	stk = all->a;
	stk_a_end = all->a->prev;
	flag = 0;
	get_min(all, 'a');
	while (1)
	{
		if (stk == stk_a_end)
			flag = 1;
		if (split == 1 && stk->num <= all->m)
			pb(all, 1);
		else if (split == 2 && stk->num > all->m)
			pb(all, 1);
		else if (stk->num == all->min)
			break ;
		else
			ra(all, 1);
		if (flag == 1)
			break ;
		stk = all->a;
	}
	reset_score(all);
}
