/*Gaussian Mixture Model (GMM) এবং Text Summarization-এর সংযোগ
তোমার প্রোজেক্টে Word Frequency Algorithm এবং TextRank Algorithm ব্যবহার করেছ, যা টেক্সট সামারাইজেশনের জনপ্রিয় দুইটি পদ্ধতি। তবে, তুমি জানতে চাচ্ছো কীভাবে Gaussian Mixture Model (GMM) এই প্রক্রিয়ার সাথে সম্পর্কিত হতে পারে। GMM সাধারণত soft clustering পদ্ধতি ব্যবহার করে, যেখানে প্রতিটি ডাটা পয়েন্ট (যেমন, একটি শব্দ বা বাক্য) একাধিক ক্লাস্টারের সাথে নির্দিষ্ট সম্ভাবনায় যুক্ত থাকে।

Text Summarization-এ GMM ব্যবহার করা যেতে পারে বাক্য বা শব্দগুলোকে বিভিন্ন গুরুত্ব অনুযায়ী শ্রেণীবদ্ধ করতে, যাতে গুরুত্বপূর্ণ তথ্য নির্ধারণ করা আরও কার্যকর হয়।

1️⃣ Word Frequency Algorithm ও GMM-এর সংযোগ
Word Frequency Algorithm শব্দের গুরুত্ব নির্ধারণের জন্য tokenizeSentences(), extractWordsFromSentences(), createWordFrequencyTable(), scoreSentences() ফাংশন ব্যবহার করে।

👉 GMM কীভাবে সাহায্য করতে পারে?

createWordFrequencyTable() এর মাধ্যমে আমরা প্রতিটি শব্দের frequency পাই, যা একটি পরিমাণগত মান দেয়।
GMM এই frequency data-কে ব্যবহার করে soft clustering-এর মাধ্যমে শব্দগুলোকে বিভিন্ন গুরুত্বের গ্রুপে ভাগ করতে পারে।
উদাহরণস্বরূপ, GMM তিনটি ক্লাস্টার তৈরি করতে পারে:
High Importance Words (যেমন "data", "algorithm", "summary")
Moderate Importance Words (যেমন "process", "sentence")
Low Importance Words (যেমন "is", "and", "the")
এই ক্লাস্টারিং sentence scoring (scoreSentences()) কে আরও নিখুঁত করে তুলতে পারে, কারণ শুধুমাত্র উচ্চ গুরুত্বের শব্দগুলোর উপর ভিত্তি করে বাক্যগুলোর গুরুত্ব নির্ধারণ করা সম্ভব হবে।

2️⃣ TextRank Algorithm ও GMM-এর সংযোগ
TextRank পদ্ধতিতে তুমি TF-IDF, Cosine Similarity, Sentence Graph, Summary Statistics ইত্যাদি ব্যবহার করছ। এই পদ্ধতিতে প্রতিটি বাক্যকে একটি node হিসেবে ধরা হয় এবং বাক্যগুলোর মধ্যে সম্পর্ক (similarity) বিশ্লেষণ করে গুরুত্বপূর্ণ বাক্যগুলো নির্বাচন করা হয়।

👉 GMM কীভাবে সাহায্য করতে পারে?

Cosine Similarity এবং TF-IDF স্কোর ব্যবহার করে GMM বাক্যগুলোর soft clustering করতে পারে।
উদাহরণস্বরূপ, GMM বাক্যগুলোকে নিম্নলিখিত তিনটি ক্লাস্টারে ভাগ করতে পারে:
Highly Relevant Sentences (গুরুত্বপূর্ণ বাক্য)
Moderately Relevant Sentences (মাঝারি গুরুত্বপূর্ণ বাক্য)
Less Relevant Sentences (কম গুরুত্বপূর্ণ বাক্য)
এতে TextRank Algorithm শুধুমাত্র Highly Relevant Sentences থেকে সংক্ষেপণ তৈরি করতে পারবে, যা summary-কে আরও বেশি কার্যকর এবং তথ্যবহুল করবে।

কেন GMM সহায়ক?
✅ Soft Clustering: K-Means-এর মতো হার্ড ক্লাস্টারিং নয়, বরং GMM প্রতিটি শব্দ বা বাক্যের সম্ভাব্যতা নির্ধারণ করে, যা বেশি নমনীয় এবং কার্যকর।
✅ Sentences Filtering: Word Frequency এবং TextRank থেকে পাওয়া ডাটা ফিল্টার করতে সাহায্য করে, যাতে summary-এর মান বাড়ে।
✅ Optimization of Summary: কম গুরুত্বপূর্ণ বাক্য বাদ দিয়ে শুধু প্রয়োজনীয় তথ্য সংক্ষেপণে রাখা সহজ হয়।

শেষ কথা
তুমি Word Frequency Algorithm এবং TextRank Algorithm ব্যবহার করে গুরুত্বপূর্ণ শব্দ ও বাক্য খুঁজে বের করছো, আর GMM এই তথ্যকে ক্লাস্টারিং-এর মাধ্যমে শ্রেণীবদ্ধ করতে পারে, যাতে সংক্ষেপণ আরও কার্যকর হয়।

এভাবে GMM, Word Frequency এবং TextRank একসাথে ব্যবহার করে একটি শক্তিশালী টেক্সট সামারাইজেশন মডেল তৈরি করা যায়, যা আরও বেশি নিখুঁত এবং তথ্যসমৃদ্ধ সংক্ষেপণ দিতে পারে। 😊🚀







 */


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <sstream>
std::string toLower(std::string str) {
    for (char& c : str) {
        
        if (c >= 'A' && c <= 'Z') {
            c += 'a' - 'A';  
        }
    }
    return str;
}


