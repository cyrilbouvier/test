#include <stdio.h>
#include <stdlib.h>

void
print_env_var (const char *name)
{
  char *v = getenv (name);
  if (v == NULL)
    printf ("%s is undefined\n", name);
  else
    printf ("%s=%s\n", name, v);
}

int
main (int argc, char *argv[])
{
  if (argc != 1)
  {
    fprintf (stderr, "Usage: %s\n", argv[0]);
    return EXIT_FAILURE;
  }

#if defined(__clang__)
  printf ("# Compiled with Clang %s\n", __VERSION__);
#elif defined(__GNUC__)
  printf ("# Compiled with gcc %s\n", __VERSION__);
#elif defined(__GNUG__)
  printf ("# Compiled with g++ %s\n", __VERSION__);
#else
  printf ("# Compiled with unknown compiler\n");
#endif
  print_env_var("TEST_ENV_VARIABLES");
  print_env_var("TEST_ENV_VARIABLE_IN_TRAVIS_YML");
  print_env_var("TRAVIS_OS_NAME");
  print_env_var("HOME");
  print_env_var("HOSTNAME");
  print_env_var("SHELL");
  print_env_var("TRAVIS_LANGUAGE");
  print_env_var("CC");

  return EXIT_SUCCESS;
}
