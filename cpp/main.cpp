#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <thread>
#include <chrono>

using namespace std;

int count = 0;

void handler() {
    int thnum = ::count;
    thnum++;
    ::count = thnum;
    for(int i = 5; i > 0; i--) {
        cout << "Thread " << thnum << "(" << i << ")" << endl;
        int t = rand() % 3000 + 1000;
        chrono::milliseconds time(t);
        this_thread::sleep_for(time); 
    }
    cout << "* Ending thread " << thnum << endl;
}

int main() {
    cout << "<< MAIN METHOD BEGINS           >>" << endl;
    srand(time(0));
    for(int i = 0; i < 5; i++) {
        int t = rand() % 3000 + 1000;
        chrono::milliseconds time(t);
        this_thread::sleep_for(time);
        cout << "-> Initializing Thread " << i + 1 << endl;
        std::thread th(handler); 
        th.detach();
    }
    cout << "<< ALL THREADS HAD BEEN STARTED >>" << endl;
    cout << "<< MAIN METHOD ENDS             >>" << endl;
    chrono::milliseconds time(20000);
    this_thread::sleep_for(time);
}
