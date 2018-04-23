/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vldfile.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:09:30 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/11 14:52:14 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	valstr(char *buf, int *i)
{
	int a;

	a = 4;
	while ((buf[*i] == '.' || buf[*i] == '#') && a && buf[*i])
	{
		*i += 1;
		a--;
	}
	if (buf[*i] == '\n' && !a)
		*i += 1;
	else
		*i = 0;
}

int		isconnect(char *buf, int delim)
{
	int c;

	c = 0;
	*(buf + 1) == '#' ? c++ : 0;
	if (delim)
		*(buf - 1) == '#' ? c++ : 0;
	if (delim < 16)
		*(buf + 5) == '#' ? c++ : 0;
	if (delim > 4)
		*(buf - 5) == '#' ? c++ : 0;
	return (c);
}

int		vldtetra(char *buf)
{
	int hash;
	int cnct;
	int delim;

	while (*buf)
	{
		hash = 0;
		cnct = 0;
		delim = 0;
		while (delim < 20 && *buf)
		{
			if (*buf == '#')
			{
				hash++;
				cnct += isconnect(buf, delim);
			}
			buf++;
			delim++;
		}
		if (hash != 4 || (cnct != 6 && cnct != 8))
			return (0);
		if (*buf)
			buf++;
	}
	return (1);
}

int		vldfile(char *buf)
{
	int		i;
	int		a;

	i = 0;
	while (buf[i])
	{
		a = 4;
		while (a--)
		{
			valstr(buf, &i);
			if (!i)
				break ;
		}
		if (((buf[i] == '\n' && buf[i + 1] == '\0') || buf[i] != '\n') && a)
			break ;
		i++;
	}
	if (buf[0] == '\0' || ft_strlen(buf) > 545 || buf[i] || !vldtetra(buf))
		return (0);
	return (1);
}
