#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;

double mean(double arr[], int size);
double median(double arr[], int size); //bubble sort
double stanDev(double arr[], int size);

int main() {
    string filename;
    ifstream inStream;
    double next(0);
    double arr[1000];

    cout << "Enter filename: ";
    cin >> filename;

    inStream.open(filename);

    int i(0);
    while(inStream >> next){
        arr[i] = next;
        i++;
    }

    double meanVar = mean(arr, i);
    double medianVar = median(arr, i);
    double stdDevVar = stanDev(arr, i);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout << "Mean = " << setprecision(3) << meanVar << endl;
    cout << "Median = " << setprecision(3) << medianVar << endl;
    cout << "Stddev = " << setprecision(3) << stdDevVar;
    
    inStream.close();
    return 0;
}

double mean(double arr[], int size){
    double total(0);
    for(int i = 0; i < size; i ++){
        total += arr[i];
    }
    double mean = total / size;
    return mean; // return mean
}

double median(double arr[], int size){
    double median(0);
    for(int i = size - 1; i >= 0; i--){
        for(int j = 1; j <= i; j++){
            if(arr[j - 1] > arr[j]){
                double swap(0);
                swap = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = swap;
            }
        }
    }
    if(size % 2 == 0){
        median = (arr[(size / 2) - 1] + arr[(size / 2)]) / 2;
    }
    else {
        median = arr[(size - 1) / 2];
    }
    return median; // return median
}

double stanDev(double arr[], int size){
    double stdDev(0);
    double meanVar = mean(arr, size);
    for(int i = 0; i < size; i++){
        stdDev = stdDev + pow((arr[i] - meanVar), 2);
    }
    stdDev = sqrt((stdDev) / (size - 1));
    return stdDev; // return stdev
}