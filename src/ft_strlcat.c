/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:46:11 by hbaduel           #+#    #+#             */
/*   Updated: 2023/11/25 11:10:56 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	sizedst;
	size_t	sizesrc;

	i = 0;
	if ((!dst || !src) && size == 0)
		return (0);
	sizedst = ft_strlen(dst);
	sizesrc = ft_strlen(src);
	if (sizedst < size - 1 && size != 0)
	{
		while (src[i] != '\0' && sizedst + i < size - 1)
		{
			dst[sizedst + i] = src[i];
			i++;
		}
		dst[sizedst + i] = 0;
	}
	if (sizedst >= size)
		return (size + sizesrc);
	return (sizedst + sizesrc);
}
