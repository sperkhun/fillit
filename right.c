/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:03:28 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/17 22:03:44 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		type1(char *s, t_list *lst)
{
	if (*(s + 6) == *s && *(s + 7) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = 1;
		lst->data->i[1] = 1;
		lst->data->j[1] = 2;
	}
	else if (*(s + 3) == *s)
	{
		lst->data->i[0] = 0;
		lst->data->j[0] = 2;
		lst->data->i[1] = 0;
		lst->data->j[1] = 3;
	}
	else if (*(s + 2) == *s && *(s + 6) == *s)
	{
		lst->data->i[0] = 0;
		lst->data->j[0] = 2;
		lst->data->i[1] = 1;
		lst->data->j[1] = 1;
	}
	else
		return (0);
	return (1);
}

int		type2(char *s, t_list *lst)
{
	if (*(s + 2) == *s && *(s + 7) == *s)
	{
		lst->data->i[0] = 0;
		lst->data->j[0] = 2;
		lst->data->i[1] = 1;
		lst->data->j[1] = 2;
	}
	else if (*(s + 11) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = 1;
		lst->data->i[1] = 2;
		lst->data->j[1] = 1;
	}
	else
		return (0);
	return (1);
}

int		right(t_list **lst)
{
	char *s;

	s = (*lst)->content;
	while (*s)
	{
		if (ft_isalpha(*s))
			break ;
		s++;
	}
	if (*(s + 1) == *s)
	{
		if (type1(s, *lst))
			return (1);
		if (type2(s, *lst))
			return (1);
	}
	return (0);
}
