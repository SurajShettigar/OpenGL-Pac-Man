#include "levelgenerator.h"
#include "constants.h"
#include "../engine/log.h"

#include <fstream>
#include <string>

using std::ifstream;
using std::getline;
using std::string;

Level LevelGenerator::Instantiate(Matrix4 projection, Matrix4 view)
{

    ifstream levelFile(Constants::FILE_LEVEL);

    if (!levelFile.is_open()) {
        LOG(LogLevel::Error) << "Failed to open Level file: " << Constants::FILE_LEVEL;
        return level;
    }

    level.projection = projection;
    level.view = view;

    string line;
    int y = 0;
    LOG(LogLevel::Debug) << "Level File: ";
    while(getline(levelFile, line))
    {
        LOG(LogLevel::Debug) << line;
        for(int x = 0; x < line.length(); x++)
        {
            if(line.at(x) == '|')
                level.AddWall(x, y);
            else if(line.at(x) != '\n')
                level.AddPoint(x, y);
        }
        ++y;
    }
    

    levelFile.close();

    return level;
}