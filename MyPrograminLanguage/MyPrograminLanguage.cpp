#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>

using str = std::string;

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

    // Assigning new value x
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

    /// Copy constructor
    void operator =(const var& other) {
        this->varint = other.varint;
        this->varchar = other.varchar;
        this->varbool = other.varbool;
        this->vardouble = other.vardouble;
        this->state = other.state;
        return;
    }

    /// += -= *= /=
    void operator +=(int val) {
        if (state == varstate::INT) {
            varint = varint + val;
        }
    }

    void operator +=(double val) {
        if (state == varstate::DOUBLE) {
            vardouble = vardouble + val;
        }
    }

    void operator -=(int val) {
        if (state == varstate::INT) {
            varint = varint - val;
        }
    }

    void operator -=(double val) {
        if (state == varstate::DOUBLE) {
            vardouble = vardouble - val;
        }
    }

    void operator *=(int val) {
        if (state == varstate::INT) {
            varint = varint * val;
        }
    }

    void operator *=(double val) {
        if (state == varstate::DOUBLE) {
            vardouble = vardouble * val;
        }
    }

    void operator /=(int val) {
        if (state == varstate::INT) {
            varint = varint + val;
        }
    }

    void operator /=(double val) {
        if (state == varstate::DOUBLE) {
            vardouble = vardouble / val;
        }
    }

    /// operator == 
    bool operator ==(int val) {
        if (state == varstate::INT) {
            return (val == varint);
        }
        return false;
    }

    bool operator ==(char val) {
        if (state == varstate::CHAR) {
            return (val == varchar);
        }
        return false;
    }

    bool operator ==(bool val) {
        if (state == varstate::BOOL) {
            return (val == varbool);
        }
        return false;
    }

    bool operator ==(double val) {
        if (this->state == varstate::DOUBLE) {
            return (val == vardouble);
        }
        return false;
    }

    bool operator ==(var val) {
        if (this->state == val.state) {
            if (this->state == varstate::UNDEFINED) {
                return true;
            }
            else if (this->state == varstate::INT) {
                return (this->varint == val.varint);
            }
            else if (this->state == varstate::BOOL) {
                return (this->varbool == val.varbool);
            }
            else if (this->state == varstate::CHAR) {
                return (this->varchar == val.varchar);
            }
            else if (this->state == varstate::DOUBLE) {
                return (this->vardouble == val.vardouble);
            }
        }
        else {
            return false;
        }
    }

    /// operator > 
    bool operator >(int val) {
        if (state == varstate::INT) {
            return (varint > val);
        }
    }

    bool operator >(char val) {
        return false;
    }

    bool operator >(bool val) {
        return false;
    }

    bool operator >(double val) {
        if (state == varstate::DOUBLE) {
            return (vardouble > val);
        }
    }

    bool operator >(var val) {
        if (this->state == val.state) {
            if (this->state == varstate::UNDEFINED) {
                return false;
            }
            else if (this->state == varstate::INT) {
                return (this->varint > val.varint);
            }
            else if (this->state == varstate::BOOL) {
                return false;
            }
            else if (this->state == varstate::CHAR) {
                return false;
            }
            else if (this->state == varstate::DOUBLE) {
                return (this->vardouble > val.vardouble);
            }
        }
        else {
            return false;
        }
    }

    /// operator < 
    bool operator <(int val) {
        if (state == varstate::INT) {
            return (varint < val);
        }
    }

    bool operator <(char val) {
        return false;
    }

    bool operator <(bool val) {
        return false;
    }

    bool operator <(double val) {
        if (state == varstate::DOUBLE) {
            return (vardouble < val);
        }
    }

    bool operator <(var val) {
        if (this->state == val.state) {
            if (this->state == varstate::UNDEFINED) {
                return false;
            }
            else if (this->state == varstate::INT) {
                return (this->varint < val.varint);
            }
            else if (this->state == varstate::BOOL) {
                return false;
            }
            else if (this->state == varstate::CHAR) {
                return false;
            }
            else if (this->state == varstate::DOUBLE) {
                return (this->vardouble < val.vardouble);
            }
        }
        else {
            return false;
        }
    }

    /// operator >= 
    bool operator >(int val) {
        if (state == varstate::INT) {
            return (varint >= val);
        }
    }

    bool operator >(char val) {
        return false;
    }

    bool operator >(bool val) {
        return false;
    }

    bool operator >(double val) {
        if (state == varstate::DOUBLE) {
            return (vardouble >= val);
        }
    }

    bool operator >(var val) {
        if (this->state == val.state) {
            if (this->state == varstate::UNDEFINED) {
                return false;
            }
            else if (this->state == varstate::INT) {
                return (this->varint >= val.varint);
            }
            else if (this->state == varstate::BOOL) {
                return false;
            }
            else if (this->state == varstate::CHAR) {
                return false;
            }
            else if (this->state == varstate::DOUBLE) {
                return (this->vardouble >= val.vardouble);
            }
        }
        else {
            return false;
        }
    }

    /// operator <= 
    bool operator <(int val) {
        if (state == varstate::INT) {
            return (varint <= val);
        }
    }

    bool operator <(char val) {
        return false;
    }

    bool operator <(bool val) {
        return false;
    }

    bool operator <(double val) {
        if (state == varstate::DOUBLE) {
            return (vardouble <= val);
        }
    }

    bool operator <(var val) {
        if (this->state == val.state) {
            if (this->state == varstate::UNDEFINED) {
                return false;
            }
            else if (this->state == varstate::INT) {
                return (this->varint <= val.varint);
            }
            else if (this->state == varstate::BOOL) {
                return false;
            }
            else if (this->state == varstate::CHAR) {
                return false;
            }
            else if (this->state == varstate::DOUBLE) {
                return (this->vardouble <= val.vardouble);
            }
        }
        else {
            return false;
        }
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

    int GetType() {
        return (int)state;
    }

private:
    int varint;
    char varchar;
    bool varbool;
    double vardouble;
    enum class  varstate { INT, CHAR, BOOL, DOUBLE, UNDEFINED } state;
};

