/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tfleming <tfleming@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/07 12:16:59 by tfleming          #+#    #+#             */
/*   Updated: 2014/09/07 13:31:14 by tfleming         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef			MAIN_H
#define			MAIN_H

#include		<stdlib.h>
#include		<stdio.h>		// nope
#include		"sudoku.h"
#include		"printing.h"

int				input_check(int size, char **nums);
int				main(int argc, char **argv);

#endif
