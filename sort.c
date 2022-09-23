/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 15:27:35 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/04 14:13:46 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_all *all)
{
	all->initial_size = find_stk_len(all, 'a');
	if (all->initial_size <= 5)
		sort_small(all);
	else if (all->initial_size <= 100)
		sort_big(all);
	else if (all->initial_size > 100)
		sort_bigger(all);
}
