#include <stdlib.h>


char	**memory_allocation(int rows, int columns)
{
	char	**table;
	int		i;

	table = (char **)malloc(sizeof(char *) * rows);
	if (!table)
		return (NULL);
	for (i = 0; i < rows; i++)
	{
		table[i] = (char *)malloc(sizeof(char) * columns);
		if (!table[i])
			return (NULL);
	}
	return (table);
}

char	**create_board(void)
{
	char	**board;
	int		i;
	int		j;

	board = memory_allocation(6, 6);
	for (i = 0; i < 6; i++)
		for (j = 0; j < 6; j++)
			board[i][j] = '0';
	return (board);
}

void	set_clues(char **puzzle_board, char **clues)
{
	int	i;

	for (i = 1; i <= 4; i++)
	{
		puzzle_board[0][i] = clues[0][i - 1];
		puzzle_board[5][i] = clues[1][i - 1];
		puzzle_board[i][0] = clues[2][i - 1];
		puzzle_board[i][5] = clues[3][i - 1];
	}
}

int	is_correct_params(char **argv)
{
	int	i;
	int	count;

	count = 0;
	for (i = 0; argv[1][i]; i++)
	{
		if (argv[1][i] >= '1' && argv[1][i] <= '4' && i % 2 == 0)
			count++;
		else if (argv[1][i] != ' ')
			return (0);
	}
	return (count == 16);
}

char	**convert_in_array(char *str)
{
	char	**clues;
	int		i;
	int		j;

	clues = memory_allocation(4, 4);
	for (i = 0, j = 0; j < 4; j++, i += 2)
	{
		clues[0][j] = str[i];
		clues[1][j] = str[i + 8];
		clues[2][j] = str[i + 16];
		clues[3][j] = str[i + 24];
	}
	return (clues);
}
