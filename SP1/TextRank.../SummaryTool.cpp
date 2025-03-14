#include "SummaryTool.hpp"

SummaryTool::SummaryTool(const std::string& text) : context(text) {
    noOfSentences = std::count(text.begin(), text.end(), '.');
    noOfSentencesInSummary = noOfSentences / 2;
    csMatrix.resize(noOfSentences, std::vector<double>(noOfSentences));

    std::istringstream iss(text);
    std::string sentence;
    int numberOrdering = 0;
    while (std::getline(iss, sentence, '.')) {
        if (!sentence.empty()) {
            paragraph.emplace_back(sentence, ++numberOrdering);
        }
    }

    docConversion();
    formAllExclusiveWords();
    tfidf();
    cosineSimilarity();
    extraction(noOfSentencesInSummary);
}

const std::string& SummaryTool::getSummary() const {
    return summary;
}

void SummaryTool::tfidf() {
    for (auto& s : paragraph) {
        s.tfidfCalculation();
    }
}

void SummaryTool::cosineSimilarity() {
    CosineSimilarity tool;
    for (int i = 0; i < noOfSentences; i++) {
        for (int j = 0; j < noOfSentences; j++) {
            csMatrix[i][j] = tool.dotProduct(paragraph[i], paragraph[j]);
        }
    }

    for (int i = 0; i < noOfSentences; i++) {
        double value = 0.0;
        for (int j = 0; j < noOfSentences; j++) {
            value += csMatrix[i][j];
        }
        paragraph[i].setScore(value);
        scoreOfSentences.push_back(value);
    }
}

void SummaryTool::formAllExclusiveWords() {
    for (const auto& s : paragraph) {
        for (const auto& w : s.getWords()) {
            if (std::find(allExclusiveWords.begin(), 
                         allExclusiveWords.end(), w) == allExclusiveWords.end()) {
                allExclusiveWords.push_back(w);
            }
        }
    }

    for (auto& s : paragraph) {
        s.setAllExclusiveWords(allExclusiveWords);
    }
}

void SummaryTool::docConversion() {
    for (const auto& s : paragraph) {
        std::vector<std::string> wordsAL;
        std::istringstream iss(s.getProcessedText());
        std::string word;
        while (iss >> word) {
            wordsAL.push_back(word);
        }
        docs.push_back(wordsAL);
    }

    for (auto& s : paragraph) {
        s.setParagraph(docs);
    }
}

void SummaryTool::extraction(int n) {
    std::vector<double> sortedScores = scoreOfSentences;
    std::sort(sortedScores.begin(), sortedScores.end(), std::greater<double>());
    double threshold = sortedScores[n - 1];

    for (const auto& s : paragraph) {
        if (s.getScore() >= threshold && !s.getText().empty()) {
            summary += s.getText() + ".\n";
        }
    }
}
