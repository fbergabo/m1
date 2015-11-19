#define M_PI 3.14159265358979323846     /* pi */

double pi_leibniz (int n);
double pi_bbp (int n);

double pi_bbp (int n) // The Bailey-Borwein-Plouffe series written as a for loop over n terms. 
{
    int k; 
    double a = 16, b, c, d, e, s = 0.0; 

    for (k = 0; k < n; k++)
    {
        a *= 1. / (16);
        b = 4. / ((8 * k) + 1);
        c = 2. / ((8 * k) + 4);
        d = 1. / ((8 * k) + 5);
        e = 1. / ((8 * k) + 6);

        s += a * (b - c - d - e);
    }
    return s; // Returns the value of the Bailey-Borwein-Plouffe series calculated using n terms.
}

double pi_leibniz (int n) // The Leibniz series written as a for loop with n terms.
{
    int i;
    double num = -1., denom = -1., s = 0;

    for (i = 0; i < n; i++)
    {
        num *= -1.;
        denom += 2.;
        s += (num / denom);
    }
    return (4*s); // Returns 4 times the value of the series calculated with n terms.
}



