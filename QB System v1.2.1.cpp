#include <iostream>
#include <conio.h> //包含 getch 函数
#include <Windows.h>

using namespace std;

struct tiku //题库的结构体
{
    string timu; //题目
    string biaoda; //标答
};

char a3 = 0; //判断是否退出系统

bool to1 = false;
bool to2 = false;
bool to3 = false;
bool to4 = false;
bool to5 = false;
bool to6 = false;
int check;

tiku ti[100010]; //题目的数组
int n = 0; //随机题库的题目数量
int m = 0; //化学题库中的题目数量
int p = 0; //选择题库中的题目数量
int z[30]; //用于记录化学模式中的题号，防止重复

string ent[] = { "退出时不进行询问", "退出时进行询问" }; //设置选项的内容
int entk = 1; //用来记录设置选项的状态
bool Enter = false;

void ShowCursor(bool visible) //显示或隐藏光标
{
    CONSOLE_CURSOR_INFO cursor_info = { 20, visible };
    //CONSOLE_CURSOR_INFO结构体包含控制台光标信息，成员分别表示光标百分比厚度和是否可见
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
    //SetConsoleCursorInfo设定控制台窗口的光标大小和是否可见
}

void SetColor(int ForgC, int BackC)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, (WORD)((BackC << 4) | ForgC));
}

void ColorChange(string a) //设置选项字体的颜色
{
    // 保存默认颜色
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(hConsole, &csbi);
    int defForgC = csbi.wAttributes & 0x0F;
    int defBackC = (csbi.wAttributes & 0xF0) >> 4;

    // 设置为白底黑字
    SetColor(0, 15);

    cout << a;

    // 恢复默认颜色
    SetColor(defForgC, defBackC);
    cout << " ";
}

void gotoxy(int x, int y) //控制光标的跳转
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(handle, pos);
}

void space()
{
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
    cout << "                                                                                                   " << endl;
}

int judgment(string a, string b) //a为输入的答案，b为标答
{
    int num = 0; //num用来计算输入内容和标答一致的文字数量
    int sum = b.length(); //sum变量为标答的长度

    for (int i = 1; i <= a.length(); i++) //逐字判断
    {
        const char c = a[i - 1];
        for (int j = 1; j <= b.length(); j++)
        {
            const char d = b[j - 1];
            if (c == d)
            {
                num++;
                break;
            }
        }
    }
    double num1 = num / 1.0, sum1 = sum / 1.0; //将整型变量转换为浮点型变量

    double n = (num1 / sum1) / 1.0; //计算重合率n
    if (n >= 0.5) //判断作答正误
    {
        return 1; //正确
    }
    else
    {
        return 2; //错误
    }
}

void n_num() //计算随机题库的题目数量n
{
    for (int i = 1; i <= 100000; i++)
    {
        if (ti[i].timu != "")
        {
            n++;
        }
        else
        {
            break;
        }
    }
}

void m_num() //计算化学题库的题目数量m
{
    for (int i = 5001; i <= 100000; i++)
    {
        if (ti[i].timu != "")
        {
            m++;
        }
        else
        {
            break;
        }
    }
}


void p_num() //计算选择题库的题目数量p
{
    for (int i = 10001; i <= 100000; i++)
    {
        if (ti[i].timu != "")
        {
            p++;
        }
        else
        {
            break;
        }
    }
}

/*-----------------------------题库部分-------------------------------------------------*/

