/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:31:24 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/29 06:20:00 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	main(int ac, char **av)
{
	int	*nums;
	int	size;

	nums = pars_args(ac, av, &size);
	if (!nums)
		printf("Error\n");
	while (size)
	{
		printf("%d\n", nums[size - 1]);
		size--;
	}
}
