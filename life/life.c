#include "life.h"


int count_n(t_life *l, int x, int y){
	int count = 0;
	for(int i = -1; i <= 1; i++){
		for(int j = -1; j <= 1; j++){
			if(i == 0 && j == 0)
				continue;
			int nx = x + j;
			int ny = y + i;
			if(ny >= 0 && ny < l->height && nx >= 0 && nx < l->width){
				if(l->board[ny * l->width + nx])
					count++;
			}
		}
	}
	return (count);
}



void step(t_life *l){
	for(int y = 0; y < l->height; y++){
		for(int x = 0; x < l->width; x++){
			int neighbours = count_n(l, x, y);
			int idx = y * l->width + x;
			if(l->board[idx])
				l->next[idx] = (neighbours == 2 || neighbours == 3);
			else
				l->next[idx] = (neighbours == 3);
		}
	}
	for (int i = 0; i < l->width * l->height; i++)
		l->board[i] = l->next[i];
}


int main(int ac, char **av){
	if(ac != 4)
		return (1);
	t_life l;
	l.width = atoi(av[1]);
	l.height = atoi(av[2]);
	l.iter = atoi(av[3]);
	l.board = calloc(l.width * l.height, sizeof(char));
	l.next = calloc(l.width * l.height, sizeof(char));
	if (!l.board || !l.next)
		return (1);
	int px = 0;
	int py = 0;
	int pen = 0;
	char cmd;

	while(read(0, &cmd, 1)){
		if(cmd == 'w' && py > 0)
			py--;
		else if(cmd == 's' && py < l.height - 1)
			py++;
		else if(cmd == 'a' && px > 0)
			px--;
		else if(cmd == 'd' && px < l.width - 1)
			px++;
		else if(cmd == 'x')
			pen = !pen;
		if(pen)
			l.board[py * l.width + px] = 1;
	}
	for(int i = 0; i < l.iter; i++)
		step(&l);
	for(int y = 0; y < l.height; y++){
		for(int x = 0; x < l.width; x++){
			if(l.board[y * l.width + x])
				putchar('0');
			else
				putchar(' ');
		}
		putchar('\n');
	}
	free(l.board);
	free(l.next);
	return (0);
}
