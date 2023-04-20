#include "Encoding.h"

int main() {
    cout << "1 - Зашифрувати слово\n"
            "2 - Розшифрувати речення\n"
            "Введіть пункт меню : ";
    string user;
    getline(cin, user);
    if(user == "1"){
        cout << "Потрібно ввести слово, яке хочете зашифрувати,\nнаприклад \"prometheus\"\nСлово : ";
        string word;
        getline(cin, word);
        cout << "Потрібно ввести речення, в якому хочете сховати повідомлення,\nнаприклад \"Welcome to the Hotel California Such a lovely place Such a lovely place\"\nРечення : ";
        string text;
        getline(cin, text);
        cout << "Результат : " << Encoding::encode(word, text);
    }
    else if(user == "2"){
        cout << "Потрібно ввести рядок, який потрібно розшифрувати,\nнаприклад \"wELcOMe To The HOtEL caLiFORNIa SUcH A LoVeLY PLaCE sucH a LOvely\"\nРядок : ";
        string str;
        getline(cin, str);
        cout << "Результат : " << Encoding::decode(str);
    }
    else{
        return 0;
    }

    return 0;
}

