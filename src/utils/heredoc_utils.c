/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 09:51:46 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:57:24 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_last_heredoc(t_data *data, t_cmd *cmd, int cmd_pos)
{
	int		count;

	count = 0;
	while (cmd->type && cmd_pos < count_tokens(data, cmd->index))
	{
		if (cmd->type[cmd_pos] == HERE)
			count++;
		cmd_pos++;
	}
	if (count > 1)
		return (0);
	return (1);
}

int	count_all_heredoc(t_data *data)
{
	int		count;
	t_cmd	*cmd;
	int		i;

	count = 0;
	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->type && cmd->token[i])
		{
			if (cmd->type[i] == HERE)
				count++;
			i++;
		}
		cmd = cmd->next;
	}
	data->proc->n_heredoc = count;
	if (data->proc->n_heredoc > 0)
	{
		data->proc->fd_heredoc = ft_calloc(count, sizeof(int));
		if (!data->proc->fd_heredoc)
			return (0);
	}
	return (count);
}