void tik1() //随机题库
{
    ti[1].timu = "太阳系中哪颗行星离太阳最近?";
    ti[1].biaoda = "水星";

    ti[2].timu = "光的传播速度在真空中是多少?";
    ti[2].biaoda = "光在真空中的传播速度是299,792,458米/秒";

    ti[3].timu = "人类最早使用的金属是什么?";
    ti[3].biaoda = "铜";

    ti[4].timu = "中国历史上著名的四大发明是什么?";
    ti[4].biaoda = "造纸术、印刷术、火药、指南针";

    ti[5].timu = "在生物学中，DNA的全称是什么?";
    ti[5].biaoda = "脱氧核糖核酸";

    ti[6].timu = "地球上有多少块大陆?";
    ti[6].biaoda = "地球上有7块大陆";

    ti[7].timu = "世界上最长的河流是哪一条?";
    ti[7].biaoda = "尼罗河";

    ti[8].timu = "人类首次登上月球是在哪一年?";
    ti[8].biaoda = "1969年";

    ti[9].timu = "C语言是在哪一年被发明的?";
    ti[9].biaoda = "1972年";

    ti[10].timu = "一个圆的周长公式是什么?";
    ti[10].biaoda = "C = 2πr，其中C是周长，r是半径，π是圆周率";

    ti[11].timu = "世界上最深的海洋是哪一个?";
    ti[11].biaoda = "太平洋";

    ti[12].timu = "大熊猫主要以什么为食?";
    ti[12].biaoda = "竹子";

    ti[13].timu = "人体的哪个器官负责呼吸?";
    ti[13].biaoda = "肺";

    ti[14].timu = "联合国是在哪一年成立的?";
    ti[14].biaoda = "1945年";

    ti[15].timu = "世界上最快的陆生动物是什么?";
    ti[15].biaoda = "猎豹";

    ti[16].timu = "元素周期表中的第一个元素是什么?";
    ti[16].biaoda = "氢";

    ti[17].timu = "《蒙娜丽莎》的作者是谁?";
    ti[17].biaoda = "达·芬奇";

    ti[18].timu = "一个标准足球比赛中每个队有多少名球员?";
    ti[18].biaoda = "11名";

    ti[19].timu = "光年是什么的单位?";
    ti[19].biaoda = "长度单位，用于测量天体间的距离";

    ti[20].timu = "世界上最小的鸟是什么?";
    ti[20].biaoda = "蜂鸟";

    ti[21].timu = "请简述量子力学中的测不准原理。";
    ti[21].biaoda = "测不准原理是由海森堡提出，它表明在微观尺度上，粒子的位置和动量无法同时被精确测量";

    ti[22].timu = "请解释广义相对论中的时空弯曲概念。";
    ti[22].biaoda = "时空弯曲是爱因斯坦广义相对论的核心概念，它认为物质和能量能够影响时空的几何结构，导致时空弯曲，进而影响物体的运动轨迹";

    ti[23].timu = "什么是遗传算法？请简述其基本原理。";
    ti[23].biaoda = "遗传算法是一种启发式搜索算法，受生物进化理论的启发，通过模拟自然选择和遗传机制来优化问题求解,基本原理包括选择、交叉和变异操作，以生成新的解，并通过适应度函数评估解的质量";

    ti[24].timu = "请简述区块链技术的基本原理和特点。";
    ti[24].biaoda = "区块链技术是一种去中心化的分布式数据库技术，其基本原理是通过网络中的多个节点共同维护一个不断增长的交易记录列表,特点是数据一旦写入就难以篡改，具有高安全性、透明度和不可篡改性";

    ti[25].timu = "什么是人工智能中的深度学习？请简述其基本原理。";
    ti[25].biaoda = "深度学习是一种机器学习技术，通过构建多层的神经网络模型来学习数据的深层表示,基本原理是通过大量的训练数据和反向传播算法，自动学习特征表示和模型参数，以实现对复杂数据的建模和预测";

    ti[26].timu = "MC里有BUG吗";
    ti[26].biaoda = "没有。";

    ti[27].timu = "Minecraft中白天的时间是多久？";
    ti[27].biaoda = "15分钟。";

    ti[28].timu = "Minecraft中最坚硬的方块是什么？";
    ti[28].biaoda = "基岩";

    ti[29].timu = "在Minecraft中，如何快速穿越地图？";
    ti[29].biaoda = "使用末影珍珠。";

    ti[30].timu = "Minecraft中哪个生物会主动攻击玩家？";
    ti[30].biaoda = "僵尸。";

    ti[31].timu = "在Minecraft中，如何进入下界？";
    ti[31].biaoda = "制作并激活下界传送门。";

    ti[32].timu = "Minecraft中哪个方块可以用来制作附魔台？";
    ti[32].biaoda = "书、钻石和黑曜石。";

    ti[33].timu = "Minecraft中哪种生物会掉落煤炭？";
    ti[33].biaoda = "僵尸猪人。";

    ti[34].timu = "在Minecraft中，如何获得经验值？";
    ti[34].biaoda = "杀死怪物、挖掘矿物或交易。";

    ti[35].timu = "Minecraft中的末影龙有多少生命值？";
    ti[35].biaoda = "200点生命值。";

    ti[36].timu = "在Minecraft中，哪个物品可以用来修复工具？";
    ti[36].biaoda = "经验修补。";

    ti[37].timu = "Minecraft中哪个方块可以用来制作TNT？";
    ti[37].biaoda = "沙子和火药。";

    ti[38].timu = "在Minecraft中，如何获得青金石？";
    ti[38].biaoda = "挖掘青金石矿石。";

    ti[39].timu = "Minecraft中哪个生物是游戏中的主角？";
    ti[39].biaoda = "史蒂夫。";

    ti[40].timu = "在Minecraft中，如何获得金块？";
    ti[40].biaoda = "将9个金锭放入合成栏。";

    ti[41].timu = "Minecraft中的狼可以被驯服吗？";
    ti[41].biaoda = "可以，使用骨头。";

    ti[42].timu = "在Minecraft中，哪个方块可以用来制作熔炉？";
    ti[42].biaoda = "圆石。";

    ti[43].timu = "Minecraft中哪个生物会掉落音乐唱片？";
    ti[43].biaoda = "骷髅。";

    ti[44].timu = "在Minecraft中，如何获得附魔书？";
    ti[44].biaoda = "在附魔台使用书和青金石。";

    ti[45].timu = "Minecraft中的末影人可以被水淹没吗？";
    ti[45].biaoda = "不可以。";

    ti[46].timu = "在Minecraft中，如何获得绿宝石？";
    ti[46].biaoda = "挖掘绿宝石矿石。";

    ti[47].timu = "Minecraft中哪个生物会掉落铁锭？";
    ti[47].biaoda = "铁傀儡。";

    ti[48].timu = "在Minecraft中，如何进入末地？";
    ti[48].biaoda = "通过末地传送门。";

    ti[49].timu = "Minecraft中的仙人掌可以在哪种方块上生长？";
    ti[49].biaoda = "沙子或红沙。";

    ti[50].timu = "在Minecraft中，如何获得烈焰棒？";
    ti[50].biaoda = "击败烈焰人。";

    ti[51].timu = "Minecraft中哪个方块可以用来制作活塞？";
    ti[51].biaoda = "粘土、圆石和铁锭。";

    ti[52].timu = "在Minecraft中，如何获得龙息？";
    ti[52].biaoda = "用玻璃瓶收集末影龙吐息。";

    ti[53].timu = "Minecraft中的兔子有几种类型？";
    ti[53].biaoda = "六种。";

    ti[54].timu = "在Minecraft中，如何获得兔子皮？";
    ti[54].biaoda = "杀死兔子。";

    ti[55].timu = "Minecraft中的末影珍珠可以用来做什么？";
    ti[55].biaoda = "制作末影之眼或末影箱。";

    ti[56].timu = "在Minecraft中，如何获得甜菜根？";
    ti[56].biaoda = "收获甜菜作物。";

    ti[57].timu = "Minecraft中哪个生物会掉落蜘蛛眼？";
    ti[57].biaoda = "蜘蛛。";

    ti[58].timu = "在Minecraft中，如何获得兔子脚？";
    ti[58].biaoda = "杀死兔子。";

    ti[59].timu = "Minecraft中的村民可以被僵尸感染吗？";
    ti[59].biaoda = "可以，变成僵尸村民。";

    ti[60].timu = "在Minecraft中，如何获得南瓜？";
    ti[60].biaoda = "收获南瓜作物。";


}

