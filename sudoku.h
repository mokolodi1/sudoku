/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 11:53:11 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 21:28:21 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		SUDOKU_H
# define 	SUDOKU_H

# include	<unistd.h>
# include	<stdlib.h>

# define		LEN					9
# define		INCONCLUSIVE		0
# define		SOLVED				1
# define		MULTIPLE			2

typedef struct	s_solution
{
	int		solved;
	char	*solution;
}				t_solution;

char			*possible_chars(char **nums, int r, int c);
int				call_with_next_num(char **nums, int row, int col
									, t_solution *t_sol);
int				solve(char **nums, int row, int col, t_solution *t_sol);
char			*sudoku(char **nums);

void			ft_putchar(char c);
void			ft_putstr(char *str);
void			print_sudoku(char *solution);

void			copy_solution(char **nums, t_solution *t_sol);
void			gen_collisions(char **nums, int (*collisions)[9], int r, int c);

int				input_check(int size, char **nums);
int				main(int argc, char **argv);

#endif
