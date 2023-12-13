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

char	*next_stock(int fd, char *stock)
{
	int	bytes;
	char	*buff;
	
	if (fd < 0)
		return (NULL);
	buff = malloc(sizeof(char) * 42 + 2);
	if (!buff)
		return(NULL);
	buff[43] = 0;
	bytes = read(fd, buff, 42);
	stock = ft_strjoin(stock, buff);
	while (bytes != 0 && !ft_strchr(stock, '\n'))
	{
		bytes = read(fd, buff, 42);
		stock = ft_strjoin(stock, buff);
	}
	free(buff);
	return(stock);
}

char	*clean_stock(char *stock)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (stock[len] != '\n')
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
	static char	*stock;
	char	*line;
	int	i;

	line = 0;
	i = 0;
	stock = next_stock(fd, stock);
	while (stock[i] != '\n' && stock[i] != 0)
		i++;
	line = malloc(sizeof(char) * i + 2);
	if (!line)
		return (NULL);
	i = 0;
	while (stock[i] != '\n' && stock[i] != 0)
	{
		line[i] = stock[i];
		i++;
	}
	if (stock[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = 0;
	stock = clean_stock(stock);
	if (stock[0] == 0)
		free (stock);
	return (line);
}
