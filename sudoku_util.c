/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 17:02:04 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 19:01:31 by nkhaldi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"sudoku.h"

void		copy_solution(char **nums, t_solution *t_sol)
{
	int	line;
	int	letter;
	int	overall;

	line = 0;
	overall = 0;
	t_sol->solution = (char*)malloc((LEN * LEN + 1) * sizeof(char));
	while (line < LEN)
	{
		letter = 0;
		while (letter < LEN)
		{
			t_sol->solution[overall] = nums[line][letter];
			overall++;
			letter++;
		}
		line++;
	}
	t_sol->solution[overall] = '\0';
	t_sol->solved = SOLVED;
}

void		gen_collisions(char **nums, int (*collisions)[9], int r, int c)
{
	int	i;

	i = 0;
	while (i < LEN)
	{
		if (nums[r][i] != '.')
			(*collisions)[nums[r][i] - '1'] = 1;
		i++;
	}
	i = 0;
	while (i < LEN)
	{
		if (nums[i][c] != '.')
			(*collisions)[nums[i][c] - '1'] = 1;
		i++;
	}
	i = 0;
	while (i < LEN)
	{
		if (nums[r - r % 3 + i / 3][c - c % 3 + i % 3] != '.')
			(*collisions)[nums[r - r % 3 + i / 3][c - c % 3 + i % 3] - '1'] = 1;
		i++;
	}
}
