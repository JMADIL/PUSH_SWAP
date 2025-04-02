/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pars_args.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 06:06:24 by ssbaytri          #+#    #+#             */
/*   Updated: 2025/04/02 17:07:09 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

static int	digit_is_ok(char *str, int *i, long *res, int sign)
{
	while (str[*i] >= '0' && str[*i] <= '9')
	{
		*res = *res * 10 + (str[*i] - '0');
		if ((*res * sign) > INT_MAX || (*res * sign) < INT_MIN)
			return (0);
		(*i)++;
	}
	while (str[*i])
	{
		if (str[*i] != ' ')
			return (0);
		(*i)++;
	}
	return (1);
}

static int	is_valid_number(char *str)
{
	int		i;
	long	result;
	int		sign;

	i = 0;
	result = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	if (!digit_is_ok(str, &i, &result, sign))
		return (0);
	return (1);
}

static int	count_args(char **splitted_nums)
{
	int	count;

	count = 0;
	while (splitted_nums[count])
		count++;
	return (count);
}

static char	*join_args(int ac, char **av)
{
	char	*res;
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 1;
	res = ft_strdup("");
	while (i < ac)
	{
		tmp2 = ft_strtrim(av[i], " ");
		if (!av[i][0] || tmp2[0] == '\0')
			return (free(res), free(tmp2), NULL);
		tmp = ft_strjoin(res, av[i]);
		free(res);
		res = tmp;
		tmp = ft_strjoin(res, " ");
		free(res);
		res = tmp;
		free(tmp2);
		i++;
	}
	return (res);
}

int	*pars_args(int ac, char **av, int *size)
{
	char	*joined_args;
	char	**splitted_args;
	int		*nums;
	int		count;
	int		i;

	i = 0;
	joined_args = join_args(ac, av);
	if (!joined_args)
		return (NULL);
	splitted_args = ft_split(joined_args, ' ');
	count = count_args(splitted_args);
	nums = malloc(sizeof(int) * count);
	if (!nums)
		return (ft_free(splitted_args), free(joined_args), NULL);
	while (i < count)
	{
		if (!is_valid_number(splitted_args[i]))
			return (free(nums), ft_free(splitted_args), free(joined_args),
				NULL);
		nums[i] = ft_atoi(splitted_args[i]);
		i++;
	}
	if (!has_duplicates(nums, count))
		return (free(nums), ft_free(splitted_args), free(joined_args), NULL);
	return (free(joined_args), ft_free(splitted_args), *size = count, nums);
}
