#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <tchar.h>
#include <string>
#include <vector>
#include <cassert>

std::vector<std::string> OrigDict = {
    "真没有素质",
    "想踩缝纫机",
    "想吃牢饭",
    "狗血淋头",
    "律师函",
    "真过分",
    "蔡徐坤",
    "漏",
    "是",
    "鸡",
    "激将",
    "速删",
    "有病",
    "想进",
    "监狱",
    "鸡你",
    "鸡你",
    "家教",
    "素质",
    "素质",
    "素质",
    "理智",
    "好玩",
    "报警",
    "魔怔",
    "道歉",
    "前途",
    "自杀",
    "路人"
};

std::vector<std::string> IKunDict = {
    "蒸梅油酥汁",
    "香菜丰仁鸡",
    "香翅捞饭",
    "狗血麟投",
    "律斯韩",
    "臻果粉",
    "坤",
    "卤",
    "食",
    "只因",
    "鸡酱",
    "苏珊",
    "油饼",
    "香精",
    "煎鱼",
    "姬尼",
    "基尼",
    "荚饺",
    "树枝",
    "树脂",
    "酥汁",
    "荔枝",
    "耗丸",
    "煲胫",
    "馍蒸",
    "稻嵌",
    "嵌土",
    "紫砂",
    "鹿人"
};

std::vector<std::string> Backup_IKunDict = IKunDict;
std::vector<std::string> Backup_OrigDict = OrigDict;

void cls()
{
    system("\u0063\u006c\u0073");
}

void openWeb(std::string web = "\u0068\u0074\u0074\u0070\u0073\u003a\u002f\u002f\u0067\u0075\u006f\u0073\u0068\u0075\u0079\u0061\u006e\u002e\u0067\u0069\u0074\u0068\u0075\u0062\u002e\u0069\u006f\u002f", std::string operation = "\u006f\u0070\u0065\u006e") {
    HINSTANCE hRslt = ShellExecute(NULL, operation.c_str(),
        web.c_str(), NULL, NULL, SW_SHOWNORMAL);
    assert(hRslt > (HINSTANCE)HINSTANCE_ERROR);
}

void showDict(){
    std::cout << "\u76ee\u524d\u5b57\u5178\uff1a\u0020\u539f\u8bdd\u0020\u003c\u002d\u003e\u0020\u0049\u004b\u0075\u006e\u0020\u8bed\u000a";
    if (OrigDict.size() != 0) {
        for (size_t i = 0; i < OrigDict.size(); i++)
        {
            std::cout << OrigDict[i] << "\t\t<->\t\t" << IKunDict[i] << std::endl;
        }
    }
    else {
        std::cout << "\u8fd9\u91cc\u4ec0\u4e48\u90fd\u6ca1\u6709\u54e6\uff0c\u770b\u6837\u5b50\u662f\u88ab\u4f60\u6e05\u7a7a\u4e86\u6b38\u000a";
    }
}

