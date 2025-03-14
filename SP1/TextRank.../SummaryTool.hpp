//#pragma once
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "Sentence.hpp"
#include "CosineSimilarity.hpp"

class SummaryTool {
public:
    SummaryTool(const std::string& text);
    const std::string& getSummary() const;

private:
    std::string context;
    std::string summary;
    int noOfSentences;
    int noOfSentencesInSummary;
    std::vector<Sentence> paragraph;
    std::vector<std::string> allExclusiveWords;
    std::vector<std::vector<std::string>> docs;
    std::vector<std::vector<double>> csMatrix;
    std::vector<double> scoreOfSentences;

    void tfidf();
    void cosineSimilarity();
    void formAllExclusiveWords();
    void docConversion();
    void extraction(int n);
};
