/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 21:43:55 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/17 21:44:11 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		type(char *s, t_list *lst)
{
	if (*(s + 6) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = 1;
	}
	else if (*(s + 10) == *s)
	{
		lst->data->i[0] = 2;
		lst->data->j[0] = 0;
	}
	else if (*(s + 2) == *s)
	{
		lst->data->i[0] = 0;
		lst->data->j[0] = 2;
	}
	else if (*(s + 4) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = -1;
	}
	else
		return (0);
	return (1);
}

int		randd(t_list **lst)
{
	char *s;

	s = (*lst)->content;
	while (*s)
	{
		if (ft_isalpha(*s))
			break ;
		s++;
	}
	if (*(s + 1) == *s && *(s + 5) == *s)
	{
		if (type(s, *lst))
			return (1);
	}
	return (0);
}
