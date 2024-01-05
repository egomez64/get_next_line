/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:55:38 by egomez            #+#    #+#             */
/*   Updated: 2023/12/06 15:09:15 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stddef.h>

struct s_stack
{
	char	*stock;
	char	*buff;
	char	ateof;
};

char	*get_next_line(int fd);
char	*ft_strjoin(char *s1, char const *s2);
char	*ft_strchr(const char *s, int c);
int		next_stock(int fd, struct s_stack *result);
char	*clean_stock(char *stock);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
char	*ft_strdup(const char *src);
void	free_result(struct s_stack *result);
int		verif(struct s_stack *result, int fd);
#endif
