#include <cmath>
#include <iostream>
#include "pbPlots.hpp" 
#include "supportLib.hpp"
using namespace std;

class swerve {
private:
    const float constant[8][3] = {
        {1, 0, -0.26363}, {0, 1, 0.26363},
        {1, 0, -0.26363}, {0, 1, 0.26363},
        {1, 0, -0.26363}, {0, 1, 0.26363},
        {1, 0, -0.26363}, {0, 1, 0.26363}
    };
    float content[631][8] = {0};
    float resultant[631][4] = {0};
    float pose[631][3] = {0};
    int current_memory = 0;

public:
    void velocityCommand(float vx, float vy, float omega) {
        float commandInput[3] = {vx, vy, omega};

        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 3; j++) {
                content[current_memory][i] += constant[i][j] * commandInput[j];
            }
        }

        velocityResultant();
        current_memory++;
    }

    void velocityResultant() {
        for (int i = 0; i < 8; i += 2) {
            for (int j = 0; j < 3; j += 2) {
                resultant[current_memory][i / 2] +=
                    sqrt(pow(content[current_memory][i + j], 2) + pow(content[current_memory][i + j + 1], 2));
            }
        }
    }

    void updatePose(float deltaTime) {
        pose[0][1] = 5;

        for (int i = 1; i < 631; i++) {
            for (int j = 0; j < 3; j++) {
                pose[i][j] = pose[i - 1][j] + pose[i][j] * deltaTime;
            }
        }
    }

    void displayPose(int n) {
        const char* code = (n == 1) ? "x" : (n == 2) ? "y" : (n == 3) ? "omega" : "pose";
        cout << code << ":\n{";
        for (int i = 0; i < 631; i++) {
            cout << pose[i][n - 1] << ", ";
        }
        cout << pose[630][n - 1] << "}\n";
    }
};

int main() {
    swerve simulation;
    for (float i = 0; i < 631; i++) {
        float t = i / 100;
        simulation.velocityCommand(48 * cos(t) * sin(t) * sin(t), 4 * sin(4 * t) + 6 * sin(3 * t) + 10 * sin(2 * t) - 13 * sin(t), 0);
    }
    simulation.updatePose(0.01);
    simulation.displayPose(3);

    StringReference *errorMessage = CreateStringReferenceLengthValue(0, L' '); 
    RGBABitmapImageReference *imageReference = CreateRGBABitmapImageReference();

    std::vector<double> xs{-2, -1, 0, 1, 2}; 
    std::vector<double> ys{2, -1, -2, -1, 2};

    std::vector<double> *pngdata = ConvertToPNG(imageReference->image); 
    WriteToFile(pngdata, "example1.png");
    DeleteImage(imageReference->image); 
    
    return 0;
}