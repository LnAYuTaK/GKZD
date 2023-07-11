#include "App.h"
int main(int argc, char *argv[]) {
  app()->init();
  app()->start();
  for (;;) {
    THREAD_SLEEP_MCROS(1000);
  }
  return 0;
}