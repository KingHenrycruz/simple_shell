#ifndef PATH_H_
#define PATH_H_

#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>

#include "types.h"
#include "string.h"
#include "list.h"
#include "info.h"

char *search_path(info_t *info, list_t *path);

#endif /* PATH_H_ */
