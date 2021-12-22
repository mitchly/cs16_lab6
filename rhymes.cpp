#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <iomanip>
using namespace std;

void lastWord(string arr[], int size);
void wordComparisons(string arr[], int size);
void cleanUp(string arr[], int size);


int main(){
    string filename, line;
    ifstream inStream;
    string arr[1000];
    
    cout << "Enter filename: ";
    cin >> filename;

    inStream.open(filename);
    if (inStream.fail()){
        cerr << "Input file opening failed." << endl;
        exit(1);
    }

    int i(0);
    while(getline(inStream, line)){
        arr[i] = line;
        i++;
    }

    inStream.close();

    lastWord(arr, i);
    cleanUp(arr, i);
    wordComparisons(arr, i);
    return 0;
}

void lastWord(string arr[], int size){
    for (int i = 0; i < 1000 ; i++){
        string str;
        if (arr[i].size() > 1){
            str = arr[i].substr(arr[i].rfind(' ')+ 1 );
            arr[i] = str;
        }
    }
}

void cleanUp(string arr[], int size){
    for(int i(0); i < size; i++){
        string str = arr[i];
        int strSize(str.size());
        for(int j(strSize - 1); j > -1; j--){
            if(isalpha(str[j]) == 0){
                str.replace(j, 1, ""); 
            }
        }
        arr[i] = str;
    }
}

void wordComparisons(string arr[], int size){
    int rhymePair(0);
    for(int i(1); i < size; i++){
        if(arr[i].size() > 1 && arr[i - 1].size() > 1){
            if(arr[i - 1].substr(arr[i - 1].size() - 2) == arr[i].substr(arr[i].size() - 2)){
                cout << arr[i - 1] << " and " << arr[i] << endl;
                rhymePair++;
            }
        }
    }

    double numerator = rhymePair;
    
    if(rhymePair == 1){
        cout << "There is 1 pair of rhyming words." << endl;
    }
    else if(rhymePair > 1){
        cout << "There are " << rhymePair << " pairs of rhyming words." << endl;
    }
    else{
        cout << "No rhymes found." << endl;
        if(size == 1){
            cout << "There is one line in this poem.";
            return;
        }
        if(size > 1 || size == 0){
            cout << "There are " << size << " lines in this poem.";
            return;
        }
    }
    
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    
    if(size == 1){
        cout << "There is one line in this poem.";
    }
    else if(size > 1){
        cout << "There are " << size << " lines in this poem, so the rhyme-line density is: " << setprecision(2) << numerator / size;
    }
    else{
        cout << "There are 0 lines in this poem.";
    }
}