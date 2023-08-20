#include "shell.h"

int main(int argc, char *argv, char *env)
{
  (void) argc, (void)argv, (void) env;

  default_process();
  return (0);
}
