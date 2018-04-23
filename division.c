/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   division.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:13:54 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/10 20:02:43 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*change(char *str, int l)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '#')
			str[i] = l;
		i++;
	}
	return (str);
}

int		fill_data(t_list *lst, int l)
{
	if (!(lst->data = (t_content*)malloc(sizeof(t_content))))
		return (0);
	lst->data->letter = l;
	if (randd(&lst))
	{
		lst->data->i[1] = 0;
		lst->data->j[1] = 1;
		lst->data->i[2] = 1;
		lst->data->j[2] = 0;
	}
	else if (right(&lst))
	{
		lst->data->i[2] = 0;
		lst->data->j[2] = 1;
	}
	else if (down(&lst))
	{
		lst->data->i[2] = 1;
		lst->data->j[2] = 0;
	}
	return (1);
}

t_list	*division(char *buf)
{
	int		l;
	char	str[21];
	t_list	*new;
	t_list	*bgn;

	l = 65;
	ft_strncpy(str, buf, 20);
	str[20] = '\0';
	if (!(bgn = ft_lstnew(change(str, l), 21)))
		return (NULL);
	if (!(fill_data(bgn, l)))
		return (NULL);
	while (*(buf += 21) && *(buf - 1) != '\0')
	{
		l++;
		ft_strncpy(str, buf, 20);
		str[20] = '\0';
		if (!(new = ft_lstnew(change(str, l), 21)))
			return (NULL);
		if (!fill_data(new, l))
			return (NULL);
		ft_lstend(&bgn, new);
	}
	return (bgn);
}
