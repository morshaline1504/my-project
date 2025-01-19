#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <set>
using namespace std;


struct wordlist {
    string word;
    double TF_IDF;
};

class TFIDFCalculator {
public:
    
    double tf(const vector<string>& doc, const string& term) {
        double count = 0;
        for (const auto& word : doc) {
            if (term == word) {
                count++;
            }
        }
        return count / doc.size();
    }

   
    double idf(const vector<vector<string>>& docs, const string& term) {
        double n = 0;
        for (const auto& doc : docs) {
            if (find(doc.begin(), doc.end(), term) != doc.end()) {
                n++;
            }
        }
        if (n == 0) {
            return 0; 
        }
        return log(docs.size() / n);
    }

    
    double tfIdf(const vector<string>& doc, const vector<vector<string>>& docs, const string& term) {
        return tf(doc, term) * idf(docs, term);
    }
};

int main() {
    
    vector<string> doc1 = {"Lorem", "ipsum", "dolor", "ipsum", "sit", "ipsum"};
    vector<string> doc2 = {"Vituperata", "incorrupte", "at", "ipsum", "pro", "quo"};
    vector<string> doc3 = {"Has", "persius", "disputationi", "id", "simul"};
    vector<vector<string>> documents = {doc1, doc2, doc3};

    TFIDFCalculator calculator;

    
    vector<wordlist> linklist;

    
    set<string> uniqueWords;
    for (const auto& doc : documents) {
        uniqueWords.insert(doc.begin(), doc.end());
    }

    map<string, double> idfCache;
    for (const auto& word : uniqueWords) {
        idfCache[word] = calculator.idf(documents, word);
    }

   
    for (const auto& doc : documents) {
        for (const auto& word : doc) {
            double tfidf = calculator.tf(doc, word) * idfCache[word];
            linklist.push_back({word, tfidf});
        }
    }

    
    for (const auto& entry : linklist) {
        cout << "Word: " << entry.word << ", TF-IDF: " << entry.TF_IDF << endl;
    }

    return 0;
}
