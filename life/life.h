#ifndef LIFE_H
#define LIFE_H

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

typedef struct s_life
{
	int width;
	int height;
	int iter;
	char *board;
	char *next;
}	t_life;

#endif

