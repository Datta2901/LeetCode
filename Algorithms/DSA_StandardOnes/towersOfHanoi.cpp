#include <bits/stdc++.h>
using namespace std;

// void towerOfHanoi(int n, char from_rod,
// 					char to_rod, char aux_rod)
// {
// 	if (n == 0)
// 	{
// 		return;
// 	}
// 	towerOfHanoi(n - 1, from_rod, aux_rod, to_rod);
// 	cout << "Move disk " << n << " from rod " << from_rod <<
// 								" to rod " << to_rod << endl;
// 	towerOfHanoi(n - 1, aux_rod, to_rod, from_rod);
// }

void TowerOfHanoi(int n,char from,char to,char temp){
    if(n == 0){
        return;
    }
    TowerOfHanoi(n - 1,from,temp,to);
    cout << "Move Disk " << n << " from rod " << from << " to rod " << to << endl;
    TowerOfHanoi(n - 1,temp,to,from);
}
// Driver code
int main()
{
	int n = 4; 
	TowerOfHanoi(n, 'A', 'C', 'B'); 
	return 0;
}

