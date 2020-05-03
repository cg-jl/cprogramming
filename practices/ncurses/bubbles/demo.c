// demo.c https://www.viget.com/articles/game-programming-in-c-with-the-ncurses-library/
#include <ncurses.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

#define DELAY 30000

extern void loop (void);
extern void setup (void);
extern void clean (void);

int drawLoopMax = 1;

void exitHandle (int signal) {
  clean();
  clear();
  refresh();
  curs_set (1);
  endwin();
  exit (signal);
}

int main (void) {
  /* Setup control-c handler */
  struct sigaction sigIntHandler;
  sigIntHandler.sa_handler = exitHandle;
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
  exitHandle (0);

  return 0;
}
