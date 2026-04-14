#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

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
            points.push_back(dp);
        }
        catch (...) {
            std::cerr << "[Warning] Line " << lineNum
                << " could not be parsed: " << line << std::endl;
            skipped++;
        }
    }

    file.close();
    std::cout << "[DataLoader] Loaded " << points.size()
        << " points from " << filename;
    if (skipped > 0) std::cout << " (" << skipped << " skipped)";
    std::cout << std::endl;
    return points;
}

/**
 * @brief Loads unlabeled data from a file.
 * @details Reads each line in format x,y,z (no label).
 *          Skips invalid rows where values are outside [-1, 1].
 *          All loaded points get label = 0 (unknown).
 * @param filename Path to the input file
 * @return Vector of DataPoints with label = 0
 */
std::vector<DataPoint> DataLoader::loadUnknownData(const std::string& filename) {
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

        try {
            std::getline(ss, token, ','); x = std::stod(token);
            std::getline(ss, token, ','); y = std::stod(token);
            std::getline(ss, token, ','); z = std::stod(token);

            DataPoint dp(x, y, z, 0);
            if (!dp.isValid()) {
                std::cerr << "[Warning] Line " << lineNum
                    << " skipped (out of range): " << line << std::endl;
                skipped++;
                continue;
            }
            points.push_back(dp);
        }
        catch (...) {
            std::cerr << "[Warning] Line " << lineNum
                << " could not be parsed: " << line << std::endl;
            skipped++;
        }
    }

    file.close();
    std::cout << "[DataLoader] Loaded " << points.size()
        << " unknown points from " << filename;
    if (skipped > 0) std::cout << " (" << skipped << " skipped)";
    std::cout << std::endl;
    return points;
}

/**
 * @brief Writes classification results to an output file.
 * @details Output format per line: x,y,z,label,OrientationName
 *          Example: -0.14139,-0.04982,-0.9887,1,Face up
 * @param filename Output file path (e.g., "result.txt")
 * @param points Vector of classified DataPoints
 * @return true if write was successful, false otherwise
 */
bool DataLoader::writeResults(const std::string& filename,
    const std::vector<DataPoint>& points) {
    std::ofstream file(filename);

    if (!file.is_open()) {
        std::cerr << "[Error] Cannot write to file: " << filename << std::endl;
        return false;
    }

    for (const auto& p : points) {
        file << p.x << "," << p.y << "," << p.z << ","
            << p.label << "," << p.getOrientationName() << "\n";
    }

    file.close();
    std::cout << "[DataLoader] Results written to: " << filename << std::endl;
    return true;
}