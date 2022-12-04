/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rucksack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:04:15 by practical         #+#    #+#             */
/*   Updated: 2022/12/04 19:12:02 by practical        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>	

int	main(void)
{
	int i;
	int x;
	int count = 0;

	char buf[64];

	FILE *input = fopen("input.txt", "r");		

	while(fgets(buf, sizeof(buf), input))		// read each line into buffer
	{	
		i = 0;
		int len = (strlen(buf) - 1) / 2;

		char *s1 = malloc(len + 1);				// string splitting
		memcpy(s1, buf, len);					// copies into s1 from buf of length len
		s1[len] = 0;						
		
		char *s2 = malloc(len + 1);				// ditto
		memcpy(s2, (buf + len), len);			// except an offset here, as we want the second half
		s2[len] = 0;

		char *same = malloc(len);			// for storing out similar strings

		while (s1[i] != '\0')
		{
			x = 0;

			while(s2[x] != '\0')				
			{
				if (s1[i] == s2[x])				// for each character in string s1, check if it exists in s2
					memcpy(same, (s2 + x), 1);	
				x++;
			}
			i++;
		}
		
		if (same[0] > 96 && same[0] < 123)
			count += (same[0] - 96);
		else if (same[0] > 64 && same[0] < 91)
			count += (same[0] - 38);

		free (same);
		free (s1);
		free (s2);

	}
	printf("Your priorities part one:  %i \n", count);
	// printf("Your score part two:  %d \n", ptwo);
	
	fclose(input);
	return (0);
}
