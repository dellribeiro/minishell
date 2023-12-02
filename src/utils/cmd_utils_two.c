/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils_two.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/02 08:50:19 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:50:32 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	add_back(t_data *data, t_cmd *cmd)
{
	t_cmd	*tmp;

	tmp = ft_cmdlast(data->cmd);
	if (!tmp)
	{
		data->cmd = cmd;
		return ;
	}
	tmp->next = cmd;
}

t_cmd	*ft_cmdnew(int index)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd = NULL;
	cmd->cmd_path = NULL;
	cmd->index = index;
	cmd->opt = NULL;
	cmd->token = NULL;
	cmd->type = 0;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*ft_cmdlast(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

int	pipe_count(t_cmd *cmd)
{
	int	i;

	i = 0;
	if (!cmd)
		return (0);
	while (cmd)
	{
		i++;
		cmd = cmd->next;
	}
	if (i > 0)
		i--;
	return (i);
}
