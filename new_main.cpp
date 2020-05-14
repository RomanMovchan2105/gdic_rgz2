#include<iostream>
#include<fstream>
#include<thread>
#include<chrono>

using namespace std;

int main()
{
    unsigned short int width, height;

    cout << "Enter the width of the field : ";
    cin >> width;
    cout << "Enter the height of the field: ";
    cin >> height;

    unsigned short int **cell = new unsigned short int*[height];
    unsigned short int **copy_cell = new unsigned short int*[height];
    for ( int i = 0; i < height; i++ )
    {
        cell[i] = new unsigned short int[width];
        copy_cell[i] = new unsigned short int[width];
    }

    unsigned short int choice;
    cout << "If you want to set cell's state manually, enter 0.\n";
    cout << "If you want to set cell's state by file,  enter 1.\n";
    cout << "You select "; cin >> choice;

    switch( choice )
    {
    case 0:
    {
        cout << "If a cell is dead,  enter 0.\n";
        cout << "If a cell is alive, enter 1.\n";
        for ( unsigned short int i = 0; i < height; i++ )
        {
            for ( unsigned short int j = 0; j < width; j++ )
            {
                cin >> cell[i][j];
                copy_cell[i][j] = 0;
            }
        }
        break;
    }
    case 1:
    {
        ifstream ifs( "bin.txt" );
        if ( ifs.is_open() )
        {
            for ( unsigned short int i = 0; i < height; i++ )
            {
                for ( unsigned short int j = 0; j < width; j++ )
                {
                    ifs >> cell[i][j];
                    copy_cell[i][j] = 0;
                }
            }
            ifs.close();
            for ( unsigned short int i = 0; i < height; i++ )
            {
                for ( unsigned short int j = 0; j < width; j++ )
                {
                    if ( ( cell[i][j] != 1 ) && ( cell[i][j] != 0 ) )
                    {
                        cell[i][j] = 0;
                    }
                }
            }
        }
        else
        {
            cout << "File open error\n";
            return 1;
        }
        break;
    }
    }

    cout << "o - alive cell.\n";
    cout << "x - dead cell.\n";
    cout << "Begin:\n";

    for ( unsigned short int i = 0; i < height; i++ )
    {
        for ( unsigned short int j = 0; j < width; j++ )
        {
            if ( cell[i][j] == 0 )
            {
                cout << "x ";
            }
            else
            {
                cout << "o ";
            }
        }
        cout << endl;
    }
    cout << endl;

    unsigned short int sum = 0;
    unsigned short int loop_count = 0;
    unsigned int final_dead = 0;
    unsigned short int dead = 0;
    unsigned int resurrected = 0;
    unsigned short int step = 1;
    bool game_over;

    do
    {
        this_thread::sleep_for(chrono::milliseconds(800));
        cout << "Step "<< step++ << "." << endl;

        game_over = true;

        for ( unsigned short int i = 0; i < height; i++ )
        {
            for ( unsigned short int j = 0; j < width; j++ )
            {
                copy_cell[i][j] = cell[i][j];
            }
        }

        for ( unsigned short int i = 0; i < height; i++ )
        {
            for ( unsigned short int j = 0; j < width; j++ )
            {
                sum = 0;
                if ( ( i == 0 ) && ( j == 0 ) )
                {
                    sum = cell[height-1-i][width-1-j] + cell[height-1][j]+ cell[height-1-i][1+j]+
                          cell[i][width-1] + cell[i][j+1]+
                          cell[i+1][width-1-j] + cell[i+1][j] + cell[i+1][j+1];
                }
                else
                if ( ( i == 0 ) && ( j > 0 ) && ( j < ( width - 1 ) ) )
                {
                    sum = cell[height-1][j-1] + cell[height-1][j]+ cell[height-1][1+j]+
                          cell[i][j-1] + cell[i][j+1]+
                          cell[i+1][j-1] + cell[i+1][j] + cell[i+1][j+1];
                }
                else
                if ( ( i == 0 ) && ( j == ( width - 1 ) ) )
                {
                    sum = cell[height-1][j-1] + cell[height-1][j] + cell[height-1][0] +
                          cell[i][j-1] + cell[i][0] +
                          cell[i+1][j-1] + cell[i+1][j] + cell[i+1][0];
                }
                else
                if ( ( i > 0 ) && ( i < ( height - 1 ) ) && ( j == 0 ) )
                {
                    sum = cell[i-1][width-1] + cell[i-1][j] + cell[i-1][j+1] +
                          cell[i][width-1] + cell[i][j+1] +
                          cell[i+1][width-1] + cell[i+1][j] + cell[i+1][j+1];
                }
                else
                if ( ( i > 0 ) && ( i < ( height - 1 ) ) && ( j > 0 ) && ( j < ( width - 1 ) ) )
                {
                    sum = cell[i-1][j-1] + cell[i-1][j] + cell[i-1][j+1] +
                          cell[i][j-1] + cell[i][j+1] +
                          cell[i+1][j-1] + cell[i+1][j] + cell[i+1][j+1];
                }
                else
                if ( ( i > 0 ) && ( i < ( height - 1 ) ) && ( j == ( width - 1 ) ) )
                {
                    sum = cell[i-1][j-1] + cell[i-1][j] + cell[i-1][0] +
                          cell[i][j-1] + cell[i][0] +
                          cell[i+1][j-1] + cell[i+1][j] + cell[i+1][0];
                }
                else
                if ( ( i == ( height - 1 ) ) && ( j == 0 ) )
                {
                    sum = cell[i-1][width-1] + cell[i-1][j] + cell[i-1][j+1] +
                          cell[i][width-1] + cell[i][j+1] +
                          cell[0][width-1] + cell[0][j] + cell[0][j+1];
                }
                else
                if ( ( i == ( height - 1 ) ) && ( j > 0 ) && ( j < ( width - 1 ) ) )
                {
                    sum = cell[i-1][j-1] + cell[i-1][j] + cell[i-1][j+1] +
                          cell[i][j-1] + cell[i][j+1] +
                          cell[0][j-1] + cell[0][j] + cell[0][j+1];
                }
                else
                if ( ( i == ( height - 1 ) ) && ( j == ( width - 1 ) ) )
                {
                    sum = cell[i-1][j-1] + cell[i-1][j] + cell[i-1][0] +
                          cell[i][j-1] + cell[i][0] +
                          cell[0][j-1] + cell[0][j] + cell[0][0];
                }

                if ( ( cell[i][j] == 1 ) && ( sum < 2 ) )
                {
                    cell[i][j] = 0;
                    dead++;
                }
                else
                if ( ( cell[i][j] == 1 ) && ( sum > 3 ) )
                {
                    cell[i][j] = 0;
                    dead++;
                }
                else
                if ( ( cell[i][j] == 1 ) && ( sum >= 2 ) && ( sum <= 3 ) )
                {
                    cell[i][j] = 1;
                }
                else
                if ( ( cell[i][j] == 0 ) && ( sum == 3 ) )
                {
                    cell[i][j] = 1;
                    resurrected++;
                }
            }
        }

        for ( unsigned short int i = 0; i < height; i++ )
        {
            for ( unsigned short int j = 0; j < width; j++ )
            {
                if ( cell[i][j] == 0 )
                {
                    cout << "x ";
                }
                else
                {
                    cout << "o ";
                }
            }
            cout << endl;
        }
        cout << endl;

        for ( unsigned short int i = 0; i < height; i++ )
        {
            for ( unsigned short int j = 0; j < width; j++ )
            {
                if ( cell[i][j] == copy_cell[i][j] )
                {
                    loop_count++;
                }
            }
        }

        for ( unsigned short int i = 0; i < height; i++ )
        {
            for ( unsigned short int j = 0; j < width; j++ )
            {
                if ( cell[i][j] != 0)
                {
                    game_over = false;
                }
                else
                    final_dead++;
            }
        }

        if ( game_over == true )
        {
            cout << "All cells died. Game over.\n";
        }
        else
            if ( loop_count == ( width * height ) )
            {
                game_over = true;

                this_thread::sleep_for(chrono::milliseconds(800));
                cout << "It's an endless loop from step " << --step << "\n";
            }
            else
            {
                final_dead = 0;
                loop_count=0;
            }

        if ( step == 100 )
        {
            cout << "It's an endless loop.\n";
            break;
        }
    }
    while ( game_over == false );

    cout << dead << " cells died per game.\n";
    cout << resurrected << " cells resurrected per game.\n";
    cout << "At the end of the game " << final_dead << " cells are dead.\n";
    cout << "At the end of the game " << height * width - final_dead << " cells are alive.\n";
    cout << "Thank you for playing!\n";

    for ( unsigned short int i = 0; i < width; i++ )
        delete[] cell[i];
    delete[] cell;

    for ( unsigned short int i = 0; i < width; i++ )
        delete[] copy_cell[i];
    delete[] copy_cell;

    return 0;
}
