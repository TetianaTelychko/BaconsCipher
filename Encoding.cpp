#include "Encoding.h"

string Encoding::makeABstring(string &initialMessage) {
    std::transform(initialMessage.begin(), initialMessage.end(), initialMessage.begin(), ::tolower);
    string result;
    for(char ch : initialMessage){
        int startNumber = ch - 97;
        for(int i = startNumber; i < (startNumber + 5); ++i){
            result += key[i];
        }
    }
    return result;
}

string Encoding::encode(string &word, string &text) {
    string result = text;
    if(stringValidation(word) && stringValidation(result)){
        if(result.size() < word.size() * 5){
            cout << "Помилка! Речення має містити в 5 разів більше літер, ніж слово, яке Ви бажаєте зашифрувати !\n";
            return nullptr;
        }
        string code = makeABstring(word);
        std::transform(result.begin(), result.end(), result.begin(), ::tolower);
        int codeSize = code.size();
        for(int i = 0; i < codeSize; ++i){
            if(code[i] == 'b'){
                result[i] = char(result[i] - 32);
            }
        }
        for(int i = 0; i < result.size(); ++i){
            if(text[i] == ' '){
                result.insert(i, " ");
            }
        }
        return result;
    }
}

char Encoding::getAlphabetLetter(string &substring) {
    int number = -1;
    for(int i = 0; i <= key.size() - 5;){
        int initial = i;
        bool allCharactersMatched = true;
        for(int j = 0; j < 5; ++j, ++i){
            if(key[i] != substring[j]){
                allCharactersMatched = false;
                break;
            }
        }
        if(allCharactersMatched){
            number = initial;
            break;
        }
        else{
            i = initial + 1;
        }
    }
    char result = number + 97;
    if(result >= 97 && result <= 122){
        return result;
    }
    else{
        cerr << "Помилка функції getAlphabetLetter !\n";
    }
}

string Encoding::decode(string &str) {
    if(stringValidation(str)){
        if(str.size() % 5 != 0){
            int max = (str.size() / 5) * 5;
            str = str.substr(0, max);
        }
        for(int i = 0; i < str.size(); ++i){
            int charToInt = str[i];
            if(charToInt >= 65 && charToInt <= 90){
                str[i] = 'b';
            }
            else{
                str[i] = 'a';
            }
        }
        string word;
        for(int i = 0; i <= str.size() - 5; i += 5){
            string substring = str.substr(i, 5);
            word += getAlphabetLetter(substring);
        }
        return word;
    }
}

bool Encoding::stringValidation(string &str) {
    str.erase(remove(str.begin(), str.end(), ' '), str.end());
    for(char ch : str){
        int ascii = ch;
        if(!(ascii >= 65 && ascii <= 90) && !(ascii >= 97 && ascii <= 122)){
            cout << "Символ '" << ch << "' не належить латинському алфавіту !\n";
            return false;
        }
    }
    return true;
}
