#include "NNClassifier.h"
#include <cmath>
#include <iostream>
#include <cfloat>

/**
 * @file NNClassifier.cpp
 * @brief Implementation of the NN classifier.
 * @author Kristen & Drayven
 */

double NNClassifier::euclideanDistance(const DataPoint& a, const DataPoint& b) const {
    // TODO: return sqrt( (a.x-b.x)^2 + (a.y-b.y)^2 + (a.z-b.z)^2 )
    return sqrt(
        pow(a.x - b.x, 2) +
        pow(a.y - b.y, 2) +
        pow(a.z - b.z, 2)
    );
}

void NNClassifier::train(const std::vector<DataPoint>& trainingData) {
    // TODO: Store trainingData into trainingData_
    trainingData_ = trainingData;
    std::cout << "[NNClassifier] Training complete. "
        << trainingData_.size() << " samples loaded." << std::endl;
}

int NNClassifier::predict(const DataPoint& point) {
    if (trainingData_.empty()) {
        std::cerr << "[NNClassifier] Error: classifier has not been trained." << std::endl;
        return 0;
    }

    double minDist = DBL_MAX;
    int bestLabel = -1;

    for (const auto& trainPoint : trainingData_) {
        double d = euclideanDistance(point, trainPoint);
        if (d < minDist) {
            minDist = d;
            bestLabel = trainPoint.label;
        }
    }

    return bestLabel;
}
double NNClassifier::evaluate(const std::vector<DataPoint>& testData) {
    // TODO: For each point in testData, call predict()
    // TODO: Compare predicted label vs actual label
    // TODO: Return accuracy = (correct / total) * 100
    int correct = 0;

    for (const auto& point : testData) {
        int predicted = predict(point);
        if (predicted == point.label) {
            correct++;
        }
    }

    double accuracy = (double)correct / testData.size() * 100.0;
    std::cout << "[NNClassifier] Accuracy: " << correct << "/"
        << testData.size() << " = " << accuracy << "%" << std::endl;

    return accuracy;
}
