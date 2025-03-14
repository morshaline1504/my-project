//#pragma once
#include <vector>
#include <string>
#include <cmath>

class TFIDFCalc {
public:
    double tf(const std::vector<std::string>& doc, const std::string& term);
    double idf(const std::vector<std::vector<std::string>>& docs, const std::string& term);
    double tfIdf(const std::vector<std::string>& doc, 
                 const std::vector<std::vector<std::string>>& docs, 
                 const std::string& term);
};
