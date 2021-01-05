#include <fstream>
#include <iostream>
#include <time.h>
#include "sample_common.h"

int forLoopNum;
int memorySize;
int networkSize;
int aArray[1000000] = {2147483647};
int bArray[1000000] = {2147483647};
int cArray[1000000] = {2147483647};
int dArray[1000000] = {2147483647};
int eArray[1000000] = {2147483647};

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

    std::cout << sizeof(aArray) << std::endl;
}
void minimumUpdate()
{
    for (int i = 0; i < forLoopNum; i++)
    {
    }

    int *temp = new int[100];
    delete[] temp;
}

SAMPLE_COMMON_MAIN_FUNCTION(minimumInit, minimumUpdate, "minimum");