void editDict(bool isAdd) {
    EDA :
    showDict();
    if (isAdd) {
        std::string input_IKun;
        std::string input_Original;
        IKUN_INPUT :
        std::cout << "\u000a\u8bf7\u8f93\u5165\u60a8\u60f3\u8981\u6dfb\u52a0\u7684\u0020\u0069\u006b\u0075\u006e\u0020\u8bed\uff08\u8f93\u5165\u0020\u0045\u0058\u0049\u0054\u0020\u9000\u51fa\uff09\uff1a";
        std::getline(std::cin, input_IKun);
        if (input_IKun == "\u0045\u0058\u0049\u0054") {
            return;
        }
        std::cout << "\u000a\u786e\u5b9a\u662f\u0020" << input_IKun << "\u0020\u5417\uff08\u004e\u002f\u0079\uff09\uff1f";
        char confirm = _getch();
        if (confirm == '\u0059' || confirm == '\u0079') {
            ORIGINAL_INPUT:
            std::cout << "\u000a\u8bf7\u8f93\u5165\u60a8\u60f3\u8981\u6dfb\u52a0\u7684\u539f\u8bed\uff08\u8f93\u5165\u0020\u0045\u0058\u0049\u0054\u0020\u9000\u51fa\uff0c\u0020" << input_IKun << "\u0020\u662f\u60a8\u521a\u624d\u8f93\u5165\u7684\uff0c\u8f93\u5165\u0020\u0050\u0052\u0045\u0056\u0020\u8fd4\u56de\u4e0a\u4e00\u6b65\uff09\uff1a";
            std::getline(std::cin, input_Original);
            if (input_Original == "\u0045\u0058\u0049\u0054") {
                return;
            }
            if (input_Original == "\u0050\u0052\u0045\u0056") {
                goto ORIGINAL_INPUT;
            }
            std::cout << "\u000a\u786e\u5b9a\u662f\u0020" << input_Original << "\u0020\u5417\uff08\u004e\u002f\u0079\uff09\uff1f";
            char confirm = _getch();
            if (confirm == '\u0059' || confirm == '\u0079') {
                OrigDict.push_back(input_Original);
                IKunDict.push_back(input_IKun);
                std::cout << "\u000a\u6dfb\u52a0\u6210\u529f\uff01";
                cls();
                goto EDA;
            }
            else {
                goto IKUN_INPUT;
            }
        }
        else {
            goto IKUN_INPUT;
        }
    }
    else {
        EDSM : 
        std::cout << "\u0031\u002e\u0020\u901a\u8fc7\u0020\u0049\u004b\u0075\u006e\u0020\u8bed\u67e5\u8be2\u000a";
        std::cout << "\u0032\u002e\u0020\u901a\u8fc7\u0020\u539f\u8bdd\u0020\u67e5\u8be2\u000a";
        std::cout << "\u0033\u002e\u0020\u9000\u51fa\u000a";
        std::string beDelete = "";
        std::cout << "\u8bf7\u9009\u62e9\u0020\u003e";
        char mode = _getch();
        if (mode == '1') {
        EDSII :
            int pos = -1;
            std::cout << "\u000a\u8bf7\u8f93\u5165\u60a8\u8981\u5220\u9664\u7684\u9009\u9879\uff08\u6839\u636e\u0020\u0049\u004b\u0075\u006e\u0020\u8bed\uff09\uff08\u8f93\u5165\u0020\u0045\u0058\u0049\u0054\u0020\u9000\u51fa\uff0c\u8f93\u5165\u0020\u0050\u0052\u0045\u0056\u0020\u8fd4\u56de\u4e0a\u4e00\u6b65\uff09\u0020\uff1a";
            std::getline(std::cin, beDelete);
            if (beDelete == "\u0045\u0058\u0049\u0054") {
                return;
            }
            if (beDelete == "\u0050\u0052\u0045\u0056") {
                goto EDSM;
            }
            for (int i = 0; i < IKunDict.size(); i++)
            {
                if (IKunDict[i] == beDelete) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                std::cout << "\u000a\u672a\u627e\u5230\u60a8\u8f93\u5165\u7684\u9009\u9879\uff08\u533a\u5206\u5927\u5c0f\u5199\uff09\uff0c\u60a8\u662f\u5426\u8f93\u5165\u4e86\u0020\u539f\u8bdd\uff1f\u000a";
                goto EDSII;
            }
            else {
                OrigDict.erase(OrigDict.begin() + pos);
                IKunDict.erase(IKunDict.begin() + pos);
                std::cout << "\u000a\u5220\u9664\u6210\u529f\uff01\u000a";
                goto EDSII;
            }
        }
        else if (mode == '2') {
        EDSIO :
            int pos = -1;
            std::cout << "\u000a\u8bf7\u8f93\u5165\u60a8\u8981\u5220\u9664\u7684\u9009\u9879\uff08\u6839\u636e\u0020\u539f\u8bdd\uff09\uff08\u8f93\u5165\u0020\u0045\u0058\u0049\u0054\u0020\u9000\u51fa\uff0c\u8f93\u5165\u0020\u0050\u0052\u0045\u0056\u0020\u8fd4\u56de\u4e0a\u4e00\u6b65\uff09\uff1a";
            std::getline(std::cin, beDelete);
            if (beDelete == "\u0045\u0058\u0049\u0054") {
                return;
            }
            if (beDelete == "\u0050\u0052\u0045\u0056") {
                goto EDSM;
            }
            for (int i = 0; i < OrigDict.size(); i++)
            {
                if (OrigDict[i] == beDelete) {
                    pos = i;
                    break;
                }
            }
            if (pos == -1) {
                std::cout << "\u000a\u672a\u627e\u5230\u60a8\u8f93\u5165\u7684\u9009\u9879\uff08\u533a\u5206\u5927\u5c0f\u5199\uff09\uff0c\u60a8\u662f\u5426\u8f93\u5165\u4e86\u0020\u0049\u004b\u0075\u006e\u0020\u8bed\uff1f";
                goto EDSIO;
            }
            else {
                OrigDict.erase(OrigDict.begin() + pos);
                IKunDict.erase(IKunDict.begin() + pos);
                std::cout << "\u000a\u5220\u9664\u6210\u529f\uff01\u000a";
                goto EDSIO;
            }
        }
        else if (mode == '3') {
            return;
        }
        else {
            std::cout << std::endl << "\u8f93\u5165\u9009\u9879\u65e0\u6548\u000a";
            goto EDSM;
        }
    }
}

