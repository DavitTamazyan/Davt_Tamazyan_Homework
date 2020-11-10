#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

class myCPU {

};

class var {
public:
    // Constructors
    var(int varint_tmp) {
        state = varstate::INT;
        varint = varint_tmp;
        varchar = ' ';
        varbool = true;
        vardouble = 0;
    }

    var(char varchar_tmp) {
        state = varstate::CHAR;
        varint = 0;
        varchar = varchar_tmp;
        varbool = true;
        vardouble = 0;
    }

    var(bool varbool_tmp) {
        state = varstate::BOOL;
        varint = 0;
        varchar = ' ';
        varbool = varbool_tmp;
        vardouble = 0;
    }

    var(double vardouble_tmp) {
        state = varstate::DOUBLE;
        varint = 0;
        varchar = ' ';
        varbool = true;
        vardouble = vardouble_tmp;
    }

    var() {
        state = varstate::UNDEFINED;
        varint = 0;
        varchar = ' ';
        varbool = true;
        vardouble = 0;
    }

    // Assigning new value x = 56
    void operator()(int varint_tmp) {
        state = varstate::INT;
        varint = varint_tmp;
        varchar = ' ';
        varbool = true;
        vardouble = 0;
    }

    void operator()(char varchar_tmp) {
        state = varstate::CHAR;
        varint = 0;
        varchar = varchar_tmp;
        varbool = true;
        vardouble = 0;
    }

    void operator()(bool varbool_tmp) {
        state = varstate::BOOL;
        varint = 0;
        varchar = ' ';
        varbool = varbool_tmp;
        vardouble = 0;
    }

    void operator()(double vardouble_tmp) {
        state = varstate::DOUBLE;
        varint = 0;
        varchar = ' ';
        varbool = true;
        vardouble = vardouble_tmp;
    }

    // return value x = x + 12
    int returnvarintplusconst(int constvalue) {
        return varint + constvalue;
    }

    char returnvarchartplusconst(char constvalue) {
        return (int)varchar + (int)constvalue;
    }

    bool returnvarbooltplusconst(bool constvalue) {
        return (int)varbool + (int)constvalue;
    }

    double returnvardoubletplusconst(double constvalue) {
        return varbool + constvalue;
    }

    // return value x = var1 + var2
    int returnvarintplusvarint(var constvalue) {
        return this->varint + constvalue.varint;
    }

    char returnvarchartplusvarchar(var constvalue) {
        return (int)this->varchar + (int)constvalue.varchar;
    }

    bool returnvarbooltplusvarbool(var constvalue) {
        return (int)this->varbool + (int)constvalue.varbool;
    }

    double returnvardoubletplusvardouble(var constvalue) {
        return this->varbool + constvalue.varbool;
    }

    // ++ and -- por varint and vardouble

    void varintplusplus() {
        ++varint;
    }

    void varintminusminus() {
        --varint;
    }

    void vardoubleplusplus() {
        ++vardouble;
    }

    void vardoubleminusminus() {
        --vardouble;
    }

    // Debug
    void printvalue() {
        switch (state)
        {
        case var::varstate::INT:
            std::cout << varint << std::endl;
            break;
        case var::varstate::CHAR:
            std::cout << varchar << std::endl;
            break;
        case var::varstate::BOOL:
            if (varbool) {
                std::cout << "True" << std::endl;
            }
            else {
                std::cout << "False" << std::endl;
            }
            break;
        case var::varstate::DOUBLE:
            std::cout << vardouble << std::endl;
            break;
        case var::varstate::UNDEFINED:
            std::cout << "undefined" << std::endl;
            break;
        default:
            break;
        }
    }

    void printtype() {
        switch (state)
        {
        case var::varstate::INT:
            std::cout << "INT" << std::endl;
            break;
        case var::varstate::CHAR:
            std::cout << "CHAR" << std::endl;
            break;
        case var::varstate::BOOL:
            std::cout << "BOOL" << std::endl;
            break;
        case var::varstate::DOUBLE:
            std::cout << "DOUBLE" << std::endl;
            break;
        case var::varstate::UNDEFINED:
            std::cout << "UNDEFINED" << std::endl;
            break;
        default:
            break;
        }
    }

private:
    int      varint;
    char    varchar;
    bool    varbool;
    double    vardouble;
    enum class  varstate { INT, CHAR, BOOL, DOUBLE, UNDEFINED } state;
};

/// Function Declaration
void ArgumentCheck(int argc, char* argv[], int argc_exp);
void CheckFile(char* path);
void CreateTmp(char* path);
int interpretr(std::string line);
void exeline(std::vector<std::string>);

std::vector<std::string> var_list;

int a;

/// Top
int main(int argc, char* argv[]) {
    //ArgumentCheck(argc, argv, 2);
    //CheckFile(argv[1]);

    std::ifstream inFile(argv[1]);
    std::string line;
    while (std::getline(inFile, line)) {

    }
    inFile.close();



}

/// Function Body
/// ///uncomment exit(1)
void ArgumentCheck(int argc, char* argv[], int argc_exp) {
    if (argc != argc_exp) {
        std::cout << "The expected argument count is " << argc_exp <<
            " \n\r Given argument count is " << argc << std::endl;
        exit(1);
    }
    else {
        std::cout << "The expected argument count is OK :)" << std::endl;
    }
}
///uncomment exit(1)
void CheckFile(char* path) {

    std::ifstream inFile;
    inFile.open(path);

    if (!inFile) {
        std::cerr << "Unable to open file " << path << std::endl;
        exit(1);
    }
    else {
        std::cerr << "File exist :)" << std::endl;
    }

    inFile.close();
}

void CreateTmp(char* path) {
    std::ifstream inFile(path);
    std::string line;
    ///
    std::cout << "Start Interpretator" << std::endl;

    while (std::getline(inFile, line)) {
        //std::cout << "Line = " << line << std::endl;
        if (interpretr(line) == -1) {
            break;
        }
    }

    std::cout << "End Interpretator" << std::endl;
    /// 
    inFile.close();
}

int interpretr(std::string line) {
    bool end = 0;
    int i = 0;
    std::string str_tmp = "";
    std::string word = "";
    std::vector<std::string> line_vector;
    while (!end) {
        str_tmp = line[i];
        std::cout << str_tmp << std::endl;
        if (str_tmp != " " & str_tmp != ";") {
            word = word + str_tmp;
            ++i;
        }
        else if (str_tmp == ";") {
            std::cout << word << std::endl;
            line_vector.push_back(word);
            end = true;
        }
        else if (word != "") {
            std::cout << word << std::endl;
            line_vector.push_back(word);
            word = "";
            ++i;
        }
        else {
            ++i;
        }
    }
    exeline(line_vector);
    return 0;
}

void exeline(std::vector<std::string> line_vector) {
    std::ofstream tmpFile("tmp.txt");
    if (line_vector[0] == "var") {
        std::cout << "var ";
        std::cout << line_vector[1];
        var_list.push_back(line_vector[1]);
        if (line_vector[2] == "<=") {
            std::cout << "(";
            std::cout << line_vector[3];
            std::cout << ")";
        }
        else if (line_vector[2] == "=") {

        }

        std::cout << ";";
        std::cout << "\n";
    }
    else if (std::find(line_vector.begin(), line_vector.end(), line_vector[0]) != line_vector.end()) {
        std::cout << line_vector[0];
        std::cout << "(";
        std::cout << line_vector[2];
        std::cout << ")";
        std::cout << "\n";
    }

}
