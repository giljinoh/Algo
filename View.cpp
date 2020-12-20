#include<iostream>
using namespace std;

int cnt;

int check(int map[255][1000],int r, int c){
    if(map[r][c-1] == 0 && map[r][c-2] == 0 && map[r][c+1] == 0 && map[r][c+2] == 0){
        cnt += 1;
    }
    return cnt; 
}

int main(int argc, char** argv)
{
	int test_case;
	int T =10;
    int result;
	
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int map[255][1000] = {0};
        int building[1000] = {0};
		int b_num,b_height;
        cnt = 0;
        cin >> b_num;

        for(int i=0; i<b_num; ++i){
            cin >> building[i];
        }

        for(int i=0; i<b_num; ++i){
            for(int j=0; j<building[i]; ++j){
                map[254-j][i] = 1;
            }
        }

        for(int i=0; i<b_num; ++i){
            for(int j=0; j<building[i]; ++j){
                if(map[254-j][i] == 1){
                    result = check(map,254-j,i);
                }
            }
        }
        cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
