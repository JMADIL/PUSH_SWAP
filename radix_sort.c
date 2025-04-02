/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 09:59:39 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/02 11:11:52 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_bits(t_list *stack)
{
	int	max;
	int	bits;

	max = ft_lstsize(stack);
	bits = 0;
	while ((max >> bits) != 0)
		bits++;
	return (bits);
}

void	radix_sort(t_list **stack_a, t_list **stack_b)
{
	int	max_bits;
	int	i;
	int	size;

	max_bits = get_max_bits(*stack_a);
	i = 0;
	while (i < max_bits)
	{
		size = ft_lstsize(*stack_a);
		while (size > 0)
		{
			if (((((*stack_a)->index >> i) & 1) == 0) 
				&& ((stack_is_sorted(*stack_a)) == 0))
				push_b(stack_a, stack_b);
			else if ((((*stack_a)->index >> i) & 1) == 1)
				ra(stack_a);
			size--;
		}
		while (*stack_b)
			push_a(stack_a, stack_b);
		i++;
	}
}
