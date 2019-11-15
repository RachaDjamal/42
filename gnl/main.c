#include "get_next_line.h"

int        main(int argc, char **argv)
{
    int        i = 1;
    int        ret;
    int        fd;
    char    *line;

    if (argc == 2)
        fd = open(argv[1], O_RDONLY);
    else
        fd = 0;
    while ((ret = get_next_line(fd, &line)))
    {
        printf("(%d) %d - ", i, ret);
        printf("%s\n", line);
        free (line);
        i++;
    }
    printf("(%d) %d - ", i, ret);
    printf("%s\n", line);
    free (line);
    printf("Lignes lues = %d\n", i);
    return (0);
}