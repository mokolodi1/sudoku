/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 11:18:05 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 19:04:17 by nkhaldi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

/*
** Calculates possible values of a cell, allocates memory for them
** I could optimize checking further!
** returns: 1 if it can be that, 0 if not
*/

char		*possible_chars(char **nums, int r, int c)
{
	int		i;
	int		p;
	int		collisions[9];
	char	*possible;

	i = 0;
	while (i < LEN)
		collisions[i++] = 0;
	gen_collisions(nums, &collisions, r, c);
	p = 0;
	i = 0;
	possible = (char*)malloc((LEN + 1) * sizeof(char));
	while (i < LEN)
	{
		if (!collisions[i])
		{
			possible[p] = i + '1';
			p++;
		}
		i++;
	}
	possible[i] = '\0';
	return (possible);
}

/*
** Calls the solve function with the next cell to solve
*/

int			call_with_next_num(char **nums, int row, int col, t_solution *t_sol)
{
	if (col == LEN - 1)
	{
		if (row == LEN - 1)
			return (SOLVED);
		else
			return (solve(nums, row + 1, 0, t_sol));
	}
	return (solve(nums, row, col + 1, t_sol));
}

/*
** Recursively solves sudoku with backtracking
**	nums		array we're working with
**	row			current row
**	col			current column
**	t_sol		holds solved and solution
**
** returns: 0 if zero or more than one solution ; 1 if there is one solution
*/

int			solve(char **nums, int row, int col, t_solution *t_sol)
{
	int		i;
	int		ret_value;
	char	*possible;

	if (nums[row][col] != '.')
		return (call_with_next_num(nums, row, col, t_sol));
	i = 0;
	possible = possible_chars(nums, row, col);
	while ((nums[row][col] = possible[i]))
	{
		ret_value = solve(nums, row, col, t_sol);
		if (ret_value == MULTIPLE)
			return (MULTIPLE);
		if (ret_value == SOLVED)
		{
			if (t_sol->solved == SOLVED)
				return (MULTIPLE);
			else
				copy_solution(nums, t_sol);
		}
		i++;
	}
	nums[row][col] = '.';
	free(possible);
	return (INCONCLUSIVE);
}

/*
** Actually does sudoku with parameters
** returns: NULL if error, grid of otherwise
*/

char		*sudoku(char **nums)
{
	int			ret_val;
	t_solution	t_sol;

	t_sol.solved = INCONCLUSIVE;
	ret_val = solve(nums, 0, 0, &t_sol);
	printf("ret_val: %d\n", ret_val);
	printf("solved: %d\n", t_sol.solved);
	if ((ret_val == INCONCLUSIVE && t_sol.solved == 0) || ret_val == MULTIPLE)
		return (NULL);
	return (t_sol.solution);
}
