#include <iostream>
#include <string>
#include <vector>

using namespace std;

string brackets;
string open_brackets = "";
bool isSuccess = true;

string SortBrackets(int i); // Сортировка скобок на левые и правые. 
string CheckBrackets(char brack); // Сопоставление скобок.
bool CheckBrackets_v2(char brack, char open_brack, char close_brack);
void Exit(); // Выход из программы если условие неверно.
bool OpenBrackets(char brack); //
bool CloseBrackets(char brack);


int main()
{
    cout << "Введите последовательность скобок: ";
    cin >> brackets;

    int counter_brackets = 0;

    for (int i = 0; i < brackets.length(); i++){ // Подсчет левых и правых скобок. Если количество одинаковое counter_brackets = 0.
        if (OpenBrackets(brackets[i]))
            counter_brackets++;
        if (CloseBrackets(brackets[i]))
            counter_brackets--;
    }
    if (counter_brackets == 0 && OpenBrackets(brackets[0])) // Если количество скобок равно и первая скобка
        SortBrackets(brackets.length() - 1);                                                     // не закрывающая.
    else Exit();
    
    
    if (open_brackets == "")
        cout << "Скобки расставлены правильно.\n";
    else cout << "Скобки расставлены неправильно.\n";

    return 0;
}

string SortBrackets(int i){
    if (i >= 0) {

        SortBrackets (i - 1);

        if (OpenBrackets(brackets[i]))
            open_brackets += brackets[i];
            
        if (CloseBrackets(brackets[i])) 
            open_brackets = CheckBrackets(brackets[i]);
    }
       return open_brackets;

}

string CheckBrackets(char brack){
    if (CloseBrackets(brack)){
    isSuccess = CheckBrackets_v2(brack, '(', ')');
    if (!isSuccess)
        isSuccess = CheckBrackets_v2 (brack, '[', ']');
        if (!isSuccess)
            isSuccess = CheckBrackets_v2 (brack, '{', '}');
    }
    
    return open_brackets;
}

bool CheckBrackets_v2 (char brack, char open_brack, char close_brack){
    if (brack == close_brack){
        if (open_brackets[open_brackets.length() - 1] == open_brack){
            open_brackets.pop_back();
            return true;
        }
        else return false;
    }

}
void Exit(){
    cout << "Скобки расставлены неправильно.\n";
    exit(0);
}

bool OpenBrackets(char brack){
    if (brack == '[' || brack == '(' || brack == '{')
        return true;
    else return false;
}

bool CloseBrackets(char brack){
    if (brack == ']' || brack == ')' || brack == '}')
        return true; 
    else return false;
}