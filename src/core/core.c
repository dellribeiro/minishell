/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 05:21:17 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:16:35 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	reset_data(t_data *data, char *str)
{
	t_envp	*tmp;

	ft_free(str);
	if (data->list)
	{
		free_list(data->list);
		data->list = NULL;
	}
	if (data->cmd)
	{
		free_cmd(data->cmd);
		data->cmd = NULL;
	}
	if (data->proc)
	{
		free_int_tab(data->proc->pipe_fd, data->proc->n_pipes);
		if (data->proc->n_heredoc > 0)
			ft_free(data->proc->fd_heredoc);
		ft_free(data->proc->pid);
	}
	tmp = search_node(data->envp, "PATH");
	if (tmp)
		data->env_path = tmp->tab[1];
	else
		data->env_path = NULL;
}

char	*get_readline(t_data *data, char *str)
{
	str = readline("🔥\033[31;1mHellShell$> \033[m" );
	if (!str)
	{
		rl_clear_history();
		free_data_proc(data);
		write(STDERR_FILENO, "exit\n", 5);
		exit(g_return_val);
	}
	add_history(str);
	return (str);
}

void	get_prompt(char **envp)
{
	char	*str;
	t_data	*data;

	data = create_data(envp);
	str = NULL;
	while (42)
	{
		if (g_return_val == -126)
			g_return_val = 130;
		str = get_readline(data, str);
		if (!str)
			return ;
		if (check_quotes_ret(str))
			return (free_data_proc(data), get_prompt(envp));
		if (!ft_split(str, data))
			return (get_prompt(envp));
		if (!parsing(data))
			return (free_data_proc(data), get_prompt(envp));
		if (get_cmd_struct(data))
			return (get_prompt(envp));
		if (!execution(data))
			return (free_data(data));
		reset_data(data, str);
	}
}
