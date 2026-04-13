#include "DataLoader.h"
#include <fstream>
#include <sstream>
#include <iostream>

/**
 * @file DataLoader.cpp
 * @brief Implementation of DataLoader.
 * @author [Your Name] & [Teammate Name]
 */

std::vector<DataPoint> DataLoader::loadLabeledData(const std::string& filename) {
    std::vector<DataPoint> points;

    // TODO: Open file
    // TODO: Read each line, parse x, y, z, label
    // TODO: Skip invalid rows (out of range)
    // TODO: Add valid DataPoints to vector

    return points;
}

std::vector<DataPoint> DataLoader::loadUnknownData(const std::string& filename) {
    std::vector<DataPoint> points;

    // TODO: Same as loadLabeledData but only 3 values per line (no label)

    return points;
}

bool DataLoader::writeResults(const std::string& filename,
                               const std::vector<DataPoint>& points) {
    // TODO: Open output file
    // TODO: Write each point as: x,y,z,label,OrientationName
    // TODO: Return true if successful

    return false;
}
