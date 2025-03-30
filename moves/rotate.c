/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 03:07:54 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/30 03:23:23 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	if (!(*stack) || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_lstlast(*stack);
	*stack = first->next;
	last->next = first;
	first->next = NULL;
}
