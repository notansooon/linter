import com.github.javaparser.*;
import com.github.javaparser.ast.*;
import com.github.javaparser.ast.body.*;
import com.github.javaparser.ParseProblemException;
import org.json.JSONObject;
import org.json.JSONArray;
import java.io.*;

public class JavaASTExtractor {

    public static JSONObject extractAST(String filePath) {
        JSONObject root = new JSONObject();
        try {
            File file = new File(filePath);
            CompilationUnit cu = StaticJavaParser.parse(file);

            JSONArray classesArray = new JSONArray();
            for (ClassOrInterfaceDeclaration c : cu.findAll(ClassOrInterfaceDeclaration.class)) {
                classesArray.put(processClass(c));
            }

            root.put("classes", classesArray);
            root.put("status", "success");  // Indicate success
        } catch (FileNotFoundException e) {
            root.put("error", "File not found: " + filePath);
            root.put("status", "failed");
        } catch (ParseProblemException e) {
            root.put("error", "Syntax error in Java file: " + e.getMessage());
            root.put("status", "failed");
        }

        return root;
    }

    private static JSONObject processClass(ClassOrInterfaceDeclaration c) {
        JSONObject classObj = new JSONObject();
        classObj.put("class", c.getNameAsString());

        JSONArray methodsArray = new JSONArray();
        for (MethodDeclaration m : c.getMethods()) {
            methodsArray.put(processMethod(m));
        }

        classObj.put("methods", methodsArray);
        return classObj;
    }

    private static JSONObject processMethod(MethodDeclaration m) {
        JSONObject methodObj = new JSONObject();
        methodObj.put("method", m.getNameAsString());
        methodObj.put("returnType", m.getTypeAsString());

        JSONArray variablesArray = new JSONArray();
        for (Parameter p : m.getParameters()) {
            variablesArray.put(new JSONObject().put("variable", p.getNameAsString()));
        }

        methodObj.put("variables", variablesArray);
        return methodObj;
    }

   
}
