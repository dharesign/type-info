#include <liba.h>
#include <vector>

const void * get()
{
    return &typeid(std::vector<std::vector<int>>);
}
