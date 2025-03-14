#include "Sentence.hpp"

Sentence::Sentence(const std::string& text, int number) 
    : number(number), text(text.empty() ? "" : text), score(0.0) {
    if (!text.empty()) {
        this->processedText = stopWordRemoval(text);
        std::istringstream iss(processedText);
        std::string word;
        while (iss >> word) {
            if (!word.empty()) {
                words.push_back(word);
            }
        }
    }
}

void Sentence::tfidfCalculation() {
    TFIDFCalc calculator;
    for (const auto& s : allExclusiveWords) {
        tfidf[s] = 0.0;
    }

    for (const auto& w : words) {
        if (!w.empty()) {
            double tfidfV = calculator.tfIdf(words, paragraph, w);
            tfidf[w] = tfidfV;
        }
    }
}

// Implement getters and setters
void Sentence::setParagraph(const std::vector<std::vector<std::string>>& p) { paragraph = p; }
void Sentence::setAllExclusiveWords(const std::vector<std::string>& words) { allExclusiveWords = words; }
void Sentence::setScore(double s) { score = s; }
double Sentence::getScore() const { return score; }
const std::string& Sentence::getText() const { return text; }
const std::vector<std::string>& Sentence::getAllExclusiveWords() const { return allExclusiveWords; }
const std::unordered_map<std::string, double>& Sentence::getTfidf() const { return tfidf; }
const std::vector<std::string>& Sentence::getWords() const { return words; }
const std::string& Sentence::getProcessedText() const { return processedText; }

std::string Sentence::punctuationRemover(const std::string& content) {
    std::string noPunctuationSentence;
    noPunctuationSentence.reserve(content.length());
    
    for (char c : content) {
        if (!std::ispunct(c) && c != '\r' && c != '\n') {
            noPunctuationSentence += c;
        }
    }
    return noPunctuationSentence;
}

std::string Sentence::stopWordRemoval(const std::string& input) {
    static const std::unordered_set<std::string> stop_words = {
        "a", "able", "about", "after", "all", "also", "am", "an", "and", "any",
        "are", "as", "at", "be", "because", "been", "but", "by", "can", "cannot",
        "could", "did", "do", "does", "either", "else", "ever", "every", "for",
        "from", "get", "got", "had", "has", "have", "he", "her", "hers", "him",
        "his", "how", "i", "if", "in", "into", "is", "it", "its", "just", "let",
        "like", "likely", "may", "me", "might", "most", "must", "my", "neither",
        "no", "nor", "not", "of", "off", "often", "on", "only", "or", "other",
        "our", "own", "said", "say", "says", "she", "should", "so", "some",
        "than", "that", "the", "their", "them", "then", "there", "these", "they",
        "this", "they're", "to", "too", "that's", "us", "was", "we", "were",
        "what", "when", "where", "which", "while", "who", "whom", "why", "will",
        "with", "would", "yet", "you", "your", "you're"
    };

    std::string noPunctuation = punctuationRemover(input);
    std::transform(noPunctuation.begin(), noPunctuation.end(), 
                  noPunctuation.begin(), ::tolower);
    
    std::istringstream iss(noPunctuation);
    std::string word;
    std::string output;
    output.reserve(noPunctuation.length());

    while (iss >> word) {
        if (!word.empty() && stop_words.find(word) == stop_words.end()) {
            if (!output.empty()) {
                output += ' ';
            }
            output += word;
        }
    }
    
    return output;
}
