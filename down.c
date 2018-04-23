/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   down.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 22:11:40 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/17 22:12:03 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		type3(char *s, t_list *lst)
{
	if (*(s + 6) == *s && *(s + 4) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = -1;
		lst->data->i[1] = 1;
		lst->data->j[1] = 1;
	}
	else if (*(s + 11) == *s && *(s + 6) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = 1;
		lst->data->i[1] = 2;
		lst->data->j[1] = 1;
	}
	else if (*(s + 9) == *s && *(s + 4) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = -1;
		lst->data->i[1] = 2;
		lst->data->j[1] = -1;
	}
	else
		return (0);
	return (1);
}

int		type4(char *s, t_list *lst)
{
	if (*(s + 15) == *s)
	{
		lst->data->i[0] = 2;
		lst->data->j[0] = 0;
		lst->data->i[1] = 3;
		lst->data->j[1] = 0;
	}
	else if (*(s + 6) == *s && *(s + 10) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = 1;
		lst->data->i[1] = 2;
		lst->data->j[1] = 0;
	}
	else if (*(s + 4) == *s && *(s + 10) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = -1;
		lst->data->i[1] = 2;
		lst->data->j[1] = 0;
	}
	else
		return (0);
	return (1);
}

int		type5(char *s, t_list *lst)
{
	if (*(s + 7) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = 1;
		lst->data->i[1] = 1;
		lst->data->j[1] = 2;
	}
	else if (*(s + 3) == *s && *(s + 4) == *s)
	{
		lst->data->i[0] = 1;
		lst->data->j[0] = -1;
		lst->data->i[1] = 1;
		lst->data->j[1] = -2;
	}
	else
		return (0);
	return (1);
}

int		type6(char *s, t_list *lst)
{
	if (*(s + 11) == *s && *(s + 10) == *s)
	{
		lst->data->i[0] = 2;
		lst->data->j[0] = 1;
		lst->data->i[1] = 2;
		lst->data->j[1] = 0;
	}
	else if (*(s + 9) == *s && *(s + 10) == *s)
	{
		lst->data->i[0] = 2;
		lst->data->j[0] = -1;
		lst->data->i[1] = 2;
		lst->data->j[1] = 0;
	}
	else
		return (0);
	return (1);
}

int		down(t_list **lst)
{
	char *s;

	s = (*lst)->content;
	while (*s)
	{
		if (ft_isalpha(*s))
			break ;
		s++;
	}
	if (*(s + 5) == *s)
	{
		if (type3(s, *lst))
			return (1);
		if (type4(s, *lst))
			return (1);
		if (type5(s, *lst))
			return (1);
		if (type6(s, *lst))
			return (1);
	}
	return (0);
}
