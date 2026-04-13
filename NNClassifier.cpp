#include "NNClassifier.h"
#include <cmath>
#include <iostream>

/**
 * @file NNClassifier.cpp
 * @brief Implementation of the NN classifier.
 * @author [Your Name] & [Teammate Name]
 */

double NNClassifier::euclideanDistance(const DataPoint& a, const DataPoint& b) const {
    // TODO: return sqrt( (a.x-b.x)^2 + (a.y-b.y)^2 + (a.z-b.z)^2 )
    return 0.0;
}

void NNClassifier::train(const std::vector<DataPoint>& trainingData) {
    // TODO: Store trainingData into trainingData_
}

int NNClassifier::predict(const DataPoint& point) {
    // TODO: Loop through trainingData_
    // TODO: Find the point with smallest euclideanDistance
    // TODO: Return that point's label
    return -1;
}

double NNClassifier::evaluate(const std::vector<DataPoint>& testData) {
    // TODO: For each point in testData, call predict()
    // TODO: Compare predicted label vs actual label
    // TODO: Return accuracy = (correct / total) * 100
    return 0.0;
}
