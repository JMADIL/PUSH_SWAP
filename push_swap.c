/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 05:31:24 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/02 11:26:28 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

int	stack_is_sorted(t_list *lst)
{
	t_list	*head;

	head = lst;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (0);
		head = head->next;
	}
	return (1);
}

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

void	push_swap(t_list **stack_a, t_list **stack_b, int size)
{
	init_index(*stack_a);
	if (stack_is_sorted(*stack_a))
		return ;
	if (size == 2 || size == 3)
		sort_two_or_three(stack_a, size);
	if (size == 4)
		sort_4_nums(stack_a, stack_b);
	if (size == 5)
		sort_5_nums(stack_a, stack_b);
	if (size > 5)
		radix_sort(stack_a, stack_b);
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
	push_swap(&stack_a, &stack_b, size);
}