class TFIDFCalc {
    public:
        double tf(const std::vector<std::string>& doc, const std::string& term) {
            double count = 0;
            for (const std::string& word : doc) {
                if (toLower(term) == toLower(word)) {
                    count++;
                }
            }
            return count / doc.size();
        }
    
        double idf(const std::vector<std::vector<std::string>>& docs, const std::string& term) {
            double docsWithTerm = 0;
            for (const std::vector<std::string>& doc : docs) {
                for (const std::string& word : doc) {
                    if (toLower(term) == toLower(word)) {
                        docsWithTerm++;
                        break;
                    }
                }
            }
            return log(docs.size() / docsWithTerm);
        }
    
        double tfIdf(const std::vector<std::string>& doc, const std::vector<std::vector<std::string>>& docs, const std::string& term) {
            return tf(doc, term) * idf(docs, term);
        }
    
    private:
        std::string toLower(std::string str) {
            for (char& c : str) {
               
                if (c >= 'A' && c <= 'Z') {
                    c += 'a' - 'A';
                }
            }
            return str;
        }
    };
    

// Sentence class
// class Sentence {
// private:
//     int number;
//     std::string text;
//     std::string processedText;
//     double score;
//     std::vector<std::string> words;
//     std::vector<std::string> allExclusiveWords;
//     std::vector<std::vector<std::string>> paragraph;
//     std::unordered_map<std::string, double> tfidf;

// public:
//     Sentence(const std::string& txt, int num) {
//         number = num;
//         text = trim(txt);
//         processedText = stopWordRemoval(text);
//         score = 0.0;

//         // Split processed text into words
//         std::istringstream iss(processedText);
//         std::string word;
//         while (iss >> word) {
//             words.push_back(word);
//         }
//     }

//     void tfidfCalculation() {
//         TFIDFCalc calculator;

//         for (const std::string& s : allExclusiveWords) {
//             tfidf[s] = 0.0;
//         }

//         for (const std::vector<std::string>& doc : paragraph) {
//             for (const std::string& w : words) {
//                 double tfidfVal = calculator.tfIdf(words, paragraph, w);
//                 tfidf[w] = tfidfVal;
//             }
//         }
//     }

//     void setParagraph(const std::vector<std::vector<std::string>>& para) {
//         paragraph = para;
//     }

//     void setAllExclusiveWords(const std::vector<std::string>& words) {
//         allExclusiveWords = words;
//     }

