#include <iomanip>
#include <iostream>
#include <typeindex>
#include <typeinfo>

#include <dlfcn.h>

void compare(const void *aptr, const void *bptr)
{
    const std::type_info& a = *(const std::type_info*)(aptr);
    const std::type_info& b = *(const std::type_info*)(bptr);

    std::cout << "Addresses:\n"
              << std::hex
              << "\ta: " << &a << "\n"
              << "\tb: " << &b << "\n"
              << "\n";

    std::cout << "Hashes:\n"
              << std::dec
              << "\ta: " << a.hash_code() << "\n"
              << "\tb: " << b.hash_code() << "\n"
              << "\n";

    std::cout << "type_info::operator==:\n"
              << std::boolalpha
              << "\t" << (a == b) << "\n"
              << "\n";

    std::cout << "type_index::operator==:\n"
              << std::boolalpha
              << "\t" << (std::type_index(a) == std::type_index(b)) << "\n"
              << "\n";
}

int main()
{
    void *liba = dlopen("liba.so", RTLD_LAZY);
    void *libb = dlopen("libb.so", RTLD_LAZY);

    using get = const void * (*)();

    get geta = (get) dlsym(liba, "get");
    get getb = (get) dlsym(libb, "get");

    compare((*geta)(), (*getb)());
}
