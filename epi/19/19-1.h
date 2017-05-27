//
// Created by Li Zuwei on 10/23/16.
//

#ifndef EPI_19_1_H
#define EPI_19_1_H
#include <vector>
#include <array>
using namespace std;

typedef enum {WHITE, BLACK} Colour;

struct Coordinates {
    bool operator==(const Coordinates& that) {
        return x == that.x && y == that.y;
    }
    int x, y;
};

bool is_valid(vector<vector<Colour>>& maze, const Coordinates& curr) {
    //check if move is valid (within bounds) + is WHITE
    return curr.x < maze.size() && curr.y < maze[curr.x].size() &&
           curr.x >= 0 && curr.y >= 0 &&
           maze[curr.x][curr.y] == WHITE;
}

bool found_exit(vector<vector<Colour>>& maze, const Coordinates& curr, const Coordinates& e, vector<Coordinates>& path) {
    //base case
    if(curr == e) {
        //found exit, yay
        return true;
    }

    const array<array<int, 2>, 4> move_type = {{{0,1},{0,-1},{1,0},{-1,0}}};
    for (const array<int, 2>& m : move_type) {
        Coordinates next{curr.x + m[0], curr.y + m[1]};
        if(is_valid(maze, next)) {
            //try the move
            maze[next.x][next.y] = BLACK;
            path.emplace_back(next);
            if(found_exit(maze, next, e, path)) {
                return true;
            }
            path.pop_back(); // does not lead to exit, pop path out and try another move
        }
    }
    return false;
}

vector<Coordinates> search_maze(vector<vector<Colour>> maze, const Coordinates& s, const Coordinates& e) {
    vector<Coordinates> path;
    maze[s.x][s.y] = BLACK;
    path.emplace_back(s);
    if(!found_exit(maze, s, e, path)) {
        path.pop_back();
    }
    return path; //empty path refers to no path found to exit
}
#endif //EPI_19_1_H
