#include <fstream>
#include <iostream>
#include <sstream>
#include <cmath>
#include <string>
#include <vector>
#include <array>
using namespace std;

typedef array<double,7> Row;
typedef vector<Row> Block;

vector<Block> ReadBlocks(const string& filename)
{
    vector<Block> blocks;
    ifstream file(filename.c_str());
    if (!file) {
        cerr << "Could not open " << filename << endl;
        return blocks;
    }

    Block current;
    string line;
    while (getline(file, line))
    {
        istringstream iss(line);
        Row r;
        bool ok = true;
        for (int k = 0; k < 7; k++) {
            if (!(iss >> r[k])) { ok = false; break; }
        }

        if (ok) {
            current.push_back(r);
        } else if (!current.empty()) {
            // header or "---" line: closes the current block
            blocks.push_back(current);
            current.clear();
        }
    }
    if (!current.empty()) blocks.push_back(current);   // last block without trailing "---"

    return blocks;
}

void DiffFiles()
{
    vector<Block> A = ReadBlocks("./Det1.txt");
    vector<Block> B = ReadBlocks("./Det1A.txt");

    if (A.size() != B.size())
        cerr << "Warning: different number of blocks: "
             << A.size() << " vs " << B.size() << endl;

    const int cols[4] = {0, 2, 4, 6};   // phi, theta, rho, effective thickness
    double globalMax[4] = {0, 0, 0, 0};

    size_t nBlocks = min(A.size(), B.size());
    for (size_t ib = 0; ib < nBlocks; ib++)
    {
        if (A[ib].size() != B[ib].size())
            cerr << "Warning: block " << ib + 1 << " has different numbers of rows: "
                 << A[ib].size() << " vs " << B[ib].size() << endl;

        size_t nRows = min(A[ib].size(), B[ib].size());
        double maxDiff[4] = {0, 0, 0, 0};

        for (size_t ir = 0; ir < nRows; ir++)
            for (int n = 0; n < 4; n++) {
                double d = fabs(A[ib][ir][cols[n]] - B[ib][ir][cols[n]]);
                if (d > maxDiff[n]) maxDiff[n] = d;
            }

        cout << "Block " << ib + 1 << " max diffs (phi, theta, rho, thickness): "
             << maxDiff[0] << " " << maxDiff[1] << " "
             << maxDiff[2] << " " << maxDiff[3] << endl;

        for (int n = 0; n < 4; n++)
            if (maxDiff[n] > globalMax[n]) globalMax[n] = maxDiff[n];
    }

    cout << "Overall max diffs: "
         << globalMax[0] << " " << globalMax[1] << " "
         << globalMax[2] << " " << globalMax[3] << endl;
}
