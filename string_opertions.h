#include <string>
using namespace std;

const char* WHITESPACE = " \t\n\r\f\v";

string ltrim(string s){
    auto index = s.find_first_not_of(WHITESPACE);
    return (index != string::npos) ? s.substr(index) : "";
}

string rtrim(string s){
    auto index = s.find_last_not_of(WHITESPACE);
    return (index != string::npos) ? s.substr(0, index + 1) : "";
}

string trim(string s){
    return rtrim(ltrim(s));
}