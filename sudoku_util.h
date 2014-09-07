/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_util.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 17:07:55 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 17:42:25 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			SUDOKU_UTIL_H
#define			SUDOKU_UTIL_H

#include		<stdlib.h>
#include		"sudoku.h"

typedef struct	s_solution
{
	int		solved;
	char	*solution;
}				t_solution;

void			copy_solution(char **nums, t_solution *t_sol);
void			gen_collisions(char **nums, int **collisions, int r, int c);
#endif
