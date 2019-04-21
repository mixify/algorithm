#include <string>
#include <vector>
#include <map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    map<string, int> marathoner;
    for (int i = 0; i < participant.size(); ++i) {
        marathoner.insert(make_pair(participant[i],i));
    }
    for (int i = 0; i < completion.size(); ++i) {
        marathoner.erase(completion[i]);
    }
    return answer;
}
