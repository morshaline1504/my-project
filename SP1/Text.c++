
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <map>
#include <cmath>

class Sentence {

private:

    int order;
    std::string sentenceString;
    int numberOfWords;
    double score;

public:

    Sentence(std::string sen, int order) {
        this->sentenceString = sen;
        
        this->sentenceString.erase(0, sentenceString.find_first_not_of(" \n\r\t"));
        this->sentenceString.erase(sentenceString.find_last_not_of(" \n\r\t") + 1);
        
        this->numberOfWords = spaceCalculator(sen) + 1;
        this->order = order;
        this->score = 0.0;
    }


    int spaceCalculator(const std::string& sen) {
        int counter = 0;
        for (char ch : sen) {
            if (ch == ' ') {
                counter++;
            }
        }
        return counter;
    }

    void setScore(double score) {
        this->score = score;
    }

    int getNumberOfWords() const {
        return numberOfWords;
    }

    std::string getSentenceString() const {
        return sentenceString;
    }

    double getScore() const {
        return score;
    }

    std::string toString() const {
        return "\n\nSentence{" + std::to_string(order) + ", sentenceString='" + sentenceString + "', \nnumberOfWords=" + std::to_string(numberOfWords) + ", \nscore=" + std::to_string(score) + "}\n\n";
    }

};

class SummaryTool {

private:
    static int order;

    std::string context;

    std::string summary;
    std::vector<Sentence> sentences;
    int noOfSentences;

    int noOfSentencesInSummary;
    std::vector<std::string> sentencesArray;

    std::vector<std::vector<double>> intersectionMatrix;
    std::map<Sentence, double> sentenceScores;

    std::vector<double> scoreOfSentences;

public:

    SummaryTool(const std::string& context) {
        this->context = context;
        
        sentencesArray = splitSentences(context);
        noOfSentences = sentencesArray.size();
        noOfSentencesInSummary = noOfSentences / 2;

        calculateIntersectionMatrix();
        calculateScores();
        extractSummary(noOfSentencesInSummary);
    }

}
 void calculateIntersectionMatrix() {
        for (int i = 0; i < noOfSentences; i++) {
            for (int j = 0; j < noOfSentences; j++) {
                intersectionMatrix[i][j] = (sentences[i].getNumberOfWords() + sentences[j].getNumberOfWords()) / 2.0;
            }
        }
    }

    void calculateScores() {
        for (int i = 0; i < noOfSentences; i++) {
            double scoreTemp = 0;
            for (int j = 0; j < noOfSentences; j++) {
                scoreTemp += intersectionMatrix[i][j];
            }
            sentences[i].setScore(scoreTemp);
            scoreOfSentences.push_back(scoreTemp);
        }
    }

    
    void extraction(int noOfSentencesInSummary) {
        std::sort(scoreOfSentences.begin(), scoreOfSentences.end(), std::greater<double>());
        double threshold = scoreOfSentences[noOfSentencesInSummary - 1];
        
        for (auto& s : sentences) {
            if (s.getScore() >= threshold && !s.getSentenceString().empty()) {
                summary += s.getSentenceString() + ".\n";
            }
        }
    }
