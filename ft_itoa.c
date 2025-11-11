/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yael-kha <yael-kha@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 17:05:37 by yael-kha          #+#    #+#             */
/*   Updated: 2025/11/11 17:05:37 by yael-kha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static char	*handling_some_cases(int n)
{
	if (n == 0)
		return (ft_strdup("0"));
	else if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n == 2147483647)
		return (ft_strdup("2147483647"));
	return (NULL);
}

char	*ft_itoa(int n)
{
	int		i;
	int		count;
	char	*ptr;

	i = 0;
	if (n == -2147483648 || n == 0 || n == 2147483647)
		return (handling_some_cases(n));
	count = digit_count(n);
	ptr = malloc(count + 1);
	if (!ptr)
		return (NULL);
	if (n < 0)
	{
		ptr[i++] = '-';
		n *= -1;
	}
	ptr[count] = '\0';
	while (i < count)
	{
		count--;
		ptr[count] = (n % 10) + '0';
		n /= 10;
	}
	return (ptr);
}
