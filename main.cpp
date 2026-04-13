/**
 * @file main.cpp
 * @brief Entry point — handles user interaction and classifier selection.
 * @author [Your Name] & [Teammate Name]
 * @course PROG71020 — OOP Winter 2026
 */

#include <iostream>
#include <string>
#include "DataPoint.h"
#include "DataLoader.h"
#include "Classifier.h"
#include "NNClassifier.h"
#include "StubClassifiers.h"

int main() {
    // TODO: Print welcome banner

    // TODO: Load trainingData.txt using DataLoader

    // TODO: Show menu — ask user to pick classifier (1=NN, 2=KNN, 3=Another, 0=Exit)

    // TODO: Create the chosen Classifier object (use polymorphism)

    // TODO: Call clf->train(trainingData)

    // TODO: If KNN or AnotherClassifier selected — print "not implemented" message

    // TODO: If NNClassifier selected — show sub-menu:
    //   Option 1: manual x,y,z input → validate → predict → print result
    //   Option 2: enter filename → load → classifyAll → write result.txt
    //   Option 3: test accuracy on testingData.txt → print accuracy %

    // TODO: Loop back to classifier selection until user exits

    return 0;
}
