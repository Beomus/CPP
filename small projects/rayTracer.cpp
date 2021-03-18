#include <fstream>
#include <cmath>

struct Vec {

    double x, y, z;
    Vec(){x=y=z=0;}
    Vec(double a, double b, double c){x=a, y=b, z=c;}
    Vec operator + (Vec v) {return Vec(x + v.x, y + v.y, z + v.z);}
    Vec operator - (Vec v) {return Vec(x - v.x, y - v.y, z - v.z);}
    Vec operator * (double d) {return Vec(x*d, y*d, z*d);}
    Vec operator / (double d) {return Vec(x/d, y/d, z/d);}
    Vec normalize() {double mg = sqrt(x*x + y*y + z*z); return Vec(x/mg, y/mg, z/mg);}
};

double dot(Vec v, Vec b) {return (v.x * b.x + v.y * b.y + v.z * b.z);}

struct Ray {

    Vec o;      // origin
    Vec d;      // direction
    Ray(Vec i, Vec j){o=i, d=j;}
};


struct Sphere {

    Vec c;      // center
    double r;      // radius
    Sphere(Vec i, double j){c=i, r=j;}

    Vec getNormal(Vec p) {return (p-c)/r;}

    bool intersect(Ray ray, double &t){
        Vec o = ray.o;
        Vec d = ray.d;
        Vec oc = o-c;
        double b = 2*dot(oc, d);
        double c = dot(oc, oc) - r*r;
        double disc = b*b - 4*c;
        if (disc < 0) return false;
        else {
            disc = sqrt(disc);
            double t0 = -b-disc;
            double t1 = -b+disc;
            t = (t0 < t1) ? t0 : t1;
            return t;
        }
    }
};

struct Color {
    double r, g, b;
    Color(){r=g=b=0;}
    Color(double i, double j, double k){r=i, g=j, b=k;}

    Color operator * (double d) {return Color(r*d, g*d, b*d);}
    Color operator + (Color d) {return Color((r+d.r)/2, (g+d.g)/2, (b+d.b)/2);}
};


int main() {
    const int W = 500;
    const int H = 500;

    std::ofstream out("out.ppm");
    out << "P3\n" << W << '\n' << H << '\n' << "255\n";

    Color pixelColor[H][W];
    Color white (255, 255, 255);
    Color red (255, 0, 0);

    Sphere sphere (Vec(W/2, H/2, 50), 50);
    Sphere light (Vec(W/2, 0, 50), 1);

    // for each pixel
    for (int y = 0; y < H; y++) {
        for (int x = 0; x < W; x++) {
            // send a ray through each pixel
            Ray ray(Vec(x, y, 0), Vec(0, 0, 1));

            double t = 2000;

            // Check intersections
            if (sphere.intersect(ray, t)) {
                // point of intersection
                Vec p = ray.o + ray.d*t;

                // color the pixel
                Vec L = light.c - p;
                Vec N = sphere.getNormal(p);

                double dt = dot(L.normalize(), N.normalize());

                pixelColor[y][x] = red + (white*dt)*1.0;

                if (pixelColor[y][x].r < 0) pixelColor[y][x].r = 0;
                if (pixelColor[y][x].g < 0) pixelColor[y][x].g = 0;
                if (pixelColor[y][x].b < 0) pixelColor[y][x].b = 0;
                if (pixelColor[y][x].r > 255) pixelColor[y][x].r = 255;
                if (pixelColor[y][x].g > 255) pixelColor[y][x].g = 255;
                if (pixelColor[y][x].b > 255) pixelColor[y][x].b = 255;

            }

            out << pixelColor[y][x].r << std::endl;
            out << pixelColor[y][x].g << std::endl;
            out << pixelColor[y][x].b << std::endl;
        }
    }

    return 0;
}