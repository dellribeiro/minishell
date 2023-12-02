/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 08:19:05 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:35:55 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	unset_option(t_data *data, char *arg)
{
	t_envp	*before;
	t_envp	*node;

	before = data->envp;
	node = search_node(data->envp, arg);
	if (node)
	{
		while (before->next && !ft_strcmp(before->next->tab[0], arg))
			before = before->next;
		if (!before->next)
			data->envp = node->next;
		else
			before->next = node->next;
		free_tab(node->tab);
		ft_free(node);
	}
}

int	ft_unset(t_data *data, char **args)
{
	int		i;

	i = 0;
	if (!args || !args[0])
		return (0);
	while (args[i])
	{
		unset_option(data, args[i]);
		i++;
	}
	return (0);
}
