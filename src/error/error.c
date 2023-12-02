/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 07:27:26 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:36:47 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

int	err_msg(char *start, char *str, char *end, int ret)
{
	if (start)
		write(STDERR_FILENO, start, ft_strlen(start));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	if (end)
		write(STDERR_FILENO, end, ft_strlen(end));
	write(STDERR_FILENO, "\n", 1);
	return (ret);
}

int	error_cmd(char **cmd)
{	
	int	fd;
	DIR	*dir;
	int	ret;

	ret = 1;
	if (!cmd || !cmd[0])
		return (err_msg("minishell: ", NULL, ": command not found", 127));
	if (ft_strchr(cmd[0], '/'))
		return (err_msg("minishell: ", cmd[0], ": command not found", 127));
	fd = open(cmd[0], O_WRONLY);
	dir = opendir(cmd[0]);
	if (fd == -1 && dir == NULL)
		ret = err_msg("minishell: ", cmd[0], ": No such file or directory",
				127);
	else if (fd == -1 && dir != NULL)
		ret = err_msg("minishell: ", cmd[0], ": is a directory", 126);
	else if (fd != -1 && dir == NULL)
		ret = err_msg("minishell: ", cmd[0], ": Permission denied", 127);
	if (fd > 0)
		close(fd);
	if (dir)
		closedir(dir);
	return (ret);
}
