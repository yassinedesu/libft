/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-kha <yael-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:10:01 by yael-kha          #+#    #+#             */
/*   Updated: 2025/11/11 17:10:01 by yael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	set_check(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	start_trims(char const *s1, char const *set)
{
	size_t	i;

	i = 0;
	while (s1[i] && set_check(s1[i], set))
		i++;
	return (i);
}

static int	end_trims(char const *s1, char const *set)
{
	size_t	i;

	i = ft_strlen(s1) - 1;
	while (i > 0 && set_check(s1[i], set))
		i--;
	return (i);
}

static char	*check_condition(char const *s1, char const *set)
{
	if (!s1 || !set)
		return (NULL);
	if (s1[0] == '\0')
		return (ft_strdup(""));
	if (set[0] == '\0')
		return (ft_strdup(s1));
	return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	start;
	size_t	end;
	char	*ss;

	i = 0;
	if (!s1 || !set || s1[i] == '\0' || set[i] == '\0')
		return (check_condition(s1, set));
	start = start_trims(s1, set);
	end = end_trims(s1, set);
	if (start > end)
		return (ft_strdup(""));
	ss = malloc(end - start + 2);
	if (!ss)
		return (NULL);
	while (start + i <= end)
	{
		ss[i] = s1[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
