/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:21:23 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/09 12:21:23 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	do_commands(char *line, t_all *all)
{
	if (!(ft_strcmp(line, "sa\n")))
		return (sa_c(all, 0));
	if (!(ft_strcmp(line, "sb\n")))
		return (sb_c(all, 0));
	if (!(ft_strcmp(line, "ss\n")))
		return (ss_c(all, 0));
	if (!(ft_strcmp(line, "pa\n")))
		return (pa_c(all, 0));
	if (!(ft_strcmp(line, "pb\n")))
		return (pb_c(all, 0));
	if (!(ft_strcmp(line, "ra\n")))
		return (ra_c(all, 0));
	if (!(ft_strcmp(line, "rb\n")))
		return (rb_c(all, 0));
	if (!(ft_strcmp(line, "rr\n")))
		return (rr_c(all, 0));
	if (!(ft_strcmp(line, "rra\n")))
		return (rra_c(all, 0));
	if (!(ft_strcmp(line, "rrb\n")))
		return (rrb_c(all, 0));
	if (!(ft_strcmp(line, "rrr\n")))
		return (rrr_c(all, 0));
	return (1);
}

static void	check_order(t_all *all)
{
	t_stk	*stk_a;
	int		error;

	stk_a = all->a;
	if (all->b)
		error = 1;
	while (stk_a && stk_a->next != all->a)
	{
		if (stk_a->num > stk_a->next->num)
			error = 1;
		stk_a = stk_a->next;
	}
	if (error)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}

int	main(int argc, char **argv)
{
	t_all	*all;
	char	*line;

	line = NULL;
	all = NULL;
	if (argc < 2)
		return (1);
	all = init_all(all, argc, argv);
	fill_stk_a(all);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		if (do_commands(line, all))
			return (return_error(&line, all));
		ft_strdel(&line);
	}
	check_order(all);
	free_all(all);
	return (0);
}
