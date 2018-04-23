/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:31:14 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/11 20:44:59 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ifonetetra(t_list *lst)
{
	char *s;

	s = lst->content;
	while (*s)
	{
		if (*s == 'A')
		{
			if ((*(s + 2) == 'A' && *(s + 3) == 'A') ||\
				(*(s + 10) == 'A' && *(s + 15) == 'A'))
				return (4);
			else if (*(s + 1) == 'A' && *(s + 5) == 'A' && *(s + 6) == 'A')
				return (2);
			else
				break ;
		}
		s++;
	}
	return (3);
}

char	**square(t_list *lst, int a)
{
	size_t	cnt;
	size_t	i;
	char	**map;

	cnt = 3;
	i = 0;
	if (ft_lstlen(lst) == 1)
		cnt = ifonetetra(lst);
	while (cnt * cnt < ft_lstlen(lst) * 4)
		cnt++;
	if (!(map = (char**)malloc(sizeof(*map) * (cnt + 1 + a))))
		return (NULL);
	while (i < cnt + a)
	{
		if (!(map[i] = ft_strnew(cnt + a)))
			return (NULL);
		ft_memset(map[i], '.', cnt + a);
		i++;
	}
	map[i] = NULL;
	return (map);
}
