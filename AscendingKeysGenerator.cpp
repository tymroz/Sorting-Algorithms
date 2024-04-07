#include <iostream>
#include <vector>
#include <random>
#include <algorithm>

std::vector<int> generateRandomKeys(int n) {
    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> dist(0, 2*n - 1);

    std::vector<int> keys(n);
    for (int i = 0; i < n; ++i) {
        keys[i] = dist(mt);
    }
    return keys;
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Użycie: " << argv[0] << " <rozmiar_tablicy>" << std::endl;
        return 1;
    }

    int n = std::stoi(argv[1]);

    std::vector<int> randomKeys = generateRandomKeys(n);
    sort(randomKeys.begin(), randomKeys.end());

    std::cout << "Losowe klucze:" << std::endl;
    for (int key : randomKeys) {
        std::cout << key << " ";
    }
    std::cout << std::endl;
}