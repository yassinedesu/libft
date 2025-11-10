/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-kha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 15:18:26 by yael-kha          #+#    #+#             */
/*   Updated: 2025/11/01 23:59:15 by yael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*ss;

	i = 0;
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len - start < len)
		ss = malloc((s_len - start) + 1);
	else
		ss = malloc(len + 1);
	if (!ss)
		return (NULL);
	while (i < len && s[start + i])
	{
		ss[i] = (char)s[start + i];
		i++;
	}
	ss[i] = '\0';
	return (ss);
}
