/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htomohit <htomohit@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/18 16:50:01 by htomohit          #+#    #+#             */
/*   Updated: 2020/12/15 17:07:08 by htomohit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main(void)
{
    int fd;
    char *line;
	int	i;

    line = NULL;
    fd = open("normal.txt", O_RDONLY);
    //fd = 0;
    while ((i = get_next_line(42, &line)) > 0)
    {
        printf("%s", line);
        free(line);
    }
	// printf("i = %d\n", i);
    printf("%s\n", line);
	printf("gnl = %d\n", get_next_line(fd, &line));
	printf("line = %s", line);

    // while (1);
	// system("leaks a.out");
    return (0);
}
