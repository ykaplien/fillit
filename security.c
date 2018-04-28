
#include "fillit.h"

int		argCount(int argc, char **argv)
{
    if (argc == 2)
        return (1);
    else if (argc == 1)
        error(1);
    else
        error(2);
    return (0);
}

void    error(int a)
{
    if (a == 1)
    {
        ft_putstr("usage: ./fillit tetriminos_map\n");
        ft_putstr("You forgot entered tetriminos map!");
        exit (0);
    }
    else if (a == 2)
    {
        ft_putstr("usage: ./fillit tetriminos_map\n");
        ft_putstr("You entered to many arguments!");
        exit (0);
    }
    else if (a == 3)
    {
        ft_putstr("usage: ./fillit tetriminos_map\n");
        ft_putstr("No such file!");
        exit (0);
    }
    else if (a == 4)
    {
        ft_putstr("usage: ./fillit tetriminos_map\n");
        ft_putstr("Invalid map!");
        exit (0);
    }
}

char		*mRead(char **argv, char *buff)
{
    int     fd;
    int		def;

    buff = (char *)malloc(sizeof(char) * 546);
    ft_bzero(buff, 546);
    def = 0;
    fd = open(argv[1], O_RDONLY);
    if (fd != 3)
        error(3);
    while (read(fd, buff, 545))
        def++;
    if (def != 1)
        error(4);
    return (buff);
}

int		tValidation(char *buff)
{
    int def;
    int tetrC;

    tetrC = tCount(buff);
    def = 0;
    while (*buff)
    {
        if (tNewl(buff))
            if (tSmbls(buff))
                if (tRelat(buff))
                    def++;
        buff += 21;
    }
    if (def == tetrC)
        return (1);
    return (0);
}

int     tNewl(char *buff)
{
    int     index;

    index = 0;
    if (buff[index + 4] == '\n' && buff[index + 9] == '\n' &&
        buff[index + 14] == '\n' && buff[index + 19] == '\n')
        return (1);
    error(4);
    return (0);
}

int     tSmbls(char *buff)
{
    int     ind;
    int     dots;
    int     hashs;

    dots = 0;
    hashs = 0;
    ind = 0;
    while (ind <= 20)
    {
        if (buff[ind] == '.')
            dots++;
        else if (buff[ind] == '#')
            hashs++;
        ind++;
    }
    if (dots != 12 && hashs != 4)
        error(4);
    return (1);
}

int     tRelat(char *b)
{
    int     i;
    int     def;

    i = 0;
    def = 0;
    while (i <= 20)
    {
        if (b[i] == '#' && b[i + 1] == '#')
            def++;
        if (b[i] == '#' && b[i + 5] == '#')
            def++;
        i++;
    }
    if (def >= 3)
        return (1);
    return (0);
}

int		tCount(char *buff)
{
    int		count;

    count = (ft_strlen(buff) + 2) / 21;
    return (count);
}

