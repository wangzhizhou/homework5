#pragma once 

class Word {
public:
    Word(string word): word(word), count(0), total(0){}
    void increaseTotal(int inc) { total += inc; count++; }
    double calculateScore() const { return count == 0 ? 0 : (double)total / (double)count; }
    int getCount() const { return count; }
    string getWord() const { return word; }
    void description() const {
        #ifdef DEBUG
        std:: cout <<"\t"<< word << " " << count << "/" << total << std:: endl;
        #endif
    }
private:
    string word;
    int count;
    int total;
};


struct wordComparator
{
    bool operator()( const Word& left,const Word& right) const
    {
        return left.getWord() < right.getWord();
    }

};