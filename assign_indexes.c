/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign_indexes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 08:55:19 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/30 10:50:35 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	swap_elements(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
int	*list_to_numbers(t_list *stack_a, int size)
{
	int		*tab;
	int		i;
	t_list	*tmp;

	tmp = stack_a;
	i = 0;
	tab = malloc(size * sizeof(int));
	if (!tab)
		return (NULL);
	while (tmp)
	{
		tab[i] = tmp->content;
		tmp = tmp->next;
		i++;
	}
	return (tab);
}

int	*sort_tab(t_list *stack_a, int size)
{
	int	i;
	int	j;
	int	*tab;

	i = 0;
	tab = list_to_numbers(stack_a, size);
	if (!tab)
		return (NULL);
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				swap_elements(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}
void	init_index(t_list *stack_a)
{
	int i;
	int size;
	int *tab;
	t_list *tmp;

	size = ft_lstsize(stack_a);
	tmp = stack_a;
	tab = sort_tab(stack_a, size);
	if (!tab)
		return ;
	while (tmp)
	{
		i = 0;
		while (i < size)
		{
			if (tab[i] == tmp->content)
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(tab);
}