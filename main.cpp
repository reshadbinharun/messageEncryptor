//Word Scrambler
//add length of array to each char's ASCII value
//swap characters about pivot

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;

const string output = "result.txt";
const string input = "input.txt";

string scramble(string);
string unscramble(string);
int main(){
    //input file
    ifstream infile;
    infile.open(input.c_str());//opens the file
    if (!infile.is_open()) cout << "Input File could not be opened!\n";
    string out;
    ofstream outfile;
    outfile.open(output.c_str());
    if (!infile.is_open()) cout << "Output File could not be opened!\n";
    while (!infile.eof()){
        char x;
        string word = "";
        while(x!=' '){
            x = infile.get();
            word += x;
        }
        //call scramble or unscramble
        out += (word + " ") ; //adds space
        word ="";
    }
    outfile.write((char*)&out,out.length()-1); //ref:https://stackoverflow.com/questions/15388041/how-to-write-stdstring-to-file
    
    //go word by word, and build up and updated
    string str;
    cout << "Please input a string: \n";
    cin >> str;
    cout << "Your scrambled word is: \n";
    cout << scramble(str) << endl;
    //Unscramble
    cout << "Enter string to unscramble: \n";
    cin >> str;
    cout << "Your scrambled word is: \n";
    cout << unscramble(str) << endl;
    return 0;
}

void input_file(istream &cin){
    
}

string scramble(string str){
    for (auto &s: str){
        s+= 1;
    }
    int mid = floor(str.length()/2); //ceil to unscramble
    int start = 0;
    int end = str.length()-1;
    while (start!=mid && end!=mid){
        swap(str[start++],str[end--]);
    }
    return str;
}

string unscramble(string str){
    int mid = ceil(str.length()/2); //ceil to unscramble
    int start = 0;
    int end = str.length()-1;
    while (start!=mid && end!=mid){
        swap(str[start++],str[end--]);
    }
    for (auto &s: str){
        s = s - 1; //assuming first and last ASCII values are not used
        //weird first ASCII, and DEL
    }
    return str;
}
