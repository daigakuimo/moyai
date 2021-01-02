#include <fstream>
#include <iostream>
#include <time.h>
#include "sample_common.h"

int forLoopNum;
int memorySize;
int networkSize;
int *aArray;
int *bArray;
int *cArray;
int *dArray;
int *eArray;

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
        std::cout << "#" << str << std::endl;
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

    aArray = new int[memorySize];
    bArray = new int[memorySize];
    cArray = new int[memorySize];
    dArray = new int[memorySize];
    eArray = new int[memorySize];

    print("cpu:%d, memory:%d, network:%d", forLoopNum, memorySize, networkSize);
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
