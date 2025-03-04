/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nogioni- <nogioni-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 18:06:57 by nogioni-          #+#    #+#             */
/*   Updated: 2024/08/09 18:07:31 by nogioni-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	while ((unsigned char)str[i] != (unsigned char)c && str[i])
		i++;
	if ((unsigned char)c == (unsigned char)str[i])
		return ((char *)(str + i));
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char	*new_string;
	size_t	i;
	size_t	j;

	if (!s1)
	{
		s1 = malloc(sizeof(char) * 1);
		s1[0] = '\0';
	}
	new_string = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!new_string)
		return (NULL);
	i = -1;
	while (s1[++i])
		new_string[i] = s1[i];
	j = -1;
	while (s2[++j])
		new_string[i + j] = s2[j];
	free(s1);
	new_string[i + j] = '\0';
	return (new_string);
}
