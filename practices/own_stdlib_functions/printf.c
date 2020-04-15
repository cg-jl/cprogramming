
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int _printf(char *format, ...) {
  /*
   * Gets arguments in the form of a format string
   * and variables within the format string.
   * It parses the format string and prints characrers that 
   * are not format normally, but formats are printed correctly.
   *
   * Available formats:
   *    - %c -> print a character
   *    - %d -> print a decimal number
   *    - %s -> print a string. Limits in the form [limit] are ignored
   *    in this function.
   *
   *
   * */
  va_list arg_list; // initialize vararg list
  va_start(arg_list, format);
  while ( *format ) {
    if (*format == '%') {
      format++; // get the next char
      if (*format == '%') {
        // Escaped '%', print it
        putchar('%');
      } else if (*format == 'c') {
        // '%c' -> character
        int char_to_print = va_arg(arg_list, int);
        putchar(char_to_print);
      } else if (*format == 'd') {
        // '%d' -> decimal
        int num_to_print = va_arg(arg_list, int);
        int n_copy = num_to_print;
        // get the number of digits in integer
        int i = 0, j;
        char next_num;
        while ( num_to_print ) {
          num_to_print /= 10;
          i++;
        }
        if ( i > 1) {
        for (j = 1; j <= i; j++ ) {
          next_num = n_copy / (10 * j);
          putchar(next_num + 48);
        }
        } else putchar(n_copy + '0');

      } else if (*format == 's') {
        // '%s' -> string
        char * st = va_arg(arg_list, char *);
        while ( *st != 0 ) putchar(*(st++));
      }
    } else {
      putchar(*format); // not formatting, print it
    }
    format++;
  }
  va_end(arg_list); // free the vararg list
}


int main() {
  char buffer[]  = "Hello, world!";
  int i = 3;
  char c = 'h';

  _printf("string : \"%s\" | int : \"%d\" | char : \'%c\'", buffer, i, c);

  return 0;
}
