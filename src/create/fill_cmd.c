/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 09:26:02 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:36:40 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_list	*fill_cmd_struct(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	if (tmp->type == 1)
	{
		if (is_cmd(data, cmd, tmp->str, data->env_path) && cmd->cmd == NULL)
			handle_cmd(data, cmd, tmp, j);
		else if (cmd->cmd == NULL && (*j) == 0)
		{
			cmd->cmd = ft_strndup(tmp->str, 0);
			cmd->opt[(*j)] = tmp->str;
			(*j)++;
		}
		else
		{
			cmd->opt[(*j)] = tmp->str;
			(*j)++;
		}
		tmp = tmp->next;
		return (tmp);
	}
	return (tmp);
}

t_list	*fill_cmd_tokens(t_cmd *cmd, t_list *tmp, int *k)
{
	if (tmp && tmp->type != 1 && tmp->type != 6 && tmp->next)
	{
		cmd->type[(*k)] = tmp->type;
		tmp = tmp->next;
		cmd->token[(*k)] = tmp->str;
		(*k)++;
		tmp = tmp->next;
	}
	else if (tmp && tmp->type != 1 && tmp->type != 6 && !tmp->next)
	{
		cmd->type[(*k)] = tmp->type;
		cmd->token[(*k)] = NULL;
		(*k)++;
		tmp = tmp->next;
	}
	return (tmp);
}

void	handle_cmd(t_data *data, t_cmd *cmd, t_list *tmp, int *j)
{
	cmd->cmd = ft_strndup(tmp->str, 0);
	if (!is_builtin(tmp->str))
	{
		cmd->opt[(*j)] = tmp->str;
		(*j)++;
		find_cmd_path(data, cmd, data->env_path);
	}
}
