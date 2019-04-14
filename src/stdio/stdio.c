#include <stdio.h>
#include <unistd.h>

FILE __stdin = { STDIN_FILENO };
FILE __stdout = { STDOUT_FILENO };
FILE __stderr = { STDERR_FILENO };

FILE *stdin = &__stdin;
FILE *stdout = &__stdout;
FILE *stderr = &__stderr;