void tik2() //化学题库
{
    ti[5001].timu = "请简述原子和离子的主要区别。";
    ti[5001].biaoda = "原子是电中性的，而离子是带电的原子或原子团";

    ti[5002].timu = "什么是摩尔？";
    ti[5002].biaoda = "摩尔是物质的量的单位，表示含有Avogadro常数个粒子的物质的数量";

    ti[5003].timu = "浓硫酸是否具有氧化性";
    ti[5003].biaoda = "是";

    ti[5004].timu = "什么是酸碱中和反应？";
    ti[5004].biaoda = "酸碱中和反应是酸和碱反应生成盐和水的化学反应";

    ti[5005].timu = "请简述氧化还原反应的定义。";
    ti[5005].biaoda = "氧化还原反应是指物质中的原子氧化态发生变化的化学反应";

    ti[5006].timu = "什么是催化剂？";
    ti[5006].biaoda = "催化剂是能够加速化学反应速率而自身不被消耗的物质";

    ti[5007].timu = "请写出氧气和氢气反应的的产物";
    ti[5007].biaoda = "水";

    ti[5008].timu = "什么是元素周期表？";
    ti[5008].biaoda = "元素周期表是按照原子序数排列所有已知元素的一种表格形式";

    ti[5009].timu = "请简述电解质和非电解质的主要区别。";
    ti[5009].biaoda = "电解质在水溶液中能够导电，而非电解质在水溶液中不能导电";

    ti[5010].timu = "什么是pH值？";
    ti[5010].biaoda = "pH值是衡量溶液酸碱程度的数值，表示溶液中氢离子浓度的负对数";

    ti[5011].timu = "请简述饱和溶液和不饱和溶液的区别。";
    ti[5011].biaoda = "在一定温度下，溶质已经溶解到最大限度，不能再溶解更多的溶质；而不饱和溶液则可以继续溶解更多的溶质";

    ti[5012].timu = "什么是同位素？";
    ti[5012].biaoda = "具有相同原子序数但质量数不同的元素，因此它们的原子核中的中子数不同";

    ti[5013].timu = "请写出氧化铜的化学式。";
    ti[5013].biaoda = "CuO";

    ti[5014].timu = "什么是化学反应的平衡常数？";
    ti[5014].biaoda = "在平衡状态下，反应物和生成物浓度的比值的乘积，与反应物初始浓度无关";

    ti[5015].timu = "请简述离子键和共价键的区别。";
    ti[5015].biaoda = "离子键是通过正负电荷吸引形成的键，通常发生在金属和非金属之间；而共价键是通过电子对共享形成的键，通常发生在非金属原子之间";

    ti[5016].timu = "什么是活化能？";
    ti[5016].biaoda = "活化学反应开始前必须克服的能量障碍";

    ti[5017].timu = "请写出氢氧化钠的化学式。";
    ti[5017].biaoda = "NaOH";

    ti[5018].timu = "什么是放射性衰变？";
    ti[5018].biaoda = "不稳定原子核自发地转变为更稳定状态的过程，伴随着粒子的发射";

    ti[5019].timu = "请简述酸的定义。";
    ti[5019].biaoda = "酸是能够提供氢离子的化合物";

    ti[5020].timu = "什么是分子量？";
    ti[5020].biaoda = "分子中所有原子相对原子质量的总和";

    ti[5021].timu = "请写出水的相对分子质量";
    ti[5021].biaoda = "18";

    ti[5022].timu = "什么是沉淀反应？";
    ti[5022].biaoda = "两种溶液混合后，生成不溶于溶液的沉淀物的化学反应";

    ti[5023].timu = "化学反应中的能量变化是如何体现的？";
    ti[5023].biaoda = "化学反应中的能量变化主要通过热效应体现，即反应放热或吸热";

    ti[5024].timu = "什么是氧化剂？";
    ti[5024].biaoda = "在化学反应中能够接受电子，使其他物质氧化的物质";

    ti[5025].timu = "请写出燃烧反应的通式。";
    ti[5025].biaoda = "燃烧反应的通式通常表示为：燃料 + 氧气 → 二氧化碳 + 水 + 能量";

    ti[5026].timu = "什么是化学键？";
    ti[5026].biaoda = "化学键是连接原子或离子的力，它决定了分子的结构和性质";

    ti[5027].timu = "请简述有机化学和无机化学的区别。";
    ti[5027].biaoda = "有机化学研究含有碳的化合物，而无机化学研究不含碳的化合物，以及一些简单的碳化合物";

    ti[5028].timu = "什么是晶体？";
    ti[5028].biaoda = "晶体是具有规则排列的粒子（如原子、离子或分子）形成的固体结构";

    ti[5029].timu = "仲钨酸铵经煅烧可得黄钨，同时也会生成蓝钨和紫钨的原因";
    ti[5029].biaoda = "黄钨被还原";

    ti[5030].timu = "什么是化学平衡？";
    ti[5030].biaoda = "化学平衡是指在封闭系统中，正反应速率相等，反应物和生成物的浓度不再发生变化的状态";

    ti[5031].timu = "请简述酸碱指示剂的原理。";
    ti[5031].biaoda = "酸碱指示剂是根据其分子结构在不同pH值下颜色变化的性质来指示溶液酸碱性的物质";

    ti[5032].timu = "什么是同素异形体？";
    ti[5032].biaoda = "同素异形体是指由相同元素组成，但结构不同，因而性质不同的化合物";

    ti[5033].timu = "氮气可以与氧气反应吗";
    ti[5033].biaoda = "可以";

    ti[5034].timu = "什么是极性分子和非极性分子？";
    ti[5034].biaoda = "极性分子是指分子中正负电荷中心不重合，存在部分电荷分离的分子；非极性分子是指分子中正负电荷中心重合，电荷分布均匀的分子";

    ti[5035].timu = "请简述配位化合物的定义。";
    ti[5035].biaoda = "配位化合物是由一个或多个中心金属离子和围绕其的配体通过配位键结合形成的化合物";

    ti[5036].timu = "什么是分散系？";
    ti[5036].biaoda = "分散系是由两种或多种物质组成的混合体系，其中一种物质以微粒形式分散在另一种物质中";

    ti[5037].timu = "请写出氢气的化学式。";
    ti[5037].biaoda = "H2";

    ti[5038].timu = "什么是活化分析？";
    ti[5038].biaoda = "活化分析是一种利用放射性同位素对物质进行化学成分分析的方法";

    ti[5039].timu = "请简述金属和非金属的主要区别。";
    ti[5039].biaoda = "金属通常具有良好的导电性和热导性，而非金属通常不良导电和不具有良好的热导性。此外，金属在固态时具有金属光泽，而非金属则不具有";

    ti[5040].timu = "什么是分子间力？";
    ti[5040].biaoda = "分子间力是分子之间的相互作用力，包括范德华力、氢键等，它们决定了物质的物理性质";

    ti[5041].timu = "请写出氯化钠的化学式。";
    ti[5041].biaoda = "NaCl";

    ti[5042].timu = "什么是多相催化？";
    ti[5042].biaoda = "多相催化是指催化剂和反应物处于不同相的催化过程";

    ti[5043].timu = "请简述光谱分析的原理。";
    ti[5043].biaoda = "光谱分析是利用物质对不同波长光的吸收或发射特性来分析其组成和性质的方法";
}

