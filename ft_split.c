/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-kha <yael-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 23:25:25 by yael-kha          #+#    #+#             */
/*   Updated: 2025/11/10 23:25:25 by yael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_word(char *s, char c)
{
	size_t	i;
	size_t	count;

	if (!s)
		return (0);
	i = 0;
	count = 0;
	while (s[i])
	{
		if (((s[i] != c && s[i + 1] == c) || (s[i] != c && s[i + 1] == '\0'))
			&& s[i])
			count++;
		i++;
	}
	return (count);
}

static size_t	len_w(char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_me(char **s, size_t allocated)
{
	size_t	i;

	i = 0;
	while (i < allocated)
	{
		free(s[i]);
		i++;
	}
	free(s);
}

static char	**allocate_fill(char const *s, char c, size_t word_count)
{
	size_t	i;
	size_t	j;
	char	**ptr;

	ptr = malloc((word_count + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < word_count)
	{
		while (s[j] && s[j] == c)
			j++;
		ptr[i] = ft_substr(s, j, len_w((char *)&s[j], c));
		if (!ptr[i])
			return (free_me(ptr, i), NULL);
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	ptr[i] = NULL;
	return (ptr);
}

char	**ft_split(char const *s, char c)
{
	size_t	word_count;
	char	**ptr;

	if (!s)
		return (NULL);
	if (*s == '\0')
	{
		ptr = malloc(sizeof(char *));
		if (!ptr)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	word_count = count_word((char *)s, c);
	return (allocate_fill(s, c, word_count));
}
