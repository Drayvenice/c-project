#pragma once
#include <string>

/**
 * @file DataPoint.h
 * @brief Represents a single 3D gravity vector data point.
 * @author Kristen & Drayven
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

    /**
     * @brief Default constructor. Initializes all values to 0.
     */
    DataPoint() : x(0), y(0), z(0), label(0) {}

    /**
     * @brief Parameterized constructor.
     * @param x X-axis value
     * @param y Y-axis value
     * @param z Z-axis value
     * @param label Orientation label (default 0 = unknown)
     */
    DataPoint(double x, double y, double z, int label = 0)
        : x(x), y(y), z(z), label(label) {
    }

    /**
     * @brief Returns the orientation name based on label.
     * @return Orientation string (e.g., "Face up")
     */
    std::string getOrientationName() const {
        switch (label) {
        case 1: return "Face up";
        case 2: return "Face down";
        case 3: return "Portrait";
        case 4: return "Portrait upside down";
        case 5: return "Landscape left";
        case 6: return "Landscape right";
        default: return "Unknown";
        }
    }

    /**
     * @brief Checks if x, y, z are all within [-1, 1].
     * @return true if valid, false otherwise
     */
    bool isValid() const {
        return (x >= -1.0 && x <= 1.0) &&
            (y >= -1.0 && y <= 1.0) &&
            (z >= -1.0 && z <= 1.0);
    }
};