class Linear {
    private:
        double slope;
        double y0;
    public:
        Linear(double s1_ = 1, double y_ = 0) : slope(s1_), y0(y_) {}
        double operator() (double x) {return y0 + slope * x; }
}；
