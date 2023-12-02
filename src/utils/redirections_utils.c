/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 08:51:57 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:57:37 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	is_token(t_cmd *cmd, int type)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return (0);
	while (cmd->token[i])
	{
		if (cmd->type[i] == type)
			return (1);
		i++;
	}
	return (0);
}

int	is_last_cmd_token_out(t_data *data, int index)
{
	t_cmd	*prev;

	prev = data->cmd;
	if (index == 0)
		return (0);
	while (prev && prev->index != index - 1)
		prev = prev->next;
	if (!prev)
		return (0);
	if (is_token(prev, OUT))
		return (1);
	return (0);
}

int	create_files(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (count_tokens(data, cmd->index) > 0)
	{
		while (cmd->token && cmd->token[i])
		{
			if (!handle_token_redir(data, cmd, i, 0))
				return (1);
			i++;
		}
	}
	return (0);
}