//     void setScore(double s) {
//         score = s;
//     }

//     double getScore() const {
//         return score;
//     }

//     std::string getText() const {
//         return text;
//     }

//     std::vector<std::string> getAllExclusiveWords() const {
//         return allExclusiveWords;
//     }

//     std::unordered_map<std::string, double> getTfidf() const {
//         return tfidf;
//     }

//     std::vector<std::string> getWords() const {
//         return words;
//     }

//     std::string getProcessedText() const {
//         return processedText;
//     }

//     std::string toString() const {
//         return "\nSentence{number=" + std::to_string(number) + 
//                ", text='" + text + "', score=" + std::to_string(score) + "}";
//     }

// private:
//     std::string trim(const std::string& str) {
//         size_t first = str.find_first_not_of(" \t\n\r");
//         if (first == std::string::npos) return "";
//         size_t last = str.find_last_not_of(" \t\n\r");
//         return str.substr(first, (last - first + 1));
//     }

//     std::string punctuationRemover(const std::string& content) {
//         std::string noPunctuationSentence = "";
//         for (char c : content) {
//             if (c != '.' && c != ',' && c != '!' && c != ':' &&
//                 c != ';' && c != '"' && c != '?' && c != '-' &&
//                 c != '(' && c != ')' && c != '*' && 
//                 c != '\r' && c != '\n') {
//                 noPunctuationSentence += c;
//             }
//         }
//         return noPunctuationSentence;
//     }

//     std::string stopWordRemoval(const std::string& input) {
//         const std::vector<std::string> stopWords = {
//             "a", "able", "about", "after", "all", "also", "am", " ", "The", "\r", "\n",
//             "an", "and", "any", "are", "as", "at", "be", "because", "been", "but", "by", 
//             "can", "cannot", "could", "did", "do", "does", "either", "else", "ever", "every", 
//             "for", "from", "get", "got", "had", "has", "have", "he", "her", "hers", "him", 
//             "his", "how", "I", "if", "in", "into", "is", "it", "its", "just", "let", "like", 
//             "likely", "may", "me", "might", "most", "must", "my", "neither", "no", "nor", 
//             "not", "of", "off", "often", "on", "only", "or", "other", "our", "own", "said", 
//             "say", "says", "she", "should", "so", "some", "than", "that", "the", "their", 
//             "them", "then", "there", "these", "they", "this", "they're", "to", "too", 
//             "that's", "us", "was", "we", "were", "what", "when", "where", "which", "while", 
//             "who", "whom", "why", "will", "with", "would", "yet", "you", "your", "you're"
//         };

//         std::string noPunctuation = punctuationRemover(input);
//         std::transform(noPunctuation.begin(), noPunctuation.end(), noPunctuation.begin(), ::tolower);
        
//         std::istringstream iss(noPunctuation);
//         std::string word;
//         std::string output = "";
        
//         while (iss >> word) {
//             bool isStopWord = false;
//             for (const std::string& stopWord : stopWords) {
//                 if (word == stopWord) {
//                     isStopWord = true;
//                     break;
//                 }
//             }
            
//             if (!isStopWord) {
//                 output += word + " ";
//             }
//         }
        
//         return output;
//     }
// };



// class Sentence {
//     private:
//         int number;
//         std::string text;
//         std::string processedText;
//         double score;
//         std::vector<std::string> words;
//         std::vector<std::string> allExclusiveWords;
//         std::vector<std::vector<std::string>> paragraph;
//         std::unordered_map<std::string, double> tfidf;
    
//     public:
//         Sentence(const std::string& txt, int num) {
//             number = num;
//             text = trim(txt);
//             processedText = stopWordRemoval(text);
//             score = 0.0;
    
//             // Split processed text into words
//             std::istringstream iss(processedText);
//             std::string word;
//             while (iss >> word) {
//                 words.push_back(word);  // 'push_back' পরিবর্তিত ফাংশন ব্যবহার করা হবে
//             }
//         }
    
//         void tfidfCalculation() {
//             TFIDFCalc calculator;
    
