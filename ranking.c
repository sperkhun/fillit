/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ranking.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:45:55 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/14 13:59:23 by tbondare         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		place_check(t_prmt prmt, int i, int j)
{
	int a;
	int y;
	int x;

	a = 0;
	if (prmt.map[i][j] != '.')
		return (0);
	while (a < 3)
	{
		y = prmt.lst->data->i[a];
		x = prmt.lst->data->j[a];
		if (!(i + y >= 0 && j + x >= 0 && i + y < prmt.size_map
				&& j + x < prmt.size_map) || prmt.map[i + y][j + x] != '.')
			return (0);
		a++;
	}
	return (1);
}

void	push_tetr(t_prmt prmt, int i, int j)
{
	int x;
	int y;
	int a;

	a = 0;
	prmt.map[i][j] = prmt.lst->data->letter;
	while (a < 3)
	{
		y = prmt.lst->data->i[a];
		x = prmt.lst->data->j[a];
		prmt.map[i + y][j + x] = prmt.lst->data->letter;
		a++;
	}
}

void	del_tetr(t_prmt prmt, int i, int j)
{
	int x;
	int y;
	int a;

	a = 0;
	prmt.map[i][j] = '.';
	while (a < 3)
	{
		y = prmt.lst->data->i[a];
		x = prmt.lst->data->j[a];
		prmt.map[i + y][j + x] = '.';
		a++;
	}
}

int		ranking(t_prmt prmt)
{
	int		i;
	int		j;
	t_prmt	p;

	i = 0;
	j = 0;
	while (j < prmt.size_map && i < prmt.size_map)
	{
		if (place_check(prmt, i, j))
		{
			push_tetr(prmt, i, j);
			if (prmt.lst->next == NULL)
				return (1);
			p = prmt;
			p.lst = p.lst->next;
			if (ranking(p))
				return (1);
			del_tetr(prmt, i, j);
		}
		j++;
		j == prmt.size_map ? j = 0 : 0;
		j == 0 ? i++ : 0;
	}
	return (0);
}
