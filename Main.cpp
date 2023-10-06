#include <iostream>
#include <array>
#include <time.h>
#include <cstdlib>
#include <string>

std::string getOsName() {
#ifdef _WIN32
    return "Windows 32-bit";
#elif _WIN64
    return "Windows 64-bit";
#elif __APPLE__ || __MACH__
    return "Mac OSX";
#elif __linux__
    return "Linux";
#elif __FreeBSD__
    return "FreeBSD";
#elif __unix || __unix__
    return "Unix";
#else
    return "Other";
#endif
};

using namespace std;

int numberms = 100;
int timestoloop = 30;

string done;
string baseText = "Programme: ";
string baseYou = "You: ";

bool ran = false;

void checkFinished() {
    cout << baseText << "Type 'yes' once you are ready to move on" << endl << endl;

    cout << baseYou;
    cin >> done;

    if (done == "Yes" || done == "Y" || done == "yes" || done == "y") {
        ran = true;
    };
}

void clearTerminal() {
    if (getOsName() == "Mac OSX") {
        system("clear");
    };
};

string reply;


bool MultiplyOption = false;
bool DivideOption = false;
bool AddOption = false;

string answer;

const string multiplyResponses[4] = { "Okay, what 2 numbers would you like to multiply?", "Sure, what 2 numbers do you want to multiply?", "Alright, give me 2 numbers to multiply", "Certainly, enter the 2 numbers you would like to multiply" };

const string divideResponses[4] = { "Okay, what 2 numbers would you like to divide?", "Sure, what 2 numbers do you want to divide?", "Alright, give me 2 numbers to divide", "Certainly, enter the 2 numbers you would like to divide" };

const string additionResponses[4] = { "Okay, what 2 numbers would you like to add?", "Sure, what 2 numbers do you want to add?", "Alright, give me 2 numbers to add", "Certainly, enter the 2 numbers you would like to add" };

const string subtractResponses[4] = { "Okay, what 2 numbers would you like to subtract?", "Sure, what 2 numbers do you want to subtract?", "Alright, give me 2 numbers to subtract", "Certainly, enter the 2 numbers you would like to subtract" };

class math {
public:

    double multiply(double a, double b) {
        int sum = (a * b);
        return sum;
    };

    double divide(double a, double b) {
        double sum = (a / b);
        return sum;
    };

    double add(double a, double b) {
        int sum = (a + b);
        return sum;
    };

    double subtract(double a, double b) {
        double sum = (a - b);
        return sum;
    };
};

void mainMultiply() {
    math equation;
    for (int i = 1; i <= 1; ++i) {

        short RanIndex = rand() % 4;

        cout << baseText << multiplyResponses[RanIndex] << endl << endl;

        double first;
        double second;
        cout << baseYou;
        cin >> first >> second;

        cout << endl << endl;

        cout << baseText << first << " Multiplied by " << second << " equals "
            << equation.multiply(first, second) << endl << endl;

        checkFinished();

    };
};

void mainDivide() {
    math equation;
    for (int i = 1; i <= 1; ++i) {

        short RanIndex = rand() % 4;

        cout << baseText << divideResponses[RanIndex] << endl << endl;

        double first;
        double second;
        cout << baseYou;
        cin >> first >> second;

        cout << endl << endl;

        cout << baseText << first << " Divided by " << second << " equals "
            << equation.divide(first, second) << endl << endl;

        checkFinished();

    };
};

void mainAdd() {

    math equation;
    for (int i = 1; i <= 1; ++i) {

        short RanIndex = rand() % 4;

        cout << baseText << additionResponses[RanIndex] << endl << endl;

        double first;
        double second;
        cout << baseYou;
        cin >> first >> second;

        cout << endl << endl;

        cout << baseText << first << " With " << second << " Added onto it equals "
            << equation.add(first, second) << endl << endl;

        checkFinished();

    };
};

void mainSubtract() {
    for (int i = 1; i <= 1; ++i) {

        math equation;

        short RanIndex = rand() % 4;

        cout << baseText << subtractResponses[RanIndex] << endl << endl;

        double first;
        double second;
        cout << baseYou;
        cin >> first >> second;

        cout << endl << endl;

        cout << baseText << first << " Take away " << second << " equals "
            << equation.subtract(first, second) << endl << endl;

        checkFinished();

    };
};


const char CheckM = 'm';
const char CheckD = 'd';
const char CheckA = 'a';
const char CheckS = 's';



int main() {

    clearTerminal();

    short min = 1;
    short max = 4;

    srand(time(NULL));


    cout << endl << baseText << "What would you like to do?" << endl << endl << "[Multiply]" << endl << "[Divide]" << endl << "[Addition]" << endl << "[Subtraction]" << endl << endl;

    cout << baseYou;
    cin >> answer;
    cout << endl << endl;

    if (answer == "Multiply" || answer == "multiply") {
        mainMultiply();
    }
    else if (answer == "Divide" || answer == "divide") {
        mainDivide();
    }
    else if (answer == "Add" || answer == "add") {
        mainAdd();
    }
    else if (answer == "Subtract" || answer == "subtract") {
        mainSubtract();
    }
    else if (answer == "Terminate" || answer == "terminate" || answer == "Close" || answer == "close" || answer == "Close application") {
        cout << "Terminating application";
        exit(0);
        //void abort(void);
    }
    else {
        cout << baseText << "I'm sorry, I didn't quite catch that" << endl;

        char newAnswer = answer.at(0);

        string str1, str2;

        string Multiply = "Mul";
        string Multiply2 = "mul";
        string Divide = "Div";
        string Divide2 = "div";
        string Add = "Add";
        string Add2 = "add";
        string Subtract = "Sub";
        string Subtract2 = "sub";

        str1 = answer;


        short length1, length2;

        switch (newAnswer) {
        case CheckM:
            str2 = Multiply;
            break;
        case CheckD:
            str2 = Divide;
            break;
        case CheckA:
            str2 = Add;
            break;
        case CheckS:
            str2 = Subtract;
            break;
        };
        length1 = 3;

        string findSub;

        findSub = str1.substr(0, length1);
        const char* SubStringFound = findSub.c_str();
        const char* string2Char = str2.c_str();

        if (strcmp(SubStringFound, string2Char)) {
            if (findSub == Multiply || findSub == Multiply2) {
                cout << baseText << "Did you mean Multiply? [Y/N]" << endl << endl;

                cout << baseYou;
                cin >> reply;

                if (reply == "Yes" || reply == "Y" || reply == "yes" || reply == "y") {
                    mainMultiply();
                };
            }
            else if (findSub == Divide || findSub == Divide2) {
                cout << baseText << "Did you mean Divide? [Y/N]" << endl << endl;

                cout << baseYou;
                cin >> reply;

                if (reply == "Yes" || reply == "Y" || reply == "yes" || reply == "y") {
                    mainDivide();
                };
            }
            else if (findSub == Add || findSub == Add2) {
                cout << baseText << "Did you mean Add? [Y/N]" << endl << endl;

                cout << baseYou;
                cin >> reply;

                if (reply == "Yes" || reply == "Y" || reply == "yes" || reply == "y") {
                    mainAdd();
                };
            }
            else if (findSub == Subtract || findSub == Subtract2) {
                cout << baseText << "Did you mean Subtract? [Y/N]" << endl << endl;

                cout << baseYou;
                cin >> reply;

                if (reply == "Yes" || reply == "Y" || reply == "yes" || reply == "y") {
                    mainSubtract();
                };
            };
        };
    };

    if (ran == true) {
        main();
        ran = false;
    };

    return 0;
};
