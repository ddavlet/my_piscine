#include <unistd.h>
#include <fcntl.h>
#include <libgen.h>
#include <errno.h>
#include <string.h>

void	ft_putstr (char *text)
{
	int	i;

	i = 0;
	while (text[i])
	{
		write (1, &text[i], 1);
		i++;
	}
}

void	ft_print_error (char *prog_name, char *file_name)
{
	ft_putstr(basename(prog_name));
	ft_putstr(": ");
	ft_putstr(file_name);
	ft_putstr(": ");
	ft_putstr(strerror(errno));
	ft_putstr("\n");
}

int	main (int argc, char *argv[])
{
	int	i;
	int	fd;
	int	sz;
	char c;

	i = 0;
	while (++i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) < 0)
			ft_print_error(argv[0], argv[i]);
		else
		{
			sz = read(fd, &c, 1);
			while (sz != 0)
			{
				write(1, &c, 1);
				sz = read(fd, &c, 1);
			}
		}
		close (fd);
	}
	return (0);
}
