#include "blake3-wide/work.h"

#include <iostream>
#include <string>

int main(int argc, char** argv) {
    if (argc > 1 && std::string(argv[1]) == "--help") {
        std::cerr << "blake3-wide [rounds]\n";
        return 0;
    }
    std::uint32_t rounds = 16;
    if (argc > 1) {
        rounds = static_cast<std::uint32_t>(std::stoul(argv[1]));
    }
    auto job = blake3w::make_job(blake3w::algo());
    auto n = blake3w::bench(rounds);
    std::cout << "algo=" << blake3w::algo() << " job=" << job.id << " rounds=" << n << "\n";
    return 0;
}
