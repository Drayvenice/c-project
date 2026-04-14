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
    bool inNNMenu = true;
    while (inNNMenu) {
        std::cout << "\n--- " << clf->getName() << " ---\n";
        std::cout << "  1. Enter x,y,z manually\n";
        std::cout << "  2. Classify a file\n";
        std::cout << "  3. Test accuracy on testingData.txt\n";
        std::cout << "  0. Back\n";
        std::cout << "  Your choice: ";

        int choice;
        std::cin >> choice;
        clearInput();

        switch (choice) {
        case 1: runManualInput(clf); break;
        case 2: runFileMode(clf); break;
        case 3: runTestAccuracy(clf); break;
        case 0: inNNMenu = false; break;
        default: std::cout << "[Error] Invalid choice.\n"; break;
        }
    }
}

void runManualInput(Classifier* clf) {
    std::cout << "\nEnter x, y, z values (space-separated, range -1 to 1):\n";
    std::cout << "  x y z: ";

    double x, y, z;
    std::cin >> x >> y >> z;
    clearInput();

    DataPoint point(x, y, z);

    if (!point.isValid()) {
        std::cout << "[Error] Values must be between -1 and 1. Please try again.\n";
        return;
    }

    int label = clf->predict(point);
    point.label = label;

    std::cout << "\nResult:\n";
    std::cout << "  Input:       (" << x << ", " << y << ", " << z << ")\n";
    std::cout << "  Label:       " << label << "\n";
    std::cout << "  Orientation: " << point.getOrientationName() << "\n";
}

void runFileMode(Classifier* clf) {
    std::cout << "\nEnter input filename (e.g., unknownData.txt): ";
    std::string inputFile;
    std::cin >> inputFile;
    clearInput();

    std::vector<DataPoint> points = DataLoader::loadUnknownData(inputFile);

    if (points.empty()) {
        std::cout << "[Error] No valid data found in: " << inputFile << "\n";
        return;
    }

    // Classify all points
    clf->classifyAll(points);

    // Output filename
    std::cout << "Enter output filename (default: result.txt): ";
    std::string outputFile;
    std::getline(std::cin, outputFile);
    if (outputFile.empty()) outputFile = "result.txt";

    DataLoader::writeResults(outputFile, points);

    // Preview first 5
    std::cout << "\nPreview (first 5 results):\n";
    std::cout << "  x,y,z,label,Orientation\n";
    int preview = std::min((int)points.size(), 5);
    for (int i = 0; i < preview; i++) {
        const auto& p = points[i];
        std::cout << "  " << p.x << "," << p.y << "," << p.z << ","
            << p.label << "," << p.getOrientationName() << "\n";
    }
    if ((int)points.size() > 5)
        std::cout << "  ... and " << (points.size() - 5) << " more.\n";
}

void runTestAccuracy(Classifier* clf) {
    // TODO: implement
}

void clearInput() {
    // TODO: implement
}
