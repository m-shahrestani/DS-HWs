#include<bits/stdc++.h>
using namespace std;

int main() {
    int ballCount, numbersPerBall;
    cin >> ballCount >> numbersPerBall;
    int ballNumbers[ballCount][numbersPerBall];
    int ballFinalRotationHead[ballCount];
    for(int i = 0; i < ballCount; i++){
        ballFinalRotationHead[i] = 0;
        for(int j = 0; j < numbersPerBall; j++){
            cin >> ballNumbers[i][j];
        }
    }
    int guideBallCount;
    cin >> guideBallCount;
    int guideNumbers[guideBallCount];
    for(int i = 0; i < guideBallCount; i++) {
        cin >> guideNumbers[i];
    }
    int moveCount;
    cin >> moveCount;
    for(int i = 0; i < moveCount; i++){
        int ballIndex = i % ballCount;
        int guideIndex = i % guideBallCount;
        ballFinalRotationHead[ballIndex] += guideNumbers[guideIndex];
    }
    for(int i = 0; i < ballCount; i++){
        while(ballFinalRotationHead[i] < 0) {
            ballFinalRotationHead[i] += numbersPerBall;
        }
        if(ballFinalRotationHead[i] >= numbersPerBall) {
        	ballFinalRotationHead[i] %= (int)numbersPerBall;
    	}
    }
    for(int i = (moveCount % ballCount); i < ballCount; i++){
        cout << ballNumbers[i][ballFinalRotationHead[i]];
    }
    for(int i = 0; i < (moveCount % ballCount); i++){
        cout << ballNumbers[i][ballFinalRotationHead[i]];
    }
    return 0;
}
