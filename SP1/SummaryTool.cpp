// #include <iostream>
// #include <string>
// #include <vector>
// #include <map>
// #include <sstream>
// #include <algorithm>
// #include <cctype>
// #include <cmath>



// using namespace std;



// class SummaryTool {
// private:
//     std::string text = "Battling pandemic fatigue: Some feel burned out as the Covid-19 outbreak drags on with no end in sight\n" +
//                 "\n" +
//                 "Freelance writer Sng Ler Jun has been taking on more writing assignments since March to earn extra money for his family and himself.\n" +
//                 "\n" +
//                 "His 55-year-old mother was retrenched from a part-time job as a food promoter in February and his father, a 59-year-old taxi driver, has seen earnings fall since the start of the coronavirus pandemic.\n" +
//                 "\n" +
//                 "As a result, the 24-year-old, who is doing a communications degree from the University at Buffalo at the Singapore Institute of Management, said he feels \"pressured to work harder\".\n" +
//                 "\n" +
//                 "The worry of finding a stable job after he graduates in December keeps him up at night. \"I'm doing unpaid writing work to beef up my resume so it'll help in my job hunt,\" said Sng, who is an only child.\n" +
//                 "\n" +
//                 "Still, he feels \"plagued by the uncertainty\" as he does not know when the economy will improve. \"It's demoralising thinking about it and I feel burned out.\"\n" +
//                 "\n" +
//                 "Because of this, his mood and energy has been low and he no longer enjoys the walks he used to take in the neighbourhood.\n" +
//                 "\n" +
//                 "Dr Annabelle Chow, principal clinical psychologist at Annabelle Psychology, said the burnout a person experiences due to effects brought about by Covid-19 is a sign of pandemic fatigue.\n" +
//                 "\n" +
//                 "\"Pandemic fatigue describes a mental state where a prolonged, heightened state of fear and caution leads to a form of burnout. Although it is not classified as a mental disorder, the effects of pandemic fatigue are nevertheless real and have an impact on those experiencing it,\" she said.\n" +
//                 "\n" +
//                 "Signs include reduced socialising with others; feeling restless, sad, helpless, unmotivated and frustrated; being irritable and sensitive; and having low mood and energy, and insomnia.\n" +
//                 "\n" +
//                 "Long-term worries about a pandemic can take a toll on mental and emotional health and may result in the worsening of mental health conditions and chronic health problems.\n" +
//                 "\n" +
//                 "It may also lead to headaches, an inability to focus, digestive issues, insomnia and a weakened immune system, ultimately affecting a person's overall daily functioning.\n" +
//                 "\n" +
//                 "Terri Chen, senior clinical psychologist at the National University Hospital's (NUH) Department of Psychological Medicine, said it is likely that people started feeling these effects in April when the circuit breaker here was extended.\n" +
//                 "\n" +
//                 "The restrictions were a \"drastic change\" to people's daily routine and way of life.\n" +
//                 "\n" +
//                 "\"Everyone was required to adapt in a short amount of time and many people were accepting of these restrictions as they thought it was a short-term measure to deal with the virus,\" said Chen, who is head of psychology at NUH.\n" +
//                 "\n" +
//                 "\"But when the circuit breaker was extended and subsequent announcements about phase one and phase two were made, it was hard for people to keep up, and even more so with no clear end in sight.\"\n" +
//                 "\n" +
//                 "Dr Chow said seniors, children, caregivers, front-line workers, those who are living alone or socially isolated, and those who already struggle with depression and anxiety have an increased risk of getting pandemic fatigue.\n" +
//                 "\n" +
//                 "Working adults have also been hit hard. Dr Geraldine Tan, director and principal psychologist at The Therapy Room, started noticing signs of pandemic fatigue in her clients last month.\n" +
//                 "\n" +
//                 "\"The uncertainty of the job market and the impending crisis get them down. The breaks they used to take overseas are now non-existent and the work they do has taken a radical shift for some, especially if they are working from home,\" she said.\n" +
//                 "\n" +
//                 "\"Each day becomes more routine and mundane. People in Singapore are very used to travelling and now we appear to be imprisoned on our island.\"\n" +
//                 "\n" +
//                 "For those working or studying from home, the frequent need to be connected via video conferencing also contributes to the fatigue.\n" +
//                 "\n" +
//                 "People report feeling exhausted after virtual interactions, a phenomenon known as \"Zoom fatigue\", although it also applies to other video-conferencing platforms like Google Hangouts, Skype or FaceTime.\n" +
//                 "\n" +
//                 "Sng, who has been attending online classes since late April, said he sometimes does not switch on his webcam during lessons.\n" +
//                 "\n" +
//                 "\"I feel like the lack of a physical presence makes me less accountable. I've put on 5kg since the circuit breaker and I don't want people to see me looking like a mess at home. I was also sick of looking at my own face on the screen.\"\n" +
//                 "\n" +
//                 "NUH's Chen said a lot of energy is required to pay attention to non-verbal communication, which is harder to pick up over video conferencing.\n" +
//                 "\n" +
//                 "\"The multi-person screens tax the brain further from the need to process and decode all the information at once. Staring at your own face during the meetings can be stressful too,\" she added.\n" +
//                 "\n" +
//                 "One danger of pandemic fatigue is that people may drop their guard against the virus.\n" +
//                 "\n" +
//                 "According to a Sunday Times survey of 1,000 people aged 16 and above, people in Singapore are becoming weary of the rules to limit the spread of the coronavirus.\n" +
//                 "\n" +
//                 "It showed that 44 per cent of people are tired of following the necessary health measures. These include having to wear a mask, checking in with SafeEntry, limiting the size of physical gatherings with friends and family, and not being able to travel overseas.\n" +
//                 "\n" +
//                 "Dr Chow said the constant barrage of Covid-19 news and advisories could actually be desensitising and complacency may set in.\n" +
//                 "\n" +
//                 "\"Repeated exposure to pandemic-related news will eventually diminish the initial feelings of anxiety and caution. Consequently, we may begin to engage in behaviours that were initially inhibited by the anxiety responses, such as not adhering to safe distancing rules or washing our hands as regularly as we did before,\" she said.\n" +
//                 "\n" +
//                 "Habituation - the progressive decrease in response, such as feelings of anxiety, after repeated exposure to a stimulus - has caused people to become less careful or conscious about the precautions they need to take than they were at the start of the pandemic, said Chen.\n" +
//                 "\n" +
//                 "\"This means that over time - especially if we or anyone we knew did not get Covid-19 - we are likely to be less careful or conscious about the precautions as it would appear that there is less of a need to maintain such levels of vigilance,\" she said.\n" +
//                 "\n" +
//                 "While it is normal to drop our guard when we see no end in sight, a reminder of the benefits of maintaining precautions and the consequences of not doing so would help people stay vigilant to fight Covid-19, Chen added.\n" +
//                 "\n" +
//                 "But musician Joe Chahal, 35, said he feels \"extremely tired\" of the situation even though he complies with the measures.\n" +
//                 "\n" +
//                 "\"I find it difficult to breathe comfortably with a mask and I don't feel like leaving my house because I have to wear it. There's also the hassle of constantly having to check in to places with SafeEntry. There are long queues just to enter a mall or a shop on weekends.\"\n" +
//                 "\n" +
//                 "Because of this, he hardly goes out and does not meet his friends much now.\n" +
//                 "\n" +
//                 "Dr Chow cautioned that social avoidance and distancing can make people feel isolated and lonely, and may increase stress and anxiety.\n" +
//                 "\n" +
//                 "Chen advised people to seek help from a psychologist if they experience persistent anxiety, hopelessness or sadness for more than two weeks, which in turn affects their performance and relationships.\n" +
//                 "\n" +
//                 "While it is normal to feel weary in response to the pandemic, it is important to remember that \"we are not alone in our struggles\", she said.\n" +
//                 "\n" +
//                 "\"This is a marathon and not a short sprint, so people need to manage their expectations and pace themselves so that they are able to go the distance,\" she added.\n" +
//                 "\n" +
//                 "\"It is important to remind ourselves that we are doing the best we can in an unprecedented situation that we are all experiencing for the first time in our lives.\"\n" +
//                 "\n" +
//                 "HOW TO COPE WITH PANDEMIC FATIGUE\n" +
//                 "Terri Chen, head of psychology and senior clinical psychologist at the National University Hospital's department of psychological medicine, gives some tips.\n" +
//                 "\n" +
//                 "BE AWARE: We cannot make changes if we are not aware of what is going on within us. When we are busy, it is easy to overlook emotions and behaviours that are warning signs for us. Practise awareness to take care of your mental health. Take some time to check in with yourself daily. This can be as short as one minute a day to observe and describe to yourself what you are thinking and feeling within.\n" +
//                 "\n" +
//                 "BE CREATIVE: Many of the ways we use to recharge have been thwarted or impacted by pandemic restrictions. Short getaways, for instance, are no longer an option. Neither are large gatherings, which feed our innate social needs.\n" +
//                 "\n" +
//                 "Being creative and open to new ideas and experiences can help you cope in the interim. For instance, you can travel vicariously with friends by having a \"watch party\" of a travel show and make a fantasy list of future travel plans together.\n" +
//                 "\n" +
//                 "BE KIND AND COMPASSIONATE: There are many things that are not within our control at this moment, which could leave us feeling angry and frustrated. This can lead to criticisms being directed towards ourselves or others, which may worsen our mood.\n" +
//                 "\n" +
//                 "Show kindness to yourself or others through one act a day. Research has shown that this can help us feel happier and it also boosts our immune system and energy levels.\n" +
//                 "\n" +
//                 "BE PATIENT: We do not know when the coronavirus pandemic will end and it is hard to be patient with the safety restrictions indefinitely. Make space for emotions, as it is impossible to think logically 100 per cent of the time.\n" +
//                 "\n" +
//                 "Try the \"five, four, three, two, one\" technique to relax: Look around you and name them aloud as you notice them: five things you can see, four things you can feel, three things you can hear, two things you can smell and one thing you can taste.\n" +
//                 "\n" +
//                 "BE EFFECTIVE: There are many tips and suggestions on how to cope with the pandemic, such as practising mindfulness or working out, and it can be overwhelming - and tiring - to try many things at once.\n" +
//                 "\n" +
//                 "It is more effective to identify what need - physical, emotional, intellectual or spiritual - is most pressing and try one technique at a time to gauge if it helps you.";



