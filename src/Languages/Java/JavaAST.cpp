#include "ASTProcessor.h"
#include <sstream>
#include <memory>
#include <string>

using namespace std;

class JavaAST : public ASTProcessor {
public:
    shared_ptr<ASTNode> processNode(const string &compileOutput) override {
        istringstream ss(compileOutput);
        string line;

        shared_ptr<ASTNode> root = make_shared<ASTNode>();

        //return nullPtr if AST is invalid (for error handler)
        if (compileOutput.find("error") != string::npos) {
           return nullptr;
        }


        while (getline(ss, line)) {
            if (line.find("class") != string::npos) {
                // Process class declaration here
                root->children.push_back(make_shared<ASTNode>("class", line, 1));
            }
            else if (line.find("Method") != string::npos) {
                      //implement later
            }
            else if (line.find("Variable") != string::npos) {
                      //implement later
            }
        }

        return root; // Ensure function returns a value
    }

    void analyzeAST(const shared_ptr<ASTNode> &root) override {
        // Analyze AST implementation here
    }

           //Helper method for extracting line number
    private:
           string extractName(const string &line){
                      int position = line.find(" ");

                      if (position != string::npos) {
                                 return line.substr(position + 1);
                      }


           }
           
};