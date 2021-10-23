#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        vector<string> combVec;

        int N, M;
        cin >> N >> M;
        string comb;

        for (int s = 0; s < N; s++) {
            cin >> comb;
            combVec.push_back(comb);
        }

        int count = 0;

        for (int i=0; i < N - 2; i++) {
            vector<int> team(3, 0);
            team[0] = i;

            for (int j=i+1; j < N - 1; j++) {
                team[1] = j;

                for (int k = j + 1; k < N; k++) {
                    team[2] = k;

                    /*
                    // Team Created in here
                    cout << endl << "Teams: ";
                    for (int i : team) {
                        cout << i << " ";
                    }
                     */

                    vector<int> calcVec(M, 0);

                    for (int u = 0; u < 3; u++) {
                        for(int z = 0; z < M; z++) {
                            if (combVec[team[u]][z] == 'y') {
                                calcVec[z]++;
                                /*
                                cout << endl;
                                for (auto i =0; i < calcVec.size() ; i++){
                                    cout << calcVec[i] << " ";
                                }
                                 */
                            }
                        }
                    }

                    vector<int>::iterator it;
                    it = std::find(calcVec.begin(), calcVec.end(), 0);

                    if (it == calcVec.end()) {
                        count++;
                        //cout<< endl<< count <<endl;
                    }
                }
            }

        }
        cout << count << endl;
    }

    return 0;
}