#include "TFIDFCalc.hpp"

double TFIDFCalc::tf(const std::vector<std::string>& doc, const std::string& term) {
    double result = 0;
    for (const auto& word : doc) {
        if (term == word) {
            result++;
        }
    }
    return result / doc.size();
}

double TFIDFCalc::idf(const std::vector<std::vector<std::string>>& docs, const std::string& term) {
    double n = 0;
    for (const auto& doc : docs) {
        for (const auto& word : doc) {
            if (term == word) {
                n++;
                break;
            }
        }
    }
    return log(docs.size() / n);
}

double TFIDFCalc::tfIdf(const std::vector<std::string>& doc, 
                        const std::vector<std::vector<std::string>>& docs, 
                        const std::string& term) {
    return tf(doc, term) * idf(docs, term);
}