void tik3() //选择题库
{
    ti[10001].timu = "以下哪位科学家提出了相对论？\n1. 牛顿\n2. 爱因斯坦\n3. 伽利略\n4. 波尔";
    ti[10001].biaoda = "2";

    ti[10002].timu = "中国的首都是哪个城市？\n1. 上海\n2. 北京\n3. 广州\n4. 深圳";
    ti[10002].biaoda = "2";

    ti[10003].timu = "以下哪种动物是哺乳动物？\n1. 鲨鱼\n2. 青蛙\n3. 老虎\n4. 鲸鱼";
    ti[10003].biaoda = "3";

    ti[10004].timu = "下列哪个国家不在亚洲？\n1. 中国\n2. 印度\n3. 巴西\n4. 日本";
    ti[10004].biaoda = "3";

    ti[10005].timu = "下列哪个行星离太阳最近？\n1. 金星\n2. 地球\n3. 水星\n4. 火星";
    ti[10005].biaoda = "3";

    ti[10006].timu = "下列哪个不是莎士比亚的作品？\n1. 《哈姆雷特》\n2. 《罗密欧与朱丽叶》\n3. 《悲惨世界》\n4. 《麦克白》";
    ti[10006].biaoda = "3";

    ti[10007].timu = "下列哪种气体是空气的主要成分？\n1. 氧气\n2. 氮气\n3. 二氧化碳\n4. 氢气";
    ti[10007].biaoda = "2";

    ti[10008].timu = "下列哪个不是中国的传统节日？\n1. 春节\n2. 中秋节\n3. 愚人节\n4. 端午节";
    ti[10008].biaoda = "3";

    ti[10009].timu = "下列哪个城市被称为“世界水都”？\n1. 巴黎\n2. 威尼斯\n3. 伦敦\n4. 罗马";
    ti[10009].biaoda = "2";

    ti[10010].timu = "下列哪种材料是导电的？\n1. 木头\n2. 塑料\n3. 铜\n4. 玻璃";
    ti[10010].biaoda = "3";

    ti[10011].timu = "下列哪个是中国的四大发明之一？\n1. 指南针\n2. 火药\n3. 印刷术\n4. 所有以上";
    ti[10011].biaoda = "4";

    ti[10012].timu = "下列哪个不是太阳系中的行星？\n1. 土星\n2. 天王星\n3. 海王星\n4. 以上都是";
    ti[10012].biaoda = "4";

    ti[10013].timu = "下列哪个不是中国的直辖市？\n1. 北京\n2. 上海\n3. 天津\n4. 成都";
    ti[10013].biaoda = "4";

    ti[10014].timu = "下列哪个是最小的哺乳动物？\n1. 大象\n2. 老鼠\n3. 蚊子\n4. 蝙蝠";
    ti[10014].biaoda = "2";

    ti[10015].timu = "下列哪个不是中国的少数民族？\n1. 汉族\n2. 壮族\n3. 满族\n4. 回族";
    ti[10015].biaoda = "1";

    ti[10016].timu = "下列哪个是中国的国宝动物？\n1. 金丝猴\n2. 大熊猫\n3. 丹顶鹤\n4. 朱鹮";
    ti[10016].biaoda = "2";

    ti[10017].timu = "下列哪个不是中国的三大石窟之一？\n1. 莫高窟\n2. 云冈石窟\n3. 龙门石窟\n4. 乐山大佛";
    ti[10017].biaoda = "4";

    ti[10018].timu = "下列哪个不是中国的五岳之一？\n1. 泰山\n2. 华山\n3. 嵩山\n4. 天山";
    ti[10018].biaoda = "4";

    ti[10019].timu = "下列哪个是中国的四大名著之一？\n1. 《红楼梦》\n2. 《西游记》\n3. 《三国演义》\n4. 以上都是";
    ti[10019].biaoda = "4";

    ti[10020].timu = "下列哪个是中国古代的“天下第一行书”？\n1. 王羲之的《兰亭序》\n2. 颜真卿的《祭侄文稿》\n3. 柳公权的《柳体书法》\n4. 欧阳询的《九成宫醴泉铭》";
    ti[10020].biaoda = "1";

    ti[10021].timu = "下列哪个是中国古代的“药王”？\n1. 孙思邈\n2. 华佗\n3. 张仲景\n4. 扁鹊";
    ti[10021].biaoda = "1";

    ti[10022].timu = "下列哪个是中国古代的“诗仙”？\n1. 杜甫\n2. 白居易\n3. 李白\n4. 王维";
    ti[10022].biaoda = "3";

    ti[10023].timu = "下列哪个是中国古代的“书圣”？\n1. 王羲之\n2. 王献之\n3. 颜真卿\n4. 柳公权";
    ti[10023].biaoda = "1";

    ti[10024].timu = "下列哪个是中国古代的“画圣”？\n1. 吴道子\n2. 张择端\n3. 赵孟頫\n4. 郑板桥";
    ti[10024].biaoda = "1";

    ti[10025].timu = "下列哪个是中国的“国剧”？\n1. 京剧\n2. 越剧\n3. 黄梅戏\n4. 秦腔";
    ti[10025].biaoda = "1";

    ti[10026].timu = "下列哪个是中国的“国饮”？\n1. 茶\n2. 酒\n3. 咖啡\n4. 可可";
    ti[10026].biaoda = "1";

    ti[10027].timu = "下列哪个是中国的“国花”？\n1. 牡丹\n2. 菊花\n3. 梅花\n4. 兰花";
    ti[10027].biaoda = "1";

    ti[10028].timu = "下列哪个是中国的“国鸟”？\n1. 丹顶鹤\n2. 朱鹮\n3. 金丝雀\n4. 红腹锦鸡";
    ti[10028].biaoda = "1";

    ti[10029].timu = "下列哪个是中国的“国石”？\n1. 玉\n2. 石榴石\n3. 水晶\n4. 玛瑙";
    ti[10029].biaoda = "1";

    ti[10030].timu = "下列哪个是中国的“国树”？\n1. 松树\n2. 桂树\n3. 梧桐树\n4. 橡树";
    ti[10030].biaoda = "1";

    ti[10031].timu = "下列哪个是中国的“国宝”？\n1. 大熊猫\n2. 金丝猴\n3. 朱鹮\n4. 扬子鳄";
    ti[10031].biaoda = "1";

    ti[10032].timu = "下列哪个是中国的“国兽”？\n1. 大熊猫\n2. 金丝猴\n3. 朱鹮\n4. 扬子鳄";
    ti[10032].biaoda = "1";

    ti[10033].timu = "下列哪个是中国的“国乐”？\n1. 古筝\n2. 二胡\n3. 琵琶\n4. 笙";
    ti[10033].biaoda = "1";

    ti[10033].timu = "在计算机科学中，以下哪个概念与二进制数有关？\n1. ASCII码\n2. 十六进制\n3. 字节\n4. 八进制";
    ti[10033].biaoda = "3";

    ti[10034].timu = "在医学领域，以下哪种疾病通常通过疫苗接种来预防？\n1. 艾滋病\n2. 感冒\n3. 乙肝\n4. 肺结核";
    ti[10034].biaoda = "3";

    ti[10035].timu = "在法律领域，以下哪个机构负责中国的司法审判？\n1. 全国人民代表大会\n2. 最高人民法院\n3. 最高人民检察院\n4. 公安部";
    ti[10035].biaoda = "2";

    ti[10036].timu = "在物理学中，以下哪个单位用于测量力？\n1. 牛顿\n2. 千克\n3. 瓦特\n4. 帕斯卡";
    ti[10036].biaoda = "1";

    ti[10037].timu = "在经济学中，以下哪个术语描述了个人或企业支付税款后的收入？\n1. 净收入\n2. 毛收入\n3. 利润\n4. 支出";
    ti[10037].biaoda = "1";

    ti[10038].timu = "在心理学中，以下哪个概念描述了个体对自己和他人的行为进行评价和解释的过程？\n1. 自我意识\n2. 自我效能\n3. 自我评价\n4. 自我监控";
    ti[10038].biaoda = "3";

    ti[10039].timu = "在历史学中，以下哪个事件标志着中华民国成立？\n1. 辛亥革命\n2. 五四运动\n3. 中国共产党成立\n4. 抗日战争胜利";
    ti[10039].biaoda = "1";

    ti[10040].timu = "在生物学中，以下哪个器官系统负责呼吸？\n1. 消化系统\n2. 循环系统\n3. 呼吸系统\n4. 泌尿系统";
    ti[10040].biaoda = "3";

    ti[10041].timu = "在管理学中，以下哪个原则是领导力的重要基础？\n1. 权力原则\n2. 激励原则\n3. 公平原则\n4. 沟通原则";
    ti[10041].biaoda = "2";

    ti[10042].timu = "在教育学中，以下哪个理论强调学生的自主性和个性化学习？\n1. 行为主义理论\n2. 建构主义理论\n3. 人本主义理论\n4. 认知主义理论";
    ti[10042].biaoda = "2";

    ti[10043].timu = "在工程学中，以下哪个材料通常用于制造高强度、轻质结构的零件？\n1. 钢材\n2. 铝材\n3. 铜材\n4. 塑料";
    ti[10043].biaoda = "2";

    ti[10044].timu = "在地理学中，以下哪个地形特征是河流冲积形成的？\n1. 山谷\n2. 三角洲\n3. 盆地\n4. 丘陵";
    ti[10044].biaoda = "2";

    ti[10045].timu = "在历史学中，以下哪个时期开始提倡人文主义？\n1. 希腊时期\n2. 中世纪\n3. 文艺复兴时期\n4. 现代主义时期";
    ti[10045].biaoda = "3";
}

