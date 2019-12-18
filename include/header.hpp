// Copyright 2018 Your Name <your_email>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_

#include <iostream>
#include <boost/filesystem.hpp>
#include <vector>
#include <map>
#include <string>
#include <utility>
using std::string;
using std::cout;
using std::endl;
using std::map;
using boost::filesystem::directory_iterator;
using boost::filesystem::directory_entry;
using boost::filesystem::path;
using std::pair;

const char* balance = "balance";
const char* spacer = "_";
const char* txt = "txt";

struct economistProjects {
    string broker;
    int billsCount;
    int billLastDate;
};

class parseFinantial {
public:
    void setDATA_BASE(string economist, string info) {
        bool existedEconomistFlag = false;
        string currentStringBill;
        string currentStringDate;
        int currentDate;
        int pos = info.find("_");
        int endPos = info.find("_", pos + 1);
        for (int i = pos + 1; i < endPos; i++) {
            currentStringBill.push_back(info.at(i));
        }
        pos = endPos;
        for (uint64_t i = pos + 1; i < info.size(); i++) {
            currentStringDate.push_back(info.at(i));
        }
        currentDate = atoi(currentStringDate.c_str());
        if (DATA_BASE.find(currentStringBill) != DATA_BASE.end()) {
            existedEconomistFlag = true;
        }
        economistProjects existedStruct;
        if (DATA_BASE.find(currentStringBill) != DATA_BASE.end()) {
            existedStruct = DATA_BASE[currentStringBill];
        }
        if (existedEconomistFlag) {
            existedStruct.billsCount++;
            if (existedStruct.billLastDate < currentDate) {
                existedStruct.billLastDate = currentDate;
            }
            existedStruct.broker = economist;
            DATA_BASE[currentStringBill] = existedStruct;
        } else {
            existedStruct.billsCount = 1;
            existedStruct.billLastDate = currentDate;
            existedStruct.broker = economist;
            DATA_BASE.insert(pair<string, economistProjects>
                    (currentStringBill, existedStruct));
        }
    }

    void printDATA() {
        for (auto it = DATA_BASE.begin(); it != DATA_BASE.end(); ++it) {
            cout << "broker: " << (*it).first << " account: "
            << (*it).second.broker
                 << " files: " << (*it).second.billsCount
                 << " lastdate: " << (*it).second.billLastDate << endl;
        }
    }

    bool checkFileName(string pathToFile) {
        const path p{pathToFile};
        string fileName = boost::filesystem::basename(p.stem());
        if (pathToFile.size() != 25) return false;
        if (!fileName.find(balance)) {
            if (fileName.find(spacer) == 7) {
                for (int i = 8; i < 16; i++) {
                    if (!checkNumber(fileName.at(i))) {
                        return false;
                    }
                }
                if (fileName.find(spacer, fileName.find(spacer) + 1) == 16) {
                    for (int i = 17; i < 25; i++) {
                        if (!checkNumber(fileName.at(i))) {
                            return false;
                        }
                    }
                    return true;
                }
            }
        }
        return false;
    }


    void getFiles(string currentDir, string lastDir, int rang) {
        const path d{currentDir};
        for (const directory_entry &x : directory_iterator{d}) {
            const path p = x;
            string fileName = boost::filesystem::basename(p.filename());
            if (is_directory(p))
                getFiles(currentDir + "/" + boost::filesystem::basename
                (p.filename()), fileName, rang + 1);
            if (checkFileName(fileName)) {
                cout << lastDir << " " << fileName << endl;
                setDATA_BASE(lastDir, fileName);
            }
        }
    }

    bool checkNumber(char str) {
        if ((str >= '0') && (str <= '9'))
        {
            return true;
        } else {
            return false;
        }
    }
    const path pathToDir;
    map <string, economistProjects> DATA_BASE;
};

#endif // INCLUDE_HEADER_HPP_
