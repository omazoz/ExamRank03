/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <tlufulua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/26 18:26:42 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/28 18:35:42 by tlufulua         ###   ########.fr       */
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

void	inter(char *s1, char *s2)
{
	char	*aux;
	size_t	n;

	n = 0;
	while (s1[n])
	{
		aux = s2;
		while (*aux)
		{
			if (s1[n] == *aux && !ft_memchr(s1, s1[n], n))
			{
				write(1, (s1 + n), 1);
				break ;
			}
			aux++;
		}
		n++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return(0);
}
