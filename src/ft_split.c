/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbaduel <hbaduel@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:52:56 by hbaduel           #+#    #+#             */
/*   Updated: 2023/11/25 11:10:44 by hbaduel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static size_t	ft_numbstr(char const *s, char c)
{
	int		inword;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	inword = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			inword = 0;
		else if (inword == 0)
		{
			inword = 1;
			count++;
		}
		i++;
	}
	return (count);
}

static void	ft_chardup(char **ptr, char const *s, char c, size_t k)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	ptr[k] = malloc(sizeof(char) * (i + 1));
	while (j < i)
	{
		ptr[k][j] = s[j];
		j++;
	}
	ptr[k][j] = '\0';
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	size_t	i;
	size_t	j;

	if (!s)
		return (NULL);
	ptr = malloc(sizeof(char *) * (ft_numbstr(s, c) + 1));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] == '\0')
			break ;
		ft_chardup(ptr, &s[i], c, j);
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	ptr[j] = 0;
	return (ptr);
}
