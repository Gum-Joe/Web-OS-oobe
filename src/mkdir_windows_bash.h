#include <direct.h>
#include <stdlib.h>
#include <string.h>
//#include "mkdir-linux.h"

namespace mkdirbash {

void mkdirs(const char *dir) {
  char *env = getenv("HOME");
  const char *stroke = "/";
  char *fenv = strcat(env, stroke);
  const char *home = strcat(fenv, dir);
  mkdir(home);
}

}  // namespace demo