/*-------------------------------------------------------*/

void mode1() //选择模式
{
    system("cls");
    ShowCursor(false);
    char ca = 0;
    int num = 0;
    srand(time(NULL));
    int d = rand() % 5 + 5; //题目数量
    cout << "[选择模式]" << endl;
    cout << "本轮共" << d << "道题" << endl;

    system("pause");
    gotoxy(0, 1);
    space();
    gotoxy(0, 1);

    for (int h = 1; h <= 25; h++) //初始数组
    {
        z[h] = 0;
    }

    for (int i = 1; i <= d; i++)
    {
        int a = rand() % p + 10001;
        bool tu = false;
        while (tu == false) //判断题目是否重复
        {
            int su = 0;
            for (int j = 1; j <= 25; j++)
            {
                if (a == z[j]) //1.2修改的bug
                {
                    su++;
                }
            }
            if (su == 0)
            {
                tu = true;
                z[i] = a;
            }
            else
            {
                tu = false;
                int a1 = rand() % p + 10001;
                a = a1;
            }
        }
        
        cout << "第" << i << "题：" << ti[a].timu << endl; //输出题目
        
        string ba = "";

        while (true)
        {
            ca = _getch();
            if (ca == '1')
            {
                ba = "1";
                break;
            }
            if (ca == '2')
            {
                ba = "2";
                break;
            }
            if (ca == '3')
            {
                ba = "3";
                break;
            }
            if (ca == '4')
            {
                ba = "4";
                break;
            }
            else
            {
                continue;
            }
        }

        if (ba == ti[a].biaoda)
        {
            cout << "回答正确" << endl;
            num++;
        }
        else
        {
            cout << "回答错误" << endl;
        }

        cout << "---------------" << endl;
        int an = 2; //判断是否退出
        cout << "5.退出" << " ";
        ColorChange("6.继续");
        char cn = 0;
        while (cn != 13)
        {
            cn = _getch();
            if (cn == '5')
            {
                gotoxy(0, 8);
                ColorChange("5.退出");
                cout << "6.继续";
                an = 1;
            }
            if (cn == '6')
            {
                gotoxy(0, 8);
                cout << "5.退出" << " ";
                ColorChange("6.继续");
                an = 2;
            }
            if (cn == 13)
            {
                if (an == 1)
                {
                    return;
                }
                else
                {
                    break;
                }
            }
        }
        
        gotoxy(0, 1);
        space();
        gotoxy(0, 1);
    }
    cout << "本次共" << d << "道题，" << "答对" << num << "道题" << endl;
    system("pause");
    space();
    ShowCursor(false);
}

