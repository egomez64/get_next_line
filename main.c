/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 14:45:14 by egomez            #+#    #+#             */
/*   Updated: 2023/12/01 14:55:26 by egomez           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	char	*result;
	int		i;

	i = 0;
	fd = open("test.txt", O_RDONLY);
	result = get_next_line(fd);
	while (result)
	{
		printf("%s", result);
		result = get_next_line(fd);
		i++;
	}
	close(fd);
	return (0);
}
