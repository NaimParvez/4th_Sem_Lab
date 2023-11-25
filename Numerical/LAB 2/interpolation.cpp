#include <iostream>
#include <vector>

using namespace std;

double newtonForwardInterpolation(double x, const vector<double> &xValues, const vector<double> &yValues)
{
    int n = xValues.size();
    double result = yValues[0];
    double h = xValues[1] - xValues[0];
    double u = (x - xValues[0]) / h;

    vector<vector<double>> dividedDifferences(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        dividedDifferences[i][0] = yValues[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            dividedDifferences[j][i] = dividedDifferences[j + 1][i - 1] - dividedDifferences[j][i - 1];
        }
    }
    cout<<"Divided Differences Table for Forward method: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dividedDifferences[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 1; i < n; i++)
    {
        double term = dividedDifferences[0][i];
        for (int j = 0; j < i; j++)
        {
            term *= (u - j) / (j + 1);
        }
        result += term;
    }

    return result;
}

double newtonBackwardInterpolation(double x, const vector<double> &xValues, const vector<double> &yValues)
{
    int n = xValues.size();
    double result = yValues[n - 1];
    double h = xValues[1] - xValues[0];
    double u = (x - xValues[n - 1]) / h;

    vector<vector<double>> dividedDifferences(n, vector<double>(n));

    for (int i = 0; i < n; i++)
    {
        dividedDifferences[i][0] = yValues[i];
    }

    for (int i = 1; i < n; i++)
    {
        for (int j = n - 1; j >= i; j--)
        {
            dividedDifferences[j][i] = dividedDifferences[j][i - 1] - dividedDifferences[j - 1][i - 1];
        }
    }
    cout<<"Divided Differences Table for backward method: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<dividedDifferences[i][j]<<" ";
        }
        cout<<endl;
    }

    for (int i = 1; i < n; i++)
    {
        double term = dividedDifferences[n - 1][i];
        for (int j = 0; j < i; j++)
        {
            term *= (u + j) / (j + 1);
        }
        result += term;
    }

    return result;
}

int main()
{
    vector<double> xValues;
    vector<double> yValues;
    double x;

    cout << "Enter the number of data points: ";
    int n;
    cin >> n;

    cout << "Enter the x-values: ";
    for (int i = 0; i < n; i++)
    {
        double value;
        cin >> value;
        xValues.push_back(value);
    }

    cout << "Enter the y-values: ";
    for (int i = 0; i < n; i++)
    {
        double value;
        cin >> value;
        yValues.push_back(value);
    }

    cout << "Enter the value of x: ";
    cin >> x;

    int choice;
    do
    {
        cout << "Menu:" << endl;
        cout << "1. Forward Interpolation" << endl;
        cout << "2. Backward Interpolation" << endl;
        cout << "0. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        double backwardInterpolatedValue;
        double forwardInterpolatedValue;
        switch (choice)
        {
        case 1:
            forwardInterpolatedValue = newtonForwardInterpolation(x, xValues, yValues);
            cout << "Forward Interpolated value at x = " << x << " is: " << forwardInterpolatedValue << endl;
            break;
        case 2:
             backwardInterpolatedValue = newtonBackwardInterpolation(x, xValues, yValues);
            cout << "Backward Interpolated value at x = " << x << " is: " << backwardInterpolatedValue << endl;
            break;
        case 0:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 0);

    return 0;
}