//     vector<string> sentences;
//     vector<string> textTable;
//     map<string, int> frequencyCounter;
//     map<string, double> sentencesScore;
//     vector<string> summary;

// public:
//     SummaryTool(string context) {
//         text = context;
//         tokenizeSentences();
//         mainProcess();
//     }



//     void setText(string newText) {
//         text = newText;
//     }

//     void mainProcess() {
//         extractWordsFromSentence();
//         createWordFrequencyTable();
//         scoreSentences();
//         generateSummary();
//     }

//     void tokenizeSentences() {
//         stringstream ss(text);
//         string sentence;
//         while (getline(ss, sentence, '.')) {
//             if (!sentence.empty()) {
//                 sentences.push_back(sentence + ". ");
//             }
//         }
//     }



//     void extractWordsFromSentence() {
//         string noPunctuation = punctuationRemover(text);
//         stringstream ss(noPunctuation);
//         string word;
//         vector<string> stopWords = {
//             "a", "able", "about", "after", "all", "also", "am", "an", "and", "any", "are", "as", "at", "be", "because", "been", "but", "by", "can", "cannot", "could", "did",
//             "do", "does", "either", "else", "ever", "every", "for", "from", "get", "got", "had", "has", "have", "he", "her", "hers", "him", "his", "how", "I",
//             "if", "in", "into", "is", "it", "its", "just", "let", "like", "likely", "may", "me", "might", "most", "must", "my", "neither", "no", "nor", "not", "of", "off",
//             "often", "on", "only", "or", "other", "our", "own", "said", "say", "says", "she", "should", "so", "some", "than", "that", "the", "their", "them", "then", "there",
//             "these", "they", "this", "to", "too", "us", "was", "we", "were", "what", "when", "where", "which", "while", "who", "whom", "why", "will", "with", "would", "yet", "you", "your"
//         };

