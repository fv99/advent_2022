/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rps.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: practical <install gentoo>                 +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 14:13:59 by practical         #+#    #+#             */
/*   Updated: 2022/12/02 19:54:21 by practical        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>


int	win(int a, int b)
{					
	if (a == 'A' && b == 'X')				// theres only 9 combinations
		return (4);							// so we just hard code this 
	if (a == 'A' && b == 'Y')
		return (8);								
	if (a == 'A' && b == 'Z')
		return (3);
	if (a == 'B' && b == 'X')
		return (1);
	if (a == 'B' && b == 'Y')
		return (5);
	if (a == 'B' && b == 'Z')
		return (9);
	if (a == 'C' && b == 'X')
		return (7);
	if (a == 'C' && b == 'Y')
		return (2);
	if (a == 'C' && b == 'Z')
		return (6);
	else
		return (0);							
}

int	wintwo(int a, int b)
{					
	if (a == 'A' && b == 'X')				
		return (3);							
	if (a == 'A' && b == 'Y')
		return (4);								
	if (a == 'A' && b == 'Z')
		return (8);
	if (a == 'B' && b == 'X')
		return (1);
	if (a == 'B' && b == 'Y')
		return (5);
	if (a == 'B' && b == 'Z')
		return (9);
	if (a == 'C' && b == 'X')
		return (2);
	if (a == 'C' && b == 'Y')
		return (6);
	if (a == 'C' && b == 'Z')
		return (7);
	else
		return (0);							
}

int	main()
{
	int score = 0;
	int scoretwo = 0;

	char buf[5];

	FILE *input = fopen("input.txt", "r");		

	while(fgets(buf, sizeof(buf), input))				// read each line into buffer
	{	
		scoretwo += wintwo(buf[0],buf[2]);				// take first (A) and second (X) and run through the table
		score += win(buf[0],buf[2]);
	}

	printf("Your score part one:  %d \n", score);
	printf("Your score part two:  %d \n", scoretwo);
	
	fclose(input);
	return (0);
}