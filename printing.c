/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 11:43:16 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 17:47:39 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"printing.h"

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

/*
**	Prints a sudoku board
*/

void		print_sudoku(char *nums)
{
	int		i;		// need to do stuff here

	line = 0;
	while (line < LEN)
	{
		letter = 0;
		while (letter < LEN)
		{
			ft_putchar(nums[line][letter]);
			if (letter < LEN - 1)
				ft_putchar(' ');
			else
				ft_putchar('\n');
			letter++;
		}
		line++;
	}
}


