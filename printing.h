/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 12:00:36 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 13:28:55 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef		PRINTING_H
#define		PRINTING_H

#include	<unistd.h>
#include	<stdio.h>		// nope
#include	"sudoku.h"

void		ft_putchar(char c);
void		ft_putstr(char *str);
void		print_sudoku(char **nums);

#endif
