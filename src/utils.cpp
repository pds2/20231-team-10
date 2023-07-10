#include "utils.h"
#include <thread>
#include <chrono>

void sleep(bool pode, int tempo) {
    if (pode) {std::this_thread::sleep_for(std::chrono::seconds(tempo));}
}