/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adompe <adompe@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/26 15:39:05 by adompe            #+#    #+#             */
/*   Updated: 2016/09/26 15:39:07 by adompe           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new_list;

	new_list = (t_list *)malloc(sizeof(t_list));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = ft_memalloc(content_size);
		if (new_list->content == NULL)
			return (NULL);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
	}
	new_list->next = NULL;
	return (new_list);
}