//         while (ss >> word) {
//             word = toLowerCase(word);
//             if (find(stopWords.begin(), stopWords.end(), word) == stopWords.end()) {
//                 textTable.push_back(word);
//             }
//         }
//     }

//     void createWordFrequencyTable() {
//         for (const string& word : textTable) {
//             frequencyCounter[word]++;
//         }
//     }

//     void scoreSentences() {
//         for (const string& sentence : sentences) {
//             double sentenceScore = 0;
//             int noOfTotalWords = spaceCounter(sentence) + 1;
//             int noOfNonStopWords = countNonStopWords(sentence);

//             sentenceScore = static_cast<double>(noOfNonStopWords) / noOfTotalWords;
//             sentencesScore[sentence] = sentenceScore;
//         }
//     }



//     double findThreshold() {
//         double threshold = 0;
//         for (const auto& entry : sentencesScore) {
//             threshold += entry.second;
//         }
//         threshold /= sentences.size();
//         return threshold;
//     }



//     void generateSummary() {
//         double threshold = findThreshold();
//         for (const auto& entry : sentencesScore) {
//             if (entry.second > threshold) {
//                 summary.push_back(entry.first);
//             }
//         }
//     }

//     string getSummary() {
//         string summaryString;
//         for (const string& s : summary) {
//             summaryString += s;
//         }
//         return summaryString;
//     }



