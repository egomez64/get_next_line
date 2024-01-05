/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:44:56 by egomez            #+#    #+#             */
/*   Updated: 2023/12/12 14:45:00 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}*/

void	free_result(struct s_stack *result)
{
	if (result->stock)
	{
		free (result->stock);
		result->stock = 0;
	}
	if (result->buff)
	{
		free (result->buff);
		result->buff = 0;
	}
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (c == '\0')
		return ((char *)s);
	return (0);
}

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	x;
	int		y;

	x = 0;
	i = 0;
	y = 0;
	while (src[y] != '\0')
		y++;
	if (size == 0)
		return (y + size);
	while (src[x] != '\0')
		x++;
	while (dst[i] != '\0' && i < size)
		i++;
	j = i;
	while (src[i - j] != '\0' && i < size - 1)
	{
		dst[i] = src[i - j];
		i++;
	}
	if (j < size)
		dst[i] = '\0';
	return (j + x);
}

char	*ft_strdup(const char *src)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = 0;
	while (src[size] != '\0')
		size++;
	copy = malloc(sizeof(char) * size + 1);
	if (copy == NULL)
		return (NULL);
	while (src[i] != 0)
	{
		copy[i] = src[i];
		i++;
	}
	copy[i] = 0;
	return (copy);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	int		y;
	char	*newchain;
	int		i;

	i = 0;
	y = 0;
	if (!s2)
		return (NULL);
	if (!s1)
	{
		newchain = ft_strdup(s2);
		return (newchain);
	}
	while (s1[i] != '\0')
		i++;
	while (s2[y] != '\0')
		y++;
	newchain = malloc(sizeof(char) * (i + y + 2));
	if (newchain == NULL)
		return (NULL);
	newchain[0] = 0;
	ft_strlcat(newchain, s1, (i + y + 1));
	ft_strlcat(newchain, s2, (i + y + 1));
	free (s1);
	return (newchain);
}