class myCPU {
public:

    myCPU() {
        index = 0;
        for (int i = 0; i < 99; ++i) {
            //arr_value[i] = 0;
            arr_name[i] = "";
        }
    }

    void printMem() {
        for (int i = 0; i < index; ++i) {
std::cout << "arr_value[" << i << "]" << " = ";
arr_value[i].printvalue();
        }
    }

    int findElement(str name) {
        for (int i = 0; i < index; ++i) {
            if (arr_name[i] == name) {
                return i;
            }
        }
        return -1;
    }

    int returnvarindex(str name) {
        int tmp = findElement(name);
        if (tmp == -1) {
            arr_name[index] = name;
            ++index;
            return index - 1;
        }
        else {
            return tmp;
        }

    }

    var arr_value[100];
    str arr_name[100];
private:
    int index;
};

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

str detectWord(str line, unsigned int index) {
    if (index > line.size()) {
        return "undefined";
    }
    char tmp = 'a';
    int i = 0;
    std::string var_name = "";
    while ((line[i + index] != ' ') && (line[i + index] != ';') && (line[i + index] != ')')) { /// detecting variable name
        var_name += line[i + index];
        ++i;
    }
    return var_name;
}

str detectComment(str line, unsigned int index) {
    if (index > line.size()) {
        return "undefined";
    }
    char tmp = 'a';
    int i = 0;
    std::string var_name = "";
    while (line[i + index] != ';') { /// detecting variable name
        var_name += line[i + index];
        ++i;
    }
    return var_name;
}

bool intOrDouble(str line, unsigned int index) {
    for (int i = index; i < line.size(); ++i) {
        if (line[i] == '.') {
            return false;
        }
    }
    return true;
}

void fixSpaces(str& line) {
    bool trigger = false;
    for (int i = 0; i < line.size(); ++i) {
        if ((' ' == line[i]) && trigger) {
            line.erase(i, 1);
            --i;
        }
        else if (' ' == line[i]) {
            trigger = true;
        }
        else if (' ' != line[i]) {
            trigger = false;
        }
    }

    if (' ' == line[0]) {
        line.erase(0, 1);
    }

    if (' ' == line[line.size() - 2]) {
        line.erase((line.size() - 2), 1);
    }
}

