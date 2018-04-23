/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 15:41:58 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/11 21:59:57 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		size_map(char **map)
{
	int i;

	i = 0;
	while (*map)
	{
		i++;
		map++;
	}
	return (i);
}

void	print_map(char **map)
{
	while (*map)
	{
		ft_putstr(*map);
		ft_putchar('\n');
		map++;
	}
}

int		fillit(char *buf)
{
	t_list	*lst;
	char	**map;
	t_prmt	prmt;
	int		cnt;

	cnt = 0;
	if (!vldfile(buf) || !(lst = division(buf)))
		return (0);
	if (!(map = square(lst, cnt)))
		return (0);
	prmt.lst = lst;
	prmt.map = map;
	prmt.size_map = size_map(map);
	while (!(ranking(prmt)) && cnt++ < 4)
	{
		ft_arrdel(map, size_map(map));
		if (cnt == 3 || !(map = square(lst, cnt)))
			return (0);
		prmt.map = map;
		prmt.size_map = size_map(map);
	}
	print_map(map);
	ft_arrdel(map, size_map(map));
	ft_lstdel(&lst, &del);
	return (1);
}