//             for (const std::string& s : allExclusiveWords) {
//                 tfidf[s] = 0.0;
//             }
    
//             for (const std::vector<std::string>& doc : paragraph) {
//                 for (const std::string& w : words) {
//                     double tfidfVal = calculator.tfIdf(words, paragraph, w);
//                     tfidf[w] = tfidfVal;
//                 }
//             }
//         }
    
//         void setParagraph(const std::vector<std::vector<std::string>>& para) {
//             paragraph = para;
//         }
    
//         void setAllExclusiveWords(const std::vector<std::string>& words) {
//             allExclusiveWords = words;
//         }
    
//         void setScore(double s) {
//             score = s;
//         }
    
//         double getScore() const {
//             return score;
//         }
    
//         std::string getText() const {
//             return text;
//         }
    
//         std::vector<std::string> getAllExclusiveWords() const {
//             return allExclusiveWords;
//         }
    
//         std::unordered_map<std::string, double> getTfidf() const {
//             return tfidf;
//         }
    
//         std::vector<std::string> getWords() const {
//             return words;
//         }
    
//         std::string getProcessedText() const {
//             return processedText;
//         }
    
//         std::string toString() const {
//             return "\nSentence{number=" + std::to_string(number) + 
//                    ", text='" + text + "', score=" + std::to_string(score) + "}";
//         }
    
//     private:
//         std::string trim(const std::string& str) {
//             size_t first = 0, last = str.length() - 1;
    
//             // প্রথমে স্পেস দিয়ে শুরু হলে সেটি বাদ দেওয়া
//             while (first <= last && (str[first] == ' ' || str[first] == '\t' || str[first] == '\n')) {
//                 first++;
//             }
    
//             // শেষে স্পেস থাকলে সেটি বাদ দেওয়া
//             while (last > first && (str[last] == ' ' || str[last] == '\t' || str[last] == '\n')) {
//                 last--;
//             }
    
//             // সাবস্ট্রিং হিসাবে প্রাসঙ্গিক অংশ ফেরত দেওয়া
//             return str.substr(first, last - first + 1);
//         }
    
//         std::string punctuationRemover(const std::string& content) {
//             std::string noPunctuationSentence = "";
//             for (char c : content) {
//                 if (c != '.' && c != ',' && c != '!' && c != ':' &&
//                     c != ';' && c != '"' && c != '?' && c != '-' &&
//                     c != '(' && c != ')' && c != '*' && 
//                     c != '\r' && c != '\n') {
//                     noPunctuationSentence += c;
//                 }
//             }
//             return noPunctuationSentence;
//         }
    
//         std::string stopWordRemoval(const std::string& input) {
//             const std::vector<std::string> stopWords = {
//                 "a", "able", "about", "after", "all", "also", "am", " ", "The", "\r", "\n",
//                 "an", "and", "any", "are", "as", "at", "be", "because", "been", "but", "by", 
//                 "can", "cannot", "could", "did", "do", "does", "either", "else", "ever", "every", 
//                 "for", "from", "get", "got", "had", "has", "have", "he", "her", "hers", "him", 
//                 "his", "how", "I", "if", "in", "into", "is", "it", "its", "just", "let", "like", 
//                 "likely", "may", "me", "might", "most", "must", "my", "neither", "no", "nor", 
//                 "not", "of", "off", "often", "on", "only", "or", "other", "our", "own", "said", 
//                 "say", "says", "she", "should", "so", "some", "than", "that", "the", "their", 
//                 "them", "then", "there", "these", "they", "this", "they're", "to", "too", 
//                 "that's", "us", "was", "we", "were", "what", "when", "where", "which", "while", 
//                 "who", "whom", "why", "will", "with", "would", "yet", "you", "your", "you're"
//             };
    
//             std::string noPunctuation = punctuationRemover(input);
//             std::transform(noPunctuation.begin(), noPunctuation.end(), noPunctuation.begin(), ::tolower);
            
//             std::istringstream iss(noPunctuation);
//             std::string word;
//             std::string output = "";
            
