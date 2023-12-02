/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 05:50:42 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:51:00 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	count_redir(t_data *data, int n)
{
	t_list	*tmp;
	int		count;
	int		index;

	tmp = data->list;
	count = 0;
	index = 0;
	if (tmp->type != 1 && !tmp->next)
		return (1);
	while (tmp)
	{
		if (tmp && (tmp->type != WORD && tmp->type != PIPE) && index == n)
			count++;
		else if (tmp->type == PIPE)
			index++;
		if (tmp)
			tmp = tmp->next;
	}
	return (count);
}

int	count_tokens(t_data *data, int n)
{
	t_list	*tmp;
	int		count;
	int		index;

	tmp = data->list;
	count = 0;
	index = 0;
	if (tmp->type != 1 && !tmp->next)
		return (1);
	while (tmp)
	{
		if (tmp && (tmp->type != WORD && tmp->type != PIPE) && index == n
			&& tmp->next && tmp->next->type == WORD)
		{
			tmp = tmp->next;
			count++;
		}
		else if (tmp->type == PIPE)
			index++;
		if (tmp)
			tmp = tmp->next;
	}
	return (count);
}

int	words_to_pipe(t_data *data, int n)
{
	t_list	*tmp;
	int		count;
	int		cappuccino;
	int		index;

	tmp = data->list;
	count = 0;
	index = 0;
	cappuccino = 0;
	while (tmp)
	{
		if (tmp->type == 1 && is_cmd(data, data->cmd, tmp->str, data->env_path)
			&& cappuccino == 0 && index == n)
			count += command_or_builtin(tmp->str, &cappuccino);
		else if (tmp->type == WORD && index == n)
			count++;
		else if (tmp->type != WORD && tmp->type != PIPE && index == n)
			count -= 1;
		else if (tmp->type == PIPE)
			index++;
		tmp = tmp->next;
	}
	if (count <= -1)
		return (0);
	return (count);
}

int	command_or_builtin(char *str, int *cappuccino)
{
	(*cappuccino)++;
	if (is_builtin(str))
		return (0);
	else
		return (1);
}
