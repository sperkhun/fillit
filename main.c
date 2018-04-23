/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 18:36:03 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/17 18:36:33 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#define BUF_SIZE 546

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char	buf[BUF_SIZE];

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit sample_file");
		ft_putchar('\n');
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	ret = read(fd, buf, BUF_SIZE);
	buf[ret] = '\0';
	if (!fillit(buf))
	{
		ft_putstr("error");
		ft_putchar('\n');
		return (0);
	}
	close(fd);
	return (0);
}
