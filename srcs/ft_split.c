/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vintran <vintran@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/19 14:54:18 by vintran           #+#    #+#             */
/*   Updated: 2021/07/13 15:00:01 by vintran          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/fdf.h"

void	ft_free_tab(char **tab, size_t size)
{
	int	i;

	i = 0;
	while (i <= (int)size)
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	tab = NULL;
}

size_t	ft_count_words(const char *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		j = 0;
		while (s[i + j] && s[i + j] != c)
			j++;
		if (j)
			nb_words++;
		i += j;
	}
	return (nb_words);
}

char	*ft_strndup(char *src, int n)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i] && i < n)
		i++;
	dest = malloc(sizeof(*dest) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_fill_tab(char **tab, const char *s, char c, size_t nb_words)
{
	size_t	i;
	size_t	j;
	size_t	word_len;

	i = 0;
	j = 0;
	tab[nb_words] = NULL;
	while (i < nb_words)
	{
		while (s[j] && s[j] == c)
			j++;
		word_len = 0;
		while (s[j + word_len] && s[j + word_len] != c)
			word_len++;
		tab[i] = ft_strndup((char *)&s[j], word_len);
		if (!tab[i])
		{
			ft_free_tab(tab, nb_words);
			break ;
		}
		j += word_len;
		i++;
	}
}

char	**ft_split(const char *s, char c)
{
	size_t	nb_words;
	char	**tab;

	if (!s)
		return (NULL);
	nb_words = ft_count_words(s, c);
	tab = malloc(sizeof(char *) * (nb_words + 1));
	if (!tab)
		return (NULL);
	ft_fill_tab(tab, s, c, nb_words);
	return (tab);
}
