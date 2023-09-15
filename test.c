#include "main.h"

int main()
{
    int len = 0;

    len = _printf("Let's test the custom _printf function:\n");
    _printf("Length: %d\n", len);

    len = _printf("Character: %c\n", 'A');
    _printf("Length: %d\n", len);

    len = _printf("String: %s\n", "Hello, World!");
    _printf("Length: %d\n", len);

    len = _printf("Null String: %s\n", NULL);
    _printf("Length: %d\n", len);

    len = _printf("Percentage: %%\n");
    _printf("Length: %d\n", len);

    return (0);
}
