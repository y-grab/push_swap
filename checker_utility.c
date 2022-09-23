/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utility.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:21:29 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 16:21:31 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}
	return (*(const unsigned char *)s1 - *(const unsigned char *)s2);
}

void	ft_strdel(char **s)
{
	if (s == NULL)
		return ;
	free(*s);
	*s = NULL;
}

int	return_error(char **line, t_all *all)
{
	ft_strdel(line);
	if (all->a)
		free_stk(all->a);
	if (all->b)
		free_stk(all->b);
	write(2, "Error\n", 6);
	return (0);
}
