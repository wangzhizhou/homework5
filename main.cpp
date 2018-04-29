#include "Analyzer.h"

int main(int argc, char** argv) {

    if(argc != 2) {
        cout<< "You should provide the input file path" << endl;
        exit(1);
    }

    //Part 1
    vector<Sentence> sentences =  Analyzer:: readFile(argv[1]);
    #ifdef DEBUG
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Part 1: Reading the input file "<< endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<endl;
    for(vector<Sentence>::iterator iter = sentences.begin(); iter != sentences.end(); iter++)
    {
        iter->description();
    }
    cout<<endl;
    #endif


    //Part 2
    set<Word,wordComparator> words = Analyzer::allWords(sentences);
    #ifdef DEBUG
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Part 2: Calculating the sentiment of each word &" << endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<endl;
    for(set<Word,wordComparator>::iterator iter = words.begin(); iter != words.end(); iter++)
    {
        iter->description();
    }
    cout<<endl;
    #endif
        
    //Part 3
    map<string, double> scores = Analyzer::calculateScores(words);
    #ifdef DEBUG
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Part 3: Storing the sentiment of each word " << endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<endl;
    for(map<string, double>::iterator iter = scores.begin(); iter != scores.end(); iter++)
    {
        cout<<iter->first<<": "<<iter->second<<endl;
    }    
    #endif


    //Part 4
    #ifdef DEBUG
    cout<<endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<"Part 4. Determining the sentiment of a sentence"<< endl;
    cout<<"--------------------------------------------------"<<endl;
    cout<<endl;
    #endif
    
    cout<<"Please input a sentence:  ";
    string sentence;
    while(getline(cin, sentence)) 
    {
        if(sentence == "quit") break;
        cout<<"The sentiment is: "<<Analyzer::calculateSentenceScore(scores,sentence)<<endl;
        cout<<endl;
        cout<<"Input another sentence('quit' to exit this program): ";

    }
    return 0;
}
