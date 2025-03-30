/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 02:46:39 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/30 03:06:18 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_list **dest, t_list **src)
{
	t_list	*top;

	if (!(*src))
		return ;
	top = *src;
	*src = top->next;
	top->next = *dest;
	*dest = top;
}
