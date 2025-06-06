#include <iostream>
#include <set>
#include <time.h>

using namespace std;

set<char> appear;

string answer(bool repeat){
    char ans[5];
    appear.clear();
    srand(time(NULL));

    if(repeat){
        for(int i = 0; i < 4; i++){
            ans[i]  = char('0' + rand() % 10);
            appear.insert(ans[i]);
        }
    }
    else{
        int cur;
        for(int i = 0; i < 4; i++){
            cur = char('0' + rand() % 10);
            while(appear.count(cur) == 1){
                cur = char('0' + rand() % 10);
            }
            ans[i] = cur;
            appear.insert(cur);
        }
    }
    ans[4] = '\0';

    return ans;
}

int main(){
    system("chcp 65001");
    cout << "歡迎來到1A2B小遊戲，我們先來做一個小設置。\n請問一個組合中的數字可以重複嗎？\n如果要重複，請輸入1，不要重複，請輸入0。\n";

    int r;
    cin >> r;
    while(r != 1 && r != 0){
        cout << "只能輸入0或1喔！請重新輸入。\n";
        cin >> r;
    }
    bool repeat;
    repeat = r;

    bool play = 1;
    int score = 0;
    while(play){
        if(score != 0){
            cout << "這次要重複數字嗎？如果要重複，請輸入1，不要重複，請輸入0。\n";
            cin >> r;
            while(r != 1 && r != 0){
                cout << "只能輸入0或1喔！請重新輸入。\n";
                cin >> r;
            }
            repeat = r;
        }

        cout << "\n------------------------------------\n\n那要開始遊戲囉！答案裡面可能會有0~9的任意數字，答案中間請不要出現換行或空格，隨時都可以輸入0以退出。\n";
        string question = answer(repeat);
        string answer = "1";

        bool incorrect = 0;
        while(1){
            cout << "\n請輸入你的答案：";
            // add length check!
            cin >> answer;
            
            if (answer.length() == 1 && answer[0] == '0') return 0;
            
            while(answer.length() != 4){
                cout << "請輸入四個數字，中間請不要出現換行或空格。\n";
                cin >> answer;
            }

            if (question.compare(answer) == 0){
                score++;
                cout << "恭喜你答對了！\n目前累計答對" << score << "題！\n";
                break;
            }
            else{
                int a = 0, b = 0;
                for(int i = 0; i < 4; i++){
                    if(appear.count(answer[i]) == 1) b++;
                    
                    if(answer[i] == question[i]){
                        b--;
                        a++;
                    }
                }

                cout << a << "A" << b << "B\n";
            }
        }

        cout << "\n------------------------------------\n\n要繼續玩遊戲嗎？\n如果要再玩一次，請輸入1；結束遊戲，請輸入0。\n";
        cin >> r;
        while(r != 1 && r != 0){
            cout << "只能輸入0或1喔！請重新輸入。\n";
            cin >> r;
        }
        play = r;
    }

    return 0;
}