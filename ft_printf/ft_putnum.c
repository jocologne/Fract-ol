/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnum.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcologne <jcologne@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 08:22:37 by jcologne          #+#    #+#             */
/*   Updated: 2024/11/10 07:57:15 by jcologne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	put_int(int n)
{
	int		len;

	len = 0;
	if (n == -2147483648)
		return (put_str("-2147483648"));
	if (n < 0)
	{
		len += put_char('-');
		n = -n;
	}
	if (n >= 10)
		len += put_int(n / 10);
	len += put_char((n % 10) + 48);
	return (len);
}

int	put_uns(unsigned int n)
{
	int	len;

	len = 0;
	if (n >= 10)
		len += put_uns(n / 10);
	len += put_char((n % 10) + 48);
	return (len);
}

/*int main(void)
{
	int num = 101;
	int a = put_int(num);
	printf("\n");
	int b = printf("%d", num);
	printf("\n");
	printf("meu_%d org_%d\n", a, b);
	unsigned int n = 1410065400;
	int c = put_uns(n);
	printf("\n");
	int d = printf("%u", n);
	printf("\n");
	printf("meu_%d org_%d\n", c, d);
}*/