//             while (iss >> word) {
//                 bool isStopWord = false;
//                 for (const std::string& stopWord : stopWords) {
//                     if (word == stopWord) {
//                         isStopWord = true;
//                         break;
//                     }
//                 }
                
//                 if (!isStopWord) {
//                     output += word + " ";
//                 }
//             }
            
//             return output;
//         }
//     };
    





class Sentence {
private:
    int number;
    std::string text;
    std::string processedText;
    double score;
    std::vector<std::string> words;
    std::vector<std::string> allExclusiveWords;
    std::vector<std::vector<std::string>> paragraph;
    std::unordered_map<std::string, double> tfidf;

public:
    Sentence(const std::string& txt, int num) {
        number = num;
        text = trim(txt);
        processedText = stopWordRemoval(text);
        score = 0.0;

        // Split processed text
        std::string word = "";
        for (char c : processedText) {
            if (c == ' ' || c == '\n' || c == '\t') {
                if (!word.empty()) {
                    words.push_back(word);  
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {  
            words.push_back(word);
        }
    }

    void tfidfCalculation() {
        TFIDFCalc calculator;

        for (const std::string& s : allExclusiveWords) {
            tfidf[s] = 0.0;
        }

        for (const std::vector<std::string>& doc : paragraph) {
            for (const std::string& w : words) {
                double tfidfVal = calculator.tfIdf(words, paragraph, w);
                tfidf[w] = tfidfVal;
            }
        }
    }

    void setParagraph(const std::vector<std::vector<std::string>>& para) {
        paragraph = para;
    }

    void setAllExclusiveWords(const std::vector<std::string>& words) {
        allExclusiveWords = words;
    }

    void setScore(double s) {
        score = s;
    }

    double getScore() const {
        return score;
    }

    std::string getText() const {
        return text;
    }

    std::vector<std::string> getAllExclusiveWords() const {
        return allExclusiveWords;
    }

    std::unordered_map<std::string, double> getTfidf() const {
        return tfidf;
    }

    std::vector<std::string> getWords() const {
        return words;
    }

    std::string getProcessedText() const {
        return processedText;
    }

    std::string toString() const {
        return "\nSentence{number=" + std::to_string(number) + 
               ", text='" + text + "', score=" + std::to_string(score) + "}";
    }

private:
    std::string trim(const std::string& str) {
        size_t first = 0, last = str.length() - 1;

        while (first <= last && (str[first] == ' ' || str[first] == '\t' || str[first] == '\n')) {
            first++;
        }

        while (last > first && (str[last] == ' ' || str[last] == '\t' || str[last] == '\n')) {
            last--;
        }

        return str.substr(first, last - first + 1);
    }

    std::string punctuationRemover(const std::string& content) {
        std::string noPunctuationSentence = "";
        for (char c : content) {
            if (c != '.' && c != ',' && c != '!' && c != ':' &&
                c != ';' && c != '"' && c != '?' && c != '-' &&
                c != '(' && c != ')' && c != '*' && 
                c != '\r' && c != '\n') {
                noPunctuationSentence += c;
            }
        }
        return noPunctuationSentence;
    }

    std::string stopWordRemoval(const std::string& input) {
        const std::vector<std::string> stopWords = {
            "a", "able", "about", "after", "all", "also", "am", " ", "The", "\r", "\n",
            "an", "and", "any", "are", "as", "at", "be", "because", "been", "but", "by", 
            "can", "cannot", "could", "did", "do", "does", "either", "else", "ever", "every", 
            "for", "from", "get", "got", "had", "has", "have", "he", "her", "hers", "him", 
            "his", "how", "I", "if", "in", "into", "is", "it", "its", "just", "let", "like", 
            "likely", "may", "me", "might", "most", "must", "my", "neither", "no", "nor", 
            "not", "of", "off", "often", "on", "only", "or", "other", "our", "own", "said", 
            "say", "says", "she", "should", "so", "some", "than", "that", "the", "their", 
            "them", "then", "there", "these", "they", "this", "they're", "to", "too", 
            "that's", "us", "was", "we", "were", "what", "when", "where", "which", "while", 
            "who", "whom", "why", "will", "with", "would", "yet", "you", "your", "you're"
        };

        std::string noPunctuation = punctuationRemover(input);

        for (size_t i = 0; i < noPunctuation.size(); ++i) {
            noPunctuation[i] = std::tolower(noPunctuation[i]);
        }
        
    
        std::string word = "";
        std::string output = "";
        
        for (char c : noPunctuation) {
            if (c == ' ' || c == '\n' || c == '\t') {
                if (!word.empty()) {
                    bool isStopWord = false;
                    for (const std::string& stopWord : stopWords) {
                        if (word == stopWord) {
                            isStopWord = true;
                            break;
                        }
                    }
                    if (!isStopWord) {
                        output += word + " ";
                    }
                    word = "";
                }
            } else {
                word += c;
            }
        }
        if (!word.empty()) {  
            bool isStopWord = false;
            for (const std::string& stopWord : stopWords) {
                if (word == stopWord) {
                    isStopWord = true;
                    break;
                }
            }
            if (!isStopWord) {
                output += word + " ";
            }
        }

        return output;
    }
};



class CosineSimilarity {
public:
    double dotProduct(const Sentence& s1, const Sentence& s2) {
        double numerator = calculateDotProduct(s1, s2);
        double denominator = (mod(s1) * mod(s2));
        return numerator / denominator;
    }

private:
    double calculateDotProduct(const Sentence& s1, const Sentence& s2) {
        double val = 0.0;
        for (const std::string& w : s1.getAllExclusiveWords()) {
            val += (s1.getTfidf().at(w) * s2.getTfidf().at(w));
        }
        return val;
    }

    double mod(const Sentence& A) {
        double val = 0.0;
        for (const std::string& s : A.getAllExclusiveWords()) {
            val += pow(A.getTfidf().at(s), 2);
        }
        return sqrt(val);
    }
};


class SummaryStatistics {
private:
    std::string context;
    std::string summary;
    int wordsInSummary;
    int wordsInContext;
    double reductionPercentage;

public:
    SummaryStatistics(const std::string& c, const std::string& s) {
        context = c;
        summary = s;
        wordsInContext = calculateWordCount(context);
        wordsInSummary = calculateWordCount(summary);
        reductionPercentage = static_cast<double>(wordsInSummary) / wordsInContext;
    }

    int getWordsInSummary() const {
        return wordsInSummary;
    }

    int getWordsInContext() const {
        return wordsInContext;
    }

    double getReductionPercentage() const {
        return reductionPercentage;
    }

private:
    int calculateWordCount(const std::string& text) {
        std::istringstream iss(text);
        int count = 0;
        std::string word;
        while (iss >> word) {
            count++;
        }
        return count;
    }
};


class SummaryTool {
private:
    std::string context;
    std::string summary;
    int sentenceCount;
    int summarySize;
    std::vector<Sentence> sentences;
    std::vector<std::string> allExclusiveWords;
    std::vector<std::vector<std::string>> docs;
    std::vector<std::vector<double>> csMatrix;
    std::vector<double> sentenceScores;

public:
    SummaryTool(const std::string& text) {
        context = text;
        summary = "";
        sentenceCount = countFullStops(text);
        csMatrix.resize(sentenceCount, std::vector<double>(sentenceCount, 0.0));
        summarySize = sentenceCount / 3;

        // Split text into sentences
        std::vector<std::string> sentenceArray = splitBySentence(text);
        for (size_t i = 0; i < sentenceArray.size(); i++) {
            sentences.push_back(Sentence(sentenceArray[i], i + 1));
        }

        
        createDocs();
        collectAllUniqueWords();
        calculateTfidf();
        calculateCosineSimilarity();
       // extractSummary(summarySize);
       extractSummary();
    }

    std::string getSummary() const {
        return summary;
    }

    std::string toString() const {
        return "SummaryTool{context='" + context + "', summary='" + summary + 
               "', sentenceCount=" + std::to_string(sentenceCount) + "}";
    }

private:
    std::vector<std::string> splitBySentence(const std::string& text) {
        std::vector<std::string> sentences;
        std::size_t start = 0;
        std::size_t end;
        
        while ((end = text.find('.', start)) != std::string::npos) {
            sentences.push_back(text.substr(start, end - start));
            start = end + 1;
        }
        
        if (start < text.length()) {
            sentences.push_back(text.substr(start));
        }
        
        return sentences;
    }

    int countFullStops(const std::string& text) {
        int count = 0;
        for (char c : text) {
            if (c == '.') count++;
        }
        return count;
    }

    void createDocs() {
        for (const Sentence& s : sentences) {
            std::string sen = s.getProcessedText();
            std::istringstream iss(sen);
            std::string word;
            std::vector<std::string> words;
            
            while (iss >> word) {
                words.push_back(word);
            }
            
            docs.push_back(words);
        }

        for (size_t i = 0; i < sentences.size(); i++) {
            sentences[i].setParagraph(docs);
        }
    }

    void collectAllUniqueWords() {
        for (const Sentence& s : sentences) {
            for (const std::string& w : s.getWords()) {
                if (std::find(allExclusiveWords.begin(), allExclusiveWords.end(), w) == allExclusiveWords.end()) {
                    allExclusiveWords.push_back(w);
                }
            }
        }

        for (size_t i = 0; i < sentences.size(); i++) {
            sentences[i].setAllExclusiveWords(allExclusiveWords);
        }
    }

    void calculateTfidf() {
        for (size_t i = 0; i < sentences.size(); i++) {
            sentences[i].tfidfCalculation();
        }
    }

    void calculateCosineSimilarity() {
        CosineSimilarity tool;
        
        for (int i = 0; i < sentenceCount; i++) {
            for (int j = 0; j < sentenceCount; j++) {
                csMatrix[i][j] = tool.dotProduct(sentences[i], sentences[j]);
            }
        }

        for (int i = 0; i < sentenceCount; i++) {
            double value = 0.0;
            for (int j = 0; j < sentenceCount; j++) {
                value += csMatrix[i][j];
            }
            sentences[i].setScore(value);
            sentenceScores.push_back(value);
        }
    }

    // void extractSummary(int n) {
    //     
    //     std::vector<double> sortedScores = sentenceScores;
    //     std::sort(sortedScores.begin(), sortedScores.end(), std::greater<double>());
        
    //     double threshold = sortedScores[n - 1];

    //     for (const Sentence& s : sentences) {
    //         if (s.getScore() >= threshold && !s.getText().empty()) {
    //             summary += s.getText() + ".\n";
    //         }
    //     }
    // }
    void extractSummary() {
        double mean = 0.0;
        for(double score : sentenceScores) {
            mean += score;
        }
        mean /= sentenceScores.size();
        
        double threshold = mean * 1.2; // 20% above mean
        
        for(const Sentence& s : sentences) {
            if(s.getScore() >= threshold && !s.getText().empty()) {
                summary += s.getText() + ".\n";
            }
        }
    }

};

#include <fstream>

int main(int argc, char* argv[]) {
    std::string inputFileName;
    std::string outputFileName = "output.txt";

    if (argc > 1) {
        inputFileName = argv[1];
    } else {
        std::cout << "Enter input file name: ";
        std::cin >> inputFileName;
    }
    

    std::ifstream inputFile(inputFileName);
    if (!inputFile.is_open()) {
        std::cerr << "Error: Could not open file " << inputFileName << std::endl;
        return 1;
    }
    
   
    std::string text;
    std::string line;
    while (std::getline(inputFile, line)) {
        text += line + " ";
    }
    inputFile.close();
    
    SummaryTool tool(text);
    std::string summary = tool.getSummary();
    
   
    std::cout << "Summary:" << std::endl;
    std::cout << summary << std::endl;
 
    std::ofstream outputFile(outputFileName);
    if (outputFile.is_open()) {
        outputFile << summary;
        outputFile.close();
        std::cout << "Summary written to " << outputFileName << std::endl;
    } else {
        std::cerr << "Error: Could not write to output file " << outputFileName << std::endl;
    }
    
    return 0;
}
