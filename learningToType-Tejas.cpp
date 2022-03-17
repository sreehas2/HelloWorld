#include<bits/stdc++.h>
using namespace std;

#define boldGreen "\e[1;32m"
#define normal "\e[0m"

// Change this to change how long cursor animation takes
#define wait this_thread::sleep_for(chrono::milliseconds(300))
#define randomChar (char)(uniform_int_distribution<int>(0,26)(rng))

//Works best on linux but does work on windows too
#ifdef __WIN32
    #define cls system("cls");
#else
    #define cls system("clear")
#endif

// With this commented 
// the program will run within your lifetime
// Otherwise no guarantees
// #define __VERY_VERY_INEFFICIENT

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

string capitalise(string s) {
    if(s[0] != ' ') s[0] -= 32;
    for(int i=1;i<s.size();i++) {
        if(s[i] != ' ' and s[i-1] == ' ') s[i] -= 32;
    }
    return s;
}

void cursor_animate(string s) {
    s = capitalise(s);
    cls;
    for(int i=0;i<6;i++) {
        cout << s;
        if(i%2 == 0) cout << "|" << endl;
        else cout << endl;
        wait;
        cls;
    }
    cout << s << endl;
}


int main()
{
    string s;
    string target = "hello world";
#ifdef __VERY_VERY_INEFFICIENT // Types random strings until it gets Hello world
    while(true) {
        char ch;
        int c = randomChar;
        if(c == 26) ch = ' ';
        else ch = 'a'+c;
        s += ch;
        cursor_animate(s);
        if(s == "hello world") break;
        if(s.back() != target[s.size()-1]) {
            while(!s.empty()) {
                s.pop_back();
                cursor_animate(s);
            }
        }
    }
#else // types random characters until it gets a chracter right
    while(true) {
        char ch;
        int c = randomChar;
        if(c == 26) ch = ' ';
        else ch = 'a'+c;
        s += ch;
        cursor_animate(s);
        if(s == "hello world") break;
        if(s.back() != target[s.size()-1]) {
            s.pop_back();
            cursor_animate(s);
        }
    }
#endif
}