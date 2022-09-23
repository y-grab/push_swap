/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:50:27 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 18:17:05 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_big(t_all *all)
{
	int	split;

	split = 1;
	get_median(all, 'a');
	while (all->a)
	{
		push_median(all, split);
		while (all->b)
		{
			get_min_max(all, 'b');
			get_score(all, 'b');
			if (all->b && (all->r_min >= 0 || all->rr_min >= 0
					|| all->r_max >= 0 || all->rr_max >= 0))
				push_min_max(all, all->b, all->b->prev);
		}
		while (--all->post_r)
			ra(all, 1);
		split++;
		if (split == 3)
			break ;
	}
}
