/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/06 10:11:11 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/06 23:18:45 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	<stdlib.h>
#include	<unistd.h>
#include	<stdio.h>					// remove this
#define		LEN					9
#define		INCONCLUSIVE		0
#define		TRUE				1
#define		MULTIPLE			2

int		solve(char **nums, int row, int col, int *solved);
void	print_sudoku(char **nums);

void	print_possible_chars(char *possible)
{
	printf("%c", possible[0]);
	printf("%c", possible[1]);
	printf("%c", possible[2]);
	printf("%c", possible[3]);
	printf("%c", possible[4]);
	printf("%c", possible[5]);
	printf("%c", possible[6]);
	printf("%c", possible[7]);
	printf("%c", possible[8]);
	printf("\n");
}

/*
** Calculates possible values of a cell, allocates memory for them
** I could optimize checking further!
** returns: 1 if it can be that, 0 if not
*/

char	*possible_chars(char **nums, int row, int col)
{
	int		i;
	int		poss_bin[9];
	char	*possible;

	printf("possible_chars: (%d, %d)\n", row, col);

	// this was added later
	i = 0;
	while (i < LEN)
		poss_bin[i++];
	i = 0;
	while (i < LEN)
	{
		if (nums[row][i] != '.')
			poss_bin[nums[row][i] - '1'] = 1;
		i++;
	}
	i = 0;
	while (i < LEN)
	{
		if (nums[i][col] != '.')
			poss_bin[nums[i][col] - '1'] = 1;
		i++;
	}
	
		


	// what was there before (below)
	possible = (char*)malloc(sizeof(char) * LEN);
	i = 0;
	while (i < LEN)
		possible[i++] = 0;
	i = 0;
	while (i < LEN)
	{
		if (nums[row][i] != '.')
			possible[nums[row][i] - '1'] = 1;
		i++;
	}
	i = 0;
	while (i < LEN)
	{
		if (nums[i][col] != '.')
			possible[nums[i][col] - '1'] = 1;
		i++;
	}
	i = 0;
	while (i < LEN)
	{
		if (nums[(row / 3) + (i % 3)][(col / 3) + (i % 3)] != '.')
			possible[nums[(row / 3) + (i % 3)][(col / 3) + (i % 3)] - '1'] = 1;
		i++;
	}
	printf("the characters: ");
	print_possible_chars(possible);
	printf("about to return from possible_chars\n");
	return possible;
}

/*
** Calls the solve function with the next cell to solve
*/

int		call_with_next_num(char **nums, int row, int col, int *solved)
{
	if (col == LEN - 1)
	{
		if (row == LEN - 1)
			return (1);
		else
		{
			printf("about to call solve with (%d, %d)\n", row + 1, 0);
			return (solve(nums, row + 1, 0, solved));
		}
	}
	return (solve(nums, row, col + 1, solved));
}

/*
** Recursively solves sudoku with backtracking
**	nums		array we're working with
**	row			current row
**	col			current column
**	solved		has it been solved already
**
** returns: 0 if zero or more than one solution ; 1 if there is one solution
*/

int		solve(char **nums, int row, int col, int *solved)
{
	int		i;
	int		ret_value;
	char	*possible;

	printf("solve: (%d, %d), solved=%d\n", row, col, *solved);
	print_sudoku(nums);
	
	if (nums[row][col] != '.')
	{
		printf("call with next num (%d, %d)\n", row, col);
		return call_with_next_num(nums, row, col, solved);
	}
	i = 0;
	possible = possible_chars(nums, row, col);
	while (i < LEN)		// while (possible[i])
	{
		nums[row][col] = possible[i] + '1';
		ret_value = solve(nums, row, col, solved);
		if (ret_value == MULTIPLE)
			return (MULTIPLE);
		if (ret_value == (TRUE))
		{
			if (*solved == TRUE)
				return (MULTIPLE);
			else
				*solved = TRUE;
		}
		i++;
	}
	nums[row][col] = '.';
	free(possible);
	return (0);
}

/*
** Actually does sudoku with parameters
** returns: NULL if error, grid of otherwise
*/

char	**sudoku(char **nums)
{
	int		ret_val;
	int		solved;

	solved = INCONCLUSIVE;
	ret_val = solve(nums, 0, 0, &solved);
	if (ret_val == INCONCLUSIVE || ret_val == MULTIPLE)
		return NULL;
	else
		return nums;
}

/*
** MAIN STUFF BELOW THIS LINE ==================================================
*/

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	print_sudoku(char **nums)
{
	int		line;
	int		letter;

	line = 0;
	while (line < LEN)
	{
		letter = 0;
		while (letter < LEN - 1)
		{
			ft_putchar(nums[line][letter]);
			ft_putchar(' ');
			letter++;
		}
		ft_putchar(nums[line][letter + 1]);
		ft_putchar('\n');
		line++;
	}
}

/*
** Checks input for errors
** - incorrect size
** - char not between 0 and 9 (inclusive)
** returns: 0 if input is good, 1 if error
*/

int		input_check(int size, char **nums)
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
			printf("word: %d;  letter: %d\n", word, letter);
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

int		main(int argc, char **argv)
{
	char **result;

	argc--;
	argv++;
	if (!input_check(argc, argv))
	{
		result = sudoku(argv);
		if (result == NULL)
			ft_putstr("Erreur with sudoku\n");
		else
			print_sudoku(argv);
	}
	else
		ft_putstr("Erreur with input\n");
	return (0);
}