//     void showSummary() {
//         cout << "\n\nSummary:" << endl;
//         for (const string& s : summary) {
//             cout << s << endl;
//         }
//     }



// private:
//     string punctuationRemover(const string& content) {
//         string noPunctuation;
//         for (char c : content) {
//             if (!ispunct(c)) {
//                 noPunctuation += c;
//             }
//         }
//         return noPunctuation;
//     }



//     int spaceCounter(const string& sample) {
//         return count(sample.begin(), sample.end(), ' ');
//     }




//     int countNonStopWords(const string& sample) {
//         string noPunctuation = punctuationRemover(sample);
//         stringstream ss(noPunctuation);
//         string word;
//         vector<string> stopWords = {
//             "a", "able", "about", "after", "all", "also", "am", "an", "and", "any", "are", "as", "at", "be", "because", "been", "but", "by", "can", "cannot", "could", "did",
//             "do", "does", "either", "else", "ever", "every", "for", "from", "get", "got", "had", "has", "have", "he", "her", "hers", "him", "his", "how", "I",
//             "if", "in", "into", "is", "it", "its", "just", "let", "like", "likely", "may", "me", "might", "most", "must", "my", "neither", "no", "nor", "not", "of", "off",
//             "often", "on", "only", "or", "other", "our", "own", "said", "say", "says", "she", "should", "so", "some", "than", "that", "the", "their", "them", "then", "there",
//             "these", "they", "this", "to", "too", "us", "was", "we", "were", "what", "when", "where", "which", "while", "who", "whom", "why", "will", "with", "would", "yet", "you", "your"
//         };

//         int noOfNonStopWords = 0;
//         while (ss >> word) {
//             word = toLowerCase(word);
//             if (find(stopWords.begin(), stopWords.end(), word) == stopWords.end()) {
//                 noOfNonStopWords++;
//             }
//         }
//         return noOfNonStopWords;
//     }

