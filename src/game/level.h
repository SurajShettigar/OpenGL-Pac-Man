#ifndef LEVEL_H
#define LEVEL_H

#include<vector>
#include "block.h"

using std::vector;

class Level
{
private:
    vector<Block> wallBlocks;
    vector<Block> pointBlocks;
public:
    Matrix4 projection;
    Matrix4 view;
    void AddWall(int xIndex, int yIndex);
    void AddPoint(int xIndex, int yIndex);
    void AnimatePoints(float speed);
    void RenderLevel(Shader &shader);
    void Clean();
};

#endif