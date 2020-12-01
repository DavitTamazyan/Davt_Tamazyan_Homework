#include<iostream>
#include<fstream>
#include<ostream>
#include<string>
#include<vector>
//#include<algorithm>

#define LOGICAL (('+' == line[2] || '-' == line[2] || '*' == line[2] || '/' == line[2]) && '=' == line[3])

using str = std::string;


bool intOrDouble(str line, unsigned int index);

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
    
    void operator =(str value) {
        if ('\'' == value[0]) {
            this->state = varstate::CHAR;
            this->varchar = (char)value[1];
        }
        else if ((value == "true") || (value == "false")) {
            this->state = varstate::BOOL;
            this->varbool = (value == "false") ? false : true;
        }
        else if (intOrDouble(value, 0) == false) {
            this->state = varstate::DOUBLE;
            this->vardouble = std::stod(value);
        }
        else if (value != "undefined") {
            this->state = varstate::INT;
            this->varint = std::stoi(value);
        }
        return;
    }

    /// + - * /

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

    void operator +=(var val) {
        if (this->state == val.state) {
            this->varint += val.varint;
            this->vardouble += val.vardouble;
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

    void operator -=(var val) {
        if (this->state == val.state) {
            this->varint -= val.varint;
            this->vardouble -= val.vardouble;
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

    void operator *=(var val) {
        if (this->state == val.state) {
            this->varint *= val.varint;
            this->vardouble *= val.vardouble;
        }
    }

    void operator /=(int val) {
        if (state == varstate::INT) {
            varint = varint / val;
        }
    }

    void operator /=(double val) {
        if (state == varstate::DOUBLE) {
            vardouble = vardouble / val;
        }
    }

    void operator /=(var val) {
        if (this->state == val.state) {
            this->varint /= val.varint;
            this->vardouble /= val.vardouble;
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
            else /*if (this->state == varstate::DOUBLE)*/ {
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
        return false;
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
        return false;
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
            else /*if (this->state == varstate::DOUBLE)*/ {
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
        return false;
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
        return false;
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
            else /*if (this->state == varstate::DOUBLE) */{
                return (this->vardouble < val.vardouble);
            }
        }
        else {
            return false;
        }
    }

    /// operator >= 
    bool operator >=(int val) {
        if (state == varstate::INT) {
            return (varint >= val);
        }
    }

    bool operator >=(char val) {
        return false;
    }

    bool operator >=(bool val) {
        return false;
    }

    bool operator >=(double val) {
        if (state == varstate::DOUBLE) {
            return (vardouble >= val);
        }
    }

    bool operator >=(var val) {
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
    bool operator <=(int val) {
        if (state == varstate::INT) {
            return (varint <= val);
        }
    }

    bool operator <=(char val) {
        return false;
    }

    bool operator <=(bool val) {
        return false;
    }

    bool operator <=(double val) {
        if (state == varstate::DOUBLE) {
            return (vardouble <= val);
        }
    }

    bool operator <=(var val) {
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

    /// others

    // Debug
    void printvalue() {
        switch (state)
        {
        case var::varstate::INT:
            std::cout << varint;
            break;
        case var::varstate::CHAR:
            std::cout << varchar;
            break;
        case var::varstate::BOOL:
            if (varbool) {
                std::cout << "True";
            }
            else {
                std::cout << "False";
            }
            break;
        case var::varstate::DOUBLE:
            std::cout << vardouble;
            break;
        case var::varstate::UNDEFINED:
            std::cout << "undefined";
            break;
        default:
            break;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const var& var1) {
        switch (var1.state)
        {
        case var::varstate::INT:
            os << var1.varint << std::endl;
            break;
        case var::varstate::CHAR:
            os << var1.varchar << std::endl;
            break;
        case var::varstate::BOOL:
            if (var1.varbool) {
                os << "True" << std::endl;
            }
            else {
                os << "False" << std::endl;
            }
            break;
        case var::varstate::DOUBLE:
            os << var1.vardouble << std::endl;
            break;
        case var::varstate::UNDEFINED:
            os << "undefined" << std::endl;
            break;
        default:
            break;
        }
        return os;
    }

    friend std::istream& operator>> (std::istream& is, var& test)
    {
        str value;
        is >> value;
        test = value;
        return is;
    }

    void printtype() {
        switch (state)
        {
        case var::varstate::INT:
            std::cout << "INT";
            break;
        case var::varstate::CHAR:
            std::cout << "CHAR";
            break;
        case var::varstate::BOOL:
            std::cout << "BOOL";
            break;
        case var::varstate::DOUBLE:
            std::cout << "DOUBLE";
            break;
        case var::varstate::UNDEFINED:
            std::cout << "UNDEFINED";
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

    void changeValue(str var_name, str var_value) {
        if (!var_value.find('\'')) {
            arr_value[returnvarindex(var_name)] = (char)var_value[1];
        }
        else if ((var_value == "true") || (var_value == "false")) {
            arr_value[returnvarindex(var_name)] = (var_value == "false") ? false : true;
        }
        else if (intOrDouble(var_value, 0) == false) {
            arr_value[returnvarindex(var_name)] = std::stod(var_value);
        }
        else if (var_value != "undefined") {
            arr_value[returnvarindex(var_name)] = std::stoi(var_value);
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
    while ((line[i + index] != ' ') && (line[i + index] != ';') && (line[i + index] != ')') && (line[i + index] != ',')) { /// detecting variable name
        var_name += line[i + index];
        ++i;
    }
    return var_name;
}

str detectComment(str line, unsigned int index) {
    if (index > line.size()) {
        return "undefined";
    }
    int i = 0;
    std::string var_name = "";
    while (line[i + index] != ';') { 
        var_name += line[i + index];
        ++i;
    }
    return var_name;
}

bool intOrDouble(str line, unsigned int index) {
    for (uint16_t i = index; i < line.size(); ++i) {
        if (line[i] == '.') {
            return false;
        }
    }
    return true;
}

void fixSpaces(str& line) {
    bool trigger = false;
    for (uint16_t i = 0; i < line.size(); ++i) {
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

str readforarguments(int* forreg, str line) {
    str var_name = detectWord(line, 4); /// detecting for variable name
    int var_name_size = var_name.size(); /// var name saze
    ////// detecting start point
    str start_point = detectWord(line, 15 + var_name_size);
    int start_point_size = start_point.size();
    forreg[0] = std::stoi(start_point); 
    ////// detecting end point
    str end_point = detectWord(line, 17 + var_name_size + start_point_size);
    int end_point_size = end_point.size(); 
    forreg[1] = std::stoi(end_point);
    ////// detecting steep
    str steep = detectWord(line, 19 + var_name_size + start_point_size + end_point_size);
    forreg[2] = std::stoi(steep);

    return var_name; /// returning var name for creating var from main
}
/// Top
int main(int argc, char* argv[]) {
    //ArgumentCheck(argc, argv, 2);
    //CheckFile(argv[1]);

    std::ifstream inFile(argv[1]);
    std::string line = "";
    myCPU mycpu;
    bool skip = false;
    bool skip1 = false;
    bool otherwise = false;
    uint16_t line_number = 1;
    bool eof = false;
    bool forcycle = false;
    int forreg[3] = {}; /// forreg[0] = forvarstart, forreg[1] = forvarend, forreg[2] = forvarsteep,
    bool for_start = true;

    std::vector<str> forlines;
    int for_line = 0;
    int forvar = 0;
    int forvarindex = 0;

    while (!eof) {

        if (false == forcycle) {
            if (!(std::getline(inFile, line))) {
                eof = true;
                continue;
            }
        }
        else {
            if (mycpu.arr_value[forvarindex] < forreg[1]) {
                if (for_line < forlines.size()) {
                    line = forlines[for_line];
                    for_line++;
                }
                else {
                    for_line = 0;
                    mycpu.arr_value[forvarindex] += forreg[2];
                    continue;
                }
            }
            else {
                forcycle = false;
                continue;
            }
        }
        

        fixSpaces(line);

        /// if - else (please change skip and skip1 names *** )
        if (skip) {
            if ("end" == line) {
                skip = false;
                otherwise = true;
            }
            continue;
        }

        if ((line == "otherwise" && !otherwise) || skip1) {
            skip1 = true;
            if ("end" == line) {
                otherwise = true;
                skip1 = false;
            }
            continue;
        }
        /// end

        if (!line.empty() && !('/' == line[0] && '/' == line[1])) { /// ignoring empty line and comment
            if (!(line.compare(0, 4, "var "))) { /// declaration of var
                str var_name = "";
                var_name = detectWord(line, 4); /// detect var name
                if (';' == line[5]) {
                    mycpu.returnvarindex(var_name);
                }
                else if (-1 == mycpu.findElement(detectWord(line, 9))) { /// assignig value
                    str var_value = "";
                    var_value = detectWord(line, 9); /// detect var value
                    mycpu.changeValue(var_name, var_value);
                }
                else { /// assigning var
                    mycpu.arr_value[mycpu.returnvarindex(var_name)];
                    int index1 = mycpu.findElement(detectWord(line, 4));
                    int index2 = mycpu.findElement(detectWord(line, 9));
                    mycpu.arr_value[index1] = mycpu.arr_value[index2];
                }

            }
            else if (!(line.compare(0, 9, "printval "))) {/// printval function
                str var_name = "";
                var_name = detectWord(line, 9); /// detect var name
                int var_address = mycpu.returnvarindex(var_name);
                mycpu.arr_value[var_address].printvalue();
            }
            else if (!(line.compare(0, 10, "printtype "))) {/// printtype function
                str var_name = "";
                var_name = detectWord(line, 10); /// detect var name
                int var_address = mycpu.returnvarindex(var_name);
                mycpu.arr_value[var_address].printtype();
            }
            else if ((!(line.compare(0, 9, "printtxt ")))) {
                str txt = detectComment(line, 9);
                if (txt == "NewLine") {
                    std::cout << std::endl;
                }
                else {
                    std::cout << txt;
                }
            }
            else if (mycpu.findElement(detectWord(line, 0)) != -1) { /// assigning new value to execting var
                if (LOGICAL) { /// +=, -=, *=, /=
                    str secArg = detectWord(line, 5); /// detect var value
                    if (-1 != mycpu.findElement(secArg)) {
                        int index1 = mycpu.findElement(detectWord(line, 0));
                        int index2 = mycpu.findElement(detectWord(line, 5));
                        if (line[2] == '+') {
                            mycpu.arr_value[index1] += mycpu.arr_value[index2];
                        }
                        else if (line[2] == '-') {
                            mycpu.arr_value[index1] -= mycpu.arr_value[index2];
                        }
                        else if (line[2] == '*') {
                            mycpu.arr_value[index1] *= mycpu.arr_value[index2];
                        }
                        else if (line[2] == '/') {
                            mycpu.arr_value[index1] /= mycpu.arr_value[index2];
                        }
                    }
                    else {
                        int index1 = mycpu.findElement(detectWord(line, 0));
                        if (intOrDouble(line, 5)) {
                            if (line[2] == '+') {
                                mycpu.arr_value[index1] += std::stoi(secArg);
                            }
                            else if (line[2] == '-') {
                                mycpu.arr_value[index1] -= std::stoi(secArg);
                            }
                            else if (line[2] == '*') {
                                mycpu.arr_value[index1] *= std::stoi(secArg);
                            }
                            else if (line[2] == '/') {
                                mycpu.arr_value[index1] /= std::stoi(secArg);
                            }
                        }
                        else {
                            if (line[2] == '+') {
                                mycpu.arr_value[index1] += std::stod(secArg);
                            }
                            else if (line[2] == '-') {
                                mycpu.arr_value[index1] -= std::stod(secArg);
                            }
                            else if (line[2] == '*') {
                                mycpu.arr_value[index1] *= std::stod(secArg);
                            }
                            else if (line[2] == '/') {
                                mycpu.arr_value[index1] /= std::stod(secArg);
                            }
                        }
                    }
                }
                else {
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
                        //std::cout << "Var name = " << var_name << "Var value = " << var_value << std::endl;
                        mycpu.changeValue(var_name, var_value);
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

                    if (value[0] == '\'') {
                        skip = !(mycpu.arr_value[index1] == value[1]);
                    }
                    else if ((value == "true") || (value == "false")) {

                    }
                    else if (intOrDouble(value, 0) == false) {
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
            else if (!(line.compare(0, 8, "takeval "))) {
                str var_name = "";
                var_name = detectWord(line, 8); /// detect var name
                int var_address = mycpu.returnvarindex(var_name); /// detect var addres
                std::cin >> mycpu.arr_value[var_address];
            }
            else if (!(line.compare(0, 4, "for "))) {
                forvarindex = mycpu.returnvarindex(readforarguments(forreg, line));
                mycpu.arr_value[forvarindex] = forreg[0];
                forcycle = true;
                std::getline(inFile, line);
                while ("end" != line) {
                    forlines.push_back(line);
                    std::getline(inFile, line);
                }
            }
            else if ("end" == line || "otherwise" == line) {

            }
            else {
                std::cout << "!!! Unknown Line !!!" << std::endl;
                std::cout << "Line " << line_number << " :: " << line << std::endl;
                exit(1);
            }
        }
        ++line_number; /// update line_number
    }
    inFile.close();
}
