/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 05:29:33 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:37:00 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	create_pipes(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < proc->n_pipes)
	{
		if (pipe(proc->pipe_fd[i]) < 0)
			return (err_msg("Pipe failed", NULL, NULL, 0));
		i++;
	}
	return (1);
}

int	create_pipes_array(t_data *data)
{
	int		i;
	t_proc	*proc;

	proc = data->proc;
	i = 0;
	proc->n_pipes = pipe_count(data->cmd);
	if (proc->n_pipes <= 0)
	{
		proc->n_pipes = 0;
		return (1);
	}
	proc->pipe_fd = ft_calloc(proc->n_pipes + 1, sizeof(int *));
	if (!proc->pipe_fd)
		return (0);
	while (i < proc->n_pipes)
	{
		proc->pipe_fd[i] = ft_calloc(2, sizeof(int));
		if (!proc->pipe_fd[i])
			return (free_int_tab(proc->pipe_fd, i), 0);
		i++;
	}
	proc->pipe_fd[i] = 0;
	if (!create_pipes(proc))
		return (free_int_tab(proc->pipe_fd, proc->n_pipes), 0);
	return (1);
}

void	close_pipes(t_proc *proc)
{
	int	i;

	i = 0;
	while (i < proc->n_pipes)
	{
		close(proc->pipe_fd[i][0]);
		close(proc->pipe_fd[i][1]);
		i++;
	}
}
