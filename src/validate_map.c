/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teva <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/21 12:07:58 by teva              #+#    #+#             */
/*   Updated: 2020/10/22 01:03:51 by teva             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void		validate_map(t_info *s)
{
	int		outer;
	int		inner;
	int		letters_so_far;

	outer = 0;
	letters_so_far = 0;
	while (outer < s->map_dim.y)
	{
		inner = 0;
		while (s->map[outer][inner] != '\0')
		{
/*			if (s->map[outer][inner] == ' ')
				//validate_space_in_map()
			else if (s->map[outer][inner] == '1')
				//validate_one_in_map()*/
			if (s->map[outer][inner] == '0')
				validate_empty_in_map(s, inner, outer);
			else if (s->map[outer][inner] == '2')
				validate_sprite_in_map(s, inner, outer);
			else if (letters_so_far == 0 && ok_letters(s->map[outer][inner]))
			{
				letters_so_far = validate_letter_in_map(s, inner, outer);
				s->spawn_point.x = inner;
				s->spawn_point.y = outer;
			}
//			else
//				ft_error(MAP_ERROR)
			inner++;
		}
		outer++;
	}
}

int			validate_letter_in_map(t_info *s, int posx, int posy)
{
	int		prev_good;
	int		next_good;
	int		curr_good;
	int		abov_good;

	curr_good = 0;
	if (posx != 0 && posx != ft_strlen(s->map[posy]) && posy != 0 &&\
		posy != s->map_dim.y)
		curr_good = 1;
	prev_good = 0;
	if ((s->map[posy][posx - 1] == '0' || s->map[posy][posx - 1] == '1' ||\
		s->map[posy][posx - 1] == '2'))
		prev_good = 1;
	next_good = 0;
	if (s->map[posy][posx + 1] == '0' || s->map[posy][posx + 1] == '1'\
		|| s->map[posy][posx + 1] == '2')
		next_good = 1;
	abov_good = 0;
	if (s->map[posy - 1][posx] == '0' || s->map[posy - 1][posx] == '1'\
		|| s->map[posy - 1][posx] == '2')
		abov_good = 1;
	if (!prev_good || !curr_good || !next_good || !abov_good)
		ft_error(MAP_ERROR);
	return (1);
}

int			validate_sprite_in_map(t_info *s, int posx, int posy)
{
	int		prev_good;
	int		next_good;
	int		curr_good;
	int		abov_good;

	curr_good = 0;
	if (posx != 0 && posx != ft_strlen(s->map[posy]) && posy != 0 &&\
		posy != s->map_dim.y)
		curr_good = 1;
	prev_good = 0;
	if (s->map[posy][posx - 1] == '0' || s->map[posy][posx - 1] == '1' ||\
		ok_letters(s->map[posy][posx - 1]))
		prev_good = 1;
	next_good = 0;
	if (s->map[posy][posx + 1] == '0' || s->map[posy][posx + 1] == '1'\
		|| ok_letters(s->map[posy][posx + 1]))
		next_good = 1;
	abov_good = 0;
	if (s->map[posy - 1][posx] == '0' || s->map[posy - 1][posx] == '1'\
		|| ok_letters(s->map[posy - 1][posx]))
		abov_good = 1;
	if (!prev_good || !curr_good || !next_good || !abov_good)
		ft_error(MAP_ERROR);
	return (1);
}

int			validate_empty_in_map(t_info *s, int posx, int posy)
{
	int		prev_good;
	int		next_good;
	int		curr_good;
	int		abov_good;

	curr_good = 0;
	if (posx != 0 && posx != ft_strlen(s->map[posy]) && posy != 0 &&\
		posy != s->map_dim.y)
		curr_good = 1;
	prev_good = 0;
	if (s->map[posy][posx - 1] == '0' || s->map[posy][posx - 1] == '1' ||\
		s->map[posy][posx - 1] == '2' || ok_letters(s->map[posy][posx - 1]))
		prev_good = 1;
	next_good = 0;
	if (s->map[posy][posx + 1] == '0' || s->map[posy][posx + 1] == '1'||\
		s->map[posy][posx + 1] == '2' || ok_letters(s->map[posy][posx + 1]))
		next_good = 1;
	abov_good = 0;
	if (s->map[posy - 1][posx] == '0' || s->map[posy - 1][posx] == '1' ||\
		s->map[posy - 1][posx] == '2' || ok_letters(s->map[posy - 1][posx]))
		abov_good = 1;
	if (!prev_good || !curr_good || !next_good || !abov_good)
		ft_error(MAP_ERROR);
	return (1);
}
