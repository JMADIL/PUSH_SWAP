/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:31:24 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/30 11:22:30 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

t_list	*init_stack(int *nums, int size)
{
	t_list	*stack;
	t_list	*tmp;
	int		i;

	i = 0;
	stack = ft_lstnew(nums[i]);
	i++;
	while (i < size)
	{
		tmp = ft_lstnew(nums[i]);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return (stack);
}

int	check_input(int *nums, int ac, int size)
{
	if (ac < 2 || size == 1)
	{
		free(nums);
		return (0);
	}
	if (!nums)
	{
		write(2, "Error\n", 6);
		free(nums);
		return (0);
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*nums;
	int		size;

	size = 0;
	nums = pars_args(ac, av, &size);
	if (!check_input(nums, ac, size))
		return (1);
	stack_a = init_stack(nums, size);
	stack_b = NULL;
	init_index(stack_a);
	while (stack_a)
	{
		printf("%d", stack_a->content);
		printf(" index = %d\n", stack_a->index);
		stack_a = stack_a->next;
	}
	
}
