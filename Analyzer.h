#pragma once

#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

#include "Sentence.h"
#include "Word.h"

class Analyzer {
    
public: 
    static vector<Sentence> readFile(string filePath) 
    {
        vector<Sentence> ret;

        ifstream input(filePath);
        string line;
        while (getline(input, line))
        {
            int score;
            string text;
            istringstream in(line);
            in >> score;
            getline(in,text,'\n');
            Sentence sentence(score, text);
            ret.push_back(sentence);
        }
    
        return ret;
    }

        
    static set<Word,wordComparator> allWords(vector<Sentence> &sentences) 
    { 
        set<Word,wordComparator> ret; 

        for(vector<Sentence>::iterator iter = sentences.begin(); iter != sentences.end(); iter++)
        {
            Sentence sentence = *iter;
            istringstream line(sentence.getText());
            string word;
            while(line >> word) 
            {
                if(!isValidWord(word)) continue;
                transform(word.begin(), word.end(), word.begin(), ::tolower);
                Word w(word);
                w.increaseTotal(sentence.getScore());

                set<Word,wordComparator>::iterator iter = ret.find(w);
                if(iter != ret.end())
                {
                    Word copy(*iter);
                    ret.erase(iter++);
                    copy.increaseTotal(sentence.getScore());
                    ret.insert(copy);
                }
                else
                {
                    ret.insert(w);
                }
            }
        }
        return ret;
    }

    static map<string, double> calculateScores(set<Word,wordComparator> &allWords) 
    {
        map<string, double> ret;

        for(set<Word,wordComparator>::iterator iter = allWords.begin(); iter != allWords.end(); iter++)
        {
            ret.insert(map<string, double>::value_type(iter->getWord(), iter->calculateScore()));
        }
        
        return ret;
    }

    static double calculateSentenceScore(map<string, double> &scores, string &sentence) 
    {
        double score = 0;
        istringstream in(sentence);
        string word;
        while(in >> word)
        {
            if(!isValidWord(word)) continue;
            transform(word.begin(), word.end(), word.begin(), ::tolower);
            score += scores[word];
        }
        return score;
    }

private: 
    static bool isValidWord(string word) 
    {
        if(word.length() == 0) 
        { 
            return false; 
        }

        char firstChar = word[0];
        if(
            !(
                (firstChar >= 'a' && firstChar <= 'z') ||
                (firstChar >= 'A' && firstChar <= 'Z')
            )
        ) 
        { 
            return false;
        }

        return true;
    }
};