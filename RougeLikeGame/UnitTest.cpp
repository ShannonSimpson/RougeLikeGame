//Shannon Simpson
//Shannon.Simpson1020@gmail.com
//UnitTest.cpp

#include "DungeonLevel.h"
#include "UnitTest.h"

using namespace std;

UnitTest::UnitTest()
{
}

UnitTest::~UnitTest()
{
}

void UnitTest::markPosition(vector<string> & vLevel, int x, int y)
{
	//check to see if x and y are within the coordinates provided by the bounds of the vector.
    //first checks the lower bounds of x and y.
    if (x < 0)
            return;
    if(y < 0)
            return;

    if( y >= vLevel.size() ) //checks upper bound of y, which must before before x since the check for x uses it.
            return;

    if(x >= vLevel[y].size() ) //checks upper bound of x.
            return;


    //check to see if it is a tunnel or room tile.
    char cTile = vLevel[y][x]; //the tile we are on.

    if( (cTile != '.') && (cTile != '#') ) //this is a totalogy, WOO! Also, use parathenses for clarity.
            return;

    //next Mark the specified tile with an 'X'
    vLevel[y][x] = 'X';

    //call the function on all adjacent tiles. adjust if you consider diagonal squares are adjacent.
    markPosition(vLevel, x - 1, y);
    markPosition(vLevel, x + 1, y);
    markPosition(vLevel, x, y - 1);
    markPosition(vLevel, x, y + 1);
}

bool UnitTest::testLevel(vector<string> & vLevel)
{
	// Display the initial state
	cout << "Initial state: " << endl;
    for( auto it = vLevel.begin(); it != vLevel.end(); it++ )
    {
		cout << (*it) << endl;
    }

    cout << endl;


	int x = -1;
	int y = -1;

	// pick a starting position
	for( int i = 0; i < vLevel.size(); i++ )
	{
		for( int j = 0; j < vLevel[i].size(); j++ )
		{
			if( vLevel[i][j] == '.' || vLevel[i][j] == '#' )
			{
				// Starting position just has to be a room or
				// tunnel tile
				x = j;
				y = i;
			}
		}
	}

	if( x == -1 )
	{
		cout << "Unable to find starting position!" << endl;
		return false;
	}

	// Call the function which actually marks the tiles -- it should mark
	// the starting tile, then any adjacent to it, etc -- so after it's done,
	// everything that can be connected to the starting tile should be
	// marked.
	markPosition(vLevel, x, y);

	bool bCorrect = true;

	cout << endl << "Marked state: " << endl;
	// Outer loop
	for( auto itOuter = vLevel.begin(); itOuter != vLevel.end(); itOuter++ )
	{
		// Inner loop
		for( auto itInner = (*itOuter).begin(); itInner != (*itOuter).end(); itInner++ )
		{
			cout << (*itInner);


			// Now, test if it's a room/tunnel tile -- if it's still
			// one after we've
			if( (*itInner) == '.' || (*itInner) == '#' )
			{
				bCorrect = false;
			}
		}

		cout << endl;
	}

	cout << endl;

	if( !bCorrect )
	{
		cout << "Unreached room/tunnel tile detected!" << endl;
	}
		
	return bCorrect;

}

