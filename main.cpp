#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <queue>

std::queue<int> fila;
std::mutex mtx;
std::condition_variable cv;

void produtor() {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);  // template explicitado
        fila.push(i);
        std::cout << "Produziu: " << i << "\n";
        cv.notify_one();
    }
}

void consumidor() {
    for (int i = 0; i < 5; ++i) {
        std::unique_lock<std::mutex> lock(mtx);  // template explicitado
        cv.wait(lock, [] { return !fila.empty(); });
        std::cout << "Consumiu: " << fila.front() << "\n";
        fila.pop();
    }
}

int main() {
    std::thread t1(produtor), t2(consumidor);
    t1.join();
    t2.join();
}
