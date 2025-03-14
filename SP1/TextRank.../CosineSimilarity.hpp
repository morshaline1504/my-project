// #pragma once
#include <cmath>
#include "Sentence.hpp"

class CosineSimilarity {
public:
    double dotProduct(const Sentence& s1, const Sentence& s2);

private:
    double calculateDotProduct(const Sentence& s1, const Sentence& s2);
    double mod(const Sentence& A);
};
