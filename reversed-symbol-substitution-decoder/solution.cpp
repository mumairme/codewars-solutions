#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

string decode(const string& m)
{
    if (m.empty()) {
        return "";
    }

    unordered_map<string, char> symbols = {
        {"|-|", 'h'}, {"[-", 'e'}, {"()", 'o'}, {"3]", 'b'},
        {"_|", 'l'}, {"|", 'i'}, {"^|", 'p'}, {"/`", 'y'},
        {")(", 'o'}, {"?/", 'r'}, {"\\/", 'a'}, {"|\\|", 'n'},
        {"</", 'k'}, {"~|~", 't'}, {"=/", 'f'}, {")|", 'd'},
        {"|_|", 'u'}, {"(", 'c'}, {"-[", 'e'}, {"~\\_", 's'},
        {"]3", 'b'}, {"_/~", 'z'}, {"/\\/\\", 'w'}, {"<>", 'x'},
        {"/\\", 'v'}, {"|/\\|", 'm'}, {"_)(", 'q'}, {"T_", 'j'},
        {",_(", 'g'}, {"__", ' '}
    };

    string reversed = m;
    reverse(reversed.begin(), reversed.end());

    unordered_map<char, int> frequency;
    for (char c : reversed) {
        frequency[c]++;
    }

    char separator = reversed[0];
    for (const auto& item : frequency) {
        if (item.second > frequency[separator]) {
            separator = item.first;
        }
    }

    string decoded;
    string token;

    for (char c : reversed) {
        if (c == separator) {
            if (symbols.count(token)) {
                decoded += symbols[token];
            }
            token.clear();
        } else {
            token += c;
        }
    }

    if (symbols.count(token)) {
        decoded += symbols[token];
    }

    return decoded;
}
