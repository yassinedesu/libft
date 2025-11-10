/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-kha <yael-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 22:40:38 by yael-kha          #+#    #+#             */
/*   Updated: 2025/11/10 22:40:38 by yael-kha         ###   ########.fr       */
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
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] && s[i] == c)
		i++;
	while (s[i] && s[i] != c)
	{
		count++;
		i++;
	}
	return (count);
}

static char	**check_condition(char *s)
{
	char	**ptr;

	if (!s)
		return (NULL);
	else if (*s == '\0')
	{
		ptr = malloc(sizeof(char *));
		if (!ptr)
			return (NULL);
		ptr[0] = NULL;
		return (ptr);
	}
	return (NULL);
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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	word_count;
	char	**ptr;

	if (!s || !*s)
		return (check_condition(s));
	i = 0;
	j = 0;
	word_count = count_word(s, c);
	ptr = malloc((word_count + 1) * (sizeof(char *)));
	if (!ptr)
		return (NULL);
	while (i < word_count + 1)
	{
		while (s[j] && s[j] == c)
			j++;
		while (s[j] && s[j] != c)
			ptr[i] = ft_substr(s, j, len_w(s, c));
		i++;
	}
	ptr[i] = NULL;
	free_me(ptr, word_count);
	return (ptr);
}
