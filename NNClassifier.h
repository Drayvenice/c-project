#pragma once
#include "Classifier.h"

/**
 * @file NNClassifier.h
 * @brief Nearest Neighbor (NN) classifier.
 * @author [Your Name] & [Teammate Name]
 */

/**
 * @class NNClassifier
 * @brief Classifies using 1-Nearest Neighbor algorithm.
 *
 * Distance formula:
 * d = sqrt((x1-x2)^2 + (y1-y2)^2 + (z1-z2)^2)
 */
class NNClassifier : public Classifier {
private:
    std::vector<DataPoint> trainingData_; ///< Stored training points

    /// @brief Compute Euclidean distance between two points.
    double euclideanDistance(const DataPoint& a, const DataPoint& b) const;

public:
    void train(const std::vector<DataPoint>& trainingData) override;
    int predict(const DataPoint& point) override;
    double evaluate(const std::vector<DataPoint>& testData) override;
    std::string getName() const override { return "NNClassifier"; }
};
