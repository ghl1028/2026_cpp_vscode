#include <iostream>
#include <vector>
#include <memory>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> data;
    data.reserve(n);

    // TODO: n개의 가변 길이 정수 배열을 입력받아 data에 저장하세요.
    for (int i = 0; i < n; i++)
    {
        int vec_num;
        std::cin >> vec_num;
        //data.push_back(std::vector<int>(vec_num));
        for (int j = 0; j < vec_num; j++)
        {
            int num = 0 ;
            std::cin >> num ;
            data[i].push_back(num) ;
            // std::cin >> data[i][j] ;
        }
    }
    // TODO: m개의 질문 (i, j)을 입력받아 data[i][j]를 한 줄에 하나씩 출력하세요.
    for (int i = 0; i < m; i++)
    {
        int q1, q2;
        std::cin >> q1 >> q2;
        std::cout << data[q1][q2] << '\n';
    }

    return 0;
}
