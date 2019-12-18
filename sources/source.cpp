// Copyright 2018 Your Name <your_email>

#include <header.hpp>

int main() {
    parseFinantial f;
    string s = "balance_12345678_20191223.txt";
    f.getFiles("/home/dellvin/Desktop/ftp", "", 1);
    f.printDATA();
    return 0;
}
