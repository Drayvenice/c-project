#pragma once
#include <string>

/**
 * @file DataPoint.h
 * @brief Represents a single 3D gravity vector data point.
 * @author [Your Name] & [Teammate Name]
 */

/**
 * @class DataPoint
 * @brief Stores x, y, z gravity values and an orientation label.
 */
class DataPoint {
public:
    double x; ///< X-axis gravity value
    double y; ///< Y-axis gravity value
    double z; ///< Z-axis gravity value
    int label; ///< Orientation label (0 = unknown)

    // TODO: Constructor(s)

    // TODO: getOrientationName() — return string like "Face up" based on label

    // TODO: isValid() — check if x, y, z are all within [-1, 1]
};