void readDict(bool isITO) {
    std::string beConvert = "";
    std::cout << "\u8bf7\u8f93\u5165\u5c06\u88ab\u8f6c\u6362\u7684\u6587\u672c\uff08\u8f93\u5165\u0020\u0045\u0058\u0049\u0054\u0020\u9000\u51fa\uff09\uff1a";
    std::getline(std::cin, beConvert);
    if (beConvert == "\u0045\u0058\u0049\u0054") {
        return;
    }
    std::cout << "\u8f6c\u6362\u4e2d\u002e\u002e\u002e\u000a";
    if (isITO) {
        for (int i = 0; i < IKunDict.size(); i++)
        {
            while (1) {
                int findstate = beConvert.find(IKunDict[i]);
                if (findstate != std::string::npos) {
                    beConvert.erase(findstate, IKunDict[i].length());
                    beConvert.insert(findstate, OrigDict[i]);
                }
                else {
                    break;
                }
            }
        }
    }
    else {
        for (int i = 0; i < OrigDict.size(); i++)
        {
            while (1) {
                int findstate = beConvert.find(OrigDict[i]);
                if (findstate != std::string::npos) {
                    beConvert.erase(findstate, OrigDict[i].length());
                    beConvert.insert(findstate, IKunDict[i]);
                }
                else {
                    break;
                }
            }
        }
    }
    std::cout << "\u000a\u8f6c\u6362\u6210\u529f\uff01\u000a";
    std::cout << "\u7ed3\u679c\uff1a\u000a\u000a";
    std::cout << beConvert;
    std::cout << "\u000a\u000a\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
    system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
}

bool isCharHex(char character) {
    return ((character < '\u0031' || character > '\u0039') && (character < '\u0041' || character > '\u0046') && (character < '\u0061' || character > '\u0066'));
}

