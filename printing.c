/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 11:43:16 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 21:27:22 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		print_sudoku(char *solution)
{
	int		i;

	i = 0;
	while (solution[i])
	{
		ft_putchar(solution[i]);
		if ((i + 1) % LEN == 0)
			ft_putchar('\n');
		else
			ft_putchar(' ');
		i++;
	}
}
