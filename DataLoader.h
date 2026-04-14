#pragma once
#include <vector>
#include <string>
#include "DataPoint.h"

/**
 * @file DataLoader.h
 * @brief Handles reading and writing data files.
 * @author Kristen & Drayven
 */

/**
 * @class DataLoader
 * @brief Reads training/testing/unknown data from .txt files.
 *        Writes classification results to output files.
 */
class DataLoader {
public:
    /**
     * @brief Load labeled data (training or testing).
     * Format: x,y,z,label
     * @param filename Path to file
     * @return Vector of DataPoints
     */
    static std::vector<DataPoint> loadLabeledData(const std::string& filename);

    /**
     * @brief Load unlabeled data (unknown samples).
     * Format: x,y,z
     * @param filename Path to file
     * @return Vector of DataPoints with label = 0
     */
    static std::vector<DataPoint> loadUnknownData(const std::string& filename);

    /**
     * @brief Write classified results to output file.
     * Format: x,y,z,label,OrientationName
     * @param filename Output file path
     * @param points Classified DataPoints
     * @return true if successful
     */
    static bool writeResults(const std::string& filename,
                             const std::vector<DataPoint>& points);
};
