// #include "SummaryTool.hpp"
// #include <iostream>
// #include <filesystem>
// using namespace std;
// int main(int argC,char *argV[]) {
//     std::string text = "Text summarization is a technique in natural language processing. "
//                       "It helps reduce large texts into shorter versions. "
//                       "The summary maintains the key points of the original content. "
//                       "This technique is useful for processing large documents. "
//                       "It saves time for readers who want to understand the main ideas quickly.";
    
//     SummaryTool summarizer(text);
    
//     std::cout << "Original text:\n" << text << "\n\n";
//     std::cout << "Summary:\n" << summarizer.getSummary() << std::endl;
    // if(argC < 2){
    //     cout << "Error!" << endl;
    //     return 1;
    // }
    // for(int i=1;i<argC;i++){
    //     string filename = argV[i];
    //     if(!filesystem :: exists(filename)){
    //         cerr << "File not found : " << filename << endl;
    //         continue;
    //     }
    //     SummaryTool summarizer(filename);
        
    //   //  cout << "Original text:\n" << filename << "\n\n";
    //     cout << "Summary :\n" << summarizer.getSummary() << endl;
    // }
    // return 0;
//}
#include "SummaryTool.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    if (argc < 2) {
        cerr << "Usage: " << argv[0] << " <filename>" << endl;
        return 1;
    }

    string filename = argv[1];
    ifstream file(filename);

    if (!file) {
        cerr << "Error: Could not open file " << filename << endl;
        return 1;
    }

    stringstream buffer;
    buffer << file.rdbuf();
    string text = buffer.str();
    file.close();

    SummaryTool summarizer(text);

    cout << "Original text:\n" << text << "\n\n";
    cout << "Summary:\n" << summarizer.getSummary() << endl;

    return 0;
}
