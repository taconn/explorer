#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include "f_malloc.h"
#include "f_strjoin.h"
#include "f_putstr.h"

static int	is_dir(const char *path)
{
	struct stat	st;

	if (stat(path, &st) != 0)
		return (0);
	return (S_ISDIR(st.st_mode));
}

static void	print_entry(const char *dir, const char *name)
{
	char	*tmp;
	char	*full;

	tmp = f_strjoin(dir, "/");
	if (tmp == NULL)
		return ;
	full = f_strjoin(tmp, name);
	f_free(tmp);
	if (full == NULL)
		return ;
	f_putstr(name);
	if (is_dir(full))
		f_putstr("/");
	f_putstr("\n");
	f_free(full);
}

int	main(int argc, char **argv)
{
	DIR				*dir;
	struct dirent	*entry;
	const char		*path;

	path = ".";
	if (argc > 1)
		path = argv[1];
	dir = opendir(path);
	if (dir == NULL)
	{
		perror(path);
		return (1);
	}
	entry = readdir(dir);
	while (entry != NULL)
	{
		print_entry(path, entry->d_name);
		entry = readdir(dir);
	}
	closedir(dir);
	return (0);
}
