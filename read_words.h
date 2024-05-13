// You do not need to edit this file.

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <ctime>
#include <string>
#include <vector>

// Helper method to get a random word.
// You do not need to edit this function.
std::string GetRandomWord(int argc, char* argv[]) {
    std::vector<std::string> words;
    if (argc > 1) {
        words.emplace_back(argv[1]);
    } else {
        std::ifstream word_file("words.txt");
        if (!word_file.is_open()) {
            std::cout << "Failed to open words.txt." << std::endl;
            return "";
        }
        std::string line;
        while (std::getline(word_file, line)) {
            words.emplace_back(line);
        }
        word_file.close();
    }
            
    std::srand(std::time(nullptr));
    int index = std::rand() % words.size();
    return words[index];
}
