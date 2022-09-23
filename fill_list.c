/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ujicama <ujicama@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/27 15:20:29 by ujicama           #+#    #+#             */
/*   Updated: 2022/03/10 19:17:13 by ujicama          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	atoi_ps(char *str)
{
	long	num;
	int		i;
	int		sign;

	num = 0;
	i = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0');
		i++;
	}
	return (num * sign);
}

void	check_dups(t_all *all)
{
	t_stk		*tmp_a;
	t_stk		*tmp_b;

	tmp_a = all->a;
	while (tmp_a != all->a->prev)
	{
		tmp_b = tmp_a->next;
		while (tmp_b != all->a)
		{
			if (tmp_a->num == tmp_b->num)
				error_exit(all);
			tmp_b = tmp_b->next;
		}
		tmp_a = tmp_a->next;
	}
}

void	fill_list(t_all *all, char *str, int i, int j)
{
	long int	tmp;

	while (str)
	{
		while (*str)
		{
			j = 0;
			while ((j == 0) && *str && *str == ' ')
				str++;
			while (*(str + j) && (*(str + j) == '-'
					|| *(str + j) == '+' || is_digit(*(str + j))))
				j++;
			if (!*str)
				break ;
			tmp = atoi_ps(str);
			if (tmp > 2147483647 || tmp < -2147483648)
				error_exit(all);
			stk_add_end(all, 'a', tmp);
			str += j;
		}
		str = all->av[++i];
	}
	if (!all->a)
		error_exit(all);
}

void	validate_args(t_all *all)
{
	char	*str;
	int		i;

	i = 1;
	str = all->av[i];
	while (str)
	{
		while (*str)
		{
			if (*str == ' ' || is_digit(*str))
				str++;
			else if (*str == '-' && is_digit(*(str + 1))
				&& (str == all->av[i] || *(str - 1) == ' '))
				str++;
			else if (*str == '+' && is_digit(*(str + 1))
				&& (str == all->av[i] || *(str - 1) == ' '))
				str++;
			else
				error_exit(all);
		}
		str = all->av[++i];
	}
}

void	fill_stk_a(t_all *all)
{
	char	*str;
	int		i;
	int		j;

	i = 1;
	j = 0;
	str = all->av[i];
	validate_args(all);
	fill_list(all, str, i, j);
	check_dups(all);
}
