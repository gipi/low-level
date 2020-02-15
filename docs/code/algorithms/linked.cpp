
#include "linked.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define ll_for_each(h, n) \
    for (n = (h)->next ; n ; n = (n)->next)
