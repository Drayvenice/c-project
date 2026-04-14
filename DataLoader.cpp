#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @file DataLoader.cpp
 * @brief Implementation of DataLoader file I/O functions.
 * @author Kristen & Drayven
 */

 /**
  * @brief Loads labeled data from a file.
  * @details Reads each line in format x,y,z,label.
  *          Skips invalid rows where values are outside [-1, 1].
  * @param filename Path to the input file
  * @return Vector of valid DataPoints
  */
std::vector<DataPoint> DataLoader::loadLabeledData(const std::string& filename) {
    std::vector<DataPoint> points;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "[Error] Cannot open file: " << filename << std::endl;
        return points;
    }

    std::string line;
    int lineNum = 0;
    int skipped = 0;

    while (std::getline(file, line)) {
        lineNum++;
        if (line.empty()) continue;

        std::stringstream ss(line);
        std::string token;
        double x, y, z;
        int label;

        try {
            std::getline(ss, token, ','); x = std::stod(token);
            std::getline(ss, token, ','); y = std::stod(token);
            std::getline(ss, token, ','); z = std::stod(token);
            std::getline(ss, token, ','); label = std::stoi(token);

            DataPoint dp(x, y, z, label);
            if (!dp.isValid()) {
                std::cerr << "[Warning] Line " << lineNum
                    << " skipped (out of range): " << line << std::endl;
                skipped++;
                continue;
            }
            points.push