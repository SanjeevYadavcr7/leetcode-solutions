#include<iostream>
#include<vector>
using namespace std;

vector<int> scoreValidator(vector<string>& events) {
    vector<int> result = {0, 0};
    
    for(string str : events) {
        if(result[1] == 10) break;
        if(str == "W") {
            result[1] += 1;
        } else {
            result[0] += (str == "WD" || str == "NB") ? 1 : stoi(str);
        }
    }
    return result;
}

int main() {
    vector<string> input1 = {"1","4","W","6","WD"};
    vector<string> input2 = {"WD","NB","0","4","4"};
    vector<string> input3 = {"W","W","W","W","W","W","W","W","W","W","W"};
    vector<string> input4 = {"4","6","1","W","4","W","2","2","0","NB","NB"};

    vector<int> scores1 = scoreValidator(input1);
    vector<int> scores2 = scoreValidator(input2);
    vector<int> scores3 = scoreValidator(input3);
    vector<int> scores4 = scoreValidator(input4);

    cout << scores1[0] << " " << scores1[1] << endl;
    cout << scores2[0] << " " << scores2[1] << endl;
    cout << scores3[0] << " " << scores3[1] << endl;
    cout << scores4[0] << " " << scores4[1] << endl;
}