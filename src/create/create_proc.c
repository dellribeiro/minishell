/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_proc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/10 17:25:42 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:36:34 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

t_proc	*create_proc(void)
{
	t_proc	*proc;

	proc = ft_calloc(1, sizeof(t_proc));
	if (!proc)
		return (NULL);
	proc->n_pipes = 0;
	proc->n_heredoc = 0;
	proc->fd_heredoc = NULL;
	proc->pipe_fd = NULL;
	proc->fd_in = STDIN_FILENO;
	proc->fd_out = STDOUT_FILENO;
	proc->pid = NULL;
	return (proc);
}
