/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 11:37:16 by exam              #+#    #+#             */
/*   Updated: 2017/12/26 13:36:32 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\n')
		return (1);
	else
		return (0);
}

int		word_len(char *s, int start)
{
	int i;

	i = 0;
	while (s[start] && !is_whitespace(s[start]))
	{
		start++;
		i++;
	}
	return (i);
}

int		words_count(char *s)
{
	int count;
	int i;

	i = 0;
	count = 0;
	while (s[i] && is_whitespace(s[i]))
		i++;
	while (s[i])
	{
		if ((!is_whitespace(s[i]) && is_whitespace(s[i + 1])) ||
				(!is_whitespace(s[i]) && s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

char	*ft_strsub(char *s, int start, int len)
{
	char	*dest;
	int		i;

	i = 0;
	dest = (char*)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (NULL);
	while (i < len)
	{
		dest[i] = s[start];
		start++;
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	**ft_split(char *str)
{
	char	**arr;
	int		w_count;
	int		arr_index;
	int		s_index;

	s_index = 0;
	arr_index = 0;
	w_count = words_count(str);
	arr = (char**)malloc(sizeof(char*) * (w_count + 1));
	if (!arr)
		return (NULL);
	while (str[s_index] && arr_index < w_count)
	{
		while (is_whitespace(str[s_index]))
			s_index++;
		if (!is_whitespace(str[s_index]))
		{
			arr[arr_index] = ft_strsub(str, s_index, word_len(str, s_index));
			s_index += word_len(str, s_index) - 1;
		}
		s_index++;
		arr_index++;
	}
	arr[arr_index] = NULL;
	return (arr);
}