void mode2() //随机模式
{
    system("cls");
    ShowCursor(true);
    cout << "[随机模式]" << endl << "题目：";
    srand(time(NULL));
    int a = rand() % n + 1;
    cout << ti[a].timu << endl; //输出题目
    string b;
    cin >> b; //输入答案
    ShowCursor(false);
    if (judgment(b, ti[a].biaoda) == 1)
    {
        cout << "回答正确" << endl;
    }
    else
    {
        cout << "回答错误" << endl;
    }
    system("pause");
}

void mode3() //化学模式
{
    system("cls");
    ShowCursor(false);
    int num = 0;
    srand(time(NULL));
    int d = rand() % 5 + 5; //题目数量
    cout << "[化学模式]" << endl;
    cout << "本轮共" << d << "道题" << endl;

    system("pause");
    gotoxy(0, 1);
    space();
    gotoxy(0, 1);

    for (int h = 1; h <= 25; h++) //初始数组
    {
        z[h] = 0;
    }
    ShowCursor(true);
    for (int i = 1; i <= d; i++)
    {
        int a = rand() % m + 5001;
        bool tu = false;
        while (tu == false) //判断题目是否重复
        {
            int su = 0;
            for (int j = 1; j <= 25; j++)
            {
                if (a == z[j]) //1.2修改的bug
                {
                    su++;
                }
            }
            if (su == 0)
            {
                tu = true;
                z[i] = a;
            }
            else
            {
                tu = false;
                int a1 = rand() % m + 5001;
                a = a1;
            }
        }
        ShowCursor(true);
        cout << i << "." << ti[a].timu << endl; //输出题目
        string b;
        cin >> b; //输入答案
        ShowCursor(false);
        if (judgment(b, ti[a].biaoda) == 1)
        {
            cout << "回答正确" << endl;
            num++;
        }
        else
        {
            cout << "回答错误" << endl;
        }

        cout << "---------------" << endl;
        int an = 2; //判断是否退出
        cout << "5.退出" << " ";
        ColorChange("6.继续");
        char cn = 0;
        while (cn != 13)
        {
            cn = _getch();
            if (cn == '5')
            {
                gotoxy(0, 5);
                ColorChange("5.退出");
                cout << "6.继续";
                an = 1;
            }
            if (cn == '6')
            {
                gotoxy(0, 5);
                cout << "5.退出" << " ";
                ColorChange("6.继续");
                an = 2;
            }
            if (cn == 13)
            {
                if (an == 1)
                {
                    return;
                }
                else
                {
                    break;
                }
            }
        }

        gotoxy(0, 1);
        space();
        gotoxy(0, 1);
    }
    gotoxy(0, 1);
    space();
    gotoxy(0, 1);
    cout << "本次共" << d << "道题，" << "答对" << num << "道题" << endl;
    system("pause");
    ShowCursor(false);
}

