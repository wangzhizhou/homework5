
#pragma once

#include <string>
using namespace std;

class Sentence {

public:
    Sentence(int score = 0, string text = ""): score(score), text(text) {}
    int getScore() const { return score; }
    string getText() const { return text; }
    void description() const {
        #ifdef DEBUG
        std::cout << "\t" << score << " " << text << std::endl;
        #endif
    }

private:
    int score;
    string text;
};