int main()
{
    std::cout << "\u6b22\u8fce\u6765\u5230\u0020\u0069\u006b\u0075\u006e\u0020\u8bed\u8a00\u7ffb\u8bd1\u5668\u0020\u0056\u0031\u002e\u0031\u0021\u000a";
    std::cout << "\u5df2\u5f00\u6e90\uff1a\u0068\u0074\u0074\u0070\u0073\u003a\u002f\u002f\u0067\u0069\u0074\u0068\u0075\u0062\u002e\u0063\u006f\u006d\u002f\u0067\u0075\u006f\u0073\u0068\u0075\u0079\u0061\u006e\u002f\u0069\u006b\u0075\u006e\u002d\u0074\u0072\u0061\u006e\u0073\u000a\u000a";
START :
    if (IKunDict.size() != OrigDict.size()) {
        std::cout << "\u5b57\u5178\u957f\u5ea6\u68c0\u6d4b\u5931\u8d25\uff01\u8bf7\u91cd\u65b0\u8fd0\u884c\u6216\u4e0b\u8f7d\u8be5\u7a0b\u5e8f\uff01\u000a";
        goto END;
    }
    std::cout << "\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u0020\u57fa\u7840\u0020\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u000a";
    std::cout << "\u0031\u002e\u0020\u7ffb\u8bd1\u0020\u539f\u6587\u2192\u0069\u006b\u0075\u006e\u6587\u000a";
    std::cout << "\u0032\u002e\u0020\u7ffb\u8bd1\u0020\u539f\u6587\u2190\u0069\u006b\u0075\u006e\u6587\u000a";
    std::cout << "\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u0020\u57fa\u7840\u0020\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u000a\u000a";
    std::cout << "\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u0020\u9ad8\u7ea7\u0020\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u000a";
    std::cout << "\u0033\u002e\u0020\u5b57\u5178\u0020\u002b\u0020\u539f\u6587\u2190\u2192\u0069\u006b\u0075\u006e\u6587\u2192\u5b57\u5178\u000a";
    std::cout << "\u0034\u002e\u0020\u5b57\u5178\u0020\u002d\u0020\u0069\u006b\u0075\u006e\u6587\u2192\u5b57\u5178\u000a";
    std::cout << "\u0035\u002e\u0020\u663e\u793a\u5b57\u5178\u000a";
    std::cout << "\u0036\u002e\u0020\u663e\u793a\u5b57\u5178\u7684\u4e2a\u6570\u000a";
    std::cout << "\u0037\u002e\u0020\u5220\u9664\u5b57\u5178\u6700\u540e\u4e00\u9879\u000a";
    std::cout << "\u0038\u002e\u0020\u5220\u9664\u5b57\u5178\u7b2c\u4e00\u9879\u000a";
    std::cout << "\u0039\u002e\u0020\u5220\u9664\u5b57\u5178\u6240\u6709\u9879\u000a";
    std::cout << "\u0030\u002e\u0020\u8fd8\u539f\u5b57\u5178\u4e3a\u0020\u3010\u6267\u884c\u0020\u0039\uff08\u5220\u9664\u5b57\u5178\u6240\u6709\u9879\uff09\u0020\u547d\u4ee4\u3011\u0020\u4e4b\u524d\u7684\u6837\u5b50\uff08\u5982\u679c\u6ca1\u6709\u6267\u884c\uff0c\u5219\u8fd8\u539f\u4e3a\u6700\u521d\u59cb\u7684\u6837\u5b50\uff09\u000a";
    std::cout << "\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u0020\u9ad8\u7ea7\u0020\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u000a\u000a";
    std::cout << "\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u0020\u6742\u9879\u0020\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u000a";
    std::cout << "\u0041\u002e\u0020\u6253\u5f00\u4f5c\u8005\u0020\u0042\u7ad9\u0020\u4e3b\u9875\u000a";
    std::cout << "\u0042\u002e\u0020\u6253\u5f00\u4f5c\u8005\u0020\u0047\u0069\u0074\u0068\u0075\u0062\u0020\u4e3b\u9875\u000a";
    std::cout << "\u0043\u002e\u0020\u6253\u5f00\u0020\u6b64\u9879\u76ee\u0020\u4e3b\u9875\u000a";
    std::cout << "\u0044\u002e\u0020\u6253\u5f00\u4f5c\u8005\u7684\u4e3b\u9875\u000a";
    std::cout << "\u0045\u002e\u0020\u4f5c\u8005\u4fe1\u606f\u000a";
    std::cout << "\u0046\u002e\u0020\u9000\u51fa\u000a";
    std::cout << "\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u0020\u6742\u9879\u0020\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u003d\u000a\u000a";
    std::cout << "\u8bf7\u8f93\u5165\u6a21\u5f0f\uff1a";
    {
        char mode = _getch();
        cls();
        if (isCharHex(mode)) {
            std::cout << "\u8f93\u5165\u9519\u8bef\uff01\u000a";
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == '1') {
            readDict(false);
        }
        else if (mode == '2') {
            readDict(true);
        }
        else if (mode == '3') {
            editDict(true);
        }
        else if (mode == '4') {
            editDict(false);
        }
        else if (mode == '5') {
            showDict();
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == '6') {
            std::cout << "\u76ee\u524d\u5b57\u5178\u6570\u91cf\uff1a" << OrigDict.size() << std::endl;
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == '7') {
            IKunDict.erase(IKunDict.end());
            OrigDict.erase(OrigDict.end());
            std::cout << "\u64e6\u9664\u6210\u529f\uff01\u000a";
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == '8') {
            IKunDict.erase(IKunDict.begin());
            OrigDict.erase(OrigDict.begin());
            std::cout << "\u64e6\u9664\u6210\u529f\uff01\u000a";
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == '9') {
            std::cout << "\u786e\u5b9a\uff08\u004e\u002f\u0079\uff09\uff1f";
            char confirm = _getch();
            if (confirm == '\u0079' || confirm == '\u0059') {
                Backup_IKunDict = IKunDict;
                Backup_OrigDict = OrigDict;
                IKunDict.clear();
                OrigDict.clear();
            }
            std::cout << "\u64e6\u9664\u6210\u529f\uff01\u000a";
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == '0') {
            std::cout << "\u786e\u5b9a\uff08\u004e\u002f\u0079\uff09\uff1f";
            char confirm = _getch();
            if (confirm == '\u0079' || confirm == '\u0059') {
                IKunDict = Backup_IKunDict;
                OrigDict = Backup_OrigDict;
            }
            std::cout << "\u8fd8\u539f\u6210\u529f\uff01\u000a";
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == 'A' || mode == 'a') {
            openWeb("\u0068\u0074\u0074\u0070\u0073\u003a\u002f\u002f\u0073\u0070\u0061\u0063\u0065\u002e\u0062\u0069\u006c\u0069\u0062\u0069\u006c\u0069\u002e\u0063\u006f\u006d\u002f\u0031\u0038\u0035\u0033\u0035\u0034\u0037\u0031\u0030");
        }
        else if (mode == 'B' || mode == 'b') {
            openWeb("\u0068\u0074\u0074\u0070\u0073\u003a\u002f\u002f\u0067\u0069\u0074\u0068\u0075\u0062\u002e\u0063\u006f\u006d\u002f\u0067\u0075\u006f\u0073\u0068\u0075\u0079\u0061\u006e");
        }
        else if (mode == 'C' || mode == 'c') {
            openWeb("\u0068\u0074\u0074\u0070\u0073\u003a\u002f\u002f\u0067\u0069\u0074\u0068\u0075\u0062\u002e\u0063\u006f\u006d\u002f\u0067\u0075\u006f\u0073\u0068\u0075\u0079\u0061\u006e\u002f\u0069\u006b\u0075\u006e\u002d\u0074\u0072\u0061\u006e\u0073");
        }
        else if (mode == 'D' || mode == 'd') {
            openWeb("\u0068\u0074\u0074\u0070\u0073\u003a\u002f\u002f\u0067\u0075\u006f\u0073\u0068\u0075\u0079\u0061\u006e\u002e\u0067\u0069\u0074\u0068\u0075\u0062\u002e\u0069\u006f\u002f");
        }
        else if (mode == 'E' || mode == 'e') {
            std::cout << "\u4f5c\u8005\u0020\u0042\u7ad9\u0020\u540d\u79f0\uff1a\u0020\u5f00\u6717\u7684\u7f51\u53cb\u56db\u4e16\u000a";
            std::cout << "\u4f5c\u8005\u0020\u0047\u0069\u0074\u0068\u0075\u0062\u0020\u540d\u79f0\uff1a\u0020\u0067\u0075\u006f\u0073\u0068\u0075\u0079\u0061\u006e\u000a";
            std::cout << "\u4f5c\u8005\u7b80\u4ecb\u0020\uff1a\u0020\u53ea\u4e0d\u8fc7\u662f\u4e2a\u0020\u0031\u0031\u0020\u5c81\uff08\u516d\u5e74\u7ea7\uff09\u7684\u5c0f\u5b66\u751f\u7f62\u4e86\u3002\u000a";
            std::cout << "\u4ec0\u4e48\u90fd\u73a9\uff0c\u539f\u795e\uff0c\u5730\u94c1\u8dd1\u9177\uff0c\u6211\u7684\u4e16\u754c\u2026\u2026\u000a";
            std::cout << "\u6211\u7684\u7c89\u4e1d\u7fa4\uff08\u0051\u0051\uff09\uff1a\u0039\u0031\u0037\u0039\u0038\u0032\u0031\u0032\u0038\u000a";
            std::cout << "\u6309\u4efb\u610f\u952e\u8fd4\u56de\u83dc\u5355\uff01";
            system("\u0070\u0061\u0075\u0073\u0065\u003e\u006e\u0075\u006c");
        }
        else if (mode == 'F' || mode == 'f') {
            goto END;
        }
        
        cls();
    }
    goto START;
    END :
    return 0;
}


// When taking a video, please stop the text cursor at the position pointed by the arrow: ↘
//                                                                                          
// 拍视频的时候，请将文本光标停在箭头指向的位置：                                                ↖