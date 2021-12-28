/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   union.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <tlufulua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 18:09:04 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/28 19:10:02 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(char *)s++ == (char)c)
			return ((void *)s);
	return (0);
}

unsigned int	ft_strlen(char *s)
{
	unsigned int	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

void	ft_union(char **argv)
{
	char			*aux;
	unsigned int	len;
	size_t			n;

	n = 0;
	len = ft_strlen(argv[1]) + ft_strlen(argv[2]) + 1;
	aux = argv[1];
	while (n < len)
	{
		if (*aux != '\0' && !ft_memchr(argv[1], *aux, n))
			write(1, aux, 1);
		aux++;
		n++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv);
	write(1, "\n", 1);
	return(0);
}
