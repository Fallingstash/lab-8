

#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

void countOneLetter(string result) {
    vector<vector<int>> letters;
        for (int i = 0; i < 26; i++) {
            vector<int> a;
            letters.push_back(a);
        }
        for (char c : result) {
            if (isalpha(c)) {
                c = tolower(c);
                for (int i = 0; i < 26; i++) {
                    char letter = 'a' + i;
                    if (c == letter) {
                        letters[i].push_back(0);
                    }
                }
            }
        }
        for (int i = 0; i < 26; i++) {
            char letter = 'a' + i;
            if (letters[i].size() > 0) { 
                cout << letter << " повторяется в тексте " << letters[i].size() << " раз" << endl;
            }
        }
}
void countTwoLetters(string result) {
    int count = 0;
    vector<vector<int>> doubleletters;
    for (int i = 0; i < 676; i++) {
        vector<int> aa;
        doubleletters.push_back(aa);
    }
    for (int i = 0; i < 26; i++) {
        char letter1 = 'a' + i;
        for (int j = 0; j < 26; j++) {
            char letter2 = 'a' + j;
            count++;
            for (int count1 = 0; count1 < result.size(); count1++) {
                if (result[count1] == letter1 and result[count1 + 1] == letter2) {
                    doubleletters[count].push_back(0);
                }
            }
        }
    }
    count = 0;
    for (int i = 0; i < 26; i++) {
        char letter1 = 'a' + i;
        for (int j = 0; j < 26; j++) {
            count++;
            string str;
            char letter2 = 'a' + j;
            str = str + letter1 + letter2;
            if (doubleletters[count].size() > 0) {
                cout << str << " повторяется в тексте " << doubleletters[count].size() << " раз" << endl;
            }
        }
    }

}
void readFile(string name){
    string result;
    ifstream in(name);
    getline(in, result);
    countOneLetter(result);
    countTwoLetters(result);
}

int main()
{
    string file = "txt.txt";
    readFile(file);
    

    return 0;
}