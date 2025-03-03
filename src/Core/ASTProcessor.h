
#include <memory>;
#include <string>;
#include <vector>;
#include <iostream>;
using namespace std;



//Construct a AST Node Structure
struct ASTNode {
    string type; 
    string name;
    int line_number;
    vector<shared_ptr<ASTNode>> children;

    ASTNode(string type, string name, int line) 
        : type(move(type)), name(move(name)), line_number(line) {}
};


//Abstract AST interface
class ASTProcessor{
public:

    virtual ~ASTProcessor() = default;

    virtual shared_ptr<ASTNode> processNode (const string &output) = 0;
    virtual void analyzeAST(const shared_ptr<ASTNode> &input) = 0;

};