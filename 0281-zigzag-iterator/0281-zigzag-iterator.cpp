class ZigzagIterator {
    bool flag = true;
    int i, j;
    std::vector<int> &v1, &v2;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) : v1(v1), v2(v2){
        i = 0;
        j = 0;
    }

    int next() {
        if (flag) {
            flag = !flag;
            if (i < v1.size()) return v1[i++];
            else return v2[j++];
        } else {
            flag = !flag;
            if (j < v2.size()) return v2[j++];
            else return v1[i++];
        }
    }

    bool hasNext() {
        return i < v1.size() || j < v2.size();
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */