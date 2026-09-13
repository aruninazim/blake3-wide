#include "blake3-wide/work.h"

#include <cstdlib>
#include <iostream>

#define CHECK(cond)                                                          \
    do {                                                                     \
        if (!(cond)) {                                                       \
            std::cerr << "fail: " #cond " (" << __FILE__ << ":" << __LINE__  \
                      << ")\n";                                              \
            return 1;                                                        \
        }                                                                    \
    } while (0)

int main() {
    auto a = blake3w::make_job("pool");
    auto b = blake3w::make_job("pool");
    CHECK(a.id == b.id);
    CHECK(blake3w::hash_nonce(a, 1) != blake3w::hash_nonce(a, 2));
    CHECK(blake3w::bench(8) == 8);
    CHECK(blake3w::algo() != nullptr);
    std::cout << "ok\n";
    return 0;
}
