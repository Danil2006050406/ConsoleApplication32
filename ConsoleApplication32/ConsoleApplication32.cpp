#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#elif __linux
#include <termios.h>
#endif

using namespace std;

string Укр = "йцукенгшщзхждлорпавфячсмитьбюЙЦУКЕНГШЩЗХЖДЛОРПАВФЯЧСМИТЬБЮґҐІіЄєЇї";
string Eng = "qwertyuioplkjhgfdsazxcvbnmQWERTYUIOPLKJHGFDSAZXCVBNM";
string Num = "0123456789";
string Symb = "`~!@#$%^&*()_+}{|\":<>?/.,\\';][=-№";

char getChar() {
#ifdef _WIN32
    return _getch();
#elif __linux
    struct termios Old, New;
    tcgetattr(0, &Old);
    New = Old;
    New.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(0, TCSANOW, &New);
    char ch = getchar();
    tcsetattr(0, TCSANOW, &Old);
    return ch;
#endif
}

string processInput(int choice) {
    string text;
    char ch;
    bool run = true;

    cout << "Для закінчення введення даних натисніть клавішу esc\n";

    while (run) {
        ch = getChar();

        switch (choice) {
        case 1:
            for (int i = 0; i < Num.length(); i++) {
                if (ch == Num[i]) {
                    ch = ' ';
                }
                else if (ch == 27) {
                    run = false;
                    ch = ' ';
                    break;
                }
            }
            break;
        case 2:
            for (int i = 0; i < Symb.length(); i++) {
                if (ch == Symb[i]) {
                    ch = ' ';
                }
                else if (ch == 27) {
                    run = false;
                    ch = ' ';
                    break;
                }
            }
            break;
        case 3:
            for (int i = 0; i < Eng.length(); i++) {
                if (ch == Eng[i]) {
                    ch = ' ';
                }
                else if (ch == 27) {
                    run = false;
                    ch = ' ';
                    break;
                }
            }
            break;
        case 4:
            for (int i = 0; i < Укр.length(); i++) {
                if (ch == Укр[i]) {
                    ch = ' ';
                }
                else if (ch == 27) {
                    run = false;
                    ch = ' ';
                    break;
                }
            }
            break;
        default:
            run = false;
            break;
        }

        text += ch;
        cout << ch;
    }

    cout << endl << "Ви ввели текст:\n";
    cout << text << endl;

    return text;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    int choice;
    bool menu_run = true;
    string text;

    while (menu_run) {
        cout << "Натисніть 1 для заміни цифр пробілами\n";
        cout << "Натисніть 2 для заміни розділових знаків пробілами\n";
        cout << "Натисніть 3 для заміни англійських букв пробілами\n";
        cout << "Натисніть 4 для заміни українських букв пробілами\n";
        cin >> choice;

        switch (choice) {
        case 1:
        case 2:
        case 3:
        case 4:
            text = processInput(choice);
            break;
        default:
            menu_run = false;
            break;
        }
    }

    return 0;
}
