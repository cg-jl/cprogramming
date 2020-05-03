// demo.c https://www.viget.com/articles/game-programming-in-c-with-the-ncurses-library/
#include <ncurses.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define DELAY 30000

extern void loop (void);
extern void setup (void);
extern void clean (void);


void cleanUp (void) {
  clean();
  clear();
  refresh();
  curs_set (1);
  endwin();
}

void sigIntHandle (int signal) {
  cleanUp();
  exit (130);
}

int main (void) {
  /* Setup control-c handler */
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = sigIntHandle;
  sigemptyset (&sigIntHandler.sa_mask);
  sigIntHandler.sa_flags = 0;
  sigaction (SIGINT, &sigIntHandler, NULL);

  /* Initialize ncurses */
  initscr();
  noecho();
  curs_set (FALSE);

  /* Program run */
  setup();

  while (1) {
    loop();
    refresh();
    usleep (3000);
  }
  cleanUp();
  return 0;
}
