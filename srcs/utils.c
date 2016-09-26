/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:36:16 by adompe            #+#    #+#             */
/*   Updated: 2016/09/26 15:36:20 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_bool		ft_is_comment(char *str)
{
	if (str && *str == '#' && *(str + 1) != '#')
		return (TRUE);
	return (FALSE);
}

t_bool		ft_is_command(char *str)
{
	int		len;

	len = ft_strlen(str);
	if (len >= 2 && str[0] == '#' && str[1] == '#')
		return (TRUE);
	return (FALSE);
}

t_bool		ft_is_room(char *str)
{
	char	**tab;
	t_bool	is_room;

	tab = ft_strsplit(str, ' ');
	is_room = TRUE;
	if (ft_tablen(tab) != 3)
		is_room = FALSE;
	else
	{
		if ((!ft_is_number(tab[1])) || (!ft_is_number(tab[2])))
			is_room = FALSE;
	}
	ft_free_str_tab(tab);
	return (is_room);
}

t_bool		ft_is_available_room(char *str, t_list *rooms)
{
	t_room		*room;

	room = ft_get_room_by_name(str, rooms);
	if (room->is_occupied)
		return (FALSE);
	return (TRUE);
}
