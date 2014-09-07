/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 10:11:11 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 18:58:46 by nkhaldi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

/*
** Checks input for errors
** - incorrect size
** - char not between 0 and 9 (inclusive)
** returns: 0 if input is good, 1 if error
*/

int			input_check(int size, char **nums)
{
	int		word;
	int		letter;
	char	curr;

	if (size != LEN)
		return (1);
	word = 0;
	while (word < LEN)
	{
		letter = 0;
		while (letter < LEN)
		{
			curr = nums[word][letter];
			if (!((curr == '.') || (curr <= '9' && curr >= '1')))
				return (1);
			letter++;
		}
		if (nums[word][LEN] != '\0')
			return (1);
		word++;
	}
	return (0);
}

/*
** The main function: everything happens from here
*/

int			main(int argc, char **argv)
{
	char		*result;

	argc--;
	argv++;
	if (!input_check(argc, argv))
	{
		result = sudoku(argv);
		if (result == NULL)
			ft_putstr("Erreur with sudoku\n");
		else
			print_sudoku(result);
	}
	else
		ft_putstr("Erreur with input\n");
	return (0);
}
