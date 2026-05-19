#include <stdio.h>
#include <stdlib.h>

// Минимум из трех чисел — ядро алгоритма
int get_min(int a, int b, int c) {
    int	min = a;

	if (b < min)
		min = b;
	if (c < min)
		min = c;

	return (min);
}

void solve(FILE *fp) {
    int rows, size = 0, r = 0, c = 0;
    char empty, obs, full;

    // 1. Читаем заголовок (например: "9 . o x")
    if (fscanf(fp, "%d %c %c %c\n", &rows, &empty, &obs, &full) != 4) {
        fprintf(stderr, "map error\n");
        return;
    }

    // Выделяем память под карту и под таблицу расчетов (DP)
    char **map = malloc(sizeof(char *) * rows);
    int **dp = malloc(sizeof(int *) * rows);
    int cols = -1;

    // 2. Читаем карту и сразу считаем значения
    for (int i = 0; i < rows; i++) {
        size_t cap = 0;
        int len = getline(&map[i], &cap, fp);
        if (map[i][len - 1] == '\n') 
			map[i][--len] = '\0'; // Убираем перенос строки
        
        if (cols == -1) 
			cols = len; // Узнаем ширину по первой строке
        dp[i] = malloc(sizeof(int) * cols);

        for (int j = 0; j < cols; j++) {
            if (map[i][j] == obs) {
                dp[i][j] = 0;
            } else {
                // Если это край — 1, иначе — минимум соседей + 1
                if (i == 0 || j == 0) 
					dp[i][j] = 1;
                else 
					dp[i][j] = get_min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]) + 1;

                // Запоминаем самый большой (первый найденный будет самым верхним/левым)
                if (dp[i][j] > size) {
                    size = dp[i][j];
                    r = i;
                    c = j;
                }
            }
        }
    }

    // 3. Рисуем квадрат (от правого нижнего угла r,c назад на размер size)
    for (int i = r; i > r - size; i--)
        for (int j = c; j > c - size; j--)
            map[i][j] = full;

    // 4. Печать и очистка
    for (int i = 0; i < rows; i++) {
        fprintf(stdout, "%s\n", map[i]);
        free(map[i]);
        free(dp[i]);
    }
    free(map);
    free(dp);
}

int main(int ac, char **av) {
    if (ac == 1) 
        solve(stdin);
    else {
        for (int i = 1; i < ac; i++) {
            FILE *f = fopen(av[i], "r");
            if (f) 
                { solve(f); fclose(f); }
            else 
                fprintf(stderr, "map error\n");
            if (i < ac - 1) 
                printf("\n");
        }
    }
    return 0;
}
