/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 14:01:34 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 16:06:42 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_all	*all;

	all = NULL;
	all = init_all(all, argc, argv);
	if (argc >= 2)
	{
		fill_stk_a(all);
		if ((check_if_sorted(all)) != 1)
			sort(all);
	}
	free_all(all);
	return (0);
}
