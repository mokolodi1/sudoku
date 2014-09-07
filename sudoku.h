/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 11:53:11 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 17:45:32 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SUDOKU_H
#define 	SUDOKU_H

#include	<stdlib.h>
#include	<stdio.h>		// nope
#include	"printing.h"
#include	"sudoku_util.h"

#define		LEN					9
#define		INCONCLUSIVE		0
#define		SOLVED				1
#define		MULTIPLE			2

char		*possible_chars(char **nums, int r, int c);
int			call_with_next_num(char **nums, int row, int col
								, t_solution *t_sol);
int			solve(char **nums, int row, int col, t_solution *t_sol);
char		**sudoku(char **nums);

#endif