//     string toLowerCase(const string& str) {
//         string lowerStr = str;
//         transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
//         return lowerStr;
//     }
// };

#include <string>

#include <vector>

#include <unordered_map>

#include <algorithm>
#include <sstream>

#include <iostream>

class SummaryTool {

private:
    std::string text;

    std::vector<std::string> textTable;

    std::vector<std::string> sentences;
    std::unordered_map<std::string, int> frequencyCounter;

    std::unordered_map<std::string, double> sentencesScore;

    std::vector<std::string> summary;

    std::vector<std::string> stop_words = {
        "a", "able", "about", "after", "all", "also", "am", "an", "and",
        "any", "are", "as", "at", "be", "because", "been", "but", "by",
        "can", "cannot", "could", "did", "do", "does", "either", "else",
        "ever", "every", "for", "from", "get", "got", "had", "has", "have",
        "he", "her", "hers", "him", "his", "how", "i", "if", "in", "into",
        "is", "it", "its", "just", "let", "like", "likely", "may", "me",
        "might", "most", "must", "my", "neither", "no", "nor", "not", "of",
        "off", "often", "on", "only", "or", "other", "our", "own", "said",
        "say", "says", "she", "should", "so", "some", "than", "that", "the",
        "their", "them", "then", "there", "these", "they", "this", "they're",
        "to", "too", "that's", "us", "was", "we", "were", "what", "when",
        "where", "which", "while", "who", "whom", "why", "will", "with",
        "would", "yet", "you", "your", "you're"
    };


    int fullstopCounter(const std::string& sample) {

        int fullstop = 0;
        for (char c : sample) {

            if (c == '.') fullstop++;
        }

        return fullstop;
    }

    
int spaceCounter(const std::string& sample) {

    int space = 0;

    bool inWord = false;

    for (char c : sample) {
        if (c == ' ') {

            if (inWord) {

                space++; 

                inWord = false;
            }
        } else {

            inWord = true;
        }
    }
    
    
    if (inWord) {

        space++;
    }

    return space;  
}


std::string punctuationRemover(const std::string& content) {


    std::string noPunctuationSentence;

    for (char c : content) {
        
        if (c != '.' && c != ',' && c != '!' && c != ':' && 

            c != ';' && c != '"' && c != '?' && c != '-' && 

            c != '(' && c != ')' && c != '*' && c != '\r' && 
            c != '\n')
             {

            noPunctuationSentence += c;
        }
    }

    return noPunctuationSentence;
}

    

    std::string toLowerCase(const std::string& str) {

    std::string result = str; 

    for (size_t i = 0; i < result.length(); ++i) {
        
        if (result[i] >= 'A' && result[i] <= 'Z') {
           
            result[i] = result[i] + ('a' - 'A');
        }
    }
    return result;
}


    void tokenizeSentences() {

        std::string currentSentence;
        
        for (char c : text) {
            if (c == '.') {
                if (!currentSentence.empty()) {
                    sentences.push_back(currentSentence);
                    currentSentence.clear();
                }
            } else {
                currentSentence += c;
            }
        }
        if (!currentSentence.empty()) {
            sentences.push_back(currentSentence);
        }
    }

