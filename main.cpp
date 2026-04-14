#include <iostream>
#include <string>
#include <limits>
#include "DataPoint.h"
#include "DataLoader.h"
#include "Classifier.h"
#include "NNClassifier.h"
#include "StubClassifiers.h"

/**
 * @file main.cpp
 * @brief Entry point - handles user interaction and classifier selection.
 * @author Kristen & Drayven
 * @course PROG71020 - OOP Winter 2026
 */

 // ─── Constants ───────────────────────────────────────────────────────────────
const std::string TRAINING_FILE = "trainingData.txt";
const std::string TESTING_FILE = "testingData.txt";

// ─── Forward declarations ─────────────────────────────────────────────────────
void printBanner();
void runNNMode(Classifier* clf);
void runManualInput(Classifier* clf);
void runFileMode(Classifier* clf);
void runTestAccuracy(Classifier* clf);
void clearInput();

// ─────────────────────────────────────────────────────────────────────────────

/**
 * @brief Application entry point.
 */
int main() {
    printBanner();

    // Load training data
    std::cout << "\n[System] Loading training data...\n";
    std::vector<DataPoint> trainingData = DataLoader::loadLabeledData(TRAINING_FILE);

    if (trainingData.empty()) {
        std::cerr << "[Error] Training data could not be loaded. Exiting.\n";
        return 1;
    }

    // Classifier selection menu
    bool running = true;
    while (running) {
        std::cout << "\n========================================\n";
        std::cout << "  Select a Classifier\n";
        std::cout << "========================================\n";
        std::cout << "  1. NNClassifier  (Nearest Neighbor)\n";
        std::cout << "  2. KNNClassifier (Not implemented)\n";
        std::cout << "  3. AnotherClassifier (Not implemented)\n";
        std::cout << "  0. Exit\n";
        std::cout << "----------------------------------------\n";
        std::cout << "  Your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        if (choice == 0) {
            std::cout << "\nGoodbye!\n";
            running = false;
            break;
        }

        // Create chosen classifier
        Classifier* clf = nullptr;
        switch (choice) {
        case 1: clf = new NNClassifier(); break;
        case 2: clf = new KNNClassifier(); break;
        case 3: clf = new AnotherClassifier(); break;
        default:
            std::cout << "[Error] Invalid choice. Please try again.\n";
            continue;
        }

        // Train it
        clf->train(trainingData);

        // If stub — inform user
        if (choice == 2 || choice == 3) {
            std::cout << "\n[Notice] " << clf->getName()
                << " is not implemented yet.\n";
            delete clf;
            continue;
        }

        // Run NN mode
        runNNMode(clf);
        delete clf;
    }

    return 0;
}

void clearInput() {
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void printBanner() {
    std::cout << "============================================\n";
    std::cout << "   Phone Orientation Classifier\n";
    std::cout << "   PROG71020 - OOP Winter 2026\n";
    std::cout << "============================================\n";
    std::cout << "\nLabel  Orientation\n";
    std::cout << "-----  --------------------\n";
    std::cout << "  1    Face up\n";
    std::cout << "  2    Face down\n";
    std::cout << "  3    Portrait\n";
    std::cout << "  4    Portrait upside down\n";
    std::cout << "  5    Landscape left\n";
    std::cout << "  6    Landscape right\n";
}

void runNNMode(Classifier* clf) {
    // TODO: implement
}

void runManualInput(Classifier* clf) {
    // TODO: implement
}

void runFileMode(Classifier* clf) {
    // TODO: implement
}

void runTestAccuracy(Classifier* clf) {
    // TODO: implement
}

void clearInput() {
    // TODO: implement
}
