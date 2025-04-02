/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:15:05 by ajamoun           #+#    #+#             */
/*   Updated: 2025/04/02 11:25:45 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	int				content;
	int				index;
	struct s_list	*next;
}					t_list;

// libc - functions
char				**ft_split(char const *s, char c);
char				*ft_strchr(const char *str, int c);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strdup(const char *s1);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *dest, const char *src, size_t dst_size);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
int					ft_atoi(const char *str);
int					ft_isdigit(int x);
void				ft_free(char **arr);
void				*ft_memcpy(void *dst, const void *src, size_t n);

// lst_utils - functions
t_list				*ft_lstlast(t_list *lst);
t_list				*ft_lstnew(int content);
void				ft_lstadd_back(t_list **lst, t_list *new_node);
int					ft_lstsize(t_list *lst);

// push_swap - functions
int					*pars_args(int ac, char **av, int *size);
int					has_duplicates(int *nums, int count);

// push_swap_moves
void				push(t_list **dest, t_list **src);
void				push_a(t_list **stack_a, t_list **stack_b);
void				push_b(t_list **stack_a, t_list **stack_b);
void				reverse_rotate(t_list **stack);
void				rra(t_list **stack_a);
void				rrb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				rotate(t_list **stack);
void				ra(t_list **stack_a);
void				rb(t_list **stack_b);
void				rr(t_list **stack_a, t_list **stack_b);
void				swap(t_list **stack);
void				sa(t_list **stack_a);
void				sb(t_list **stack_b);
void				ss(t_list **stack_a, t_list **stack_b);

// helper_fun
void				init_index(t_list *stack_a);
int					stack_is_sorted(t_list *lst);
int					get_min(t_list *list);

// sort_functions

void				sort_two_or_three(t_list **stack_a, int size);
void				sort_4_nums(t_list **stack_a, t_list **stack_b);
void				sort_5_nums(t_list **stack_a, t_list **stack_b);
void				radix_sort(t_list **stack_a, t_list **stack_b);

#endif