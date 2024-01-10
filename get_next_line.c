/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:14:39 by egomez            #+#    #+#             */
/*   Updated: 2023/12/12 14:41:25 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*clean_stock(char *stock);
static int	verif(struct s_stack *result, int fd);
static char	*extract_line(struct s_stack *result);
static int	next_stock(int fd, struct s_stack *result);

static int	verif(struct s_stack *result, int fd)
{
	if (result->buff == 0)
	{
		result->buff = malloc(sizeof (char) * BUFFER_SIZE + 1);
		if (!result->buff)
			return (0);
	}
	if (!result->stock)
	{
		if (!next_stock(fd, result))
			return (0);
	}
	else if (!ft_strchr(result->stock, '\n'))
	{
		if (!next_stock(fd, result))
			return (0);
	}
	return (1);
}

static char	*extract_line(struct s_stack *result)
{
	char	*line;
	int		i;

	i = 0;
	while (result->stock[i] != 0 && result->stock[i] != '\n')
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (result->stock[i] != '\n' && result->stock[i] != 0)
	{
		line[i] = result->stock[i];
		i++;
	}
	if (result->stock[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	return (line);
}

static int	next_stock(int fd, struct s_stack *result)
{
	int	bytes;

	while ((!result->stock || !ft_strchr(result->stock, '\n'))
		&& result->ateof != 1)
	{
		bytes = read(fd, result->buff, BUFFER_SIZE);
		if (bytes == -1)
			return (0);
		if (bytes != BUFFER_SIZE)
			result->ateof = 1;
		result->buff[bytes] = 0;
		result->stock = ft_strjoin(result->stock, result->buff);
		if (result->stock[0] == 0)
			return (0);
	}
	return (1);
}

static char	*clean_stock(char *stock)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (stock[len] && stock[len] != '\n')
		len++;
	if (stock[len] == 0)
		stock[0] = 0;
	else
	{
		len++;
		while (stock[len] != 0)
		{
			stock[i] = stock[len];
			i++;
			len++;
		}
		stock[i] = 0;
	}
	return (stock);
}

char	*get_next_line(int fd)
{
	static struct s_stack	result;
	char					*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (result.ateof == 1 && (result.stock == NULL || result.stock[0] == 0))
	{
		free_result(&result);
		return (NULL);
	}
	if (!verif(&result, fd))
	{
		free_result(&result);
		return (NULL);
	}
	line = extract_line(&result);
	clean_stock(result.stock);
	return (line);
}
