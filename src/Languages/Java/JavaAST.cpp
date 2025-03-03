#include "ASTProcessor.h";
#include <sstream>



class JavaAST : public ASTProcessor {
public:


//
shared_ptr<ASTNode> processNode(const string &compileOutput) override {

           istringstream ss(compileOutput);
           string line;

           shared_ptr<ASTNode> root = make_shared<ASTNode>();

           while (getline(ss, line)) {

           if(line.find("class") != string::npos) {

                      children

           }

           }

}

void analyzeAST(const shared_ptr<ASTNode> &root) override {

}






};