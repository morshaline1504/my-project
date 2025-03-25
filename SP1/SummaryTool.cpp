#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <memory>



class Sentence {

private:
    int order;
    std::string sentenceString;
    int numberOfWords;
    double score;



    int spaceCalculator(const std::string& sen) {
        int counter = 0;
        for (char c : sen) {
            if (c == ' ') {
              
                counter++;
            }
        }

        return counter;
    }



public:

   Sentence(const std::string& sen, int order) :
    order(order),
    sentenceString(sen),
    numberOfWords(spaceCalculator(sen) + 1),
    score(0.0) {
    


    size_t start = 0;
    size_t end = sen.size();


    while (start < end && (sen[start] == ' ' || sen[start] == '\t' || sen[start] == '\n')) {
        ++start;
    }


    while (end > start && (sen[end - 1] == ' ' || sen[end - 1] == '\t' || sen[end - 1] == '\n')) {
        --end;
    }

  
    sentenceString.clear();

    for (size_t i = start; i < end; ++i) {
        sentenceString += sen[i];
    }

}


    void setScore(double newScore) {

        score = newScore;
    }

    int getNumberOfWords()  {
       
        return numberOfWords;
    }

    const std::string& getSentenceString()  {
       
        return sentenceString;
    }

    double getScore()  {
      
        return score;
    }

    int getOrder()  {
        
        return order;
    }

    int siize() const {
        return numberOfWords;
    }
    int Length() const {
        return sentenceString.length();  
    }
    bool emptY() const {
        return sentenceString.empty();  
    }
    void pushback(const Sentence& s) {
       
        pushback(s);
    }
    
    
    
    std::string toString()  {

        std::string result = "\n\nSentence{";
        result += "order=" + std::to_string(order);
        result += ", sentenceString='" + sentenceString + "'";
        result += ", \nnumberOfWords=" + std::to_string(numberOfWords);
        

        std::string scoreStr = std::to_string(score);
        scoreStr = scoreStr.substr(0, scoreStr.find(".") + 3);


        result += ", \nscore=" + scoreStr;
        result += "}\n\n";
        return result;
    
    
    }

    
};

class SummaryTool {
private:
    static int order;
    std::string context;
    std::string summary;
    std::vector<std::shared_ptr<Sentence>> sentences;
    int noOfSentences;

    int noOfSentencesInSummary;
    std::vector<std::vector<double>> intersectionMatrix;
    std::map<std::shared_ptr<Sentence>, double> sentenceScores;
    std::vector<double> scoreOfSentences;

    std::vector<std::string> splitIntoSentences(const std::string& text) {
    std::vector<std::string> result;

    std::string current;
    bool inQuote = false;


    for (size_t i = 0; i < text.length(); i++) {
        current += text[i];

        if (text[i] == '"') {
            inQuote = !inQuote;
        }

        if (text[i] == '.' && !inQuote && 
            
            (i + 1 == text.length() || text[i + 1] == ' ' || text[i + 1] == '\n' || text[i + 1] == '\t')) {
            if (!current.empty()) {
               
                result.push_back(current);
                current.clear();
           
            }
       
       
     }
   
    }


    if (!current.empty()) {
        result.push_back(current);
    }

    return result;
}


   void calculateIntersectionMatrix() {
    
    intersectionMatrix = std::vector<std::vector<double>>(noOfSentences, std::vector<double>(noOfSentences));

    for (int i = 0; i < noOfSentences; i++) {
       
        for (int j = 0; j < noOfSentences; j++) {
            intersectionMatrix[i][j] = (sentences[i]->getNumberOfWords() + sentences[j]->getNumberOfWords()) / 2.0;
        }
   
   
    }

}


    void calculateScores() {

        for (int i = 0; i < noOfSentences; i++) {
            double scoreTemp = 0.0;

            for (int j = 0; j < noOfSentences; j++) {
                scoreTemp += intersectionMatrix[i][j];
            }

            sentences[i]->setScore(scoreTemp);
            scoreOfSentences.push_back(scoreTemp);
        
        }
   
    }

    // void extraction(int noOfSentencesInSummary) {
    //     std::sort(scoreOfSentences.begin(), scoreOfSentences.end(), std::greater<double>());
        
    //     if (noOfSentencesInSummary > 0 && scoreOfSentences.size() >= static_cast<size_t>(noOfSentencesInSummary)) {
    //         double threshold = scoreOfSentences[noOfSentencesInSummary - 1];

    //         // Sort sentences by original order for proper summary construction
    //         std::vector<std::shared_ptr<Sentence>> summaryParts;
    //         for (const auto& s : sentences) {
    //             if (s->getScore() >= threshold && !s->getSentenceString().empty()) {
    //                 summaryParts.push_back(s);
    //             }
            // }

            // // Sort by original order
            // std::sort(summaryParts.begin(), summaryParts.end(),
            //     [](const auto& a, const auto& b) {
            //         return a->getOrder() < b->getOrder();
            //     });