   int noOfNonStopWords(const std::string& sample) {
    std::string noPunctuation = punctuationRemover(sample); 
    std::string lowercased = toLowerCase(noPunctuation);  
    
    int count = 0;
    std::string word;
    
    for (size_t i = 0; i < lowercased.size(); ++i) {
        char ch = lowercased[i];
        
        if (ch == ' ' || (ch == '.' || ch == ',' || ch == '?' || ch == '!' || ch == ';' || ch == ':' || ch == '-' || ch == '"')) {
            if (!word.empty()) {
                
                bool isStopWord = false;
                for (size_t j = 0; j < stop_words.size(); ++j) {
                    if (stop_words[j] == word) {
                        isStopWord = true;
                        break;
                    }
                }
                
               
                if (!isStopWord) {
                    count++;
                }
                
                
                word.clear();
            }
        } else {
           
            word += ch;
        }
    }
    
   
    if (!word.empty()) {
        bool isStopWord = false;
        for (size_t j = 0; j < stop_words.size(); ++j) {
            if (stop_words[j] == word) {
                isStopWord = true;
                break;
            }
        }

        if (!isStopWord) {
            count++;
        }
    }

    return count;
}


void extractWordsFromSentence() {
    std::string noPunctuation = punctuationRemover(text);
    std::string lowercased = toLowerCase(noPunctuation);

    std::string word;
    for (char c : lowercased) {
       
        if (c != ' ' && c != '.' && c != ',' && c != '!' && c != ':' &&
            c != ';' && c != '"' && c != '?' && c != '-' && c != '(' && 
            c != ')' && c != '*' && c != '\r' && c != '\n') {
            word += c;
        } else {
                      
            if (!word.empty()) {
                
                bool isStopWord = false;
                for (const auto& stop_word : stop_words) {
                    if (word == stop_word) {
                        isStopWord = true;
                        break;
                    }
                }
                if (!isStopWord) {
                    textTable.push_back(word);
                }
                word.clear();  
            }
        }
    }

   
    if (!word.empty()) {
        bool isStopWord = false;
        for (const auto& stop_word : stop_words) {
            if (word == stop_word) {
                isStopWord = true;
                break;
            }
        }
        if (!isStopWord) {
            textTable.push_back(word);
        }
    }
}


    void createWordFrequencyTable() {
        for (const auto& word : textTable) {
            frequencyCounter[word]++;
        }
    }
void scoreSentences() {
    for (const auto& sentence : sentences) {
        int totalWords = spaceCounter(sentence);
        int nonStopWords = noOfNonStopWords(sentence);
        
        
        double score = (double)nonStopWords / totalWords;
        sentencesScore[sentence] = score;
    }
}


    double findThreshold() {
        if (sentencesScore.empty()) return 0.0;
        
        double sum = 0.0;
        for (const auto& pair : sentencesScore) {
            sum += pair.second;
        }
        return sum / sentencesScore.size();
    }

    void generateSummary() {
        double threshold = findThreshold();
        for (const auto& pair : sentencesScore) {
            if (pair.second > threshold) {
                summary.push_back(pair.first);
            }
        }
    }

    void mainProcess() {
        tokenizeSentences();
        extractWordsFromSentence();
        createWordFrequencyTable();
        scoreSentences();
        generateSummary();
    }

public:
    SummaryTool(const std::string& context) : text(context) {
        mainProcess();
    }

    void setText(const std::string& newText) {
        text = newText;
        sentences.clear();
        textTable.clear();
        frequencyCounter.clear();
        sentencesScore.clear();
        summary.clear();
        mainProcess();
    }

    std::string getSummary() {
        std::string result;
        for (const auto& s : summary) {
            result += s + ". ";
        }
        return result;
    }

    void showComparison() {
        std::cout << "Original Content:\n" << text << "\n";
        std::cout << "Word count: " << spaceCounter(text) << "\n";
        showSummary();
    }

    void showSummary() {
        int wordCount = 0;
        std::cout << "\nSummary:\n";
        for (const auto& s : summary) {
            std::cout << s << ".\n";
            wordCount += spaceCounter(s);
        }
        std::cout << "Summary word count: " << wordCount << "\n";
    }

    void showSentences() {
        std::cout << "\nSentence Scores:\n";
        for (const auto& pair : sentencesScore) {
            std::cout << pair.first << " = " << pair.second << "\n";
        }
    }

    void showFrequencyTable() {
        std::cout << "\nWord Frequencies:\n";
        for (const auto& pair : frequencyCounter) {
            std::cout << pair.first << " = " << pair.second << "\n";
        }
    }

