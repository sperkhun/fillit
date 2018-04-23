/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libfil.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sperkhun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/05 18:14:01 by sperkhun          #+#    #+#             */
/*   Updated: 2017/12/09 17:43:47 by sperkhun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H

# define FILLIT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <stdlib.h>

typedef struct		s_content
{
	int				i[3];
	int				j[3];
	char			letter;
}					t_content;

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
	t_content		*data;
}					t_list;

typedef struct		s_prmt
{
	t_list			*lst;
	char			**map;
	int				size_map;

}					t_prmt;

int					vldfile(char *buf);
char				**square(t_list *lst, int a);
int					ranking(t_prmt prmt);
t_list				*division(char *buf);
void				del(void *content, size_t content_size, t_content *data);
int					fillit(char *buf);
int					randd(t_list **lst);
int					right(t_list **lst);
int					down(t_list **lst);
void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strncpy(char *dst, const char *src, size_t len);
int					ft_isalpha(int c);
char				*ft_strnew(size_t size);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t,\
															t_content *));
void				ft_arrdel(char **str, size_t a);
size_t				ft_lstlen(t_list *lst);
void				ft_lstend(t_list **alst, t_list *new);

#endif
