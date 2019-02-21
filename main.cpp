#include <iostream>
#include <map>
#include <math.h>
#include <vector>
#include <queue>

using namespace std;

int sumDigits(int num) {
  int sumDigits = 0;
  int currNum = abs(num);
  while (currNum > 0) {
    sumDigits += currNum % 10;
    currNum /= 10;
  }
  return sumDigits;
}

vector<pair<int, int> > getNeighbors(pair<int, int> coordinates) {
  vector<pair<int, int> > neighbors;
  pair<int, int> up (coordinates.first, coordinates.second + 1);
  pair<int, int> down (coordinates.first, coordinates.second - 1);
  pair<int, int> left (coordinates.first - 1, coordinates.second);
  pair<int, int> right (coordinates.first + 1, coordinates.second);

  neighbors.push_back(up);
  neighbors.push_back(down);
  neighbors.push_back(left);
  neighbors.push_back(right);

  return neighbors;
}

bool coordinatesAreValid(pair<int, int> coordinates, int maxAbsValSum) {
  return sumDigits(coordinates.first) + sumDigits(coordinates.second) <= maxAbsValSum;
}

int main(int argc, char *argv[]) {
  if (argc != 2) {
    cout << "Incorrect number of arguments. Please specify max absolute value sum.\n";
    cout << "Usage:\n";
    cout << "./monkey maxAbsoluteValueSum\n";
    return 0;
  }
  const int maxAbsValSum = atoi(argv[1]);
  int reachable = 0;
  pair<int, int> start (0, 0);
  map<pair<int,int>, bool> visited;
  visited[start] = true;
  queue<pair<int, int> > q;
  q.push(start);
  while (!q.empty()) {
    auto currCoordinates = q.front();
    q.pop();
    if (coordinatesAreValid(currCoordinates, maxAbsValSum)) {
      reachable++;
      auto neighbors = getNeighbors(currCoordinates);
      for (auto neighbor = neighbors.begin(); neighbor != neighbors.end(); neighbor++) {
        if (!visited[*neighbor]) {
          visited[*neighbor] = true;
          q.push(*neighbor);
        }
      }
    }
  }
  cout << "Can reach " << reachable << "\n";
}
