#ifndef FUNC_H
#define FUNC_H
int _printf(const char *format, ...);
void int_to_str(int num, char *str);
int convert_int(va_list args_list);
int _prinT_f(va_list s);
int prinT_f(va_list a);
void my_printf(const char* format, ...);
char *print_bin(unsigned int num);
char *to_print_bin(va_list args_list);
int _print_bin (va_list args_list);
int _putchar(char c);
void _puts(char *str);
int _strlen(char *s);
void callwriteToBuf(char *buf, size_t *bufIndex, const char *data, size_t dataSize);
void flushBuf(int fileDes, char *buf, size_t *bufIndex);

#endif/*FUNC_H*/
