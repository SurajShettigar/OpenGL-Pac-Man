#include "level.h"
#include "constants.h"
#include "../engine/vector3.h"

void Level::AddWall(int xIndex, int yIndex)
{
    Block block;
    block.type = BlockType::Wall;
    block.color = Constants::COLOR_BLUE;
    block.xIndex = xIndex;
    block.yIndex = yIndex;
    block.Instantiate(projection,
                      view,
                      Vector3((static_cast<float>(xIndex) / 2.0f),
                              0.0f,
                              -(static_cast<float>(yIndex) / 2.0f)));
    wallBlocks.push_back(block);
}

void Level::AddPoint(int xIndex, int yIndex)
{
    Block block;
    block.type = BlockType::Point;
    block.color = Constants::COLOR_WHITE;
    block.xIndex = xIndex;
    block.yIndex = yIndex;
    block.Instantiate(projection,
                      view,
                      Vector3((static_cast<float>(xIndex) / 2.0f),
                              0.0f,
                              -(static_cast<float>(yIndex) / 2.0f)),
                              Vector3::zero,
                              Vector3::one * 0.25f);
    pointBlocks.push_back(block);
}

void Level::AnimatePoints(float speed)
{
    for(Block p : pointBlocks)
        p.Rotate(Vector3(0.0f, speed, 0.0f));
}

void Level::RenderLevel(Shader &shader)
{
    for (Block b : wallBlocks)
    {
        b.UpdateView(view);
        b.Render(shader);
    }
    for(Block p : pointBlocks)
    {
        p.UpdateView(view);
        p.Render(shader);
    }
}

void Level::Clean()
{
    for (Block b : wallBlocks)
    {
        b.Destroy();
    }
    for(Block p : pointBlocks)
    {
        p.Destroy();
    }
}