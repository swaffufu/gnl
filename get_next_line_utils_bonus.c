/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afitri <afitri@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 18:35:35 by afitri            #+#    #+#             */
/*   Updated: 2025/09/21 18:35:36 by afitri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dest;
	char	*start;

	dest = malloc(ft_strlen(s) + 1);
	if (!dest)
		return (NULL);
	start = dest;
	while (*s)
		*dest++ = *s++;
	*dest = '\0';
	return (start);
}

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char) c)
			return ((char *)s);
		s++;
	}
	if ((char) c == '\0')
		return ((char *)s);
	return (NULL);
}

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	char	*dest;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
	{
		dest = malloc(1);
		if (dest)
			dest[0] = '\0';
		return (dest);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_join(char *s1, char *s2)
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s1)
		s1 = ft_strdup("");
	res = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!res)
	{
		free(s1);
		return (NULL);
	}
	while (s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	while (*s2)
		res[i++] = *s2++;
	res[i] = '\0';
	free(s1);
	return (res);
}
