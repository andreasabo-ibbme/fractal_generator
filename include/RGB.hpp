
namespace asabo {
struct RGB
{
    double R;
    double G;
    double B;

    RGB(double r, double g, double b) : R(r), G(g), B(b) {}
};

RGB operator-(const RGB& first, const RGB& second)
{
    return RGB(first.R + second.R, first.G + second.G, first.B + second.B);
}

} // namespace asabo