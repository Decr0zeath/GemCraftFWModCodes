#include <stdio.h>

#define CODE_COUNT 36
#define CODE_LENGTH 5

// Achievement codes: 36 achievements with 5-element code each
int codes[CODE_COUNT][CODE_LENGTH] = {
	{12,5,11,2,4} 	, 	// Armored Orb
	{4,10,9,12,12} 	, 	// Derangement
	{2,4,12,8,1} 	, 	// Dry Puddle
	{8,3,8,9,7} 	, 	// Double Strike
	{1,5,7,11,11} 	, 	// A Shrubbery!
	{3,12,4,8,11} 	, 	// Fully Lit
	{1,4,12,12,5} 	, 	// Stumbling
	{2,4,10,5,10} 	, 	// Juggler
	{5,7,9,6,2} 	, 	// Sharpened
	{12,12,3,11,1} 	, 	// Skylark
	{9,7,6,3,1} 	, 	// Double Sharded
	{2,2,7,10,5} 	, 	// Eggnog
	{6,2,4,10,1} 	, 	// Bye Bye Hideous
	{1,7,11,2,4} 	, 	// Not So Fast
	{3,3,12,5,1} 	, 	// Multiline
	{9,9,10,4,6} 	, 	// Come Again
	{1,7,3,10,8} 	, 	// Vantage Point Down
	{1,6,8,5,7} 	, 	// Disciple
	{1,6,10,2,2} 	, 	// Ages Old Memories
	{6,3,9,3,3} 	, 	// What Are You Waiting For?
	{1,4,10,7,6} 	, 	// Blue Wand
	{8,11,9,3,1} 	, 	// Connecting the Dots
	{7,8,5,8,1} 	, 	// Black Blood
	{1,7,10,9,9} 	, 	// Round Cut
	{11,11,5,7,8} 	, 	// By Three They Go
	{11,9,2,6,1} 	, 	// Mana Trader
	{1,4,8,8,3} 	, 	// Come Out, Come Out
	{1,10,3,4,10} 	, 	// Century Egg
	{1,3,7,6,3} 	, 	// Forged in Battle
	{4,5,9,11,1} 	, 	// Your Mana is Mine
	{5,10,9,2,1} 	, 	// Early Bird
	{10,5,7,5,1} 	, 	// Is Anyone in There?
	{7,6,9,11,9} 	, 	// Can't Stop
	{10,8,7,4,5} 	, 	// Feels Like Endurance
	{4,6,5,5,1} 	, 	// Out of Nowhere
	{1,7,6,3,12} 		// Purist
};


// Function to print a valid mod combination
void printMod(int index1, int index2, int index3, int *modCounter) {
    printf("Code #%.2d : ", (*modCounter)++);
    
    // Part 1 from first code
    for (int i = 0; i < 5; i++) {
        printf("%d ", codes[index1][i]);
    }
    // Middle digit from third code
    printf("%d ", codes[index3][2]);

    // Part 2 from second code
    for (int i = 0; i < 5; i++) {
        printf("%d ", codes[index2][i]);
    }
    
    printf("\n");
}

int main() {
    int modCounter = 1;

    for (int i = 0; i < CODE_COUNT; i++) {
        // Code must start with 1
        if (codes[i][0] != 1) continue;

        for (int j = 0; j < CODE_COUNT; j++) {
            if (j == i || codes[j][4] != 1) continue; // Must end with 1

            for (int k = 0; k < CODE_COUNT; k++) {
                if (k == i || k == j) continue;

                // Check matching conditions
                if (codes[k][0] == codes[i][3] &&
                    codes[k][1] == codes[i][4] &&
                    codes[k][3] == codes[j][0] &&
                    codes[k][4] == codes[j][1]) {

                    printMod(i, j, k, &modCounter);
                }
            }
        }
    }

    return 0;
}