#include <stdio.h>
#include <unistd.h>

FILE __stdin = { STDIN_FILENO, _IOFBF, NULL, { 0, 0, 0 }, { 0 } };
FILE __stdout = { STDOUT_FILENO, _IOLBF, NULL, { 0, 0, 0 }, { 0 } };
FILE __stderr = { STDERR_FILENO, _IONBF, NULL, { 0, 0, 0 }, { 0 } };

FILE *stdin = &__stdin;
FILE *stdout = &__stdout;
FILE *stderr = &__stderr;
