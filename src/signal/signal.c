/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 01:11:58 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 04:07:43 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sigquit(int sig_quit)
{
	(void)sig_quit;
	g_return_val = 131;
	ft_putstr("Quit (core dumped)\n");
}

void	handle_sigsegv(int sig_segv)
{
	(void)sig_segv;
	err_msg(NULL, "exit", NULL, 1);
	exit(1);
}

void	handle_sigint(int sig_int)
{
	(void)sig_int;
	g_return_val = 130;
	ft_putstr("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

void	handle_signal(void)
{
	signal(SIGQUIT, SIG_IGN);
	signal(SIGTSTP, SIG_IGN);
	signal(SIGSEGV, handle_sigsegv);
	signal(SIGINT, handle_sigint);
}
