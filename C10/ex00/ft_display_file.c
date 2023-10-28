#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void	ft_print (char *text)
{
	while (text)
		write(1, text++, 1);
}
int	main (int	argc, char *argv[])
{
	char	c;
	int		fd;
	int		sz;

	c = 1;
	if (argc < 2)
	{
		write(1, "File name missing.\n", 19);
		return (0);
	}
	else if (argc > 2)
	{
		write(1, "Too many arguments.\n", 20);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(1, "Cannot read file.\n", 17);
		return (0);
	}
	sz = read(fd, &c, 1);
	while (sz != 0)
	{
		write(1, c, 1);
		sz = read(fd, &c, 1);
	}
}