    void showTextTable() {
        std::cout << "\nProcessed Words:\n";
        for (const auto& word : textTable) {
            std::cout << word << "\n";
        }
    }
};

int main() {
    std::string text = "The sun rises every morning, bringing light to the world."
"Birds chirp, announcing the start of a new day."
"Trees sway gently in the breeze, their leaves dancing in the wind."
"Flowers bloom, filling the air with sweet fragrances."
"People gather, sharing stories and laughter, creating memories together."
"Nature reminds us to appreciate the simple joys of life and live in harmony with the world around us.";

    SummaryTool summarizer(text);
    

    summarizer.showComparison();
    summarizer.showSentences();
    summarizer.showFrequencyTable();
    summarizer.showTextTable();

    return 0;


}
/* সূর্য প্রতিদিন সকালে উঠে পৃথিবীকে আলো দিয়ে পূর্ণ করে।
 এটি আমাদের জীবনধারার জন্য অপরিহার্য, কারণ সূর্য ছাড়া পৃথিবী অন্ধকারে নিমজ্জিত হয়ে পড়বে।

পাখিরা চিঁচিঁ করতে থাকে, নতুন দিনের শুরু ঘোষণা করে।
 এটি প্রকৃতির একটি সাধারণ দৃশ্য, যা আমাদের দিন শুরু হওয়ার আনন্দ দেয়।

 গাছগুলি মৃদু বাতাসে দুলতে থাকে, তাদের পাতা বাতাসে নাচছে। 
 এটি প্রকৃতির শান্তিপূর্ণ এবং সুন্দর দৃশ্য যা আমাদের মনকে শান্তি এবং প্রশান্তি দেয়।

 ফুলগুলো ফুটে উঠে, বাতাসকে মিষ্টি সুগন্ধে পূর্ণ করে। 
 ফুলের সৌন্দর্য এবং তাদের গন্ধ পরিবেশকে আরও সুন্দর ও আনন্দময় করে তোলে।

 মানুষ একত্রিত হয়, গল্প এবং হাস্য-রসের মাধ্যমে স্মৃতি সৃষ্টি করে।
  এটি আমাদের জীবনের একটি গুরুত্বপূর্ণ দিক—একসঙ্গে সময় কাটানো এবং একে অপরের সঙ্গে সম্পর্ক তৈরি করা।

  প্রকৃতি আমাদের স্মরণ করিয়ে দেয় যে, জীবনের সাধারণ আনন্দগুলোকে মূল্যায়ন করতে এবং আমাদের চারপাশের পৃথিবীকে সমন্বয়ে জীবনযাপন করতে। 
  প্রকৃতি আমাদের শেখায় কিভাবে সহজভাবে জীবনযাপন করতে হয় এবং বিশ্বকে সম্মানের সঙ্গে গ্রহণ করতে হয়।
*/

/*মানুষ একত্রিত হয়, গল্প ও হাস্য-রস শেয়ার করে, এবং একে অপরের সঙ্গে স্মৃতি সৃষ্টি করে। এটি জীবনের একটি গুরুত্বপূর্ণ দিক, 
যেখানে সম্পর্ক এবং বন্ধন গড়ে ওঠে। একসঙ্গে সময় কাটানো, গল্প করা, এবং হাস্য-রসে মজায় সময় পার করা আমাদের মধ্যে ভালবাসা এবং সম্পর্কের গাঢ়তা সৃষ্টি করে।

ফুলগুলো ফুটে উঠে, বাতাসকে মিষ্টি সুগন্ধে পূর্ণ করে। 
ফুলের সৌন্দর্য এবং তাদের গন্ধ পরিবেশে একটা শান্তিপূর্ণ এবং সুখময় অনুভূতি তৈরি করে। 
এটি প্রকৃতির এক বিশেষ উপহার, যা আমাদের মনকে প্রশান্তি দেয় এবং সুন্দর মুহূর্তে উদযাপন করার জন্য উদ্বুদ্ধ করে।
 */
