#include "CosineSimilarity.hpp"

double CosineSimilarity::dotProduct(const Sentence& s1, const Sentence& s2) {
    double num = calculateDotProduct(s1, s2);
    double deno = (mod(s1) * mod(s2));
    return num / deno;
}

double CosineSimilarity::calculateDotProduct(const Sentence& s1, const Sentence& s2) {
    double val = 0.0;
    for (const auto& w : s1.getAllExclusiveWords()) {
        val += (s1.getTfidf().at(w) * s2.getTfidf().at(w));
    }
    return val;
}

double CosineSimilarity::mod(const Sentence& A) {
    double val = 0.0;
    for (const auto& s : A.getAllExclusiveWords()) {
        val += pow(A.getTfidf().at(s), 2);
    }
    return sqrt(val);
}
