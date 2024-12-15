#include <iostream>
#include <graphics.h>
#include <cmath>

using namespace std;

void multiplyMatrix(int A[][3], int B[][3], int C[][3])
{
    // C = A X B
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            C[i][j] = 0;
            for (int k = 0; k < 3; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void printMatrix(int B[][3])
{
    line(B[0][0], B[1][0], B[0][1], B[1][1]);
    line(B[0][1], B[1][1], B[0][2], B[1][2]);
    line(B[0][2], B[1][2], B[0][0], B[1][0]);
}

int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, NULL);

    int A[3][3], B[3][3], C[3][3];

    cout << "Enter the coordinates of the first vertex: " << endl;
    cin >> B[0][0] >> B[1][0];

    cout << "Enter the coordinates of the second vertex: " << endl;
    cin >> B[0][1] >> B[1][1];

    cout << "Enter the coordinates of the third vertex: " << endl;
    cin >> B[0][2] >> B[1][2];

    B[2][0] = B[2][1] = B[2][2] = 1;

    // Printing initial shape
    setcolor(1);
    printMatrix(B);

    cout << "Enter the transformation to be performed: " << endl;
    cout << "1. Translation" << endl;
    cout << "2. Scaling" << endl;
    cout << "3. Rotation" << endl;
    int ch;
    cin >> ch;

    switch (ch)
    {
    default:
    {
        cout << "Invalid Choice!!!";
        break;
    }

    case 1:
    {
        cout << "Enter the translation factors tx and ty: " << endl;
        int tx, ty;
        cin >> tx;
        cin >> ty;

        // Defining the translation matrix
        A[0][0] = A[1][1] = A[2][2] = 1;
        A[0][1] = A[1][0] = A[2][0] = A[2][1] = 0;
        A[0][2] = tx;
        A[1][2] = ty;

        // Resultant transformed matrix
        multiplyMatrix(A, B, C);
        setcolor(2);
        printMatrix(C);
        break;
    }

    case 2:
    {
        cout << "Enter the scaling factors sx and sy: " << endl;
        float sx, sy;
        cin >> sx;
        cin >> sy;
        float A[3][3];
        A[0][0] = sx;
        A[1][1] = sy;
        A[2][2] = 1;
        A[0][1] = A[0][2] = A[1][0] = A[1][2] = A[2][0] = A[2][1] = 0;

        // Resultant transformed matrix
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }
        setcolor(3);
        line(C[0][0], C[1][0], C[0][1], C[1][1]);
        line(C[0][1], C[1][1], C[0][2], C[1][2]);
        line(C[0][2], C[1][2], C[0][0], C[1][0]);
        break;
    }

    case 3:
    {
        cout << "Enter the angle in degrees: " << endl;
        float angle;
        cin >> angle;
        angle = (M_PI / 180) * angle;

        float A[3][3], C[3][3];

        A[2][2] = 1;
        A[0][2] = A[1][2] = A[2][0] = A[2][1] = 0;
        A[0][0] = cos(angle);
        A[0][1] = -sin(angle);
        A[1][0] = sin(angle);
        A[1][1] = cos(angle);

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                C[i][j] = 0;
                for (int k = 0; k < 3; k++)
                {
                    C[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        setcolor(5);

        line(C[0][0], C[1][0], C[0][1], C[1][1]);
        line(C[0][1], C[1][1], C[0][2], C[1][2]);
        line(C[0][2], C[1][2], C[0][0], C[1][0]);
        break;
    }
    }

    delay(5000);
    closegraph();
    return 0;
}
