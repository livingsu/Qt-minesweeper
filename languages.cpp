#include <stdlib.h>
#include "languages.h"

char* en[] = {"About",
              "Simulate the minesweeper game that comes with the Windows.\nDeveloper: livingsu.\nqq:1753843140",
              "Time is up! The game is over!",
              "Game over!",
              "Congratulations on your success!",
              "Mines"};
char* cn[] = {"?? TODO",
              "模拟windows自带游戏的扫雷.\n开发者:livingsu.\nqq:1753843140",
              "时间到!游戏结束！",
              "游戏结束！",
              "恭喜你成功了！",
              "雷数"};

char** langLocal[2] = {en, cn};
char*** lang = langLocal;


// 扫雷艇 Minesweeper
