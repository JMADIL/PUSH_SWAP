/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajamoun <ajamoun@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 06:15:05 by ajamoun           #+#    #+#             */
/*   Updated: 2025/03/29 06:19:44 by ajamoun          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>

// libc - functions
char	**ft_split(char const *s, char c);
char	*ft_strchr(const char *str, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size);
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
int		ft_isdigit(int x);
void	ft_free(char **arr);
void	*ft_memcpy(void *dst, const void *src, size_t n);
// push_swap - functions

int		*pars_args(int ac, char **av, int *size);
int		has_duplicates(int *nums, int count);

#endif