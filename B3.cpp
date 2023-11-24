#include <iostream>
#include <vector>

class Sequence {
private:
    std::vector<long long> elements;
    std::vector<long long> prefixSum;

public:
    Sequence(int n) {
        elements.resize(n, 0);
        prefixSum.resize(n + 1, 0);
    }

    void updateRange(int u, int v, long long k) {
        elements[u] += k;
        elements[v + 1] -= k;
    }

    void computePrefixSum() {
        prefixSum[0] = elements[0];
        for (int i = 1; i < elements.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + elements[i];
        }
    }

    long long getMaxInRange(int u, int v) {
        return getMaxFromPrefixSum(v) - getMaxFromPrefixSum(u - 1);
    }

private:
    long long getMaxFromPrefixSum(int index) {
        if (index < 0)
            return 0;
        return prefixSum[index];
    }
};

int main() {
    int n, m, q;
    std::cout << "Nhap so phan tu (n): ";
    std::cin >> n;
    std::cout << "Nhap so phep bien doi (m): ";
    std::cin >> m;
    std::cout << "Nhap so cau hoi (q): ";
    std::cin >> q;

    Sequence sequence(n);

    std::cout << "Nhap " << m << " phep bien doi:\n";
    for (int i = 0; i < m; i++) {
        int u, v;
        long long k;
        std::cout << "Phep bien doi thu " << i + 1 << ": ";
        std::cin >> u >> v >> k;
        sequence.updateRange(u, v, k);
    }

    sequence.computePrefixSum();

    std::cout << "Nhap " << q << " cau hoi:\n";
    for (int i = 0; i < q; i++) {
        int u, v;
        std::cout << "Cau hoi thu " << i + 1 << ": ";
        std::cin >> u >> v;
        long long maxVal = sequence.getMaxInRange(u, v);
        std::cout << "Gia tri lon nhat trong doan [" << u << ", " << v << "]: " << maxVal << std::endl;
    }

    return 0;
}
