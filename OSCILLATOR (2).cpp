#include <stdio.h>

int main()
{
    double x = 1.0;      // initial position
    double v = 0.0;      // initial velocity
    double w = 1.0;      // angular frequency
    double gamma = 0.15; // damping constant

    double dt = 0.01;    // time step
    double t = 0.0;

    double a;

    printf("time\tposition\tvelocity\tenergy\n");

    for(int i = 0; i < 500; i++)
    {
        double energy = 0.5*v*v + 0.5*w*w*x*x;

        printf("%.3f\t%.5f\t%.5f\t%.5f\n", t, x, v, energy);

        // acceleration
        a = -w*w*x - gamma*v;

        // Euler-Cromer update
        v = v + a*dt;
        x = x + v*dt;

        t = t + dt;
    }

    return 0;
}
