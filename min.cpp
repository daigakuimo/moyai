#include <fstream>
#include <iostream>
#include <time.h>
#include "sample_common.h"

int forLoopNum;
int memorySize;
int networkSize;

bool flag = false;

void minimumInit()
{
    Prop2D *p = new Prop2D(g_base_deck, ATLAS_MYSHIP, Vec2(48, 48), Vec2(0, 0));
    g_main_layer->insertProp(p);

    std::ifstream ifs("size.txt");
    std::string str;

    if (ifs.fail())
    {
        std::cerr << "Failed to open file." << std::endl;
    }
    int count = 0;
    while (getline(ifs, str))
    {
        int i = std::stoi(str);
        if (count == 0)
        {
            forLoopNum = i;
        }
        else if (count == 1)
        {
            memorySize = i;
        }
        else
        {
            networkSize = i;
        }
        count++;
    }
}
void minimumUpdate()
{
    for (int i = 0; i < forLoopNum; i++)
    {
    }

    if (!flag)
    {
        int *temp = new int[memorySize];
        std::cout << sizeof(temp) << std::endl;
        flag = true;
    }
}

SAMPLE_COMMON_MAIN_FUNCTION(minimumInit, minimumUpdate, "minimum");
