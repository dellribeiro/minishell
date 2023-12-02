/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/29 04:41:40 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:41:55 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	handle_sighere(int sig_segv)
{
	(void)sig_segv;
	printf("\n");
	g_return_val = -126;
	close(0);
}

void	handle_sigint_exec(void)
{
	signal(SIGINT, handle_exec);
}

void	handle_exec(int sig_int)
{
	(void)sig_int;
	g_return_val = 130;
	ft_putstr("\n");
}
