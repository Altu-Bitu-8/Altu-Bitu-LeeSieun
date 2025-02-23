#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; //전역변수로 선언. namespace : 이름공간


bool arrange(const string& A, const string& B) {
	if (A.length() != B.length()) //길이비교 cf. 10825-국영수
		return A.length() < B.length(); // 길이가 짧을수록 앞에 온다. 트루 -> 안바뀜.
	int sumA = 0, sumB = 0;
	for (int i = 0; i < A.length(); i++) { //어차피 길이 같음.
		if (isdigit(A[i])) sumA += A[i] - '0'; // ASCII 코드값때문에 0(48)을 빼줌.
		if (isdigit(B[i])) sumB += B[i] - '0';
	}
	if (sumA != sumB)
		return sumA < sumB; //A가 크면 false니까 바뀜.
	return A < B; //사전순 앞으로 배열.
}


int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);


	int n;//  차 개수 입력
	cin >> n;
	vector<string> guitarname(n);// 기타 이름 입력

	for (int i = 0; i < n; i++) {
		cin >> guitarname[i];
	}
	sort(guitarname.begin(), guitarname.end(), arrange);


	//기타 정렬한거 출력
	for (int i = 0; i < n; i++) {
		cout << guitarname[i] << '\n';
	}
	return 0;

}

