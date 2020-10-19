/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/14 13:32:42 by teva              #+#    #+#             */
/*   Updated: 2020/10/18 23:04:48 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

/* ****** */
/*	KEYS  */
/* ****** */

# define ESC		53

/* ******** */
/*	COLORS  */
/* ******** */

# define RED	    0XFF0000
# define GREEN	    0X00FF00
# define BLUE       0X0000FF
# define CYAN       0X00FFFF
# define WHITE      0XFFFFFF
# define BLACK      0X000000

/* ******** */
/*	ERRORS  */
/* ******** */

# define ARG_ERROR				1
# define FILE_OPEN_ERROR		2
# define FILE_CLOSE_ERROR		3
# define ARGS_IN_FILE_ERROR		4
# define TYPE_IDENTIFIER_ERROR	5
# define READ_ERROR				6
# define FILE_EXTENSION_ERROR	7

#endif
