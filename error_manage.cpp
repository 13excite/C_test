//
// Created by vladimir on 14.07.16.
//

#include <stdio.h>
#include <cstdlib>

/* cat:  concatention file */
int main(int argc, char *argv[])
{
    FILE *fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0]; /* prog name */
    if (argc ==1) /* no args; copy stand enter  */
        filecopy(stdin, stdout);
    else
        while (--argc > 0)
            if ((fp = fopen(*++argv, "r")) == NULL) {
                fprintf (stderr, "%s: can't open file %s\n",
                         prog, *argv);
                exit(1);
            } else {
                filecopy(fp, stdout);
                fclose(fp);
            }
    if (ferror(stdout)) {
        fprintf (stderr, "%s: write error in stdout\n", prog); exit(2);
    }
    exit(0);
}