            // // Construct summary
    //         summary.clear();
    //         for (const auto& s : summaryParts) {
    //             summary += s->getSentenceString();
    //             summary += ".\n";
    //         }
    //     }
    // }


    void extraction(int noOfSentencesInSummary) {
  
    sortDescending(scoreOfSentences);

    if (noOfSentencesInSummary > 0 && scoreOfSentences.size() >= noOfSentencesInSummary) {
        double threshold = scoreOfSentences[noOfSentencesInSummary - 1]; 

        std::vector<Sentence*> summaryParts;  
        
        for (auto& s : sentences) {
            Sentence* rawPtr = s.get();  
           
            if (rawPtr->getScore() >= threshold && !rawPtr->getSentenceString().empty()) {
                summaryParts.push_back(rawPtr);
            }
        }

    
        sortByOrder(summaryParts);

        summary.clear();
        
        for (auto& s : summaryParts) {
            summary += s->getSentenceString();  
            summary += ".\n";
       
        }
    
    }

}


void swap(double& a, double& b) {
    double temp = a;
    a = b;
    b = temp;
}


void sortDescending(std::vector<double>& scores) {

    bool swapped;
    do {
        swapped = false;
        for (size_t i = 0; i < scores.size() - 1; ++i) {
            if (scores[i] < scores[i + 1]) {
                
                swap(scores[i], scores[i + 1]);  
                swapped = true;
            }
        }
   
    } while (swapped);

}



void swap(Sentence*& a, Sentence*& b) {
    Sentence* temp = a;
    a = b;
    b = temp;

}



void sortByOrder(std::vector<Sentence*>& summaryParts) {
    bool swapped;
    
    do {
        swapped = false;
        for (size_t i = 0; i < summaryParts.size() - 1; ++i) {
            if (summaryParts[i]->getOrder() > summaryParts[i + 1]->getOrder()) {
               
                swap(summaryParts[i], summaryParts[i + 1]);  
                swapped = true;
            }
       
        }
    
    } while (swapped);

}


    // int spaceCalculator(const std::string& sen) const {
    //     return std::count(sen.begin(), sen.end(), ' ');
    // }
   
    int spaceCalculator( std::string& sen) const {
    int spaceCount = 0;
    for (char c : sen) {
        if (c == ' ') {
       
            spaceCount++;
        }
    }
  
    return spaceCount;
}


public:
    // explicit SummaryTool(const std::string& inputContext) : 
    //     context(inputContext),
    //     noOfSentences(0),
    //     noOfSentencesInSummary(0) {
        
    //     auto sentencesArray = splitIntoSentences(context);
    //     noOfSentences = sentencesArray.size();
    //     noOfSentencesInSummary = noOfSentences / 2;

    //     for (const auto& sen : sentencesArray) {
    //         sentences.push_back(std::make_shared<Sentence>(sen, order++));
    //     }

    //     calculateIntersectionMatrix();
    //     calculateScores();
    //     extraction(noOfSentencesInSummary);

    //     std::cout << "Original text word count: " << spaceCalculator(context) + 1 << std::endl;
    //     std::cout << "Summary word count: " << spaceCalculator(summary) + 1 << std::endl;
    // }

    SummaryTool( std::string& inputContext) {

    context = inputContext;
    noOfSentences = 0;
    noOfSentencesInSummary = 0;
    

    std::vector<std::string> sentencesArray = splitIntoSentences(context);
    noOfSentences = sentencesArray.size();

    noOfSentencesInSummary = noOfSentences / 3;

    int order = 0; 

    for (const auto& sen : sentencesArray) {
        sentences.push_back(std::shared_ptr<Sentence>(new Sentence(sen, order++))); 
    }

    calculateIntersectionMatrix();

    calculateScores();
    extraction(noOfSentencesInSummary);

    std::cout << "Original text word count: " << spaceCalculator(context) + 2 << std::endl;
    
    std::cout << "Summary word count: " << spaceCalculator(summary) + 2 << std::endl;


}

    const std::string& getSummary()  {
      
        return summary;
    }

    std::string toString()  {
      
        return "SummaryTool{\nsummary='" + summary + "'\n}";
   
    }

};



int SummaryTool::order = 1;

// int main() {
//     std::string context = "The sun rises in the east and sets in the west. " 
//                           "Birds fly across the sky. " 
//                           "Trees sway with the wind. "
//                           "We should protect our environment to keep it safe and clean.";


//     SummaryTool tool(context);
//     std::cout << tool.getSummary() << std::endl;

//     return 0;
// }
#include <fstream>

// In main():




int main() {

    std::string context;
    std::ifstream inputFile("input.txt");  
    

    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open the file." << std::endl;
        return 1;
    }


    std::string line;
    while (std::getline(inputFile, line)) {
        context += line + "\n";  
    }


    SummaryTool tool(context);
    std::cout << tool.getSummary() << std::endl;
    
   
    return 0;

}
