
#include <cstdlib>
#include <ctime>

namespace Amber
{
    class Dice
    {
    public:
        static void initializeDice()
        {
            srand(static_cast<unsigned int>(time(nullptr)));
        }

        static int rollDice(int num, int type)
        {
            int ret = 0;
            for (int i = 0; i < num; i++) ret += (rand() % type) + 1;
            return ret;
        }

        // useing a 3d6 system we have the following :

        static bool criticalSucess(int effectiveSkill, int diceRoll)
        {
            bool ret = false;
            int crit = 4;
            if (effectiveSkill > 20) effectiveSkill = 20;
            if (effectiveSkill > 14) crit += (effectiveSkill - 14);
            if (diceRoll <= crit) ret = true;
            return ret;
        }

        static bool criticalFailure(int effectiveSkill, int diceRoll)
        {
            bool ret = false;
            if (effectiveSkill > 20) effectiveSkill = 20;
            if (effectiveSkill < 3) effectiveSkill = 3;
            if (diceRoll == 18) ret = true;
            else if ((diceRoll == 17) && (effectiveSkill < 16)) ret = true;
            else if (diceRoll >= effectiveSkill + 10) ret = true;
            return ret;
        }
    };
}
