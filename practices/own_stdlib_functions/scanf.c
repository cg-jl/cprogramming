
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>


int _scanf(char * format, ...) {
  va_list vlist;
  int argc = 0;
  char * ft_back = format;
  while (*ft_back) { 
    if (*ft_back == '%') { 
      ft_back++;
      if (*ft_back == 'd' || *ft_back == 'c' || *ft_back == 's') argc++;
    }
    ft_back++;
  }
  char buff[256];
  fgets(buff, 256, stdin); // get input`
  buff [strlen (buff) - 1] = 0; // trim newline
  char * buf = buff;
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
  int i = 1, j = 2, received;
  
  printf("Selecciona ANCHOxALTO\n");

  if ((received = _scanf("%dx%d", &i, &j)) != 2) { 
    printf("Expected 2, got only %d\n", received);
    return 1;
  }


  printf("i : %d, j : %d\n", i, j);


  return 0;
}
