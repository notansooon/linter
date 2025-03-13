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

        shared_ptr<ASTNode> currentClass = nullptr;
        shared_ptr<ASTNode> currentMethod = nullptr;

        //return nullptr if AST is invalid (for error handler)
        if (compileOutput.find("error") != string::npos) {
           return nullptr;
        }


        while (getline(ss, line)) {
            if (line.find("Class") != string::npos) {
                currentClass = make_shared<ASTNode>();
                currentClass->children.push_back(make_shared<ASTNode>("class", extractName(line), 1));
            }
            else if (line.find("Method") != string::npos) {
                if (currentClass) {
                    currentMethod->children.push_back(make_shared<ASTNode>("Method", extractName(line), 2));
                }
            }
            else if (line.find("Variable") != string::npos) {
                if (currentClass) {
                    currentMethod->children.push_back(make_shared<ASTNode>("Variable", extractName(line), 3));
                }
            }
        }

        return root; // Ensure function returns a value
    }

    void analyzeAST(const shared_ptr<ASTNode> &root) override {
        for (const auto &classNode : root->children) {
            for (const auto &methodNode : root->children) {
                for (const auto &varNode : root->children) {
                    //varname is hard coded -> need future modification
                    if (varNode->type == "Variable" && varNode->name == "temp") {

                        

                    }
                }
            }
        }
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
