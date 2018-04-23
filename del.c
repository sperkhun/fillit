/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/17 19:21:55 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/17 19:22:31 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	del(void *content, size_t content_size, t_content *data)
{
	if (!content || !data)
		return ;
	content_size = 0;
	free(content);
	free(data);
}
