#include <stdio.h>
#include <unistd.h>

FILE __stdin = { STDIN_FILENO, _IOFBF, 0, NULL, { 0, 0, 0 }, { 0 } };
FILE __stdout = { STDOUT_FILENO, _IOLBF, 0, NULL, { 0, 0, 0 }, { 0 } };
FILE __stderr = { STDERR_FILENO, _IONBF, 0, NULL, { 0, 0, 0 }, { 0 } };

FILE *stdin = &__stdin;
FILE *stdout = &__stdout;
FILE *stderr = &__stderr;
