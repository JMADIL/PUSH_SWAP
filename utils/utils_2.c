/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 16:58:13 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/29 05:37:18 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_atoi(const char *str)
{
	int		i;
	int		s;
	long	rs;

	i = 0;
	s = 1;
	rs = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			s *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		if (rs > LONG_MAX / 10 && s == 1)
			return (-1);
		if (rs > LONG_MAX / 10 && s == -1)
			return (0);
		rs = rs * 10 + (str[i] - 48);
		i++;
	}
	return (rs * s);
}
int has_duplicates(int *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	int		i;

	i = 0;
	len = ft_strlen(src);
	dest = (char *)malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
