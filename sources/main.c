/*
** EPITECH PROJECT, 2021
** poll
** File description:
** main
*/

#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include "../libs/includes/list.h"
#include "../libs/includes/cstring.h"
#include "../libs/includes/string.h"
#include "../libs/includes/foreach.h"

static void get_min(float sample)
{
    if (0 > sample) printf("O%%");
    else printf("%0.2f%%", sample);
}

static void get_max(float sample)
{
    if (100 < sample) printf("100%%");
    else printf("%0.2f%%", sample);
}

static int poll(char **_av, float p_size, float s_size, float p)
{
    float p1 = 0;
    float p2 = 0;
    float variance = 0;

    if (0 >= p_size) uraise("pSize > 0");
    else if (s_size >= p_size || s_size <= 0) uraise("sSize < pSize > 0");
    else if (0 > p || 100 < p) uraise("0% <= p >= 100%");
    else if (0 > p_size - 1) uraise("Division by zero");
    p /= 100;
    variance = ((p * (1 - p)) / s_size) * ((p_size - s_size) / (p_size - 1));
    p1 = (2 * 1.96 * sqrt(variance)) / 2 * 100;
    p2 = (2 * 2.58 * sqrt(variance)) / 2 * 100;
    printf("Population size:\t\t%d\nSample size:\t\t\t%d\nVoting intentions:\t\t%s%%\nVariance:\t\t\t%0.6f\n95%% confidence interval:\t[", (int)p_size, (int)s_size, _av[2], variance);
    get_min(p * 100 - p1);
    printf("; ");
    get_max(p * 100 + p1);
    printf("]\n99%% confidence interval:\t[");
    get_min(p * 100 - p2);
    printf("; ");
    get_max(p * 100 + p2);
    printf("]\n");
    return 0;
}

static void arg_handling(int const _ac, char **_av)
{
    if (4 != _ac) uraise("Expected 4 arguments.");
}

int main(int const _ac, char **_av)
{
    errno = 0;
    if (2 == _ac && !strcmp(_av[1], "-h")) helper(0);
    _av++;
    arg_handling(_ac, _av);
    return poll(_av, atoi(_av[0]), atoi(_av[1]), atof(_av[2]));
}