void mode4() //设置选项
{
    system("cls");
    cout << "[设置选项]" << endl;
    cout << "退出选项 ";
    cout << endl << endl;;
    cout << "按“0”键退出设置选项\n按“Enter”键更改设置" << endl;
    
    ShowCursor(false);
    while (true)
    {
        if (entk == 0)
        {
            gotoxy(9, 1);
            ColorChange(ent[0]);
            cout << "     ";
        }
        else
        {
            gotoxy(9, 1);
            ColorChange(ent[1]);
            cout << "     ";
        }

        char cn = _getch();
        if (cn == 13)
        {
            if (entk == 1)
            {
                entk = 0;
            }
            else
            {
                entk = 1;
            }
        }
        if (cn == '0')
        {
            break;
        }
    }
    ShowCursor(false);
}

void mode5() //使用说明
{
    system("cls");
    ShowCursor(false);
    cout << "[使用说明]" << endl;
    cout << "欢迎使用题库系统v1.2.1，以下是相关使用说明：" << endl;
    cout << "1.主菜单页面按键盘1~6数字进行选择，按Enter键确认." << endl;
    cout << "2.进入模式后，按照要求进行操作，结束后按任意键退出" << endl;
    cout << endl;
    cout << "-系统日志" << endl;
    cout << "-修改主菜单函数的底层代码，解决了闪屏问题。" << endl;
    cout << "-优化了部分代码，以及程序运行效率。" << endl;
    cout << "-随机题库中新增MC相关题目。" << endl;
    system("pause");
    ShowCursor(false);
}

