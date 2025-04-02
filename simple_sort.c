/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 12:37:28 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/02 09:24:23 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_min(t_list *list)
{
	int		min;
	t_list	*tmp;

	tmp = list;
	min = tmp->index;
	while (tmp->next)
	{
		if (tmp->next->index < min)
			min = tmp->next->index;
		tmp = tmp->next;
	}
	return (min);
}

void	sort_two_or_three(t_list **stack_a, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
	if (size == 3)
	{
		if ((*stack_a)->content > (*stack_a)->next->content
			&& (*stack_a)->content > (*stack_a)->next->next->content)
			ra(stack_a);
		if ((*stack_a)->next->content > (*stack_a)->content
			&& (*stack_a)->next->content > (*stack_a)->next->next->content)
			rra(stack_a);
		if ((*stack_a)->content > (*stack_a)->next->content)
			sa(stack_a);
	}
}

void	sort_4_nums(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	if ((*stack_a)->index == min)
		push_b(stack_a, stack_b);
	else if ((*stack_a)->next->index == min)
	{
		sa(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->index == min)
	{
		rra(stack_a);
		rra(stack_a);
		push_b(stack_a, stack_b);
	}
	else if ((*stack_a)->next->next->next->index == min)
	{
		rra(stack_a);
		push_b(stack_a, stack_b);
	}
	sort_two_or_three(stack_a, 3);
	push_a(stack_a, stack_b);
}

void	sort_5_nums(t_list **stack_a, t_list **stack_b)
{
	int	min;

	min = get_min(*stack_a);
	if ((*stack_a))
	{
		if ((*stack_a)->next->index == min)
			sa(stack_a);
		else if ((*stack_a)->next->next->index == min)
		{
			ra(stack_a);
			ra(stack_a);
		}
		else if ((*stack_a)->next->next->next->index == min)
		{
			rra(stack_a);
			rra(stack_a);
		}
		else if ((*stack_a)->next->next->next->next->index == min)
			rra(stack_a);
		push_b(stack_a, stack_b);
	}
	sort_4_nums(stack_a, stack_b);
	push_a(stack_a, stack_b);
}
