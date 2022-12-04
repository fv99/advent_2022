/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rucksack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:04:15 by practical         #+#    #+#             */
/*   Updated: 2022/12/04 13:22:15 by practical        ###   ########.fr       */
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
		s1[len + 1] = '\0';						
		
		char *s2 = malloc(len + 1);				// ditto
		memcpy(s2, (buf + len), len);			// except an offset here, as we want the second half
		s2[len + 1] = '\0';

		char *same = malloc(len + 1);			// for storing out similar strings

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
		
		if (same[0] >= 'a' && same[0] <= 'z')
			count += same[0] - 96;
		else 
			count += same[0] - 37;
		
		printf("same:  %s priority %i \n", same, count);

		free (same);

	}
	printf("Your priorities part one:  %d \n", count);
	// printf("Your score part two:  %d \n", ptwo);
	
	fclose(input);
	return (0);
}
