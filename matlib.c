#include <string.h>

void rowcol(int* l, double** m, char* type)
{
    int typesize, pointsize, returnnum = 0;
    /*while (type[strlen(type) - 1] == "*")
    {
        returnnum++;
        type[strlen(type) - 1] == "\0";
    }*/
    if (strstr(type, "char") != NULL)
    {
        pointsize = sizeof(char*);
        typesize = 1;
        m = (char**)m;
    }
    else if (strstr(type, "short") != NULL)
    {
        pointsize = sizeof(short*);
        typesize = 2;
        m = (short**)m;
    }
    else if (strstr(type, "double") != NULL)
    {
        pointsize = sizeof(double*);
        typesize = 8;
    }
    else
    {
        pointsize = sizeof(float*);
        typesize = 4;
        m = (float**)m;
    }
    l[0] = (int)_msize(m) / pointsize;
    l[1] = (int)_msize(m[0]) / typesize;
}

double** IDmat(int s)
{
    double** m = malloc(s * sizeof(double*));
    for (int i = 0; i < s; i++)
    {
        m[i] = calloc(s, sizeof(double));
        m[i][i] = 1;
    }
    return m;
}