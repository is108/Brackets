#include <iostream>
#include <string>
#include <vector>

using namespace std;

string brackets;
string open_brackets = "";

bool validateBrackets(int i); // Сортировка скобок на левые и правые.
bool compareWithOpen(char brack); // Сопоставление скобок.
bool CheckBrackets_v2(char brack, char open_brack, char close_brack);
void Exit(); // Выход из программы если условие неверно.
bool isOpenBracket(const char brack); //
bool isCloseBracket(const char brack);


int main()
{
    cout << "Введите последовательность скобок: ";
    cin >> brackets;

    int counter_brackets = 0;

    for (int i = 0; i < brackets.length(); i++){ // Подсчет левых и правых скобок. Если количество одинаковое counter_brackets = 0.
        if (isOpenBracket(brackets[i]))
            counter_brackets++;
        else if (isCloseBracket(brackets[i]))
            counter_brackets--;
    }
    if (counter_brackets == 0 && isOpenBracket(brackets[0])) // Если количество скобок равно и первая скобка
        validateBrackets(brackets.length() - 1);                                                     // не закрывающая.
    else Exit();


    if (open_brackets == "")
        cout << "True Скобки расставлены правильно.\n";
    else cout << "False Скобки расставлены неправильно.\n";

    return 0;
}

bool validateBrackets(int i){
    if (i >= 0) {
        if (!validateBrackets(i - 1))
            return false;
        if (isOpenBracket(brackets[i]))
            open_brackets += brackets[i];
        else if (isCloseBracket(brackets[i]))
            return compareWithOpen(brackets[i]);
    }
    return true;
}

char pairFor(char bracket){
    if (bracket == ')')
        return '(';
    if (bracket == ']')
        return '[';
    if (bracket == '}')
        return '{';
    return '0';
}

bool compareWithOpen(char closeBrack){
    if (open_brackets.back() == pairFor(closeBrack)){
        open_brackets.pop_back();
        return true;
    }
    return false;
}

void Exit(){
    cout << "Скобки расставлены неправильно.\n";
    exit(0);
}

bool isOpenBracket(const char brack){
    return (brack == '[' || brack == '(' || brack == '{');
}

bool isCloseBracket(const char brack){
    return (brack == ']' || brack == ')' || brack == '}');
}
