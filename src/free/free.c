/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 08:31:07 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:37:13 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

void	free_list(t_list *list)
{
	t_list	*save;

	save = list;
	while (list)
	{
		list = list->next;
		if (save->str)
			ft_free(save->str);
		if (save->dollar)
			ft_free(save->dollar);
		ft_free(save);
		save = list;
	}
}

void	free_envp(t_envp *envp)
{
	t_envp	*save;

	save = envp;
	while (envp)
	{
		envp = envp->next;
		if (save->tab)
			free_tab(save->tab);
		ft_free(save);
		save = envp;
	}
}

void	free_cmd(t_cmd *cmd)
{
	t_cmd	*save;

	save = cmd;
	while (cmd)
	{
		cmd = cmd->next;
		if (save->cmd)
			ft_free(save->cmd);
		if (save->cmd_path)
			ft_free(save->cmd_path);
		if (save->opt)
			ft_free(save->opt);
		if (save->type)
			ft_free(save->type);
		if (save->token)
			ft_free(save->token);
		ft_free(save);
		save = cmd;
	}
}

void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->list)
		free_list(data->list);
	if (data->cmd)
		free_cmd(data->cmd);
	if (data->envp)
		free_envp(data->envp);
	if (data->proc)
		free_proc(data->proc);
	ft_free(data);
}
