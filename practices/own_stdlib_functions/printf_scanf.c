#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

int _printf(char *format, ...) {
  va_list argp; // initialize vararg list
  va_start(argp, format);
  while ( *format ) {
    if (*format == '%') {
      format++; // get the next char
      if (*format == '%') {
        // Escaped '%', print it
        putchar('%');
      } else if (*format == 'c') {
        // '%c' -> character
        int char_to_print = va_arg(argp, int);
        putchar(char_to_print);
      } else if (*format == 'd') {
        // '%d' -> decimal
        int num_to_print = va_arg(argp, int);
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
        char * st = va_arg(argp, char *);
        while ( *st != 0 ) putchar(*(st++));
      }
    } else {
      putchar(*format); // not formatting, print it
    }
    format++;
  }
  va_end(argp); // free the vararg list
}

int _atoi(char * st) {
  int i = 0, j;
  for ( j = 0; j < strlen(st); j++) {
    i *= 10;
    i += st[i] - 48;
  }
  return i;
}

int _scanf(char * format, ...) {
  va_list vlist;
  int nargs = 0;
  char * ft = format;
  while (*ft) { 
    if (*ft == '%') { 
      ft++;
      if (*ft == 'd' || *ft == 'c' || *ft == 's') nargs++;
    }
    ft++;
  }
  char buff[256];
  fgets(buff, 256, stdin); // get input`
  buff [strlen (buff) - 1] = 0; // trim newline
  char * buf = buff;
  _printf("Got : \"%s\"\n", buf);
  va_start(vlist, format);
  int got = 0;
  while (*format && *buf) {
    if (*format == '%') {
      format++;
      if (*format == 'd') {
          int *nextpointer = (int *) va_arg(vlist, int *);
          int i = 0;
          while (*buf && (*buf >= '0' && *buf <= '9') ) {
            i *= 10;
            i += *buf - 48;
            buf++;
         }
         (*nextpointer) = i;
         got++;
      } else if (*format == 's') {
        /* gets a string. could be limited to a certain number 
         * of chars with bracket notation : %s[limit].
         */
        int limit ;
        if ( *format == '[' ) {
          limit = 0;
          while (*format != ']') { 
            // If I am at end of string, return
            if (!*format || *format < '0' || *format > '9') return got; // not good number format, return
            limit *= 10;
            limit += *format - 48;
            format++;
          }
        } else limit = -1;

               
        char *bf = (char *) va_arg(vlist, char *);
        int i = 0;
        while (*buf && limit) {
          bf[i++] = *buf;
          limit++;
          buf += 1;
        }
        got++;
      } else if (*format == 'c') {
        /* gets a character */  
        char *c = (char *) va_arg(vlist, char *);
        (*c) = *buf;
      } 
    }
      else if (*format != *buf) { return got; }
    else buf++;
      format++;
    }
    return got;
  }


int main() {
  char buf[256];
  int i = 1, j = 2, r;
  
  printf("Selecciona ANCHOxALTO\n");

  if ((r = _scanf("%dx%d", &i, &j)) != 2) { 
    printf("Expected 2, got only %d\n", r);
    return 1;
  }

  // _scanf runs OK but values from pointers do not seem to be applied?

  _printf("i : %d, j : %d\n", i, j);


  return 0;
}
