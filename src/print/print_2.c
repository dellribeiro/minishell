/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: whendrix <whendrix@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 01:41:09 by whendrix          #+#    #+#             */
/*   Updated: 2023/08/20 03:41:22 by whendrix         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	print_tab_index(int *tab, int n)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (i < n)
	{
		printf("tab[%d] : %d\n", i, tab[i]);
		i++;
	}
}

void	print_int_tab(t_data *data, int *tab)
{
	int	n;
	int	i;

	if (!tab)
		return ;
	n = count_tokens(data, 0);
	i = 0;
	printf("INT TAB SIZE : %d\n", n);
	while (i < n)
	{
		printf("tab[%d] : %d\n", i, tab[i]);
		i++;
	}
}
