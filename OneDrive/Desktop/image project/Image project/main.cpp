#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std;

class Image {
private:
    int width, height, maxVal, channels;
    vector<vector<vector<int>>> data; // height x width x channels

public:
    Image() {
        width = 0;
        height = 0;
        maxVal = 255;
        channels = 3;
    }

    Image(int w, int h, int ch = 3) {
        width = w;
        height = h;
        maxVal = 255;
        channels = ch;
        data.resize(height, vector<vector<int>>(width, vector<int>(channels, 0)));
    }

    int getWidth() const { return width; }
    int getHeight() const { return height; }
    int getChannels() const { return channels; }

    int& operator()(int y, int x, int c) { return data[y][x][c]; }
    const int& operator()(int y, int x, int c) const { return data[y][x][c]; }

    bool loadPPM(const string& filename) {
        ifstream file(filename);
        if (!file.is_open()) return false;

        string format;
        file >> format;
        if (format != "P3") return false;

        file >> width >> height >> maxVal;
        channels = 3;
        data.resize(height, vector<vector<int>>(width, vector<int>(channels, 0)));

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                for (int c = 0; c < channels; c++) {
                    file >> data[y][x][c];
                }
            }
        }
        file.close();
        return true;
    }

    bool savePPM(const string& filename) const {
        ofstream file(filename);
        if (!file.is_open()) return false;

        file << "P3\n" << width << " " << height << "\n" << maxVal << "\n";

        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                for (int c = 0; c < channels; c++) {
                    file << data[y][x][c] << " ";
                }
            }
            file << "\n";
        }
        file.close();
        return true;
    }
};

// rotate 90 degrees clockwise
Image rotate90Clockwise(const Image& img) {
    int w = img.getWidth();
    int h = img.getHeight();
    int ch = img.getChannels();

    Image rotated(h, w, ch);

    for (int y = 0; y < h; y++) {
        for (int x = 0; x < w; x++) {
            for (int c = 0; c < ch; c++) {
                rotated(x, w - 1 - y, c) = img(y, x, c);
            }
        }
    }

    return rotated;
}

int main() {
    Image input;
    if (!input.loadPPM("input.ppm")) {
        cerr << "Error loading input.ppm" << endl;
        return 1;
    }

    Image output = rotate90Clockwise(input);

    if (!output.savePPM("output.ppm")) {
        cerr << "Error saving output.ppm" << endl;
        return 1;
    }

    cout << "Rotation done. Check output.ppm" << endl;
    return 0;
}
