// #pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <sstream>
#include <cctype>
#include "TFIDFCalc.hpp"

class Sentence {
public:
    Sentence(const std::string& text, int number);
    void tfidfCalculation();
    
    void setParagraph(const std::vector<std::vector<std::string>>& p);
    void setAllExclusiveWords(const std::vector<std::string>& words);
    void setScore(double s);
    double getScore() const;
    const std::string& getText() const;
    const std::vector<std::string>& getAllExclusiveWords() const;
    const std::unordered_map<std::string, double>& getTfidf() const;
    const std::vector<std::string>& getWords() const;
    const std::string& getProcessedText() const;

private:
    int number;
    std::string text;
    std::string processedText;
    double score;
    std::vector<std::string> words;
    std::vector<std::string> allExclusiveWords;
    std::vector<std::vector<std::string>> paragraph;
    std::unordered_map<std::string, double> tfidf;

    std::string punctuationRemover(const std::string& content);
    std::string stopWordRemoval(const std::string& input);
};