/// Top
int main(int argc, char* argv[]) {
    //ArgumentCheck(argc, argv, 2);
    //CheckFile(argv[1]);

    std::ifstream inFile(argv[1]);
    std::string line = "";
    myCPU mycpu;
    bool skip = false;


    while (std::getline(inFile, line)) {
        fixSpaces(line);

        if (skip) {
            if ("end" == line) {
                skip = false;
            }
            continue;
        }

        if (!line.empty()) { /// ignoring empty line
            if (!(line.compare(0, 4, "var "))) { /// declaration of var
                str var_name = "";
                var_name = detectWord(line, 4); /// detect var name
                str var_value = "";
                var_value = detectWord(line, 9); /// detect var value

                if (!var_value.find('\'')) {
                    mycpu.arr_value[mycpu.returnvarindex(var_name)] = (char)var_value[1];
                }
                else if ((var_value == "true") || (var_value == "false")) {
                    mycpu.arr_value[mycpu.returnvarindex(var_name)] = (var_value == "false")? false : true;
                }
                else if (intOrDouble(var_value, 0) == false) { /// ???
                    mycpu.arr_value[mycpu.returnvarindex(var_name)] = std::stod(var_value);
                }
                else if (var_value != "undefined"){
                    mycpu.arr_value[mycpu.returnvarindex(var_name)] = std::stoi(var_value);
                }

            }
            else if (!(line.compare(0, 9, "printval "))) {/// printval function
                str var_name = "";
                var_name = detectWord(line, 9); /// detect var name
                int var_address = mycpu.returnvarindex(var_name);
                mycpu.arr_value[var_address].printvalue();
            }
            else if (line[0] == '/' && line[2] == '/') { /// Comment

            }
            else if (!(line.compare(0, 10, "printtype "))) {/// printtype function
                str var_name = "";
                var_name = detectWord(line, 10); /// detect var name
                int var_address = mycpu.returnvarindex(var_name);
                mycpu.arr_value[var_address].printtype();
            }
            else if ((!(line.compare(0, 9, "printtxt ")))) {
                str txt = detectComment(line, 9);
                std::cout << txt << std::endl;
            }
            else if (mycpu.findElement(detectWord(line, 0)) != -1) { /// assigning new value to execting var
                int index1 = mycpu.findElement(detectWord(line, 0));
                int index2 = mycpu.findElement(detectWord(line, 5));
                if ('<' != line[2]) {
                    str var_value = "";
                    var_value = detectWord(line, 5); /// detect var value
                    if ('+' == line[2]) {
                        if (intOrDouble(var_value, 0) == false) {
                            mycpu.arr_value[index1].operator+=(std::stod(var_value));
                        }
                        else {
                            mycpu.arr_value[index1].operator+=(std::stoi(var_value));
                        }
                    }
                    else if ('-' == line[2]) {
                        if (intOrDouble(var_value, 0) == false) {
                            mycpu.arr_value[index1].operator-=(std::stod(var_value));
                        }
                        else {
                            mycpu.arr_value[index1].operator-=(std::stoi(var_value));
                        }
                    }
                    else if ('*' == line[2]) {
                        if (intOrDouble(var_value, 0) == false) {
                            mycpu.arr_value[index1].operator*=(std::stod(var_value));
                        }
                        else {
                            mycpu.arr_value[index1].operator*=(std::stoi(var_value));
                        }
                    }
                    else if ('/' == line[2]) {
                        if (intOrDouble(var_value, 0) == false) {
                            mycpu.arr_value[index1].operator/=(std::stod(var_value));
                        }
                        else {
                            mycpu.arr_value[index1].operator/=(std::stoi(var_value));
                        }
                    }
                }
                else if (-1 != index2) {/// Copy constructor
                    mycpu.arr_value[index1] = mycpu.arr_value[index2];
                }
                else {
                    bool isConst = false;
                    str var_name = "";
                    var_name = detectWord(line, 0); /// detect var name
                    str var_value = "";
                    var_value = detectWord(line, 5); /// detect var value

                    /// assigning const
                    if (!var_value.find('\'')) {
                        mycpu.arr_value[mycpu.returnvarindex(var_name)]((char)var_value[1]);
                        isConst = true;
                    }
                    else if (("true" == var_value) || ("false" == var_value)) {
                        mycpu.arr_value[mycpu.returnvarindex(var_name)]((var_value == "false") ? false : true);
                        isConst = true;
                    }
                    else if (intOrDouble(var_value, 0) == false) {
                        mycpu.arr_value[mycpu.returnvarindex(var_name)](std::stod(var_value));
                        isConst = true;
                    }
                    else if ("undefined" != var_value) {
                        mycpu.arr_value[mycpu.returnvarindex(var_name)](std::stoi(var_value));
                        isConst = true;
                    }

                }
            }
            else if (!(line.compare(0, 5, "when "))) {
                if (mycpu.findElement(detectWord(line, 10)) != -1) {
                    int index1 = mycpu.findElement(detectWord(line, 6));
                    int index2 = mycpu.findElement(detectWord(line, 10));
                    if (line[8] == '=') {
                        skip = !(mycpu.arr_value[index1].operator==(mycpu.arr_value[index2]));
                    }
                    else if (line[8] == '>') {
                        skip = !(mycpu.arr_value[index1].operator>(mycpu.arr_value[index2]));
                    }
                    else if (line[8] == '<') {
                        skip = !(mycpu.arr_value[index1].operator<(mycpu.arr_value[index2]));
                    }
                }
                else {
                    int index1 = mycpu.findElement(detectWord(line, 6));
                    str value = detectWord(line, 10);
                    if (intOrDouble(value, 0) == false) {
                        if (line[8] == '=') {
                            skip = !(mycpu.arr_value[index1] == std::stod(value));
                        }
                        else if (line[8] == '>') {
                            skip = !(mycpu.arr_value[index1] > std::stod(value));
                        }
                        else if (line[8] == '<') {
                            skip = !(mycpu.arr_value[index1] < std::stod(value));
                        }

                    }
                    else if (value[0] == '\'') {
                        skip = !(mycpu.arr_value[index1] == value[1]);
                    }
                    else if ((value == "true") || (value == "false")) {

                    }
                    else {
                        if (line[8] == '=') {
                            skip = !(mycpu.arr_value[index1] == std::stoi(value));
                        }
                        else if (line[8] == '>') {
                            skip = !(mycpu.arr_value[index1] > std::stoi(value));
                        }
                        else if (line[8] == '<') {
                            skip = !(mycpu.arr_value[index1] < std::stoi(value));
                        }
                    }
                }
            }
        }
    }
    inFile.close();
}
