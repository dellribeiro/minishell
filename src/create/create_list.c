/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 04:24:42 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:36:28 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*ft_lstnew(char *str, int type)
{
	t_list	*list;

	list = ft_calloc(1, sizeof(t_list));
	if (!list)
		return (NULL);
	list->str = str;
	list->type = type;
	list->dollar = NULL;
	list->next = NULL;
	return (list);
}

t_list	*ft_lstlast(t_list *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

int	add_last_list(t_data *data, char *str)
{
	t_list	*new;
	t_list	*last;

	new = ft_lstnew(str, redir_type(str));
	if (!new)
		return (0);
	last = ft_lstlast(data->list);
	if (!last)
	{
		data->list = new;
		return (1);
	}
	last->next = new;
	return (1);
}
