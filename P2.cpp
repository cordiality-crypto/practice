#include <iostream>
using namespace std;

string RemoveDuplicates(string, int, int[]);
string Reverse(string, int);
/*
TEST CASES:
3 allah mine SixxiS 
*/
int main() {
    cout << "T = \t" << endl;
    int t;
    cin >> t;
    while (t--) {
        cout << "Word = \t" << endl;
        string Word;
        cin >> Word;
        int arr[26] = {0};
        cout << Reverse(RemoveDuplicates(Word, Word.length()-1, arr), Word.length()-1) << endl;
    }
    return 0;
}

string RemoveDuplicates(string str, int n, int arr[]) {
    if (n > -1) {
        char ch = str[n];
        if (ch >= 'a' && ch <= 'z') {
            if (arr[ch - 'a'] == 0) {
                arr[ch - 'a']++;
                return ch + RemoveDuplicates(str, n-1, arr);
            }
            return RemoveDuplicates(str, n-1, arr);
        }
        else if (ch >= 'A' && ch <= 'Z') {
            if (arr[ch - 'A'] == 0) {
                arr[ch - 'A']++;
                return ch + RemoveDuplicates(str, n-1, arr);
            }
            return RemoveDuplicates(str, n-1, arr);
        }
        return ch + RemoveDuplicates(str, n-1, arr);
    }
    return "\0";
}

void swap(char *A, char *B) {
    char temp = *A;
    *A = *B;
    *B = temp;
}

string Reverse(string s, int n) {
    for(int i = 0; i < n / 2; i++) 
        swap(&s[i], &s[n-i-1]);
    return s;
}