void mode6() //退出系统
{
    system("cls");
    ShowCursor(false);
    int zt = 2;
    if (entk == 1)
    {
        cout << "您正在尝试退出系统，退出后将清空所有用户数据，是否继续？" << endl;
        while (true)
        {
            if (zt == 1)
            {
                gotoxy(0, 1);
                ColorChange("1.是");
                cout << "2.否";
            }
            else
            {
                gotoxy(0, 1);
                cout << "1.是" << " ";
                ColorChange("2.否");
            }
            char cx = _getch();

            if (cx == '1')
            {
                zt = 1;
            }
            if (cx == '2')
            {
                zt = 2;
            }
            if (cx == 13)
            {
                if (zt == 1)
                {
                    a3 = zt;
                    Enter = true;
                    return;
                }
                if (zt == 2)
                {
                    a3 = zt;
                    break;
                }
            }
        }
    }
    else
    {
        return;
    }
}


void Menu()
{
    //to1 = true;
    ShowCursor(false);
    system("cls"); // 清屏
    cout << "题库系统v1.2.1" << endl << endl;
    cout << "1.选择模式 2.随机模式 3.化学模式" << endl;
    cout << "4.设置选项 5.使用说明 6.退出系统" << endl << endl;
    cout << "单项选择的选择题题库，每轮题目5~10道" << endl;

    while (true)
    {
        char ch = 0;
        ch = _getch(); //获取键盘输入
        if (check == 1 && ch != '1')
        {
            gotoxy(0, 2);
            cout << "1.选择模式";
        }
        if (check == 2 && ch != '2')
        {
            gotoxy(11, 2);
            cout << "2.随机模式";
        }
        if (check == 3 && ch != '3')
        {
            gotoxy(22, 2);
            cout << "3.化学模式";
        }
        if (check == 4 && ch != '4')
        {
            gotoxy(0, 3);
            cout << "4.设置选项";
        }
        if (check == 5 && ch != '5')
        {
            gotoxy(11, 3);
            cout << "5.使用说明";
        }
        if (check == 6 && ch != '6')
        {
            gotoxy(22, 3);
            cout << "6.退出系统";
        }

        if (ch == '1' && to1 == false)
        {
            to1 = true;
            to2 = false;
            to3 = false;
            to4 = false;
            to5 = false;
            to6 = false;
            gotoxy(0, 2);
            ColorChange("1.选择模式");
            check = 1;
            gotoxy(0, 5);
            cout << "单项选择的选择题题库，每轮题目5~10道";
            cout << "                 ";
            to1 = false;
        }
        if (ch == '2' && to2 == false)
        {
            to1 = false;
            to2 = true;
            to3 = false;
            to4 = false;
            to5 = false;
            to6 = false;
            gotoxy(11, 2);
            ColorChange("2.随机模式");
            check = 2;
            gotoxy(0, 5);
            cout << "随机简答题，每轮题目1道";
            cout << "                 ";
            to2 = false;
        }
        if (ch == '3' && to3 == false)
        {
            to1 = false;
            to2 = false;
            to3 = true;
            to4 = false;
            to5 = false;
            to6 = false;
            gotoxy(22, 2);
            ColorChange("3.化学模式");
            check = 3;
            gotoxy(0, 5);
            cout << "化学学科的简答题，每轮题目5~10道";
            cout << "                 ";
            to3 = false;
        }
        if (ch == '4' && to4 == false)
        {
            to1 = false;
            to2 = false;
            to3 = false;
            to4 = true;
            to5 = false;
            to6 = false;
            gotoxy(0, 3);
            ColorChange("4.设置选项");
            check = 4;
            gotoxy(0, 5);
            cout << "设置相关内容以改善用户体验";
            cout << "                 ";
            to4 = false;
        }
        if (ch == '5' && to5 == false)
        {
            to1 = false;
            to2 = false;
            to3 = false;
            to4 = false;
            to5 = true;
            to6 = false;
            gotoxy(11, 3);
            ColorChange("5.使用说明");
            check = 5;
            gotoxy(0, 5);
            cout << "题库系统的使用说明及注意事项";
            cout << "                 ";
            to5 = false;
        }
        if (ch == '6' && to6 == false)
        {
            to1 = false;
            to2 = false;
            to3 = false;
            to4 = false;
            to5 = false;
            to6 = true;
            gotoxy(22, 3);
            ColorChange("6.退出系统");
            check = 6;
            gotoxy(0, 5);
            cout << "退出系统，并清空所有用户数据";
            cout << "                 ";
            to6 = false;
        }

        if (ch == 13)
        {
            if (check == 1)
            {
                mode1();
                break;
            }
            if (check == 2)
            {
                mode2();
                break;
            }
            if (check == 3)
            {
                mode3();
                break;
            }
            if (check == 4)
            {
                mode4();
                break;
            }
            if (check == 5)
            {
                mode5();
                break;
            }
            if (check == 6)
            {
                mode6();
                if (Enter == true)
                {
                    return;
                }
                else
                {
                    break;
                }
            }
        }
    }
}

int main()
{
    ShowCursor(false);
    tik1();
    tik2();
    tik3();
    n_num();
    m_num();
    p_num();
    while (Enter == false)
    {
        Menu();
    }
    return 0;
}