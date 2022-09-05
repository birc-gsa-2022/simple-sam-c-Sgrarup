#include <stdio.h>

#define LINEWIDTH 1024

// This function will return the next token, which is
// the current string but where we have scanned forward to
// the next `delim` and replaced that with a zero-sentinel.
// The s variable keeps track of the state.
// It has side effects, it is not particularly safe,
// and does not check if the input is valid, so use with
// care...
static char *gettok(char **s, char delim)
{
    char *res = *s;
    while (**s && **s != delim)
    {
        (*s)++;
    }
    **s = 0; // Terminate the token
    (*s)++;  // Move the the start of the next token
    return res;
}

int main(int argc, char const *argv[])
{
    FILE *input = 0;
    if (argc < 2 || !(input = fopen(argv[1], "r")))
    {
        fprintf(stderr, "File name argument missing or file not readable.");
        return 1;
    }

    // I do not error handling here, so don't give the program
    // any crap input!
    char buf[LINEWIDTH], *line = buf;
    while (fgets(line, LINEWIDTH, input))
    {
        char *chrom = gettok(&line, '\t');
        char *read_name = gettok(&line, '\t');
        char *read_str = gettok(&line, '\t');
        char *pos = gettok(&line, '\n');
        // Now you have the input; just output it in Simple-SAM format.
    }

    fclose(input);
    return 0;
}
