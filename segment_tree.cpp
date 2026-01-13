template <typename T>
class SegmentTree {
private:
    int size;
    vector<T> t;
    T Id; // Neutral element for invalid range
    function<T(T, T)> combine;
 
    void build(vector<T>& a, int v, int tl, int tr) {
        if (tl == tr) {
            t[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2;
            build(a, v * 2, tl, tm);
            build(a, v * 2 + 1, tm + 1, tr);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
 
    T get(int v, int tl, int tr, int l, int r) {
        if (l > r) return Id;
        if ((tl == l) && (tr == r)) {
            return t[v];
        }
        int tm = (tl + tr) / 2;
        return combine(
            get(v * 2, tl, tm, l, min(r, tm)),
            get(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)
        );
    }
 
    void update(int v, int tl, int tr, int pos, T new_val) { // point update
        if (tl == tr) {
            t[v] = new_val;
        } else {
            int tm = (tl + tr) / 2;
            if (pos <= tm)
                update(v * 2, tl, tm, pos, new_val);
            else
                update(v * 2 + 1, tm + 1, tr, pos, new_val);
            t[v] = combine(t[v * 2], t[v * 2 + 1]);
        }
    }
 
public:
    SegmentTree(function<T(T, T)> combineFunction, T Id)
    : combine(combineFunction), Id(Id) {}
 
    void init(int n) {
        size = 1;
        while (size < n) size *= 2;
        // t.resize(2 * size);
        t.assign(2 * size, Id); // if no build
    }
 
    void build(vector<T>& a) {
        a.resize(size, Id); // Resize and fill with default value
        build(a, 1, 0, size - 1);
    }
 
    T get(int l, int r) {
        return get(1, 0, size - 1, l, r);
    }
 
    void update(int pos, T inc) { // assignment, can also make for increment
        update(1, 0, size - 1, pos, inc);
    }
 
    void print() {
        for (int i = 1; i < 2 * size; ++i) {
            cout << t[i] << " ";
        }
        cout << endl;
    }
};
